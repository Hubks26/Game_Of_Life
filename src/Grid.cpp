#include "Grid.h"

Grid::Grid()
{
	modif(25, 25);
	modif(26, 24);
	modif(25, 24);
	modif(24, 25);
	modif(25, 26);
}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::RectangleShape rectangle;
	
	for(int i = 1; i < m_dim-1; i++)
	{
		for(int j = 1; j < m_dim-1; j++)
		{
			rectangle.setSize(sf::Vector2f(600/m_dim, 600/m_dim));
			rectangle.setPosition(i*600/m_dim, j*600/m_dim);
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
	if(numRow == 1 || numRow == m_dim-1 || numCol == 1 || numCol == m_dim-1)
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
	bool newArray[m_dim][m_dim]{};
	
	for(int i = 0; i < m_dim; i++)
	{
		for(int j = 0; j < m_dim; j++)
		{
			if(verif(i, j))
				newArray[i][j] = verif(i, j);
		}
	}
	
	for(int i = 0; i < m_dim; i++)
	{
		for(int j = 0; j < m_dim; j++)
		{
			if(newArray[i][j] != m_table[i][j])
				modif(i,j);
		}
	}
}
