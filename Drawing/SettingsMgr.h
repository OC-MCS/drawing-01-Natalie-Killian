#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

// enumerated data for the type of shapes available
enum ShapeEnum { CIRCLE, SQUARE };

class SettingsMgr
{
private:
	Color currentColor;
	ShapeEnum currentShape;
public:
	// constructor for colors and shapes
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		currentColor = startingColor;
		currentShape = startingShape;
	}
	// color setter
	void setCurColor(Color startingColor)
	{
		currentColor = startingColor;
	}
	// color getter
	Color getCurColor()
	{
		return currentColor;
	}
	// shape setter
	void setCurShape(ShapeEnum startingShape)
	{
		currentShape = startingShape;
	}
	// shape getter
	ShapeEnum getCurShape()
	{
		return currentShape;
	}
};
