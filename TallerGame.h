#ifndef TALLERGAME_H
#define TALLERGAME_H

#include "RosalilaEngine/RosalilaScreens/Game.h"
#include "PlayScreen.h"
#include "GameOvercSreen.h"

class TallerGame : public Game
{
    public:
        PlayScreen *PLAY;
        GameOvercSreen *G_OVER;

        TallerGame();
        virtual ~TallerGame();

        void create();
    protected:
    private:
};

#endif // TALLERGAME_H
