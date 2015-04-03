//
//  game.cpp
//  SDLTest
//
//  Created by Михаил Помахин on 03.04.15.
//  Copyright (c) 2015 Михаил Помахин. All rights reserved.
//

#include "game.h"
#include <iostream>
#include <SDL2_image/SDL_image.h>


void Game::init(const char* title, int xpos, int ypos, int
          height, int width, bool fullScreen)
{
    // initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        // if succeeded create our window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos,
                                     height, width, 0);
        // if the window creation succeeded create our renderer
        if(m_pWindow != 0)
        {
            std::cout << "window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            if (m_pRenderer)
            {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(m_pRenderer,
                                       255,255,255,255);
            }
            
            
            SDL_Surface *tempSurface = IMG_Load("assets/char9.jpg");
            m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer,
                                                      tempSurface);
            SDL_FreeSurface(tempSurface);
            
            SDL_QueryTexture(m_pTexture, NULL, NULL,
                             &m_sourceRectangle.w, &m_sourceRectangle.h);
            
            m_sourceRectangle.x = 0;
            m_sourceRectangle.y = 0;
            m_destinationRectangle.x = 100;
            m_destinationRectangle.y = 100;
            m_destinationRectangle.w = m_sourceRectangle.w;
            m_destinationRectangle.h = m_sourceRectangle.h;
            
            m_running = true;
        }
    }
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color
    SDL_RenderCopy(m_pRenderer, m_pTexture, nullptr, nullptr);
    SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::clean()
{
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

void Game::handleEvents()
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                m_running = false;
                break;
            default:
                break;
        }
    }
}
