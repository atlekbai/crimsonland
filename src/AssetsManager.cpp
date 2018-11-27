// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AssetsManager.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/27 21:49:44 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/27 21:49:44 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AssetsManager.hpp"

void            AssetsManager::addFont(std::string id, const char *fontFile, int fontSize)
{
    fonts.emplace(id, TTF_OpenFont(fontFile, fontSize));
}

void            AssetsManager::addTexture(std::string id, const char *textureFile)
{
    // implement texture adding
}

TTF_Font*       AssetsManager::getFont(std::string id)
{
    return (fonts[id]);
}

SDL_Texture*    AssetsManager::getTexture(std::string id)
{
    return (textures[id]);
}
