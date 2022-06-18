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


void Actor::Update(float deltaTime)
{
    if (mState == EActive)
    {
        UpdateComponents(deltaTime);
        UpdateActor(deltaTime);
    }
}


void Actor::UpdateActor(float deltaTime)
{
}


void Actor::AddComponent(Component* component)
{
    // Find the insertion point in the sorted vector
    // (The first element with a order higher than me)
    int mOrder = component->GetUpdateOrder();
    auto iter = mComponents.begin();
    for (;
        iter != mComponents.end();
        ++iter)
    {
        if (mOrder < (*iter)->GetUpdateOrder())
        {
            break;
        }
    }
}