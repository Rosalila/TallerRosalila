#include "GameOvercSreen.h"
#include "TallerGame.h"

GameOvercSreen::GameOvercSreen(Game *game)
{
    this->game = game;
}

GameOvercSreen::~GameOvercSreen()
{
    //dtor
}

void GameOvercSreen::show ()
{
    rec = new SDL_Rect();
    rec->x = 0;
    rec->y = 0;
    rec->w = 500;
    rec->h = 500;
}

void GameOvercSreen::render (RosalilaGraphics*p)
{
    p->drawRectangle(rec->x,rec->y,rec->w,rec->h,0,255,0,0,255,false);

    if(game->receiver->isKeyPressed(SDLK_a))
    {
        game->setScreen(((TallerGame*)game)->PLAY);
    }
}

void GameOvercSreen::pause ()
{

}

void GameOvercSreen::resume ()
{

}

void GameOvercSreen::hide ()
{

}

void GameOvercSreen::dispose ()
{

}
