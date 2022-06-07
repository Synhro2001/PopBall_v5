#include <iostream>;
#include <math.h>;
#include "Ball.h";

Ball::Ball(int frameWidth, int frameHeight, int x, int y) : Mover(frameWidth, frameHeight, x, y)
{



}


void Ball::draw(Graphics^ graphics) {

    Pen ballPen(Color::Black, 1);
    SolidBrush brush(Color::FromArgb(color_));
    graphics->FillEllipse(% brush, x_ - size_, y_ - size_, size_ * 2.0, size_ * 2.0);
    graphics->DrawEllipse(% ballPen, x_ - size_, y_ - size_, size_ * 2.0, size_ * 2.0);


}


/*
void Ball::interactReaction() {
    float speed = sqrt((dX_ * dX_) + (dY_ * dY_));
    if (speed == 0) {
        dX_ = (rand() % 10) - 10;
        dY_ = (rand() % 10) - 10;
    }

}
*/

void Ball::interact(PopObject* popObject) {

	Mover::interact(popObject);
    int count = manager->countOf(&typeid(Ball));
    int k = rand() % 3;
    if (typeid(*popObject) == typeid(Ball)) { 
        if (k == 0 && count < 5) {
            manager->place(new Ball(frameWidth_, frameHeight_, x_, y_));
        }

    
    }
    else {
        if (k == 0) {
            manager->add(new Explosion(frameWidth_, frameHeight_, x_, y_));
            manager->remove(this);
        }
    }



		
}





