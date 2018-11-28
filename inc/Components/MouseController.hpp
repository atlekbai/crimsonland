// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MouseController.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/28 15:46:07 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/28 15:46:08 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MOUSE_CONTROLLER_HPP
# define MOUSE_CONTROLLER_HPP

# include "Component.hpp"
# include "Components.hpp"

class SpriteComponent;

class MouseController: public Component
{
public:
    TransformComponent  *transform;
    SpriteComponent     *sprite;

    void    init(void) override;
    void    update(void) override;
};

#endif
