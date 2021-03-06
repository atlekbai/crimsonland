// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AssetsManager.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/27 21:49:39 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/27 21:49:40 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ASSETS_MANAGER_HPP
# define ASSETS_MANAGER_HPP

# include "SDL2/SDL.h"
# include "SDL2_ttf/SDL_ttf.h"
# include "SDL2_image/SDL_image.h"
# include "Sprite.hpp"
# include <iostream>
# include <map>

class AssetsManager
{
private:
    std::map<std::string, Sprite*>      sprites;
    std::map<std::string, TTF_Font*>    fonts;
public:
    void            addFont(std::string id, const char *fontFile, int fontSize);
    void            addSprite(std::string id, const char *spriteFile);
    TTF_Font*       getFont(std::string id);
    Sprite*         getSprite(std::string id);
    ~AssetsManager();
};

#endif