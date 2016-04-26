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

class Skeletor
{
    public:
        RosalilaGraphics * painter;
        double x, y, scale;
        Image *skull;
        SDL_Rect hurt_box;
        string state;
        map< string, vector<Image*>* > state_animations;

        Skeletor(RosalilaGraphics *p,string);
        virtual ~Skeletor();
        void update(Receiver *r);
        void draw();
    protected:
    private:
};

#endif // SKELETOR_H
