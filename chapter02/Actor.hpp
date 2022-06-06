#pragma once
#include <vector>
// #include "Math.h"


class Actor
{
public:
    enum State
    {
        EActive,
        EPaused,
        EDead
    };

    Actor(class Game* game);
    virtual ~Actor();

};