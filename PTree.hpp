

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#ifndef PTREE_H
#define PTREE_H

using namespace std;

class PTree 
{
public:
	void drawTree(sf::RenderTarget& window, int N, sf::RectangleShape& parent);
	sf::RectangleShape colorSwitch(sf::RectangleShape target, int N);

};


#endif