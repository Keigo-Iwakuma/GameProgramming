#include "Actor.hpp"
#include "Game.hpp"
#include "Component.hpp"
#include <algorithm>


Actor::Actor(Game* game)
    :mState(EActive)
    ,mPosition(Vector2::Zero)
    ,mScale(1.0f)
    ,mRotation(0.0f)
    ,mGame(game)
{
    mGame->AddActor(this);
}


Actor::~Actor()
{
    mGame->RemoveActor(this);
    // Need to delete components
    // Because ~Component calls RemoveComponent, need a different style loop
    while (!mComponents.empty())
    {
        delete mComponents.back();
    }
}