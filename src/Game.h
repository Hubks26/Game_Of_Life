#ifndef GAME_H
#define GAME_H

#include "Grid.h"

class Game
{
public :
	
	Game();
	void run();
	
private :
	
	void processEvents();
	void update();
	void render();
	//void handlePlayerInput();
	
private :
	
	sf::RenderWindow m_window;
	static const sf::Time m_timePerFrame;
	
	Grid m_grid;
};

#endif //GAME_H
