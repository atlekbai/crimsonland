// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/28 13:20:43 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/28 13:20:44 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
 
#include "Game.hpp"
#include "Manager.hpp"
#include "Components.hpp"
#include "Map.hpp"

AssetsManager	*Game::assets = nullptr;
Map				*Game::map = nullptr;
Manager			Game::manager;

auto			&reticle(Game::manager.addEntity());
 auto			&player(Game::manager.addEntity());
 auto			&enemySpawner(Game::manager.addEntity());

Game::Game(Framework *fr) : frameWork(fr)
{
	assets = new AssetsManager();
	assets->addSprite("soldier", "assets/soldier.png");
	assets->addSprite("tile", "assets/tile.png");
	assets->addSprite("spider", "assets/spawn_spider.png");
	assets->addSprite("fire", "assets/fire.png");
	assets->addSprite("reticle", "assets/reticle.png");

	map = new Map("tile", 2, 32);
	map->loadMap(30, 30);

	player.addComponent<TransformComponent>(MyFramework::camera.w / 2, MyFramework::camera.h / 2, 4);
	player.addComponent<SpriteComponent>("soldier");
	player.addComponent<KeyboardController>();
	player.addComponent<MouseController>();
	player.addGroup(group_players);

	reticle.addComponent<TransformComponent>();
	reticle.addComponent<SpriteComponent>("reticle");
	reticle.addComponent<FollowMouseComponent>();
	reticle.addGroup(group_ui);
	
	enemySpawner.addComponent<EnemySpawnComponent>(&player, "spider", map->size);
 }

void Game::handleEvents(void)
{
	SDL_PollEvent(&MyFramework::event);

    if (MyFramework::event.type == SDL_QUIT)
        exit(1);
}

bool	collision(TransformComponent *t1, TransformComponent *t2)
{
	return (t1->position.x < t2->position.x + t2->width && 
			t1->position.x + t1->width > t2->position.x &&
			t1->position.y < t2->position.y + t2->height && 
			t1->position.y + t1->height > t2->position.y);
}

auto	&tiles(Game::manager.getGroup(group_map));
auto	&players(Game::manager.getGroup(group_players));
auto	&enemies(Game::manager.getGroup(group_enemies));
auto	&bullets(Game::manager.getGroup(group_bullets));
auto	&uis(Game::manager.getGroup(group_ui));

void Game::update(void)
{
	Game::manager.refresh();
    Game::manager.update();

	MyFramework::camera.x = player.getComponent<TransformComponent>().position.x - 400;
	MyFramework::camera.y = player.getComponent<TransformComponent>().position.y - 320;

	if (MyFramework::camera.x < 0)
		MyFramework::camera.x = 0;
	if (MyFramework::camera.y < 0)
		MyFramework::camera.y = 0;
	if (MyFramework::camera.x > MyFramework::camera.w)
		MyFramework::camera.x = MyFramework::camera.w;
	if (MyFramework::camera.y > MyFramework::camera.h)
		MyFramework::camera.y = MyFramework::camera.h;
	
	for (auto &b: bullets)
	{
		if (b->getComponent<TransformComponent>().position.x > 30 * 2 * 32 ||
			b->getComponent<TransformComponent>().position.y > 30 * 2 * 32)
			b->destroy();
		else
			for (auto &e: enemies)
				if (collision(&b->getComponent<TransformComponent>(), &e->getComponent<TransformComponent>()))
				{
					enemySpawner.getComponent<EnemySpawnComponent>().killSpawn(e);
					b->destroy();
					break ;
				}
	}
	for (auto &e: enemies)
	{
		if (collision(&player.getComponent<TransformComponent>(), &e->getComponent<TransformComponent>()))
		{
			MyFramework::is_running = false;
			std::cout << "You dead" << std::endl;
		}
	}
}

void Game::render(void)
{
	SDL_RenderClear(MyFramework::renderer);

	for (auto &t: tiles)
		t->draw();
	for (auto &p: players)
		p->draw();
	for (auto &e: enemies)
		e->draw();
	for (auto &b: bullets)
		b->draw();
	for (auto &u: uis)
		u->draw();

	SDL_RenderPresent(MyFramework::renderer);
}
