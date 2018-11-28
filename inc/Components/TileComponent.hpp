// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TileComponent.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/28 16:28:28 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/28 16:28:28 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef TILE_COMPONENT_HPP
# define TILE_COMPONENT_HPP

# include "Component.hpp"
# include "Components.hpp"
# include "Game.hpp"
# include "Vector2D.hpp"
# include "Sprite.hpp"

class TileComponent: public Component
{
public:
    Sprite      *sprite;
    Vector2D    position;
    SDL_Rect    src;
    SDL_Rect    dst;
    TileComponent(int src_x, int src_y, int dst_x, int dst_y, int size, int scale, std::string id);
    void update(void) override;
    void draw(void) override;
};

#endif