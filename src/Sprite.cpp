// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Sprite.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/27 22:34:20 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/27 22:34:20 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Sprite.hpp"

Sprite::Sprite(SDL_Texture *tex)
{
    texture = tex;
}

Sprite::~Sprite(void)
{
    SDL_DestroyTexture(texture);
}

SDL_Texture *Sprite::get_texture(void) const
{
    return (texture);
}
