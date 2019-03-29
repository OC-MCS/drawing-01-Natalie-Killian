//========================================================
// Natalie Killian
// March 29th, 2019
// Programming Assignment #6
// Description: Drawing
// File Name: SettingsMgr.h
//		Keeps up with current drawing settings
//========================================================
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

// enumerated data for the type of shapes available
enum ShapeEnum { CIRCLE, SQUARE };

// structure that holds the current settings
struct SetRecord
{
	ShapeEnum curShape;
	int colorNum;
};

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

	// writes the Record of shapes to the file
	void saveSettings(fstream &file)
	{
		SetRecord settings;
		settings.curShape = currentShape;
		settings.colorNum = currentColor.toInteger();
		file.write(reinterpret_cast<char*>(&settings), sizeof(settings));
	}

	// gets the previous settings  
	void readPrevSettings(fstream &file)
	{
		SetRecord settings;
		if (file.read(reinterpret_cast<char*>(&settings), sizeof(settings)))
		{
			Color prevColor(settings.colorNum);
			currentColor = prevColor;
			currentShape = settings.curShape;
		}
		else
		{
			currentColor = Color::Blue;
			currentShape = CIRCLE;
		}
	}
};
