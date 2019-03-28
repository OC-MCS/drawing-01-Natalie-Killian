#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

class ShapeMgr
{
private:
	
public:
	// a vector of pointers to drawing shapes
	// holds the shapes
	vector <DrawingShape*> shapeHolder;

	ShapeMgr()
	{
		
	}

	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		if (whichShape == CIRCLE)
		{
			Circle* newCircle;

			newCircle = new Circle(pos, color, whichShape);
			shapeHolder.push_back(newCircle);
		}
		if (whichShape == SQUARE)
		{
			Square* newSquare;

			newSquare = new Square(pos, color, whichShape);
			shapeHolder.push_back(newSquare);
		}
		
	}

};
