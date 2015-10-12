////////////////////////////////////////////////////////////
// File: TileMap.cpp
// Author: Ben Odom
// Date Created: 10/01/2015
////////////////////////////////////////////////////////////

#include "TileMap.h"



void TileMap::Draw()
{
	for (int i = 0; i < TILEMAP_SIZEH; ++i)
	{
		for (int j = 0; j < TILEMAP_SIZEW; ++j)
		{
			switch (m_voLayer[i][j].iRow)
			{
			case 0: // This game only has one real row of tiles, so this is the only one used
			{
				switch (m_voLayer[i][j].iCollumn)
				{
				case 0: Graphics::DrawSurface(m_glSurfaceDirt, (j * 128) + 64, (i * 128) + 64); break;  // Found Dirt
				case 1: Graphics::DrawSurface(m_glSurfaceSand, (j * 128) + 64, (i * 128) + 64); break;  // Found Sand
				case 2: Graphics::DrawSurface(m_glSurfaceGrass, (j * 128) + 64, (i * 128) + 64); break; // Found Grass

				default: break;
				}
			}
			break;
			case 1: break;
			case 2: break;

			default: break;
			}
		}
	}
}

TileMap::TileMap(const std::string ac_sTileFile, const std::string ac_sImageFile)
{
	FILE *File; // The text file for the tile set
	fopen_s(&File, ac_sTileFile.c_str(), "r"); // Loading the text file for the tile set

	if (File != NULL)
	{
		Layer *oTemp = new Layer;
		std::vector<Layer> voLayer;
		for (int i = 0; i < TILEMAP_SIZEH; ++i)
		{
			for (int j = 0; j < TILEMAP_SIZEW; ++j)
			{
				fscanf_s(File, "%d:%d  ", &oTemp->iRow, &oTemp->iCollumn);
				voLayer.push_back(*oTemp);
			}
			fscanf_s(File, "\n");

			m_voLayer.push_back(voLayer);
			voLayer.clear();
		}
		fclose(File);
	}
	else
		printf("Error opening \"%s\" make sure the file exists...", ac_sTileFile.c_str());

	m_glSurfaceEnviorment = Graphics::LoadSurface(ac_sImageFile);

	m_glSurfaceDirt = m_glSurfaceEnviorment;
	m_glSurfaceSand = m_glSurfaceEnviorment;
	m_glSurfaceGrass = m_glSurfaceEnviorment;

	// Set the offsets for each different tile
	m_glSurfaceDirt.centerY = 64.0f;
	m_glSurfaceSand.offsetH = 192.0f;
	m_glSurfaceGrass.offsetH = 320.0f;

	m_glSurfaceSand.offsetY = 128.0f;
	m_glSurfaceGrass.offsetY = 256.0f;
}
TileMap::TileMap()
{

}
TileMap::~TileMap()
{

}
