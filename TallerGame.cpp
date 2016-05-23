#include "TallerGame.h"

TallerGame::TallerGame()
{
    PLAY = new PlayScreen(this);
    G_OVER = new GameOvercSreen(this);
}

TallerGame::~TallerGame()
{
    delete PLAY;
    delete G_OVER;
}

void TallerGame::create()
{
    setScreen(PLAY);
}
