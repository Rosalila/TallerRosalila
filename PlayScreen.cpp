#include "PlayScreen.h"

PlayScreen::PlayScreen(Game* game)
{
    this->game = game;
}

PlayScreen::~PlayScreen()
{
    //dtor
}

void PlayScreen::show ()
{
    Kenshi = new Skeletor(game->rosalila_graphics,"HeroSkeleton");
}

void PlayScreen::render (RosalilaGraphics*p)
{
    Kenshi->update(game->receiver);
    Kenshi->draw();
}

void PlayScreen::pause ()
{

}

void PlayScreen::resume ()
{

}

void PlayScreen::hide ()
{

}

void PlayScreen::dispose ()
{

}
