// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Framework.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/27 20:23:10 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/27 20:23:11 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FRAMEWORK_HPP
# define FRAMEWORK_HPP

# include "SDL2/SDL.h"
# include "SDL2_image/SDL_image.h"
# include "SDL2_ttf/SDL_ttf.h"

class Sprite;

Sprite*         createSprite(const char* path);
void            drawSprite(Sprite*, int x, int y);
void            getSpriteSize(Sprite* s, int& w, int &h);
void            destroySprite(Sprite* s);
void            drawTestBackground();
void            getScreenSize(int& w, int &h);

// Get the number of milliseconds since library initialization.
unsigned int    getTickCount();
void            showCursor(bool bShow);

enum class FRKey {
	RIGHT,
	LEFT,
	DOWN,
	UP,
	COUNT
};

enum class FRMouseButton {
	LEFT,
	MIDDLE,
	RIGHT,
	COUNT
};

class Framework {
public:
	// no function calls are available here, this function shuld only return width, height and fullscreen values
	virtual void PreInit(int& width, int& height, bool& fullscreen) = 0;
	
	// return : true - ok, false - failed, application will exit
	virtual bool Init() = 0;
	virtual void Close() = 0;
	
	// return value: if true will exit the application
	virtual bool Tick() = 0;
	
	// param: xrel, yrel: The relative motion in the X/Y direction 
	// param: x, y : coordinate, relative to window
	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) = 0;
	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) = 0;
	virtual void onKeyPressed(FRKey k) = 0;
	virtual void onKeyReleased(FRKey k) = 0;
	virtual ~Framework() {};
};


int     run(Framework*);

#endif