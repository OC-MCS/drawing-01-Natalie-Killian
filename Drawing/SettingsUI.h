#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

// function prototype
void die(string msg);

class SettingsUI
{
private:
	CircleShape blueBtn;
	CircleShape redBtn;
	CircleShape greenBtn;
	RectangleShape squareBtn;
	CircleShape circleBtn;
	SettingsMgr *sMgr;
public:
	SettingsUI(SettingsMgr *mgr)
	{
		sMgr = mgr;
	
		// define blue button
		Vector2f pos1(95, 100);
		blueBtn.setPosition(pos1);
		blueBtn.setRadius(10);
		blueBtn.setOutlineThickness(2);
		blueBtn.setOutlineColor(Color::Blue);
		blueBtn.setFillColor(Color::Blue);

		// define red button
		Vector2f pos2(95, 175);
		redBtn.setPosition(pos2);
		redBtn.setRadius(10);
		redBtn.setOutlineThickness(2);
		redBtn.setOutlineColor(Color::Red);
		redBtn.setFillColor(Color::Transparent);

		// define green button
		Vector2f pos3(95, 250);
		greenBtn.setPosition(pos3);
		greenBtn.setRadius(10);
		greenBtn.setOutlineThickness(2);
		greenBtn.setOutlineColor(Color::Green);
		greenBtn.setFillColor(Color::Transparent);		

		// define circle shape selection button
		Vector2f pos4(95, 400);
		circleBtn.setPosition(pos4);
		circleBtn.setRadius(10);
		circleBtn.setOutlineThickness(2);
		circleBtn.setOutlineColor(Color::White);
		circleBtn.setFillColor(Color::White);

		// define square shape selection button
		Vector2f sqPos1(97, 475);
		squareBtn.setPosition(sqPos1);
		squareBtn.setOutlineColor(Color::White);
		squareBtn.setOutlineThickness(2);
		squareBtn.setSize(Vector2f(15, 15));
		squareBtn.setFillColor(Color::Transparent);

	}
	void handleMouseUp(Vector2f mouse)
	{
		// check if mouse is currently over blueBtn
		if (blueBtn.getGlobalBounds().contains(mouse)) {
			sMgr->setCurColor(Color::Blue);
			blueBtn.setFillColor(Color::Blue);
			redBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Transparent);
		}
		// check if mouse is currently over redBtn
		if (redBtn.getGlobalBounds().contains(mouse)) {
			sMgr->setCurColor(Color::Red);
			blueBtn.setFillColor(Color::Transparent);
			redBtn.setFillColor(Color::Red);
			greenBtn.setFillColor(Color::Transparent);
		}
		// check if mouse is currently over greenBtn
		if (greenBtn.getGlobalBounds().contains(mouse)) {
			sMgr->setCurColor(Color::Green);
			blueBtn.setFillColor(Color::Transparent);
			redBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Green);
		}
		// check if mouse is currently over circleBtn
		if (squareBtn.getGlobalBounds().contains(mouse)) {
			sMgr->setCurShape(SQUARE);
			squareBtn.setFillColor(Color::White);
			circleBtn.setFillColor(Color::Transparent);
		}
		// check if mouse is currently over squareBtn
		if (circleBtn.getGlobalBounds().contains(mouse)) {
			sMgr->setCurShape(CIRCLE);
			squareBtn.setFillColor(Color::Transparent);
			circleBtn.setFillColor(Color::White);
		}		
	}

	void draw(RenderWindow& win)
	{
		win.draw(blueBtn);
		win.draw(redBtn);
		win.draw(greenBtn);
		win.draw(circleBtn);
		win.draw(squareBtn);

		// define color and shape label header
		Font font;		// first load font
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");
		// title
		Text colorTitle("Color Selection", font, 25);
		colorTitle.setPosition(30, 25);
		win.draw(colorTitle);
		// title
		Text shapeTitle("Shape Selection", font, 25);
		shapeTitle.setPosition(30, 325);
		win.draw(shapeTitle);
	}

};

// utility function when we need to bail out
void die(string msg)
{
	cout << msg << endl;
	exit(-1);
}
