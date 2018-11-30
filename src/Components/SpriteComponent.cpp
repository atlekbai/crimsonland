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

SpriteComponent::SpriteComponent(std::string id, double angl)
{
    setTexture(id);
    angle = angl;
}

void    SpriteComponent::setTexture(std::string id)
{
    sprite = Game::assets->getSprite(id);
}

void    SpriteComponent::init(void)
{
    transform = &entity->getComponent<TransformComponent>();
    src.x = 0;
    src.y = 0;
    src.w = transform->width;
    src.h = transform->height;
}

void    SpriteComponent::update(void)
{
    dst.x = static_cast<int>(transform->position.x) - MyFramework::camera.x;
    dst.y = static_cast<int>(transform->position.y) - MyFramework::camera.y;
    dst.w = transform->width * transform->scale;
    dst.h = transform->height * transform->scale;
}

void    SpriteComponent::draw(void)
{
    drawSprite(sprite, src, dst, angle);
}