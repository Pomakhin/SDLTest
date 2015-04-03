//
//  main.cpp
//  SDLTest
//
//  Created by Михаил Помахин on 27.03.15.
//  Copyright (c) 2015 Михаил Помахин. All rights reserved.
//

#include <iostream>
#include "game.h"

Game *g_game = nullptr;

int main(int argc, char* args[])
{
    g_game = new Game();
    g_game->init("Chapter 1", 100, 100, 755, 600, 0);
    while(g_game->isRunning())
    {
        g_game->handleEvents();
        g_game->update();
        g_game->render();
    }
    g_game->clean();
    return 0;
}