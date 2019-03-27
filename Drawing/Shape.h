#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// DrawingShape is an abstract base class 
// for Circle and Square
class DrawingShape 
{
public:
	Vector2f location;
	Color color;
	ShapeEnum shape;
	DrawingShape(Vector2f l, Color c, ShapeEnum s)
	{
		location = l;
		color = c;
		shape = s;
	}
	virtual void draw(RenderWindow &w) = 0;
};

// Circle class is derived from DrawingShape
class Circle : public DrawingShape
{
public:
	CircleShape newCircle;
	Circle(Vector2f l, Color c, ShapeEnum s) : DrawingShape(l, c, s) 
	{
		newCircle.setPosition(l);
		newCircle.setRadius(20.0);
		newCircle.setOutlineThickness(2);
		newCircle.setOutlineColor(c);
		// for just an outlined button do Color::Transparent
		newCircle.setFillColor(c);
	}
	void draw(RenderWindow &window)
	{
		window.draw(newCircle);
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
	void draw(RenderWindow &window)
	{
		window.draw(newSquare);
	}
};
