#pragma once
#pragma once
#pragma once
#include"shape.h"

#include<SFML/Graphics.hpp>
using namespace sf;

class T :public shape
{
	const int s = 4;
	int rotation = 0;



public:


	T();




	void updateCoordinates() override;



	void rotate(int arr[20][10]);


	void Draw(RenderWindow& window, float blocks) override;



	int num();

};




