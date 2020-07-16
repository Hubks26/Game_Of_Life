#include "Grid.h"

Grid::Grid()
: m_dim(10)
{
	modif(3, 2);
	modif(4, 3);
	modif(4, 4);
	modif(3, 4);
	modif(2, 4);
}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::RectangleShape rectangle;
	
	for(int i = 1; i < 23; i++)
	{
		for(int j = 1; j < 23; j++)
		{
			rectangle.setSize(sf::Vector2f(25, 25));
			rectangle.setPosition(i*25, j*25);
			rectangle.setOutlineColor(sf::Color::Blue);
			rectangle.setOutlineThickness(1);
				
			if(not m_table[i][j])
			{
				rectangle.setFillColor(sf::Color::Black);
			}
			else
			{
				rectangle.setFillColor(sf::Color::White);
			}
			
			target.draw(rectangle, states);
		}
	}
}

void Grid::modif(int numRow, int numCol)
{
	m_table[numRow][numCol] = not m_table[numRow][numCol];
}

bool Grid::verif(int numRow, int numCol) const
{
	if(numRow == 0 || numRow == 21 || numCol == 0 || numCol == 21)
		return false;
	
	int compteur;
	compteur = m_table[numRow-1][numCol-1] + m_table[numRow-1][numCol] + m_table[numRow-1][numCol+1];
	compteur += m_table[numRow][numCol-1] + m_table[numRow][numCol+1];
	compteur += m_table[numRow+1][numCol-1] + m_table[numRow+1][numCol] + m_table[numRow+1][numCol+1];
		
	if(m_table[numRow][numCol])
	{
		if(compteur > 1 && compteur < 4)
			return true;
		else
			return false;
	}
	else
	{
		if(compteur == 3)
			return true;
		else
			return false;
	}
}

void Grid::update()
{
	bool newArray[22][22]{};
	
	for(int i = 0; i < 22; i++)
	{
		for(int j = 0; j < 22; j++)
		{
			if(verif(i, j))
				newArray[i][j] = verif(i, j);
		}
	}
	
	for(int i = 0; i < 22; i++)
	{
		for(int j = 0; j < 22; j++)
		{
			if(newArray[i][j] != m_table[i][j])
				modif(i,j);
		}
	}
}
