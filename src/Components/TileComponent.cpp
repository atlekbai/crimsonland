// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TileComponent.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/28 16:28:34 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/28 16:28:34 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "TileComponent.hpp"

TileComponent::TileComponent(int src_x, int src_y, int dst_x, int dst_y, int size, int scale, std::string id)
{
    sprite = Game::assets->getSprite(id);
    position.x = dst_x;
    position.y = dst_y;

    src.x = src_x;
    src.y = src_y;
    src.w = size;
    src.h = size;
    
    dst.x = dst_x;
    dst.y = dst_y;
    dst.w = size * scale;
    dst.h = size * scale;
}

void TileComponent::update(void)
{
    dst.x = position.x - MyFramework::camera.x;
    dst.y = position.y - MyFramework::camera.y;
}

void TileComponent::draw(void)
{
    drawSprite(sprite, src, dst);
}
