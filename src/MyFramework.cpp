// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MyFramework.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/27 22:36:08 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/27 22:36:09 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "MyFramework.hpp"

AssetManager *MyFramework::assets = nullptr;
SDL_Renderer *MyFramework::renderer = nullptr;
SDL_Event    MyFramework::event;
SDL_Rect     MyFramework::camera;

void MyFramework::PreInit(int& width, int& height, bool& fullscreen)
{
    int flags;

    flags = (fullscreen) ? SDL_WINDOW_FULLSCREEN : 0;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        return  ;
    window = SDL_CreateWindow("dragonlk", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
    if (!window)
        return;
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer)
        return ;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    if (TTF_Init() == -1)
        return ;
    init = true;
    camera = {0, 0, width, height};
}

bool MyFramework::Init()
{
    return (init);
}

void MyFramework::Close()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool MyFramework::Tick()
{}

void MyFramework::onMouseMove(int x, int y, int xrelative, int yrelative)
{}

void MyFramework::onMouseButtonClick(FRMouseButton button, bool isReleased)
{}

void MyFramework::onKeyPressed(FRKey k)
{}

void MyFramework::onKeyReleased(FRKey k)
{}

