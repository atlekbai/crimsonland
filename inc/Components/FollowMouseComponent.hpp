// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FollowMouseComponent.hpp                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/30 17:39:07 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/30 17:39:07 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FOLLOW_MOUSE_COMPONENT_HPP
# define FOLLOW_MOUSE_COMPONENT_HPP

# include "Component.hpp"
# include "Components.hpp"

class SpriteComponent;

class FollowMouseComponent: public Component
{
public:
    TransformComponent  *transform;
    SpriteComponent     *sprite;

    void    init(void) override;
    void    update(void) override;
};

#endif