


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include "PTree.hpp"
#include <iostream>

using namespace std;
using namespace sf;

void PTree::drawTree(sf::RenderTarget& window, int N, sf::RectangleShape& parent)
{
	static const float halfSqrt2 = sqrt(2.f) / 2;

	if (N < 1) return;
	window.draw(parent);
	auto const& sz = parent.getSize();
	auto const& tf = parent.getTransform();

	sf::RectangleShape left = parent;                 
	left.setPosition(tf.transformPoint({ 0, 0 })); 
	left.rotate(-45);
	left.setSize(sz * halfSqrt2);
	left.setOrigin(0, left.getSize().y);
	left = colorSwitch(left, N);
	drawTree(window, N - 1, left);

	sf::RectangleShape right = parent;             
	right.setPosition(tf.transformPoint({ sz.x, 0 })); 
	right.rotate(45);
	right.setSize(sz * halfSqrt2);
	right.setOrigin(right.getSize());
	right = colorSwitch(right, N);
	drawTree(window, N - 1, right);
}


sf::RectangleShape PTree::colorSwitch(sf::RectangleShape target, int N)
{
	switch (N)
	{
	case 1:
		target.setFillColor(sf::Color::White);
		break;
	case 2:
		target.setFillColor(sf::Color::Red);
		break;
	case 3:
		target.setFillColor(sf::Color::Green);
		break;
	case 4:
		target.setFillColor(sf::Color::Blue);
		break;
	case 5:
		target.setFillColor(sf::Color::Yellow);
		break;
	case 6:
		target.setFillColor(sf::Color::Magenta);
		break;
	case 7:
		target.setFillColor(sf::Color::Cyan);
		break;
	case 8:
		target.setFillColor(sf::Color::Cyan);
		break;
	case 9:
		target.setFillColor(sf::Color::Magenta);
		break;
	case 10:
		target.setFillColor(sf::Color::Cyan);
		break;
	case 11:
		target.setFillColor(sf::Color::Blue);
		break;
	case 12:
		target.setFillColor(sf::Color::White);
		break;
	case 13:
		target.setFillColor(sf::Color::White);
		break;
	case 14:
		target.setFillColor(sf::Color::White);
		break;
	default:
		target.setFillColor(sf::Color::White);
	}
	
	return target;
}
