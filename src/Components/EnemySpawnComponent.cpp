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

EnemySpawnComponent::EnemySpawnComponent(Entity *entityToAttack, std::string id)
{
    hero = entityToAttack;
    sprite_id = id;
    count = 10;
}

void EnemySpawnComponent::init(void)
{
    addSpawns(count);
}

void EnemySpawnComponent::update(void)
{
    // transform = &hero->getComponent<TransformComponent>();
    // auto &spawns(Game::manager.getGroup(group_enemies));
    // for (auto &s: spawns)
    // {
        
    // }
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
    for (int _ = 0; _ < n; _++)
    {
        x = rand() % 500 + MyFramework::camera.w + 20;
        y = rand() % 500 + MyFramework::camera.h + 20;
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

void EnemySpawnComponent::killSpawn(Entity &s)
{
    s.destroy();
    count--;
}
