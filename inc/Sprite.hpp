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

# include "Vector2D.hpp"
# include "MyFramework.hpp"

class Sprite
{
private:
    SDL_Texture *texture;
public:
    Vector2D    size;
    Sprite(SDL_Texture *tex);
    ~Sprite(void);
    SDL_Texture *getTexture(void) const;
    void        getSize(int &w, int &h) const;
};

#endif