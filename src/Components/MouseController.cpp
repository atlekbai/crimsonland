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
    int delta_x;
    int delta_y;
    int x;
    int y;
    SDL_GetMouseState(&x, &y);
    delta_x = transform->position.x - x;
    delta_y = transform->position.y - y;
    sprite->angle = (atan2(delta_y, delta_x) * 180.0) / 3.1416 + 90;
}
