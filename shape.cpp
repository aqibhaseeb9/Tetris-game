#include"shape.h"


int  shape::getcoorX(int i)
{
	return Xcoordinates[i];
}

int  shape::getcoorY(int i)
{
	return Ycoordinates[i];
}


bool shape:: iswithinbounds(int dx, int dy, int arr[20][10])
{
	for (int i = 0; i < 4; i++)
	{
		int newX = Xcoordinates[i] + dx;
		int newY = Ycoordinates[i] + dy;

		// First check boundaries
		if (newX < 0 || newX >= 10 || newY < 0 || newY >= 20)
			return false;

		// Then check collision only if within bounds
		if (arr[newY][newX] != 0)
		{
			// skip own body (if needed)
			bool isSelf = false;
			for (int j = 0; j < 4; j++) {
				if (Xcoordinates[j] == newX && Ycoordinates[j] == newY) {
					isSelf = true;
					break;
				}
			}
			if (!isSelf)
				return false;
			//return false;
		}
	}
	return true;
}

bool shape:: isgamecon(int mat[20][10])
{
	for (int i = 0; i < 4; i++)
	{
		int x = Xcoordinates[i];
		int y = Ycoordinates[i];

		if (y < 0 || y >= 20 || x < 0 || x >= 10)
			return false;

		if (mat[y][x] != 0)
			return false;
	}

	return true;
}


void  shape::moveLeft(int arr[20][10])
{
	if (iswithinbounds(-1, 0, arr)) {
		x--;
		updateCoordinates();
	}
}

void shape:: moveRight(int arr[20][10])
{

	if (iswithinbounds(1, 0, arr)) {
		x++;
		updateCoordinates();
	}
}

void shape:: moveDown(int arr[20][10])
{
	if (iswithinbounds(0, 1, arr))
	{
		y++;
		updateCoordinates();
	}
	else
		setarray();
}

//void shape:: moveUP(int arr[20][10])
//{
//	if (iswithinbounds(0, -1, arr)) {
//		y--;
//		updateCoordinates();
//	}
//
//}



void shape:: setarray()
{
	for (int i = 0;i < 4;i++)
	{
		Xcoordinates[i] = getcoorX(i);
		Ycoordinates[i] = getcoorY(i);
	}

}


void shape:: setMainarray(int arr[20][10])
{
	for (int i = 0; i < 4; i++)
	{
		int row = Ycoordinates[i];
		int col = Xcoordinates[i];
		arr[row][col] = num();
	}
}

bool shape:: lockTheShapeInTheGrid(int arr[20][10])
{
	for (int i = 0; i < 4; i++)
	{
		int row = Ycoordinates[i];
		int col = Xcoordinates[i];

		if (row >= 19 || arr[row + 1][col] != 0)
		{
			setMainarray(arr);
			return true;
		}
	}
	return false;
}