
#include "PTree.hpp"
#include <string>
#include <iostream>
#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

int main(int argc, char* argv[])
{
	const float L = stoi(argv[1]);		//Size of the tree (initial square)
	const int N = stoi(argv[2]);		//Depth of recursion
	const unsigned width = static_cast<unsigned>(6 * L);
	const unsigned height = static_cast<unsigned>(4 * L);

	sf::RenderWindow window{ {width, height}, "Pythagorean Tree" };
	sf::RectangleShape base{ {L, L} };
	base.setOrigin(base.getSize() / 2.f);
	base.setPosition(window.getSize().x / 2.f, window.getSize().y - L / 2.f);
	PTree myTree;
	
	while (window.isOpen())
	{
		for (sf::Event event; window.pollEvent(event);)
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);
		myTree.drawTree(window, N, base);
		window.display();
	}
	
}






