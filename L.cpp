#include"L.h"

L::L()
{
	Xcoordinates[0] = { 4 }, Xcoordinates[1] = { 4 }, Xcoordinates[2] = { 4 }, Xcoordinates[3] = { 5 },
		Ycoordinates[0] = { 0 }, Ycoordinates[1] = { 1 }, Ycoordinates[2] = { 2 }, Ycoordinates[3] = { 2 };

}




void L::updateCoordinates()
{

	switch (rotation) {
	case 0: // default (vertical L)
		Xcoordinates[0] = x;
		Ycoordinates[0] = y;

		Xcoordinates[1] = x;
		Ycoordinates[1] = y + 1;

		Xcoordinates[2] = x;
		Ycoordinates[2] = y + 2;

		Xcoordinates[3] = x + 1;
		Ycoordinates[3] = y + 2;
		break;

	case 1: // rotate 90
		Xcoordinates[0] = x;
		Ycoordinates[0] = y;

		Xcoordinates[1] = x + 1;
		Ycoordinates[1] = y;

		Xcoordinates[2] = x + 2;
		Ycoordinates[2] = y;

		Xcoordinates[3] = x;
		Ycoordinates[3] = y + 1;
		break;

	case 2: // rotate 180
		Xcoordinates[0] = x;
		Ycoordinates[0] = y;

		Xcoordinates[1] = x + 1;
		Ycoordinates[1] = y;

		Xcoordinates[2] = x + 1;
		Ycoordinates[2] = y + 1;

		Xcoordinates[3] = x + 1;
		Ycoordinates[3] = y + 2;
		break;

	case 3: // rotate 270
		Xcoordinates[0] = x + 2;
		Ycoordinates[0] = y;

		Xcoordinates[1] = x;
		Ycoordinates[1] = y + 1;

		Xcoordinates[2] = x + 1;
		Ycoordinates[2] = y + 1;

		Xcoordinates[3] = x + 2;
		Ycoordinates[3] = y + 1;
		break;
	}



}



void L::rotate(int arr[20][10])
{
	int tempX[4], tempY[4];


	int rot = (rotation + 1) % 4;



	int old_rot = rotation;

	if (rot == 1 || rot == 3)
	{
		if (x + 2 >= 10) 
			x = 7;  // Push left to avoid overflow
	}
	else if (rot == 0 || rot == 2)
	{
		if (x + 1 >= 10) 
			x = 8;
	}


	//for (int i = 0;i < s;i++)
	{
		switch (rot)
		{
		case 0:  // Vertical L pointing right
			tempX[0] = x;
			tempY[0] = y;

			tempX[1] = x;
			tempY[1] = y + 1;

			tempX[2] = x;
			tempY[2] = y + 2;

			tempX[3] = x + 1;
			tempY[3] = y + 2;

			break;

		case 1:  // Horizontal L pointing down

			tempX[0] = x;
			tempY[0] = y;

			tempX[1] = x + 1;
			tempY[1] = y;

			tempX[2] = x + 2;
			tempY[2] = y;

			tempX[3] = x;
			tempY[3] = y + 1;
			break;

		case 2:  // Vertical L pointing left
			tempX[0] = x + 1;
			tempY[0] = y;

			tempX[1] = x + 1;
			tempY[1] = y + 1;

			tempX[2] = x + 1;
			tempY[2] = y + 2;

			tempX[3] = x;
			tempY[3] = y;
			break;

		case 3:  // Horizontal L pointing up
			tempX[0] = x;
			tempY[0] = y + 1;

			tempX[1] = x + 1;
			tempY[1] = y + 1;

			tempX[2] = x + 2;
			tempY[2] = y + 1;

			tempX[3] = x + 2;
			tempY[3] = y;

			break;
		}

	}

	// Check if new rotated coordinates are valid
	for (int i = 0; i < 4; i++)
	{
		if (tempX[i] < 0 || tempX[i] >= 10 || tempY[i] < 0 || tempY[i] >= 20)
		{
			rotation = old_rot;
			return;

		}


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
	for (int i = 0; i < s; i++)
	{
		Xcoordinates[i] = tempX[i];
		Ycoordinates[i] = tempY[i];
		//arr[tempY[i]][tempX[i]] = 3;
	}

	rotation = rot;


}



void L::Draw(RenderWindow& window, float blocks)
{
	RectangleShape block;
	block.setSize(Vector2f(blocks - 3.f, blocks - 3.f));
	block.setFillColor(Color::Green);
	block.setOutlineColor(Color::Black);
	block.setOutlineThickness(1.f);

	for (int i = 0; i < 4; i++)
	{
		block.setPosition(Xcoordinates[i] * blocks, Ycoordinates[i] * blocks);
		window.draw(block);

	}

}


int L:: num()
{
	return 3;
}