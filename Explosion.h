#pragma once
#include "Mover.h"
#include <math.h>;
#include <iostream>;
#include "Manager.h"

#define _USE_MATH_DEFINES

class Explosion :
    public Mover
{
private:
    int eSize_;
   
    //double eDirection_;
    //double eSpeed_;
    int eColor_;
    int eCount_;
    int currentStep_ = 0;
   
   

public:

    PopObject* eObj[100];
    Explosion(int frameWidth, int frameHeight, int x, int y);
    void move() ;
    void draw(Graphics^grp) ;
    bool interactable(PopObject* popObject) ;


};

