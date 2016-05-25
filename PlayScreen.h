#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H

#include "RosalilaEngine/RosalilaScreens/Screen.h"
#include "RosalilaEngine/RosalilaScreens/Game.h"
#include "Skeletor.h"
#include "Enemy.h"

class PlayScreen : public Screen
{
    public:
        Game *game;
        PlayScreen(Game*);
        virtual ~PlayScreen();

        Skeletor *Kenshi;
        Enemy *Malon;

        Image*platform;
        vector<SDL_Rect*> platforms;
        bool applayGravity;
        float gravity;

        void show ();
        void render (RosalilaGraphics*);
        void pause ();
        void resume ();
        void hide ();
        void dispose ();

        void drawPlatform(RosalilaGraphics*p);
        void applyGravity(RosalilaGraphics*p);
    protected:
    private:
};

#endif // PLAYSCREEN_H
