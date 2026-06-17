#pragma once
#pragma once
#include"shape.h"

#include<SFML/Graphics.hpp>
using namespace sf;

class O :public shape
{

	const int s = 4;
	int rotation = 0;



public:

	O();

	


	void updateCoordinates() override;





	void Draw(RenderWindow& window, float blocks) override;


	int num();


	virtual void rotate(int arr[20][10]) {}
};




