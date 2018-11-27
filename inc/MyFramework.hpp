// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MyFramework.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/27 20:23:38 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/27 20:23:39 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MY_FRAMEWORK_HPP
# define MY_FRAMEWORK_HPP

# include "Framework.hpp"
# include "AssetsManager.hpp"

class MyFramework : public Framework {
private:
    SDL_Window  *window;
    bool        init = false;
public:
	virtual void PreInit(int& width, int& height, bool& fullscreen);
	virtual bool Init();
	virtual void Close();
	virtual bool Tick();
	virtual void onMouseMove(int x, int y, int xrelative, int yrelative);
	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased);
	virtual void onKeyPressed(FRKey k);
	virtual void onKeyReleased(FRKey k);

    static SDL_Renderer *renderer;
    static SDL_Event    event;
    static SDL_Rect     camera;
    static AssetManager *assets;
};

#endif