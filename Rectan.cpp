#define _USE_MATH_DEFINES


#include "Rectan.h"
#include <iostream>;
#include <cmath>
#include "Explosion.h"
#include "Manager.h"


using namespace System::Drawing;

Rectan::Rectan(int frameWidth, int frameHeight, int x, int y)
	: Rotator(frameWidth, frameHeight, x, y) { 
	size_ = 25;
};

Rectan::Rectan(int frameWidth, int frameHeight, int x, int y, int size)
	: Rotator(frameWidth, frameHeight, x, y) {
	size_ = size;
};

void Rectan::draw(Graphics^ graphics) {
	SolidBrush brush(Color::FromArgb(color_)); // izveidot otu

	array<Point>^ points = gcnew array<Point>(4);
	for (int i = 0; i < 4; i++) {

		points[i] = Point(
		    x_ + size_ * cos(alpha_ + 2 * M_PI / 4 * i),
			y_ + size_ * sin(alpha_ + 2 * M_PI / 4 * i)
			

		);
	}

	graphics->FillPolygon(% brush, points);



}

void Rectan::interact(PopObject* popObject) {

	Mover::interact(popObject);
	int count = manager->countOf(&typeid(Rectan));
	int k = rand() % 3;
	if (typeid(*popObject) == typeid(Rectan)) {
		if (k == 0 && count < 5) {
			manager->place(new Rectan(frameWidth_, frameHeight_, x_, y_));
		}


	}
	else {
		if (k == 0) {
			manager->add(new Explosion(frameWidth_, frameHeight_, x_, y_));
			manager->remove(this);
		}
	}




}


/*
void Rectan::interactReaction() {
	size_ = rand() % 20 + 10;
}
*/


