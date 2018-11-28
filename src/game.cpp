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

 auto			&player(Game::manager.addEntity());

 Game::Game(Framework *fr) : frameWork(fr)
 {
	assets = new AssetsManager();
	assets->addSprite("soldier", "assets/soldier.png");
	assets->addSprite("tile", "assets/tile.png");
	assets->addSprite("spider", "assets/spawn_spider.png");

	map = new Map("tile", 3, 32);
	map->loadMap(30, 30);

	player.addComponent<TransformComponent>(MyFramework::camera.w / 2, MyFramework::camera.h / 2);
	player.addComponent<SpriteComponent>("soldier");
	player.addComponent<KeyboardController>();
	player.addComponent<MouseController>();
	player.addGroup(group_players);
 }

 void Game::handleEvents(void)
{
	SDL_PollEvent(&MyFramework::event);

    if (MyFramework::event.type == SDL_QUIT)
        MyFramework::is_running = false;
}

auto	&tiles(Game::manager.getGroup(group_map));
auto	&players(Game::manager.getGroup(group_players));


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
}

void Game::render(void)
{
	SDL_RenderClear(MyFramework::renderer);

	for (auto &t: tiles)
		t->draw();

	for (auto &p: players)
		p->draw();

	SDL_RenderPresent(MyFramework::renderer);
}

