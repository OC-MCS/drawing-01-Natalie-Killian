//=====================================================
// Natalie Killian
// March 29th, 2019
// Programming Assignment #6
// Description: Drawing
// File Name: DrawingUI.h
//		Handles user interface from drawing area
//=====================================================
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
	// empty constructor
	DrawingUI(Vector2f p){}

	// draws window with borders around user's drawing window and
	// the settings available
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
	
	// sets the bounds for the window the user is able to draw in and 
	// check to see if the mouse is within the drawing window/canvas
	bool isMouseInCanvas(Vector2f mousePos)
	{
		bool inCanvas = false;
		if (mousePos.x >= 265 && mousePos.x <= 747 && mousePos.y >= 14 && mousePos.y <= 547) {
			inCanvas = true;
		}

		return inCanvas;
	}

};
