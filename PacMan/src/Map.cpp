#include "Map.hpp"

Map::Map()
{
}

Map::Map(const std::string& filename, sf::Vector2u textureSize, unsigned int width, unsigned int height)
{
	if(!load(filename + std::to_string(textureSize.x) + ".png", textureSize, level, width, height))
		throw std::runtime_error("Map failed to load Image " + filename);
}

bool Map::load(const std::string& filename, sf::Vector2u textureSize, const int* tiles, unsigned int width, unsigned int height)
{
	if (!textureSet.loadFromFile(filename))
		throw std::runtime_error("Map failed to load Image " + filename);

	unsigned int i = 0;
	unsigned int j;// = 0;
	unsigned int k = 0;
	unsigned int validTiles = 0;

    // Cuenta la cantidad de posiciones con las que se dibuja el mapa
	while(i < width*height)
	{
		if (*(tiles+i) != 0)
			validTiles++;
		i++;
	}

	// Ajusta el tamaño vertex array de acuerdo al numero de texturas con las que se dibuja el mapa
	mVertices.setPrimitiveType(sf::Quads);
	mVertices.resize((long long)validTiles * 4);

	// Numero de texturas en el textureSet (en la imagen)
	int numTextures = textureSet.getSize().x / textureSize.x;

    int ty = 0; // Posicion horizontal de cada textura textureSet. Las texturas se ordenan en una fila, asi que 0.

	// Define la posicion de cada textura en la ventana
	for (i = 0; i < width; ++i)
		for (j = 0; j < height; ++j)
		{
			// Obtiene el valor almacenado en el array
			int tNumber = tiles[i + j * width];

			// Posicion vertical de la textura a cargar en el textureSet
			int tx = tNumber % numTextures;

			if (tNumber != 0 && tNumber != 99 && tNumber != 98)
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
	long long i;
	long long numWalls = mVertices.getVertexCount() / 4;
	for (i = 0; i < numWalls; i++)
	{
		sf::Vertex* quad = &mVertices[(long long)(i*4)];
		if (px < quad[0].position.x + 11.5 &&
			px + 11.5 > quad[0].position.x &&
			py < quad[0].position.y + 11.5 &&
			11.5 + py > quad[0].position.y)
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
