#include "Game.hpp"


const int tickness = 15;
const float paddleH = 100.0f;


Game::Game()
:mWindow(nullptr)
,mRenderer(nullptr)
,mIsRunning(true)
{

}


bool Game::Initialize()
{
    // Initialize SDL
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);
    if (sdlResult != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }

    // Create an SDL window
    mWindow = SDL_CreateWindow(
        "Game Programming in C++ (Chapter 01).", // Window title
        100,   // Top left x-coordinate of window
        100,   // Top left y-coordinate of window
        1024,  // Width of window
        768,   // Height of window
        0      // Flags (0 for no flags set)
    );

    if (!mWindow)
    {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    }


    // Create SDL renderer
    mRenderer = SDL_CreateRenderer(
        mWindow,   // Window to create renderer for
        -1,   // Usually -1
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (!mRenderer)
    {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        return false;
    }

    mPaddlePos.x = 10.0f;
    mPaddlePos.y = 768.0f/2.0f;
    mBallPos.x = 1024.0f/2.0f;
    mBallPos.y = 768.0f/2.0f;

    return true;
}


void Game::Shutdown()
{
    SDL_DestroyWindow(mWindow);
    SDL_DestroyRenderer(mRenderer);
    SDL_Quit();
}


void Game::RunLoop()
{
    while (mIsRunning)
    {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}


void Game::ProcessInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            // If we get an SDL_QUIT event, end loop
            case SDL_QUIT:
                mIsRunning = false;
                break;
        }
    }

    // Get state of keyboard
    const Uint8* state = SDL_GetKeyboardState(NULL);
    // If escape is pressed, also end loop
    if (state[SDL_SCANCODE_ESCAPE])
    {
        mIsRunning = false;
    }

}


void Game::UpdateGame()
{

}


void Game::GenerateOutput()
{
    // Set draw color to blue
    SDL_SetRenderDrawColor(
        mRenderer,
        0,   // R
        0,   // G
        255, // B
        255  // A
    );

    // Clear back buffer
    SDL_RenderClear(mRenderer);

    // Draw walls
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);

    // Draw top wall
    SDL_Rect wall{
        0,          // Top left x
        0,          // Top left y
        1024,       // Width
        tickness    // Height
    };
    SDL_RenderFillRect(mRenderer, &wall);

    // Draw bottom wall
    wall.y = 768 - tickness;
    SDL_RenderFillRect(mRenderer, &wall);

    // Draw right wall
    wall.x = 1024 - tickness;
    wall.y = 0;
    wall.w = tickness;
    wall.h = 768;
    SDL_RenderFillRect(mRenderer, &wall);

    // Draw paddle
    SDL_Rect paddle{
        static_cast<int>(mPaddlePos.x),
        static_cast<int>(mPaddlePos.y - paddleH/2),
        tickness,
        static_cast<int>(paddleH)
    };
    SDL_RenderFillRect(mRenderer, &paddle);

    // Draw ball
    SDL_Rect ball{
        static_cast<int>(mBallPos.x - tickness/2),
        static_cast<int>(mBallPos.y - tickness/2),
        tickness,
        tickness
    };
    SDL_RenderFillRect(mRenderer, &ball);

    // Swap front buffer and back buffer
    SDL_RenderPresent(mRenderer);

}