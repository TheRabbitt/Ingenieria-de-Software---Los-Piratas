#include "Map.hpp"

Map::Map()
{
}

Map::Map(const std::string& filename, sf::Vector2u textureSize, unsigned int width, unsigned int height)
{
	const int level[] =
	{
		00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		02, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 6, 7, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4,
		01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5,
		01, 0,15,17,17,16, 0,15,17,17,17,16, 0, 8, 9, 0,15,17,17,17,16, 0,15,17,17,16, 0, 5,
		01, 0, 8, 0, 0, 9, 0, 8, 0, 0, 0, 9, 0, 8, 9, 0, 8, 0, 0, 0, 9, 0, 8, 0, 0, 9, 0, 5,
		01, 0,13,18,18,14, 0,13,18,18,18,14, 0,13,14, 0,13,18,18,18,14, 0,13,18,18,14, 0, 5,
		01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5,
		01, 0,15,17,17,16, 0,15,16, 0,15,17,17,17,17,17,17,16, 0,15,16, 0,15,17,17,16, 0, 5,
		01, 0,13,18,18,14, 0, 8, 9, 0,13,18,18,22,20,18,18,14, 0, 8, 9, 0,13,18,18,14, 0, 5,
		01, 0, 0, 0, 0, 0, 0, 8, 9, 0, 0, 0, 0, 8, 9, 0, 0, 0, 0, 8, 9, 0, 0, 0, 0, 0, 0, 5,
		10,11,11,11,11,32, 0, 8,19,17,17,16, 0, 8, 9, 0,15,17,17,21, 9, 0,31,11,11,11,11,12,
		00, 0, 0, 0, 0, 1, 0, 8,20,18,18,14, 0,13,14, 0,13,18,18,22, 9, 0, 5, 0, 0, 0, 0, 0,
		00, 0, 0, 0, 0, 1, 0, 8, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 9, 0, 5, 0, 0, 0, 0, 0,
		00, 0, 0, 0, 0, 1, 0, 8, 9, 0,27,11,11,35,35,11,11,28, 0, 8, 9, 0, 5, 0, 0, 0, 0, 0,
		03, 3, 3, 3, 3,34, 0,13,14, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0,13,14, 0,33, 3, 3, 3, 3, 3,
		00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		11,11,11,11,11,32, 0,15,16, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0,15,16, 0,31,11,11,11,11,11,
		00, 0, 0, 0, 0, 1, 0, 8, 9, 0,29, 3, 3, 3, 3, 3, 3,30, 0, 8, 9, 0, 5, 0, 0, 0, 0, 0,
		00, 0, 0, 0, 0, 1, 0, 8, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 9, 0, 5, 0, 0, 0, 0, 0,
		00, 0, 0, 0, 0, 1, 0, 8, 9, 0,15,17,17,17,17,17,17,16, 0, 8, 9, 0, 5, 0, 0, 0, 0, 0,
		02, 3, 3, 3, 3,34, 0,13,14, 0,13,18,18,22,20,18,18,14, 0,13,14, 0,33, 3, 3, 3, 3, 4,
		01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5,
		01, 0,15,17,17,16, 0,15,17,17,17,16, 0, 8, 9, 0,15,17,17,17,16, 0,15,17,17,16, 0, 5,
		01, 0,13,18,22, 9, 0,13,18,18,18,14, 0,13,14, 0,13,18,18,18,14, 0, 8,20,18,14, 0, 5,
		01, 0, 0, 0, 8, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 9, 0, 0, 0, 5,
		23,17,16, 0, 8, 9, 0,15,16, 0,15,17,17,17,17,17,17,16, 0,15,16, 0, 8, 9, 0,15,17,25,
		24,18,14, 0,13,14, 0, 8, 9, 0,13,18,18,22,20,18,18,14, 0, 8, 9, 0,13,14, 0,13,18,26,
		01, 0, 0, 0, 0, 0, 0, 8, 9, 0, 0, 0, 0, 8, 9, 0, 0, 0, 0, 8, 9, 0, 0, 0, 0, 0, 0, 5,
		01, 0,15,17,17,17,17,21,19,17,17,16, 0, 8, 9, 0,15,17,17,21,19,17,17,17,17,16, 0, 5,
		01, 0,13,18,18,18,18,18,18,18,18,14, 0,13,14, 0,13,18,18,18,18,18,18,18,18,14, 0, 5,
		01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5,
		10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,12,
		00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};
	
	if(!load(filename + std::to_string(textureSize.x) + ".png", textureSize, level, width, height))
		throw std::runtime_error("Map failed to load Image " + filename);
}

bool Map::load(const std::string& filename, sf::Vector2u textureSize, const int* tiles, unsigned int width, unsigned int height)
{
	if (!textureSet.loadFromFile(filename))
		throw std::runtime_error("Map failed to load Image " + filename);

	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int k = 0;
	unsigned int validTiles = 0;

    // Cuenta la cantidad de posiciones con las que se dibuja el mapa
	while(i < width*height)
	{
		if (*(tiles+i) != 0)
			validTiles++;
		i++;
	}

	// Ajusta el tamaño vertex array de acuerdo al numero de texturas con las que se dinuja mapa
	mVertices.setPrimitiveType(sf::Quads);
	mVertices.resize((long long)validTiles * 4);

	// Numero de texturas en el textureSet (en la imagen)
	int numTextures = textureSet.getSize().x / textureSize.x;

    int ty = 0; // Posicion horizontal de cada textura textureSet. Las texturas se ordenan en fila, asi que 0.

	// Define la posicion de cada textura en la ventana
	for (i = 0; i < width; ++i)
		for (j = 0; j < height; ++j)
		{
			// Obtiene el numero valor almacenado en el array
			int tNumber = tiles[i + j * width];

			// Posicion vertical de la textura a cargar en el textureSet
			int tx = tNumber % numTextures;

			if (tNumber != 0)
			{
				// Puntero a un vertex en mVertices. En 4 vertex se define una textura
				sf::Vertex* quad = &mVertices[(long long)(k * 4)];
				k++;

				// Posicion de la textura en el mapa (coordenadas en el mapa).
				quad[0].position = sf::Vector2f((float)(i * textureSize.x), (float)(j * textureSize.y));
				quad[1].position = sf::Vector2f((float)((i + 1) * textureSize.x), (float)(j * textureSize.y));
				quad[2].position = sf::Vector2f((float)((i + 1) * textureSize.x), (float)((j + 1) * textureSize.y));
				quad[3].position = sf::Vector2f((float)(i * textureSize.x), (float)((j + 1) * textureSize.y));

				// Posicion de la textura en el textureSet (imagen). Coordenadas en la imagen.
				quad[0].texCoords = sf::Vector2f((float)(tx * textureSize.x), (float)(ty * textureSize.y));
				quad[1].texCoords = sf::Vector2f((float)((tx + 1) * textureSize.x), (float)(ty * textureSize.y));
				quad[2].texCoords = sf::Vector2f((float)((tx + 1) * textureSize.x), (float)((ty + 1) * textureSize.y));
				quad[3].texCoords = sf::Vector2f((float)(tx * textureSize.x), (float)((ty + 1) * textureSize.y));
			}
		}
	return true;
}

bool Map::detectCollision(float px, float py)
{
	int i;
	for (i = 0; i < mVertices.getVertexCount()/4; i++)
	{
		sf::Vertex* quad = &mVertices[(long long)(i*4)];
		if (px < quad[0].position.x + 11 &&
			px + 11 > quad[0].position.x &&
			py < quad[0].position.y + 11 &&
			11 + py > quad[0].position.y)
			return true;
	}
	return false;
}

// Para implementar sf::Drawable. Permite que el objeto (mapa) sea dibujado en la ventana.
void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	// Aplica la textura (imagen)
	states.texture = &textureSet;
	// Dibuja las texturas (que "contienen" cada textura)
	target.draw(mVertices, states);
}
