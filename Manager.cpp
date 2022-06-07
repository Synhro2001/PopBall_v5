#include "Manager.h"
#include "math.h"
#include <iostream>


Manager* manager; // ������ ������������ ������ 

using namespace System::Drawing;

Manager::Manager(int frameWidth, int frameHeight) {
	frameHeight_ = frameHeight;
	frameWidth_ = frameWidth;
	for(int i = 0; i < MAX_OBJECTS; i++) 
    popObjects_[i] = nullptr;
	
	

}

Manager::~Manager() {


	for (int i = 0; i < MAX_OBJECTS; i++) delete popObjects_[i];
}


void Manager::add(PopObject* popObject) {
	for (int i = 0; i < MAX_OBJECTS; i++) if (!popObjects_[i]) {
		popObjects_[i] = popObject;
		break;
	}
}



void Manager::drawFrame(Graphics^ graphics) {
	
	//������ ��� - ������ ������������� � ��������� �����,
	Pen framePen(Color::Black, 3);
	graphics->FillRectangle(% SolidBrush(Color::White), 0, 0, frameWidth_, frameHeight_);
	graphics->DrawRectangle(% framePen, 0, 0, frameWidth_, frameHeight_);
	for (int i = 0; i < MAX_OBJECTS; i++) if (popObjects_[i]) {
		popObjects_[i]->draw(graphics);
	}

}

PopObject* Manager::search(int x, int y) {
	int i;
	
	for (i = 0; i < MAX_OBJECTS; i++) {
		if (!popObjects_[i])continue;



		float Xcentr = popObjects_[i]->getX();
		float Ycentr = popObjects_[i]->getY();

		float dist = sqrt(pow(x - Xcentr, 2) + pow(y - Ycentr, 2));

		if (dist < popObjects_[i]->getSize() + popObjects_[i]->getSize()) {
			return popObjects_[i];
		}
		
	}
	return nullptr;
	
}




bool Manager::objCollision(PopObject* firstBall, PopObject* secondBall) {
	
	
	/* ������� ��������� ����� ��������� ��� ������� �������� 
	���������� get ��� �� �������� ���������� ������� ������� � ������� 
	pow - ��� ���������� � ������� ����� ���������� math.h
	� ����� ���������� �������� bool ����� �������� �������� �������� 
	��� ����� ������ � ������������
	
	*/
	if (firstBall && secondBall) {
		float firstX = firstBall->getX();
		float firstY = firstBall->getY();
		float secondX = secondBall->getX();
		float secondY = secondBall->getY();


		float dist = sqrt(pow(secondX - firstX, 2) + pow(secondY - firstY, 2));

		return (dist < firstBall->getSize() + secondBall->getSize());
	}
	return false;
	
}

void Manager::move() { 
	/*
	
	��� ������������� ������� ����� ����������������� ���� � ������ ����� ������� ������� �������������� interactable
	���-�� ������� �� ���������� ���� ���� ���� ��������� ��� ��� ������� ����������
	*/
	for ( int i = 0; i < MAX_OBJECTS; i++) {
		if(!popObjects_[i])continue; // ������������� ������� �������� � ��������� � ������ 
		for ( int j = 0; j < MAX_OBJECTS; j++){
			if(!popObjects_[j] || popObjects_[i] == popObjects_[j])continue;

			bool coolision = objCollision(popObjects_[i], popObjects_[j]);
			if (coolision) {
				if (popObjects_[i]->interactable(popObjects_[j]) && popObjects_[j]->interactable(popObjects_[i]))
			popObjects_[i]->interact(popObjects_[j]);
			if(popObjects_[j]) popObjects_[j]->move();
			if(popObjects_[i]) popObjects_[i]->move();
			}
		}
		if(popObjects_[i])popObjects_[i]->move();
	}
	
	//���������� ������  � ������� ������������ �� ������ !
	// ������� ������ ��� ������� �����
}


bool Manager::remove(PopObject* popObject) {

	for (int i = 0; i < MAX_OBJECTS; i++) if (popObjects_[i] == popObject) {
		popObjects_[i] = nullptr;
		delete popObject;
	
		break;
	}
	return nullptr;
}


void Manager::decreaseSpeed(PopObject* popObject) { 

	for (int i = 0; i < MAX_OBJECTS; i++) {
		if (!popObjects_[i])continue;

		float dx = popObjects_[i]->getdX();
		float dy = popObjects_[i]->getdY();

		if (dx < 15) {
			dx = dx * 2;
		} 
		if (dy < 15) {
			dy = dy * 2;
		}
		popObjects_[i]->setSpeed(dx, dy);
	}
	

}


void Manager::increaseSpeed(PopObject* popObject) {

	for (int i = 0; i < MAX_OBJECTS; i++) {
		if (!popObjects_[i])continue;

		float dx = popObjects_[i]->getdX();
		float dy = popObjects_[i]->getdY();
		if (abs(dx) > 1) { // ����� ����� � ������ ����� ��� ��������� �������� ������ ��� �������� �� ������ ����������� !!!
			dx = dx * 0.5; // �������� �� ��������� < 1
		}
		if (abs(dy) > 1) {
			dy = dy * 0.5;
		}
		popObjects_[i]->setSpeed(dx, dy);
	}


}

int Manager::countOf(const type_info* type) {
	int count = 0;
	for (int i = 0; i < MAX_OBJECTS; i++) 
		if (popObjects_[i] && typeid(*popObjects_[i]) == *type) {
			count++;
		}
	
	return count;
}

void Manager::place(PopObject* popObject) {

	int x_Coord = popObject->getX();
	int y_Coord = popObject->getY();
	popObject->setPos(x_Coord, y_Coord);
	
	int k = 0; // ������ 100 ������� ��� ���������� ������� �������� �� ������������
	bool isFound = false;
	
	for (k = 0; k < 100; k++) {
		for (int i = 0; i < MAX_OBJECTS; i++) {
			if (objCollision(popObjects_[i], popObject)) {
				x_Coord = popObject->getX();
				y_Coord = popObject->getY();
				isFound = true;
				popObject->setPos(x_Coord, y_Coord);
				k++;
				break;
			}

		}
		if (isFound == true) {
			return add(popObject);
		}

	}
	delete(popObject);

}

