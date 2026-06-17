
#pragma once
#include"shape.h"

#include<SFML/Graphics.hpp>
using namespace sf;

class S :public shape
{

	int rotation = 0;



public:

	S();



	void updateCoordinates() override;



	void rotate(int arr[20][10]);




	void Draw(RenderWindow& window, float blockSize) override;



	int num();




};




