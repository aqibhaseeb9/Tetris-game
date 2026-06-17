#include"Z.h"


 Z::Z()
{
	Xcoordinates[0] = { 4 }, Xcoordinates[1] = { 5 }, Xcoordinates[2] = { 5 }, Xcoordinates[3] = { 6 },
		Ycoordinates[0] = { 0 }, Ycoordinates[1] = { 0 }, Ycoordinates[2] = { 1 }, Ycoordinates[3] = { 1 };
}




void  Z::updateCoordinates()
{


	if (rotation == 0)
	{
		Xcoordinates[0] = x;
		Ycoordinates[0] = y;

		Xcoordinates[1] = x + 1;
		Ycoordinates[1] = y;

		Xcoordinates[2] = x + 1;
		Ycoordinates[2] = y + 1;

		Xcoordinates[3] = x + 2;
		Ycoordinates[3] = y + 1;



	}
	else  if (rotation == 1)
	{
		Xcoordinates[0] = x;
		Ycoordinates[0] = y + 1;

		Xcoordinates[1] = x;
		Ycoordinates[1] = y + 2;

		Xcoordinates[2] = x + 1;
		Ycoordinates[2] = y;

		Xcoordinates[3] = x + 1;
		Ycoordinates[3] = y + 1;

	}



}



void  Z::rotate(int arr[20][10])
{
	int tempX[4], tempY[4];
	int rot = 1 - rotation;

	if (x + 2 >= 10)
	{
		x = 7; // Handling overflow
	}

	if (rot == 0)
	{
		tempX[0] = x;
		tempY[0] = y;

		tempX[1] = x + 1;
		tempY[1] = y + 1;

		tempX[2] = x + 1;
		tempY[2] = y + 1;

		tempX[3] = x + 2;
		tempY[3] = y + 1;


	}
	else
	{
		tempX[0] = x;
		tempY[0] = y + 1;

		tempX[1] = x;
		tempY[1] = y + 2;

		tempX[2] = x + 1;
		tempY[2] = y;

		tempX[3] = x + 1;
		tempY[3] = y + 1;
	}

	// Check if new rotated coordinates are valid
	for (int i = 0; i < 4; i++)
	{
		if (tempX[i] < 0 || tempX[i] >= 10 || tempY[i] < 0 || tempY[i] >= 20)
			return;


		bool f = false;
		for (int j = 0; j < 4; j++)
		{
			if (Xcoordinates[j] == tempX[i] && Ycoordinates[j] == tempY[i])
			{
				f = true;
				break;
			}
		}

		if (!f && arr[tempY[i]][tempX[i]] != 0)
			return;
	}



	// Apply new coordinates
	for (int i = 0; i < 4; i++)
	{
		Xcoordinates[i] = tempX[i];
		Ycoordinates[i] = tempY[i];
		//arr[tempY[i]][tempX[i]] = 6;
	}



	// Toggle rotation flag
	rotation = rot;

	updateCoordinates();
}


void  Z::Draw(RenderWindow& window, float blockSize) 
{
	RectangleShape block;
	block.setSize(Vector2f(blockSize - 3.f, blockSize - 3.f));
	block.setFillColor(Color::Red);
	block.setOutlineColor(Color::Black);
	block.setOutlineThickness(1.f);

	for (int i = 0; i < 4; i++)
	{
		block.setPosition(Xcoordinates[i] * blockSize, Ycoordinates[i] * blockSize);
		window.draw(block);

	}

}

int Z:: num()
{
	return 6;
}
