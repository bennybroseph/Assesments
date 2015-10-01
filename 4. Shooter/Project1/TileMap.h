#ifndef _TILEMAP_H_
#define _TILEMAP_H_

#include "Graphics.h"

const unsigned int TILEMAP_SIZEW = 10;
const unsigned int TILEMAP_SIZEH = 7;

class TileMap
{
private:
	enum TILE
	{
		DIRT,
		SAND,
		GRASS,

		SIZE
	};

	struct Layer
	{
		int iRow = NULL, iCollumn = NULL;
	};
	std::vector<std::vector<Layer>> m_voLayer;

	GLSurface m_glSurfaceEnviorment;
	GLSurface m_glSurfaceDirt, m_glSurfaceSand, m_glSurfaceGrass;

public:
	void Draw();

	TileMap(const std::string ac_sTileFile, const std::string ac_sImageFile);
	TileMap();
	~TileMap();
};

#endif // _TILEMAP_H_