#include "Skeletor.h"

Skeletor::Skeletor(RosalilaGraphics *p,string image)
{
    image = "assets/"+image+"/";
    painter = p;
    state = IDLE;
    face=false;
    health = 10;
    delta=0;
    index=0;
    scale=0.5;

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

    //For JUMP
    vector<Image*>* Jump = new vector<Image*>();
    for(int i=1;i<=8;i++)
    {
        Jump->push_back(p->getTexture(image+"Jump 2/Separate sp/jump_"+toString(i)+".png"));
    }
    state_animations[JUMP] = Jump;

    //For ATTACK
    vector<Image*>* Attack = new vector<Image*>();
    for(int i=1;i<=8;i++)
    {
        Attack->push_back(p->getTexture(image+"Attack 1/Separate sp/attack_"+toString(i)+".png"));
    }
    state_animations[ATTACK] = Attack;

    skull = (*Idle)[0];
    x = skull->getWidth()*scale;
    y = p->screen_height*0.5 - skull->getHeight()*scale;

    hurt_box.x=x;
    hurt_box.y=y;
    hurt_box.w=skull->getWidth()*scale;
    hurt_box.h=skull->getHeight()*scale;

    feet_box.x=x;
    feet_box.w=skull->getWidth()*scale;
    feet_box.h=skull->getHeight()*scale*0.125;
    feet_box.y=y + hurt_box.h - feet_box.h;

    hit_box.x=x;
    hit_box.w=skull->getWidth()*scale;
    hit_box.h=skull->getHeight()*scale*0.4;
    hit_box.y=y + hit_box.h;

}

Skeletor::~Skeletor()
{
    //dtor
}

void Skeletor::update(Receiver *r)
{
    if(state!=JUMP && state!=ATTACK)
    {
        if(r->isKeyDown(SDL_SCANCODE_RIGHT))
        {
            state = WALK;
            face=false;
        }else if(r->isKeyDown(SDL_SCANCODE_LEFT))
        {
            state = WALK;
            face=true;
        }else{
            state = IDLE;
        }

        if(r->isKeyPressed(SDLK_z))
        {
            if(state!=ATTACK)
            {
                state = ATTACK;
                index=0;
                cout<<"ATTACK"<<endl;
            }
        }else if(r->isKeyPressed(SDL_SCANCODE_UP))
        {
            if(state!=JUMP)
            {
                state=JUMP;
                index=0;
            }
        }
    }else if(state==ATTACK)
    {
        if(index==state_animations[ATTACK]->size()-1)
        {
            state=IDLE;
        }
    }else{
        if(index==state_animations[JUMP]->size()-1)
        {
            state=IDLE;
        }
        else
        {
            if(index<=3)
                y-=15+9.8;
            else
                y+=15;
        }
    }

    hurt_box.x=x;
    hurt_box.y=y;

    feet_box.x=x;
    feet_box.y=y + hurt_box.h - feet_box.h;

    hit_box.x=x + (face?-0.25:0.25)*x;
    hit_box.y=y + hit_box.h*0.5;

    if(state==WALK)
    {
       if(delta%3==0)
        {
            if(index<state_animations[WALK]->size()-1)
                index++;
            else
                index=0;
        }
        if(index<state_animations[WALK]->size())
            skull = (*state_animations[WALK])[index];
        else
            index=0;
    }else if(state==JUMP)
    {
       if(delta%5==0)
        {
            if(index<state_animations[JUMP]->size()-1)
                index++;
            else
                index=0;
        }
        if(index<state_animations[JUMP]->size())
            skull = (*state_animations[JUMP])[index];
        else
            index=0;
    }else if(state==ATTACK)
    {
       if(delta%3==0)
        {
            if(index<state_animations[ATTACK]->size()-1)
                index++;
            else
                index=0;
        }
        if(index<state_animations[ATTACK]->size())
            skull = (*state_animations[ATTACK])[index];
        else
            index=0;
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

    //draw hurt_box
//    painter->drawRectangle(hurt_box.x,hurt_box.y,hurt_box.w,hurt_box.h,
//                            0,255,0,0,100,false);

    //draw feet_box
//    painter->drawRectangle(feet_box.x,feet_box.y,feet_box.w,feet_box.h,
//                            0,0,255,0,100,false);

//draw hit_box
//    painter->drawRectangle(hit_box.x,hit_box.y,hit_box.w,hit_box.h,
//                            0,0,0,255,100,false);
}

int Skeletor::getDeltha_X()
{
    int deltha;
    switch(state)
    {
        case WALK: deltha = 10; break;
        case JUMP: deltha = 10; break;
        case ATTACK: deltha = 1; break;
        default: deltha = 0; break;
    }

    if(!face) deltha*=-1;
    return deltha;
}
