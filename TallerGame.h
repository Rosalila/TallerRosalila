#ifndef TALLERGAME_H
#define TALLERGAME_H

#include "RosalilaEngine/RosalilaScreens/Game.h"
#include "PlayScreen.h"

class TallerGame : public Game
{
    public:
        PlayScreen *PLAY;

        TallerGame();
        virtual ~TallerGame();

        void create();
    protected:
    private:
};

#endif // TALLERGAME_H
