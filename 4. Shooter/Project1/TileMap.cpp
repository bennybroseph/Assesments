#include "TileMap.h"



void TileMap::Draw()
{
	for (int i = 0; i < TILEMAP_SIZEH; ++i)
	{
		for (int j = 0; j < TILEMAP_SIZEW; ++j)
		{
			switch (m_voLayer[i][j].iRow)
			{
			case 0:
			{
				switch (m_voLayer[i][j].iCollumn)
				{
				case 0: Graphics::DrawSurface(m_glSurfaceDirt, (j * 128) + 64, ((i+1) * 128) + 64); break;
				case 1: Graphics::DrawSurface(m_glSurfaceSand, (j * 128) + 64, ((i+1) * 128) + 64); break;
				case 2: Graphics::DrawSurface(m_glSurfaceGrass, (j * 128) + 64, ((i+1) * 128) + 64); break;

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
	FILE *File;
	fopen_s(&File, ac_sTileFile.c_str(), "r");

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

	m_glSurfaceDirt.offsetH = 128.0f;
	m_glSurfaceSand.offsetH = 128.0f;
	m_glSurfaceGrass.offsetH = 128.0f;

	m_glSurfaceSand.offsetY = 128.0f;
	m_glSurfaceGrass.offsetY = 256.0f;
}
TileMap::TileMap()
{

}
TileMap::~TileMap()
{

}
