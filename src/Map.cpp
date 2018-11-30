// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Map.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/28 16:19:20 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/28 16:19:20 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Map.hpp"
#include "Manager.hpp"
#include "Game.hpp"
#include "Components.hpp"

Map::Map(std::string id, int _scale, int _size)
{
    sprite_id = id;
    map_scale = _scale;
    tile_size = _size;
    scaled_size = map_scale * tile_size;
}

Map::~Map(void)
{}

void Map::loadMap(int size_x, int size_y)
{
    size = {size_x, size_y};
    for (int y = 0; y < size_y; y++)
        for (int x = 0; x < size_x; x++)
            addTile(0, 0, x * scaled_size, y * scaled_size);
}

void Map::addTile(int src_x, int src_y, int dst_x, int dst_y)
{
    auto &tile(Game::manager.addEntity());
    tile.addComponent<TileComponent>(src_x, src_y, dst_x, dst_y, tile_size, map_scale, sprite_id);
    tile.addGroup(group_map);
}
