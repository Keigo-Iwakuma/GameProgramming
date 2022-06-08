#include "Game.hpp"
#include <SDL2/SDL_image.h>
#include <algorithm>
#include "Actor.hpp"
// #include "SpriteComponent.hpp"
// #include "Ship.hpp"
// #include "BGSpriteComponent.hpp"


Game::Game()
:mWindow(nullptr)
,mRenderer(nullptr)
,mIsRunning(true)
,mUpdatingActors(false)
{

}