#include <GL/gl.h>
#include <stdio.h>

#include "RosalilaEngine/system.h"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string>
//#include <List>
#include <iostream>
using namespace std;

//SDL
#include "SDL2/SDL.h"
#include "RosalilaEngine/RosalilaUtility/RosalilaUtility.h"
#include "RosalilaEngine/RosalilaInputs/RosalilaInputs.h"
#include "RosalilaEngine/RosalilaGraphics/RosalilaGraphics.h"
#include "RosalilaEngine/RosalilaSound/RosalilaSound.h"

#ifdef LINUX
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#endif

#ifdef WINDOWS
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#endif

#ifdef OSX
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>
#endif

#include "TallerGame.h"

int main(int argc, char *argv[])
{
    clearLog();

    TallerGame *taller_game = new TallerGame();
    taller_game->create();

    while(true)
    {
        taller_game->render();

    }
    return 0;
}
