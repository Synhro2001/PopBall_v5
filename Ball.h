#pragma once
#include "PopObject.h";
#include "Explosion.h";
#define MAX_COUNT = 5;



class Ball : public Mover
{
	
	public:
		void interact(PopObject* popObject) ;
		void draw(Graphics^ graphics) ;
		Ball(int frameWidth, int frameHeight, int x, int y);
		//void interactReaction() override;
};


// Исправил ошибку связаную с циклическим включением С2504 'PopObject': base class undefined
