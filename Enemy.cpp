#include "Enemy.h"

Enemy::Enemy(RosalilaGraphics *p,string image)
{
    image = "assets/"+image+"/";
    painter = p;    //objeto paradibujar
    state = IDLE;   //estado del enemigo
    face = false;   //izquierda por defecto
    health = 10;    //vida
    delta = 0;
    index = 0;      //index para ver la posicion actual en nuestros vectores
    scale = 0.5;    //escala del personaje

    //IDLE
    vector<Image*> *idle = new vector<Image*>(); //vector de Image apuntador para guardar los sprites para la animacion de Idle
    for(int i=0; i<10;i++)
    {
        //llenamos el vector con cada sprite
        idle->push_back(p->getTexture(image + "Idle/Separate sp/idle (" + toString(i+1) + ").png"));
    }
    state_animations[IDLE] = idle; //guardamos nuestro vector en nuestro mapa

    skull = (*idle)[0]; //inicializamos la primera animacion del personaje

    //seteamos posiciones y dimenciones escaladas
    x = 100;
    y = painter->screen_height - skull->getHeight()*scale;

    hit_box.x = x;
    hit_box.y = y;
    hit_box.w = skull->getWidth()*scale;
    hit_box.h = skull->getHeight()*scale;
}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::update(Receiver *r)
{
    if(state==IDLE) // si el estado del enemigo es Idle
    {
        if(delta%5==0) // cada 5 delta vamos a cambiar de imagen (sprite)
        {
            // si index es menor que la ultima posicion de nuestro vector de animaciones
            if(index<state_animations[IDLE]->size()-1)
                index++; //podemos movernos a la siguiente
            else
                index=0; //de lo contrario, reseteamos nuestro index
        }
        //si nuestro index aun esta en el rango de nuestro vector, cambiamos el sprite actial por el que este en index
        if(index<state_animations[IDLE]->size())
            //skull = (*state_animations/*<-mapa*/[IDLE])/*<-vector de (Image apuntador)*/[index];//<- vector en la posicion index
            skull = (*state_animations[IDLE])[index];
        else
            index=0; // si ya no esta en el rango, lo reseteamos
    }

    delta++; //contador de delta
}

void Enemy::draw()
{
    //metodo para dibujar objetos Image
    painter->draw2DImage(skull,skull->getWidth(),skull->getHeight()
            ,hit_box.x,hit_box.y
            ,scale,0,face,0,0,Color(255,255,255,255),0,0,false,FlatShadow());

    //hit_box
//    painter->drawRectangle(hit_box.x,hit_box.y,hit_box.w,hit_box.h
//            ,0,255,0,0,100,false);
}
