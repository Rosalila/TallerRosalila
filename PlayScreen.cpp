#include "PlayScreen.h"
#include "TallerGame.h"

PlayScreen::PlayScreen(Game* game)
{
    this->game = game;
    applayGravity = true;
    gravity = 9.8;
}

PlayScreen::~PlayScreen()
{
    //dtor
}

void PlayScreen::drawPlatform(RosalilaGraphics*p)
{
    for(int i=0;i<platforms.size();i++)
    {
        p->draw2DImage(platform,platforms[i]->w,platforms[i]->h,platforms[i]->x,platforms[i]->y,1,0,true,0,0,Color(255,255,255,255),0,0,false,FlatShadow());
    }

    //Hit_Box platform
//    for(int i=0;i<platforms.size();i++)
//    {
//        p->drawRectangle(platforms[i]->x,platforms[i]->y,platforms[i]->w,platforms[i]->h,
//                            0,255,0,0,100,false);
//    }
}

void PlayScreen::applyGravity(RosalilaGraphics*p)
{
    applayGravity=true;
    double yTemp = Kenshi->y;

    for(int i=0; i<platforms.size();i++)
    {
        platforms[i]->x+=Kenshi->getDeltha_X();
    }

    for(int i=0; i<platforms.size();i++)
    {
        if(hitboxCollision(Kenshi->feet_box,0,*platforms[i],0))
        {
            if(applayGravity && Kenshi->feet_box.y + Kenshi->feet_box.h*0.5> platforms[i]->y && Kenshi->feet_box.y + Kenshi->feet_box.h*0.5 < platforms[i]->y + platforms[i]->h*0.5)
            {
                Kenshi->state = IDLE;
                Kenshi->y = platforms[i]->y - Kenshi->skull->getHeight()*Kenshi->scale;
            }
            applayGravity=false;
            yTemp = platforms[i]->y - Kenshi->skull->getHeight()*Kenshi->scale;
        }

    }

    if(applayGravity)
    {
        Kenshi->y+=gravity;
    }else{
//        Kenshi->y=yTemp;
    }

    if(Kenshi->feet_box.y > p->screen_height)
    {
        game->setScreen(((TallerGame*)game)->G_OVER);
    }

    if(game->receiver->isKeyPressed(SDLK_a))
    {
        game->setScreen(((TallerGame*)game)->G_OVER);
    }
}

void PlayScreen::show ()
{
    Kenshi = new Skeletor(game->rosalila_graphics,"HeroSkeleton");

    platform = game->rosalila_graphics->getTexture("assets/platform.png");
    for(int i = 0; i<10; i++)
    {
        SDL_Rect *r = new SDL_Rect();
        r->x = i*platform->getWidth()*Kenshi->scale;
        r->y = game->rosalila_graphics->screen_height - platform->getHeight()*Kenshi->scale;
        r->w = platform->getWidth()*Kenshi->scale;
        r->h = platform->getHeight()*Kenshi->scale;
        platforms.push_back(r);
    }
    SDL_Rect *r2 = new SDL_Rect();
    r2->x = platforms.size()*platform->getWidth()*Kenshi->scale+50;
    r2->y = game->rosalila_graphics->screen_height - platform->getHeight()*Kenshi->scale - 150;
    r2->w = platform->getWidth()*Kenshi->scale;
    r2->h = platform->getHeight()*Kenshi->scale;
    platforms.push_back(r2);

    for(int i = 0; i<10; i++)
    {
        SDL_Rect *r = new SDL_Rect();
        r->x = r2->x + i*platform->getWidth()*Kenshi->scale;
        r->y = r2->y;
        r->w = platform->getWidth()*Kenshi->scale;
        r->h = platform->getHeight()*Kenshi->scale;
        platforms.push_back(r);
    }
}

void PlayScreen::render (RosalilaGraphics*p)
{
    drawPlatform(p);
    Kenshi->update(game->receiver);
    Kenshi->draw();
    applyGravity(p);
}

void PlayScreen::pause ()
{

}

void PlayScreen::resume ()
{

}

void PlayScreen::hide ()
{

}

void PlayScreen::dispose ()
{

}
