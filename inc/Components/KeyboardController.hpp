// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   KeyboardController.hpp                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/28 15:26:47 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/28 15:26:48 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef KEYBOARD_CONTROLLER_HPP
# define KEYBOARD_CONTROLLER_HPP

# include "Component.hpp"
# include "Components.hpp"

class SpriteComponent;

class KeyboardController: public Component
{
public:
    TransformComponent  *transform;
    SpriteComponent     *sprite;

    void    init(void) override;
    void    update(void) override;
};

#endif