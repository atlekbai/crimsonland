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
    SDL_QueryTexture(texture, nullptr, nullptr, &size.x, &size.y);
    src = {0, 0, size.x, size.y};
    dst = {0, 0, size.x, size.y};
}

Sprite::~Sprite(void)
{
    SDL_DestroyTexture(texture);
}

SDL_Texture *Sprite::getTexture(void) const
{
    return (texture);
}

void        Sprite::getSize(int &w, int &h) const
{
    w = size.x;
    h = size.y;
}

Sprite*         createSprite(const char* path)
{
    SDL_Surface *tmp = IMG_Load(path);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(MyFramework::renderer, tmp);
    SDL_FreeSurface(tmp);
    return (new Sprite(texture));
}

void            drawSprite(Sprite* sprite, int x, int y)
{
    sprite->dst.x = x;
    sprite->dst.y = y;
    SDL_RenderCopyEx(MyFramework::renderer, sprite->getTexture(), &sprite->src, &sprite->dst, 0.0, nullptr, SDL_FLIP_NONE);
}

void            drawSprite(Sprite* sprite, SDL_Rect src, SDL_Rect dst)
{
    SDL_RenderCopyEx(MyFramework::renderer, sprite->getTexture(), &src, &dst, 0.0, nullptr, SDL_FLIP_NONE);
}


void            drawSprite(Sprite* sprite)
{
    SDL_RenderCopyEx(MyFramework::renderer, sprite->getTexture(), &sprite->src, &sprite->dst, 0.0, nullptr, SDL_FLIP_NONE);
}

void            drawSprite(Sprite* sprite, double angle)
{
    SDL_RenderCopyEx(MyFramework::renderer, sprite->getTexture(), &sprite->src, &sprite->dst, angle, nullptr, SDL_FLIP_NONE);
}

void            getSpriteSize(Sprite* s, int& w, int &h)
{
    s->getSize(w, h);
}

void            destroySprite(Sprite* s)
{
    delete s;
}

void            drawTestBackground()
{
    // implement map reading
}

void            getScreenSize(int& w, int &h)
{
    w = MyFramework::camera.w;
    h = MyFramework::camera.h;
}
