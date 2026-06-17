//#include"shape.h"
#include"I.h"


I::I() {
	Xcoordinates[0] = { 4 };
	Ycoordinates[0] = { 0 };

	Xcoordinates[1] = { 4 };
	Ycoordinates[1] = { 1 };

	Xcoordinates[2] = { 4 };
	Ycoordinates[2] = { 2 };

	Xcoordinates[3] = { 4 };
	Ycoordinates[3] = { 3 };


}




void I::updateCoordinates() 
{

	/*for (int i = 0; i < 4; i++)
	{
		if (Ycoordinates[i] >= 0 && Ycoordinates[i] < 20 &&
			Xcoordinates[i] >= 0 && Xcoordinates[i] < 10)
		{
			arr[Ycoordinates[i]][Xcoordinates[i]] = 0;
		}
	}*/

	if (rotation == 0)  // vertical
	{
		for (int i = 0; i < 4; i++)
		{
			Xcoordinates[i] = x;
			Ycoordinates[i] = y + i;
		}
	}
	else  // horizontal
	{
		for (int i = 0; i < 4; i++)
		{
			Xcoordinates[i] = x + i - 1;
			Ycoordinates[i] = y;
		}
	}




	/*for (int i = 0; i < 4; i++)
	{
		if (Ycoordinates[i] >= 0 && Ycoordinates[i] < 20 && Xcoordinates[i] >= 0 && Xcoordinates[i] < 10)
		{
			arr[Ycoordinates[i]][Xcoordinates[i]] = 1;
		}
	}*/


}



void  I::rotate(int arr[20][10])
{
	int tempX[4], tempY[4];


	if (rotation == 0)  // vertical to horizontal
	{
		for (int i = 0; i < 4; i++)
		{
			tempX[i] = x + i - 1;
			tempY[i] = y;
		}
	}
	else  // horizontal to vertical
	{
		for (int i = 0; i < 4; i++)
		{
			tempX[i] = x;
			tempY[i] = y + i;
		}
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

	// Clear current position from grid
	//for (int i = 0; i < 4; i++)
	//{
	//	if (Ycoordinates[i] >= 0 && Ycoordinates[i] < 20 &&
	//		Xcoordinates[i] >= 0 && Xcoordinates[i] < 10)
	//	{
	//		arr[Ycoordinates[i]][Xcoordinates[i]] = 0;
	//	}
	//}

	//// Apply new coordinates
	for (int i = 0; i < 4; i++)
	{
		Xcoordinates[i] = tempX[i];
		Ycoordinates[i] = tempY[i];
		//arr[tempY[i]][tempX[i]] = 1;
	}

	// Toggle rotation flag
	rotation = 1 - rotation;
}




void  I::Draw(RenderWindow& window, float blockSize) 
{
	RectangleShape block;
	block.setSize(Vector2f(blockSize - 3.f, blockSize - 3.f));
	block.setFillColor(Color::Blue);
	block.setOutlineColor(Color::Black);
	block.setOutlineThickness(1.f);

	for (int i = 0; i < 4; i++)
	{
		block.setPosition(Xcoordinates[i] * blockSize, Ycoordinates[i] * blockSize);
		window.draw(block);

	}

}




int I:: num()
{
	return 1;
}