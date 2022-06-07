#pragma once
#include "PopObject.h"

class Mover :
    public PopObject
{
protected:
	float x_, y_; // ���������� ������ ���� 
	int color_; // ���� ����
	int size_; // ������ ���� (������)
	int frameWidth_, frameHeight_; // ������� �����, � ������� ����� ���������� ���
	float dX_, dY_; // skorostj
public:
	Mover(); // default constructor
	Mover(int frameWidth, int frameHeight, int x, int y);
	void interact(PopObject* popObject) override;
	bool interactable(PopObject* popObject) override;
	void setPos(int x, int y) override;
	int getSize() override;
	float getdX()override;
	float getdY()override;
	float getX() override;
	float getY() override;
	void setSpeed(float dX, float dY)override;
	void move()override;

	//void centerCoord(int x, int y) override;
	//bool hit(int x, int y) override;
	//	void followTo(int x, int y);// UBRATJ
	//	void setSize(int size); // UBRATJ 


};

