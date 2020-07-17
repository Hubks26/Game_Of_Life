#include "Grid.h"

Grid::Grid()
{
	modif(50, 50);
	modif(51, 49);
	modif(50, 49);
	modif(49, 50);
	modif(50, 51);
}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::RectangleShape rectangle;
	
	for(int i = 1; i < m_dim-1; i++)
	{
		for(int j = 1; j < m_dim-1; j++)
		{
			rectangle.setSize(sf::Vector2f(2500/m_dim, 2500/m_dim));
			rectangle.setPosition(i*2500/m_dim, j*2500/m_dim);
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
	if(numRow == 0 || numRow == m_dim-1 || numCol == 0 || numCol == m_dim-1)
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
