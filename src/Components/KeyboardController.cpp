// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   KeyboardController.cpp                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/28 15:26:41 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/28 15:26:42 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "KeyboardController.hpp"
#include "MyFramework.hpp"

void    KeyboardController::init(void)
{
    transform = &entity->getComponent<TransformComponent>();
    sprite = &entity->getComponent<SpriteComponent>();
}

void    KeyboardController::update(void)
{
    if (MyFramework::event.type == SDL_KEYDOWN)
    {
        SDL_Keycode code = MyFramework::event.key.keysym.sym;

        if (code == SDLK_w)
            transform->velocity.y = -1;
        else if (code == SDLK_s)
            transform->velocity.y = 1;
        else if (code == SDLK_a)
            transform->velocity.x = -1;
        else if (code == SDLK_d)
            transform->velocity.x = 1;
    }

    if (MyFramework::event.type == SDL_KEYUP)
    {
        SDL_Keycode code = MyFramework::event.key.keysym.sym;

        if (code == SDLK_w)
            transform->velocity.y = 0;
        else if (code == SDLK_s)
            transform->velocity.y = 0;
        else if (code == SDLK_a)
            transform->velocity.x = 0;
        else if (code == SDLK_d)
            transform->velocity.x = 0;
        else if (code == SDLK_ESCAPE)
            exit(1);
    }
}
