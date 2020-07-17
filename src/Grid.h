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
	
	static constexpr int m_dim = 50;
	bool m_table[m_dim][m_dim]{};
};

#endif // GRID_H
