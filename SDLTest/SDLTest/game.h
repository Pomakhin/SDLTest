//
//  game.h
//  SDLTest
//
//  Created by Михаил Помахин on 03.04.15.
//  Copyright (c) 2015 Михаил Помахин. All rights reserved.
//

#ifndef __SDLTest__game__
#define __SDLTest__game__

#include <stdio.h>
#include <SDL2/SDL.h>

class Game
{
private:
    bool m_running = false;
    
    SDL_Window* m_pWindow = 0;
    SDL_Renderer* m_pRenderer = 0;
public:
    Game() {}
    ~Game() {}
    
    void init(const char* title, int xpos, int ypos, int
              height, int width, int flags);
    
    void render();
    void update(){}
    void handleEvents();
    void clean();
    
    bool isRunning() {return m_running;}
    
};

#endif /* defined(__SDLTest__game__) */
