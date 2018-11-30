// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   EnemySpawnComponent.cpp                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/30 13:22:49 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/30 13:22:49 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "EnemySpawnComponent.hpp"

EnemySpawnComponent::EnemySpawnComponent(Entity *entityToAttack, std::string id, Vector2D map_size)
{
    hero = entityToAttack;
    sprite_id = id;
    countSpawns = 5;
    count = countSpawns;
    mapSize = map_size;
}

void EnemySpawnComponent::init(void)
{
    addSpawns(count);
}

void EnemySpawnComponent::update(void)
{
    TransformComponent *transformHero;
    TransformComponent *transformSpawn;

    if (count == 0)
    {
        countSpawns += 5;
        count = countSpawns;
        std::cout << countSpawns << std::endl;
        addSpawns(count);
        return ;
    }
    transformHero = &hero->getComponent<TransformComponent>();
    auto &spawns(Game::manager.getGroup(group_enemies));
    for (auto &s: spawns)
    {
        transformSpawn = &s->getComponent<TransformComponent>();
        int delta_x = transformHero->position.x - transformSpawn->position.x;
        int delta_y = transformHero->position.y - transformSpawn->position.y;
        if (delta_x == 0 || delta_y == 0)
            continue ;
        int length = Vector2D::vectorLength(Vector2D(delta_x, delta_y));
        double angle = (atan2(-delta_y, -delta_x) * 180.0) / 3.1416 + 90;
        Vector2D dir = {(delta_x * 2)/ length, (delta_y * 2)/ length};
        transformSpawn->setVelocity(dir);
        s->getComponent<SpriteComponent>().angle = angle;
    }
}

void EnemySpawnComponent::addSpawns(int n)
{
    TransformComponent *transform;
    int delta_x;
    int delta_y;
    int x;
    int y;
    int angle;
    int length;

    transform = &hero->getComponent<TransformComponent>();
    for (int _ = 1; _ <= n; _++)
    {
        int s = rand() % 2;
        x = rand() % MyFramework::camera.w + (MyFramework::camera.x + MyFramework::camera.w) * s;
        y = rand() % MyFramework::camera.h + (MyFramework::camera.y + MyFramework::camera.h) * (1 - s);
        delta_x = x - transform->position.x;
        delta_y = y - transform->position.y;
        angle = (atan2(delta_y, delta_x) * 180.0) / 3.1416 + 90;
        length = Vector2D::vectorLength(Vector2D(delta_x, delta_y));

        auto	&enemy(Game::manager.addEntity());
        enemy.addComponent<TransformComponent>(x, y);
        enemy.addComponent<SpriteComponent>("spider", angle);
        enemy.addGroup(group_enemies);
    }
}

void EnemySpawnComponent::killSpawn(Entity *s)
{
    s->destroy();
    count--;
}
