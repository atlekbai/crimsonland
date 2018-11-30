// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SpriteComponent.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/28 14:27:47 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/28 14:27:47 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SPRITE_COMPONENT_HPP
# define SPRITE_COMPONENT_HPP

#include "Component.hpp"
#include "Components.hpp"
#include "Game.hpp"
#include "Sprite.hpp"

class SpriteComponent: public Component
{
private:
    TransformComponent  *transform;
    SDL_Rect            src;
    Sprite              *sprite;
public:
    SDL_Rect            dst;
    SDL_RendererFlip    sprite_flip = SDL_FLIP_NONE;
    double              angle = 0;
    SpriteComponent(void) = default;
    SpriteComponent(std::string id);
    SpriteComponent(std::string id, double angl);
    void    setTexture(std::string id);
    void    init(void) override;
    void    update(void) override;
    void    draw(void) override;
};

#endif