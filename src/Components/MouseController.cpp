// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MouseController.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/28 15:46:13 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/28 15:46:13 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "MouseController.hpp"
#include "MyFramework.hpp"

void    MouseController::init(void)
{
    transform = &entity->getComponent<TransformComponent>();
    sprite = &entity->getComponent<SpriteComponent>();
}

void    MouseController::update(void)
{
    static int bulletDelay = 0;
    int delta_x;
    int delta_y;
    int x;
    int y;
    SDL_GetMouseState(&x, &y);

    delta_x = transform->position.x - MyFramework::camera.x - x;
    delta_y = transform->position.y - MyFramework::camera.y - y;
    sprite->angle = (atan2(delta_y, delta_x) * 180.0) / 3.1416 + 90;

    if (MyFramework::event.type == SDL_MOUSEBUTTONDOWN)
    {
        if (MyFramework::event.button.button == SDL_BUTTON_LEFT && bulletDelay == 0)
        {
            int length = Vector2D::vectorLength(Vector2D(delta_x, delta_y));
            Vector2D dir = {- delta_x * 5/ length, - delta_y * 5/ length};
            auto &bullet(Game::manager.addEntity());
            bullet.addComponent<TransformComponent>(transform->position.x, transform->position.y, 32, 32, 1, 2, dir);
            bullet.addComponent<SpriteComponent>("fire", sprite->angle);
            bullet.addGroup(group_bullets);
            bulletDelay = 10;
        }
    }
    if (MyFramework::event.type == SDL_MOUSEBUTTONUP)
        if (MyFramework::event.button.button == SDL_BUTTON_LEFT)
            bulletDelay = 0;

    if (bulletDelay != 0)
        bulletDelay--;
}
