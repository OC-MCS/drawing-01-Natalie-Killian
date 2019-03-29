//=====================================================
// Natalie Killian
// March 29th, 2019
// Programming Assignment #6
// Description: Drawing
// File Name: Shapes.h
//=====================================================
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// structure of drawn shape data to write to file
struct Record
{
	int colorNum;
	Vector2f pos;
	ShapeEnum shape;
};

// DrawingShape is an abstract base class for Circle and Square
class DrawingShape 
{
public:
	Vector2f location;
	Color color;
	ShapeEnum shape;
	// constructor
	DrawingShape(Vector2f l, Color c, ShapeEnum s)
	{
		location = l;
		color = c;
		shape = s;
	}
	// overridden in derived classes; draws an instance of a shape in the window
	virtual void draw(RenderWindow &w) = 0;
	// overridden in derived classes; returns a Record of a shape to be written to the file
	virtual Record getFileRecord() = 0;
};

// Circle class is derived from DrawingShape
class Circle : public DrawingShape
{
public:
	CircleShape newCircle;
	// constructor
	Circle(Vector2f l, Color c, ShapeEnum s) : DrawingShape(l, c, s) 
	{
		newCircle.setPosition(l);
		newCircle.setRadius(20.0);
		newCircle.setOutlineThickness(2);
		newCircle.setOutlineColor(c);
		newCircle.setFillColor(c);
	}
	// draws an instance of a circle in the window
	void draw(RenderWindow &window)
	{
		window.draw(newCircle);
	}
	// returns a Record of a circle to be written to the file
	Record getFileRecord()
	{
		Record tempRec;
		Color tempColor = newCircle.getFillColor();
		tempRec.colorNum = tempColor.toInteger();
		tempRec.pos = newCircle.getPosition();
		tempRec.shape = CIRCLE;	

		return tempRec;
	}
};

// Square class is derived from DrawingShape
class Square : public DrawingShape
{
public:
	RectangleShape newSquare;
	Square(Vector2f l, Color c, ShapeEnum s) : DrawingShape(l, c, s) 
	{
		newSquare.setPosition(l);
		newSquare.setOutlineColor(c);
		newSquare.setOutlineThickness(2);
		newSquare.setSize(Vector2f(40.0, 40.0));
		newSquare.setFillColor(c);
		// for just an outlined button do Color::Transparent
		newSquare.setFillColor(c);
	}
	// draws an instance of a square in the window
	void draw(RenderWindow &window)
	{
		window.draw(newSquare);
	}
	// returns a Record of a square to be written to the file
	Record getFileRecord()
	{
		Record tempRec;
		Color tempColor = newSquare.getFillColor();
		tempRec.colorNum = tempColor.toInteger();
		tempRec.pos = newSquare.getPosition();
		tempRec.shape = SQUARE;

		return tempRec;
	}
};
