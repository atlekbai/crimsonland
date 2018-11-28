// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SpriteComponent.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/28 14:27:52 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/28 14:27:53 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "SpriteComponent.hpp"
#include "Manager.hpp"

SpriteComponent::SpriteComponent(std::string id)
{
    setTexture(id);
}

void    SpriteComponent::setTexture(std::string id)
{
    sprite = Game::assets->getSprite(id);
}

void    SpriteComponent::init(void)
{
    transform = &entity->getComponent<TransformComponent>();
    sprite->src.w = transform->width;
    sprite->src.h = transform->height;
}

void    SpriteComponent::update(void)
{
    sprite->dst.x = static_cast<int>(transform->position.x) - MyFramework::camera.x;
    sprite->dst.y = static_cast<int>(transform->position.y) - MyFramework::camera.y;
    sprite->dst.w = transform->width * transform->scale;
    sprite->dst.h = transform->height * transform->scale;
}

void    SpriteComponent::draw(void)
{
    drawSprite(sprite, angle);
}