#include "TallerGame.h"

TallerGame::TallerGame()
{
    PLAY = new PlayScreen(this);
}

TallerGame::~TallerGame()
{
    delete PLAY;
}

void TallerGame::create()
{
    setScreen(PLAY);
}
