// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Sprite.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/27 22:34:15 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/27 22:34:16 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SPRITE_HPP
# define SPRITE_HPP

# include "SDL2/SDL.h"
# include "SDL2_image/SDL_image.h"

class Sprite
{
private:
    SDL_Texture *texture;
public:
    SDL_Rect    src;
    SDL_Rect    dst;
    Sprite(SDL_Texture *tex);
    ~Sprite(void);
    SDL_Texture *get_texture(void) const;
};

#endif