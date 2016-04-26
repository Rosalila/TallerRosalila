#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H

#include "RosalilaEngine/RosalilaScreens/Screen.h"
#include "RosalilaEngine/RosalilaScreens/Game.h"
#include "Skeletor.h"

class PlayScreen : public Screen
{
    public:
        Game *game;
        PlayScreen(Game*);
        virtual ~PlayScreen();

        Skeletor *Kenshi;

        void show ();
        void render (RosalilaGraphics*);
        void pause ();
        void resume ();
        void hide ();
        void dispose ();
    protected:
    private:
};

#endif // PLAYSCREEN_H
