#include "Skeletor.h"

Skeletor::Skeletor(RosalilaGraphics *p,string image)
{
    image = "assets/"+image+"/";
    painter = p;
    state = IDLE;
    face=false;
    delta=0;
    index=0;
    scale=1;

    //For IDLE
    vector<Image*>* Idle = new vector<Image*>();
    for(int i=1;i<=10;i++)
    {
        Idle->push_back(p->getTexture(image+"Idle 2/Separate sp/idle_"+toString(i)+".png"));
    }
    state_animations[IDLE] = Idle;

    //For WALK
    vector<Image*>* Walk = new vector<Image*>();
    for(int i=1;i<=8;i++)
    {
        Walk->push_back(p->getTexture(image+"Run/Separate sp/run_"+toString(i)+".png"));
    }
    state_animations[WALK] = Walk;

    skull = (*Idle)[0];
    x = 0;
    y = p->screen_height - skull->getHeight();
}

Skeletor::~Skeletor()
{
    //dtor
}

void Skeletor::update(Receiver *r)
{
    if(r->isKeyDown(SDL_SCANCODE_RIGHT))
    {
        state = WALK;
        face=false;
        x+=10;
    }else if(r->isKeyDown(SDL_SCANCODE_LEFT))
    {
        state = WALK;
        face=true;
        x-=10;
    }else{
        state = IDLE;
    }

    if(state==WALK)
    {
       if(delta%2==0)
        {
            if(index<state_animations[WALK]->size()-1)
                index++;
            else
                index=0;
        }
        skull = (*state_animations[WALK])[index];
    }else{
        if(delta%10==0)
        {
            if(index<state_animations[IDLE]->size()-1)
                index++;
            else
                index=0;
        }
        if(index<state_animations[IDLE]->size())
            skull = (*state_animations[IDLE])[index];
        else
            index=0;
    }

    delta++;
}

void Skeletor::draw()
{
    painter->draw2DImage(skull,skull->getWidth(),skull->getHeight(),x,y,scale,0,face,0,0,Color(255,255,255,255),0,0,false,FlatShadow());
}
