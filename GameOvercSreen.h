#ifndef GAMEOVERCSREEN_H
#define GAMEOVERCSREEN_H

#include "RosalilaEngine/RosalilaScreens/Game.h"
#include "RosalilaEngine/RosalilaScreens/Screen.h"

class GameOvercSreen : public Screen
{
    public:
        Game *game;
        SDL_Rect *rec;
        GameOvercSreen(Game *game);
        virtual ~GameOvercSreen();

        void show ();
        void render (RosalilaGraphics*);
        void pause ();
        void resume ();
        void hide ();
        void dispose ();

    protected:
    private:
};

#endif // GAMEOVERCSREEN_H
