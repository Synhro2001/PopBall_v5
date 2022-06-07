#define _USE_MATH_DEFINES

#include "Triangle.h";
#include <iostream>;
#include <cmath>
#include "Manager.h"
#include "Explosion.h"


using namespace System::Drawing;


Triangle::Triangle(int frameWidth, int frameHeight, int x, int y)
	: Rotator(frameWidth, frameHeight, x, y) {
	size_ = 20;
};

void  Triangle::draw(Graphics^ graphics) {

	SolidBrush brush(Color::FromArgb(color_)); // izveidot otu
	array<Point>^ points = gcnew array<Point>(3); // izveidot CLI masīvu ar 3 elementiem Point tipa
	for (int i = 0; i < 3; i++) { // aprēķināt virsotnes koordinātas
		points[i] = Point( // un ierakstīt tas uz masīva
			x_ + size_ * cos(alpha_ + 2 * M_PI / 3 * i),
			y_ + size_ * sin(alpha_ + 2 * M_PI / 3 * i)
		);
	}
	graphics->FillPolygon(% brush, points); // uzzīmēt aizpildīto figūru
}


void Triangle::interact(PopObject* popObject) {

	Mover::interact(popObject);
	int count = manager->countOf(&typeid(Triangle));
	int k = rand() % 3;
	if (typeid(*popObject) == typeid(Triangle)) {
		if (k == 0 && count < 5) {
			manager->place(new Triangle(frameWidth_, frameHeight_, x_, y_));
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
void Triangle::interactReaction() {

	color_ = Color::FromArgb(rand() % 256, rand() % 256, rand() % 256).ToArgb(); //   Transparent red color.

}
*/


