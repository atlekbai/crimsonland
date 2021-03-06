// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TransformComponent.hpp                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/28 14:17:03 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/28 14:17:03 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef TRANSFORM_COMPONENT_HPP
# define TRANSFORM_COMPONENT_HPP

#include "Component.hpp"
#include "Vector2D.hpp"

class TransformComponent: public Component
{
public:
    Vector2D    position;
    Vector2D    velocity;
    int         width = 32;
    int         height = 32;
    int         scale = 2;
    int         speed = 2;
    double      angle = 0;
    bool        vel_set = false;

    TransformComponent(void);
    TransformComponent(int _scale);
    TransformComponent(int x, int y);
    TransformComponent(int x, int y, int _speed);
    TransformComponent(int x, int y, int w, int h, int _speed, int _scale, Vector2D vel);

    void setAngle(double angl);
    void setVelocity(Vector2D dir);
    void init(void) override;
    void update(void) override;
};

#endif