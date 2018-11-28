// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Map.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/28 16:19:15 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/28 16:19:16 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MAP_HPP
# define MAP_HPP

# include "Sprite.hpp"

class Map
{
private:
    std::string sprite_id;
    int         map_scale;
    int         tile_size;
    int         scaled_size;
public:
    Map(std::string id, int _scale, int _size);
    ~Map(void);
    void loadMap(int size_x, int size_y);
    void addTile(int src_x, int src_y, int dst_x, int dst_y);
};

#endif