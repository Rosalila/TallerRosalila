#ifndef SKELETOR_H
#define SKELETOR_H

//SDL
#include "SDL2/SDL.h"
#include "RosalilaEngine/RosalilaUtility/RosalilaUtility.h"
#include "RosalilaEngine/RosalilaInputs/RosalilaInputs.h"
#include "RosalilaEngine/RosalilaGraphics/RosalilaGraphics.h"
#include "RosalilaEngine/RosalilaSound/RosalilaSound.h"
#include <vector>
#include <map>

enum State{
        IDLE,WALK,JUMP,ATTACK
};

class Skeletor
{
    public:
        RosalilaGraphics * painter;
        double x, y, scale;
        Image *skull;
        SDL_Rect hit_box, hurt_box,feet_box;
        State state;
        bool face;
        map< State, vector<Image*>* > state_animations;
        int health, delta, index;
        int getDeltha_X();

        Skeletor(RosalilaGraphics *p,string);
        virtual ~Skeletor();
        void update(Receiver *r);
        void draw();
    protected:
    private:
};

#endif // SKELETOR_H
