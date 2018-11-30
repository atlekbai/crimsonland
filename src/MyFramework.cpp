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
#include "AssetsManager.hpp"
#include "Game.hpp"

SDL_Renderer    *MyFramework::renderer = nullptr;
SDL_Event       MyFramework::event;
SDL_Rect        MyFramework::camera;
unsigned        MyFramework::timeStart = 0;
bool            MyFramework::is_running = false;

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
    is_running = true;
    camera = {0, 0, width, height};
    timeStart = SDL_GetTicks();
    game = new Game(this);
}

bool MyFramework::Init()
{
    return (is_running);
}

void MyFramework::Close()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool MyFramework::Tick()
{
    return (!is_running);
}

void MyFramework::play(void)
{
    game->handleEvents();
    game->update();
    game->render();
}

/*
**  Extra functions
*/

unsigned int    getTickCount()
{
    return (SDL_GetTicks() - MyFramework::timeStart);
}

void            showCursor(bool bShow)
{}

int     run(Framework* fr)
{
    const int   FPS = 90;
    const int   frameDelay = 1000 / FPS;
    unsigned    frameStart;
    int         frameTime;
    int         width = 800;
    int         height = 640;
    bool        full = false;

    fr->PreInit(width, height, full);
    if (!fr->Init())
        return (1);
    while (!fr->Tick())
    {
        frameStart = SDL_GetTicks();

        fr->play();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
    }
    fr->Close();
    return (1);
}
