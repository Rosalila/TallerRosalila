#ifndef ENEMY_H
#define ENEMY_H
#include "RosalilaEngine/RosalilaGraphics/RosalilaGraphics.h"
#include "Skeletor.h"

class Enemy
{
    public:
        RosalilaGraphics * painter;                     //objeto painter para dibijar
        double x, y, scale;                             //posicion x, y y escala
        Image *skull;                                   //sprite actual a dibujarse
        State state;                                    //estado del personaje (IDLE, WALK, JUMP, ATACK...)
        bool face;                                      //derecha o izquierda (izquierda por default)
        SDL_Rect hit_box;                               //caja de colision
        map< State, vector<Image*>* > state_animations; //mapa para guardar nuestros vectores de animaciones (Image apuntador)
        int health, delta, index;

        Enemy(RosalilaGraphics *p,string);
        virtual ~Enemy();

        void update(Receiver *r);
        void draw();
    protected:
    private:
};

#endif // ENEMY_H
