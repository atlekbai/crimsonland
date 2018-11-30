// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FollowMouseComponent.cpp                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/30 17:39:12 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/30 17:39:12 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "FollowMouseComponent.hpp"
#include "MyFramework.hpp"

void    FollowMouseComponent::init(void)
{
    transform = &entity->getComponent<TransformComponent>();
    sprite = &entity->getComponent<SpriteComponent>();
}

void    FollowMouseComponent::update(void)
{
    int x;
    int y;
    SDL_GetMouseState(&x, &y);
    transform->position.x = MyFramework::camera.x + x - 32;
    transform->position.y = MyFramework::camera.y + y - 32;
}
