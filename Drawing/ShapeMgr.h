//=====================================================
// Natalie Killian
// March 29th, 2019
// Programming Assignment #6
// Description: Drawing
// File Name: ShapeMgr.h
//		Keeps track of all current shapes that have
//		been created. Reads and writes shape data 
//		to/from file
//=====================================================
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
	// a vector of pointers to drawing shapes (holds the shapes)
	vector <DrawingShape*> shapeHolder;

	// constructor 
	ShapeMgr(){}
	
	// adds drawn shapes into the vector 
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

	// writes the Record of shapes to the file
	void saveToFile(fstream &file)
	{
		Record newRecord;
		for (int i = 0; i < shapeHolder.size(); i++)
		{
			newRecord = shapeHolder[i]->getFileRecord();
			file.write(reinterpret_cast<char*>(&newRecord), sizeof(newRecord));
		}
	}

	// gets the last drawing
	void readFromFile(fstream &file)
	{
		Record newRecord;
		while (file.read(reinterpret_cast<char*>(&newRecord), sizeof(newRecord)))
		{
			Color prevColor(newRecord.colorNum);
			addShape(newRecord.pos, newRecord.shape, prevColor);
		}
	}
};
