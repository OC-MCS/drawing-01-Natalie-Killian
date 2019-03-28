#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

class DrawingUI
{
private:
	RectangleShape outerBorder;
	RectangleShape leftBorder;
public:
	DrawingUI(Vector2f p)
	{

	}

	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		// Draw outer border
		Vector2f sqPos(10, 10);
		outerBorder.setPosition(sqPos);
		outerBorder.setOutlineColor(Color::White);
		outerBorder.setOutlineThickness(3);
		outerBorder.setSize(Vector2f(780, 580));
		outerBorder.setFillColor(Color::Transparent);
		win.draw(outerBorder);

		// Draw left border for settings menu
		Vector2f sqPos2(10, 10);
		leftBorder.setPosition(sqPos2);
		leftBorder.setOutlineColor(Color::White);
		leftBorder.setOutlineThickness(3);
		leftBorder.setSize(Vector2f(250, 580));
		leftBorder.setFillColor(Color::Transparent);
		win.draw(leftBorder);

		// Draw the shapes
		for (int i = 0; i < mgr->shapeHolder.size(); i++)
		{
			mgr->shapeHolder[i]->draw(win);
		}
	}
	
	bool isMouseInCanvas(Vector2f mousePos)
	{
		bool inCanvas = false;
		if (mousePos.x >= 265 && mousePos.x <= 747 && mousePos.y >= 14 && mousePos.y <= 547) {
			inCanvas = true;
		}

		return inCanvas;
	}

};
