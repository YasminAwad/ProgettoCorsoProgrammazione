//
// Created by Yasmin on 13/05/2018.
//

#ifndef GAME_PROVA3_PROJECTILE_H
#define GAME_PROVA3_PROJECTILE_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Enumeration.h"

class Projectile: public Entity {
public:
    int movementSpeed=10;
    bool destroy=false;
    int counterLifetime=0;
    int lifeTime=50;
    int counterAnimation;

    Projectile();
    virtual ~Projectile(){}

    void update();
    int loadTexture();
    int getAttackDamage();
    void setAttackDamage(int attackDamage);
    Direction getDirection();
    void setDirection(Direction direction);

private:
    int attackDamage=30;
    Direction direction;
};


#endif //GAME_PROVA3_PROJECTILE_H
