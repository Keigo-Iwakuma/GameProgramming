#include "Actor.hpp"
#include "Game.hpp"
#include "Component.hpp"
#include <algorithm>


Actor::Actor(Game* game)
    :mState(EActive)
    ,mPosition(Vector2::Zero)
{
    mGame->AddActor(this);
}