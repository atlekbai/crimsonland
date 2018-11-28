// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TransformComponent.cpp                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/28 14:17:08 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/28 14:17:08 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "TransformComponent.hpp"

TransformComponent::TransformComponent(void) : position(Vector2D(0, 0))
{}

TransformComponent::TransformComponent(int _scale) : position(Vector2D(0, 0)), scale(_scale)
{}
TransformComponent::TransformComponent(int x, int y) : position(Vector2D(x, y))
{}
TransformComponent::TransformComponent(int x, int y, int w, int h, int _scale)
{
    position = Vector2D(x, y);
    width = w;
    height = h;
    scale = _scale;
}

void TransformComponent::init(void)
{
    velocity.zero();
}

void TransformComponent::update(void)
{
    position.x += velocity.x * speed;
    position.y += velocity.y * speed;
}
