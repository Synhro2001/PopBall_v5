#pragma once
#include "Rotator.h"
class Rectan :
    public Rotator
{
public:
    Rectan(int frameWidth, int frameHeight, int x, int y);
    Rectan(int frameWidth, int frameHeight, int x, int y, int size);
    void draw(Graphics^ graphics);
    void interact(PopObject* popObject);

   // void interactReaction() override;

};

