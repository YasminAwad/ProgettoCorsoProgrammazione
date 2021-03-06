//
// Created by Yasmin on 26/06/2018.
//

#include "Strategy.h"

void ChaseHero::movementBehavior(GameCharacter* player, Monster* monster) {
    if(monster->walkingTime.getElapsedTime().asSeconds() > 0.3) {
        float Ydiff = player->rect.getPosition().y - monster->rect.getPosition().y;
        float Xdiff = player->rect.getPosition().x - monster->rect.getPosition().x;

        if (abs(static_cast<int>(Ydiff)) < Xdiff && Xdiff > 0) {
            monster->setDirection(Direction ::right);
            if (!monster->canMoveRight) { //se non puoi muovere a dx (ostacolo), vai up, sennò down
                if (monster->canMoveUp)
                    monster->setDirection(Direction ::up);
                else if (monster->canMoveDown)
                    monster->setDirection(Direction ::down);
            }
        }
        if (abs(static_cast<int>(Xdiff)) < Ydiff && Ydiff > 0) {
            monster->setDirection(Direction ::down);
            if (!monster->canMoveDown) {
                if (monster->canMoveRight)
                    monster->setDirection(Direction ::right);
                else if (monster->canMoveLeft)
                    monster->setDirection(Direction ::left);
            }
        }
        if (abs(static_cast<int>(Ydiff)) < abs(static_cast<int>(Xdiff)) && Xdiff < 0) {
            monster->setDirection(Direction ::left);
            if (!monster->canMoveLeft) {
                if (monster->canMoveDown)
                    monster->setDirection(Direction ::down);
                else if (monster->canMoveUp)
                    monster->setDirection(Direction ::up);
            }
        }
        if (abs(static_cast<int>(Xdiff)) < abs(static_cast<int>(Ydiff)) && Ydiff < 0) {
            monster->setDirection(Direction ::up);
            if (!monster->canMoveUp) {
                if (monster->canMoveRight)
                    monster->setDirection(Direction ::right);
                else if (monster->canMoveLeft)
                    monster->setDirection(Direction ::left);
            }
        }
    }

    if(monster->walkingTime.getElapsedTime().asSeconds()>0.3)
        monster->walkingTime.restart();
}

void TurnAround::movementBehavior(GameCharacter* player, Monster* monster) {
    if (monster->walkingTime.getElapsedTime().asSeconds() >= 0.5) {
        //Changes facing direction
        monster->counter++;
        if(monster->counter>=monster->movementLenght) {
            monster->counter = 0;
            int myRandom = Random::generateRandom(5);
            switch(myRandom){
                case 1:
                    monster->setDirection(Direction ::up);
                    break;
                case 2:
                    monster->setDirection(Direction ::down);
                    break;
                case 3:
                    monster->setDirection(Direction ::left);
                    break;
                case 4:
                    monster->setDirection(Direction ::right);
                    break;
                case 5:
                    monster->setDirection(Direction::null);
                    break;

            }
            monster->walkingTime.restart();
        }
    }

    if(abs(static_cast<int>(player->rect.getPosition().x - monster->rect.getPosition().x)) < 100 &&
       abs(static_cast<int>(player->rect.getPosition().y - monster->rect.getPosition().y)) < 100) {
        monster->setAggroed(true);
        monster->setMovementSpeed(4);
    }
}

void Flee::movementBehavior(GameCharacter* player, Monster* monster) {
    monster->setAggroed(false);

    if(monster->walkingTime.getElapsedTime().asSeconds() < 0.5) {
        float Ydiff = player->rect.getPosition().y - monster->rect.getPosition().y;
        float Xdiff = player->rect.getPosition().x - monster->rect.getPosition().x;

        if (abs(static_cast<int>(Ydiff)) < Xdiff && Xdiff > 0) {
            monster->setDirection(Direction ::left);
            if (!monster->canMoveLeft) {
                if (monster->canMoveUp)
                    monster->setDirection(Direction ::up);
                else if (monster->canMoveDown)
                    monster->setDirection(Direction ::down);
            }
        }
        if (abs(static_cast<int>(Xdiff)) < Ydiff && Ydiff > 0) {
            monster->setDirection(Direction ::up);
            if (!monster->canMoveUp) {
                if (monster->canMoveRight)
                    monster->setDirection(Direction ::right);
                else if (monster->canMoveLeft)
                    monster->setDirection(Direction ::left);
            }
        }
        if (abs(static_cast<int>(Ydiff)) < abs(static_cast<int>(Xdiff)) && Xdiff < 0) {
            monster->setDirection(Direction ::right);
            if (!monster->canMoveRight) {
                if (monster->canMoveDown)
                    monster->setDirection(Direction ::down);
                else if (monster->canMoveUp)
                    monster->setDirection(Direction ::up);
            }
        }
        if (abs(static_cast<int>(Xdiff)) < abs(static_cast<int>(Ydiff)) && Ydiff < 0) {
            monster->setDirection(Direction ::down);
            if (!monster->canMoveDown) {
                if (monster->canMoveRight)
                    monster->setDirection(Direction ::right);
                else if (monster->canMoveLeft)
                    monster->setDirection(Direction ::left);
            }
        }
    }

    if(monster->walkingTime.getElapsedTime().asSeconds()>0.5)
        monster->walkingTime.restart();
}