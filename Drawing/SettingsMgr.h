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
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		currentColor = startingColor;
		currentShape = startingShape;
	}
	void setCurColor(Color startingColor)
	{
		currentColor = startingColor;
	}
	Color getCurColor()
	{
		return currentColor;
	}
	void setCurShape(ShapeEnum startingShape)
	{
		currentShape = startingShape;
	}
	ShapeEnum getCurShape()
	{
		return currentShape;
	}
};
