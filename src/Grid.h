#ifndef GRID_H
#define GRID_H

#include <SFML/Graphics.hpp>

class Grid : public sf::Drawable
{
public :
	
	Grid();
	void update();
	
private :
	
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	void modif(int, int);
	bool verif(int, int) const;
	
private :
	
	const int m_dim;
	bool m_table[22][22]{};
};

#endif // GRID_H
