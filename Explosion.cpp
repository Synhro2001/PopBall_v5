#include "Explosion.h"
#include "Rectan.h"
#include <corecrt_math_defines.h>

Explosion::Explosion(int frameWidth, int frameHeight, int x, int y) :
	Mover(frameWidth, frameHeight, x, y) {
	//eDirection_ = (2 * M_PI * rand()) / RAND_MAX;
	//eSpeed_ = (0.0001 * rand()) / RAND_MAX;
	eColor_ = Color::FromArgb(rand() % 256, rand() % 256, rand() % 256).ToArgb();
	eCount_ = 20;
	eSize_ = 5;
	x_ = x;
	y_ = y;
	for (int i = 0; i < eCount_; i++) {
		eObj[i] = new Rectan(frameWidth_, frameHeight_, x_, y_, eSize_);
	}

}

void Explosion::move(){
	if (currentStep_ == eCount_) {

		manager->remove(this);
		return;
	}

	for (int i = 0; i < eCount_; i++) {
		if (eObj) {
			eObj[i]->move();
			
		}

	}
	currentStep_++;
	
}


bool Explosion::interactable(PopObject* popObject) {
	return false;
}




void Explosion::draw(Graphics^ grp) {

	for (int i = 0; i < eCount_; i++) {
		eObj[i]->draw(grp);
	}
}

