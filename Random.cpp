//
// Created by Yasmin on 14/05/2018.
//

#include "Random.h"

int Random::generateRandom(int max) {
    int randomNumber=rand();
    float random=(randomNumber%max)+1;
    int myRandom=random;

    return myRandom;
}

int Random::generateRandom0(int max) {
    int randomNumber=rand();
    float random=(randomNumber%max);
    int myRandom=random;

    return myRandom;
}
