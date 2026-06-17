#include"O.h"

 O::O()
{
	Xcoordinates[0] = { 4 }, Xcoordinates[1] = { 4 }, Xcoordinates[2] = { 5 }, Xcoordinates[3] = { 5 },
		Ycoordinates[0] = { 0 }, Ycoordinates[1] = { 1 }, Ycoordinates[2] = { 0 }, Ycoordinates[3] = { 1 };
}




void O:: updateCoordinates()
{



	Xcoordinates[0] = x;
	Ycoordinates[0] = y;

	Xcoordinates[1] = x;
	Ycoordinates[1] = y + 1;

	Xcoordinates[2] = x + 1;
	Ycoordinates[2] = y;

	Xcoordinates[3] = x + 1;
	Ycoordinates[3] = y + 1;



}





void  O::Draw(RenderWindow& window, float blocks)
{
	RectangleShape block;
	block.setSize(Vector2f(blocks - 3.f, blocks - 3.f));
	block.setFillColor(Color::Yellow);
	block.setOutlineColor(Color::Black);
	block.setOutlineThickness(1.f);

	for (int i = 0; i < 4; i++)
	{
		block.setPosition(Xcoordinates[i] * blocks, Ycoordinates[i] * blocks);
		window.draw(block);

	}

}


int O:: num()
{
	return 2;
}
