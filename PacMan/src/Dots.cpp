#include "Dots.hpp"

Dots::Dots(const int* level, int width, int height)
{
	int i;
	for (i = 0; i < 240; i++)
	{
		dots[i] = sf::CircleShape(2.f);
		dots[i].setFillColor(sf::Color(255, 255, 0));
		dotsPtr[i] = &dots[i];
	}
	setDots(level, width, height);
}

void Dots::setDots(const int* level, int width, int height)
{
	int i, j, k;
	k = 0;
	// Define la posicion de cada textura en la ventana
	for (i = 0; i < width; ++i)
		for (j = 0; j < height; ++j)
		{
			// Obtiene el valor almacenado en el array
			int tNumber = level[i + j * width];

			if (tNumber == 99)
			{
				// Posicion de la textura en el mapa (coordenadas en el mapa).
				dots[k].setPosition(sf::Vector2f((float)(i * 16 + 8), (float)(j * 16 + 8)));
				k++;
				if (k >= 240)
					return;
			}
		}
}

sf::CircleShape** Dots::getDotsPtr()
{
	return dotsPtr;
}

void Dots::nullDotPtr(int i)
{
	dotsPtr[i] = nullptr;
}