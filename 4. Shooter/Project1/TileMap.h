////////////////////////////////////////////////////////////
// File: TileMap.h
// Author: Ben Odom
// Date Created: 10/01/2015
// Brief: This file contains the functionality for tile-
//		  mapping.
////////////////////////////////////////////////////////////

#ifndef _TILEMAP_H_
#define _TILEMAP_H_

#include "Graphics.h"

const unsigned int TILEMAP_SIZEW = 10;
const unsigned int TILEMAP_SIZEH = 7;

class TileMap
{
private:
	enum TILE // The different kinds of tiles and their names
	{
		DIRT,
		SAND,
		GRASS,

		SIZE
	};

	struct Layer // Allows a row and column value for each Layer in [x][y]
	{
		int iRow = NULL, iCollumn = NULL;
	};
	std::vector<std::vector<Layer>> m_voLayer; // The vector holding all the tile set values

	GLSurface m_glSurfaceEnviorment; // The default image for the tile set. This is the only one that gets loaded by 'Graphics::LoadImage'
	GLSurface m_glSurfaceDirt, m_glSurfaceSand, m_glSurfaceGrass; // Each individual default image for the tile set

public:
	// Draws the tile set
	void Draw();

	// The proper constructor for the tile set
	// Expects the text file name of the tile set, and the image filename for the tile set
	TileMap(const std::string ac_sTileFile, const std::string ac_sImageFile);
	TileMap();
	~TileMap();
};

#endif // _TILEMAP_H_