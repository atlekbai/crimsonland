// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/28 13:19:42 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/28 13:19:43 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_HPP
# define GAME_HPP

# include "MyFramework.hpp"
# include "Manager.hpp"
# include "AssetsManager.hpp"

class Map;

class Game
{
public:
    Framework   *frameWork;

public:
    Game(Framework *fr);

    virtual void handleEvents(void);
	virtual void update(void);
	virtual void render(void);

    static AssetsManager	*assets;
    static Manager          manager;
    static Map              *map;
};

#endif