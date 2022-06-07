#pragma once

#include <SDL2/SDL.h>
#include <unordered_map>
#include <string>
#include <vector>


class Game
{
public:
    Game();
    bool Initialize();
    void RunLoop();
};