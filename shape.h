#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;


class shape
{
protected:
	int Xcoordinates[4];
	int Ycoordinates[4];
	int x = 4, y = 0;

public:

	// Virtual functions
	virtual void Draw(RenderWindow& window, float blockSize) = 0;
	virtual void rotate(int arr[20][10]) = 0;
	virtual void updateCoordinates() = 0;
	virtual int num() = 0;

	
	// Getters
	int getcoorX(int i);

	int getcoorY(int i);

	// Checking of coordinates and array
	bool iswithinbounds(int dx, int dy,int arr[20][10]);

	bool isgamecon(int mat[20][10]);

	// Movements
	void moveLeft(int arr[20][10]);

	void moveRight(int arr[20][10]);

	void moveDown(int arr[20][10]);

	//void moveUP(int arr[20][10]);


	// Updation of coordinates and array
	void setarray();

	
	void setMainarray(int arr[20][10]);

	bool lockTheShapeInTheGrid(int arr[20][10]);
};


