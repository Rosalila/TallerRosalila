#include "Skeletor.h"

Skeletor::Skeletor(RosalilaGraphics *p,string image)
{
    image = "assets/"+image+"/";
    painter = p;
    state = "Idle";
    vector<Image*>* Idle = new vector<Image*>();
    scale=1;
    for(int i=1;i<=10;i++)
    {
        Idle->push_back(p->getTexture(image+"Idle2/Separate_sp/idle_"+toString(i)+".png"));
        cout<<"Paso"<<endl;
    }
    cout<<"Paso 2"<<endl;
    state_animations["Idle"] = Idle;
    cout<<"Paso 3"<<endl;
    skull = (*Idle)[0];
    cout<<"Paso 4"<<endl;
    x = 0;//p->screen skull->getWidth();
    y = p->screen_height - skull->getHeight();
    cout<<"Paso 5"<<endl;
}

Skeletor::~Skeletor()
{
    //dtor
}

void Skeletor::update(Receiver *r)
{

}

void Skeletor::draw()
{
    painter->draw2DImage(skull,skull->getWidth(),skull->getHeight(),x,y,scale,0,false,0,0,Color(255,255,255,255),0,0,false,FlatShadow());
}
