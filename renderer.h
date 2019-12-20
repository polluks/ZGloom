#pragma once

#include <vector>
#include "gloommap.h"
#include "gloommaths.h"
#include "quick.h"
#include "objectgraphics.h"

#include "SDL.h"

class Camera
{
	public:
	Quick x;
	int16_t y;
	Quick z;
	uint8_t rot;
};

class Wall
{
public:
	int16_t wl_lsx; // leftmost screen X
	int16_t wl_rsx; // rightmost screen X
	int16_t wl_nz;	// near Z!
	int16_t wl_fz;	// far Z!
	int16_t wl_lx;	//
	int16_t wl_lz;	//
	int16_t wl_rx;	//
	int16_t wl_rz;	//
	uint16_t wl_a;	//
	uint16_t wl_b;	//
	uint32_t wl_c;	//
	uint16_t wl_sc;	//
	uint16_t wl_open;// 0 = door shut, $4000 = open!
	uint8_t wl_t[8];// textures

	// added this myself
	int16_t len;

	bool valid;
};

class Renderer
{
	public:
		void Init(SDL_Surface* nrendersurface, GloomMap* ngloommap, ObjectGraphics* nObjectGraphics);
		void Render(Camera* Camera);

	private:
		bool OriginSide(int16_t fx, int16_t fz, int16_t bx, int16_t bz);
		bool PointInFront(int16_t fx, int16_t fz, Wall& z);
		bool Intersect(int16_t t, int16_t x0, int16_t x1) { return (t >= x0) && (t <= x1); };
		void ClipWalls();
		void DrawMap();
		int16_t CastColumn(int32_t x, int16_t& zone, Quick& t);
		void DrawColumn(int32_t x, int32_t ystart, int32_t h, Column* texturedata, int32_t z, int32_t palused);
		void DrawFlat(std::vector<int32_t>& ceilend, std::vector<int32_t>& floorstart, Camera* camera);
		void Renderer::DrawObjects(Camera* camera);
		SDL_Surface* rendersurface;
		GloomMap* gloommap;
		ObjectGraphics* objectgraphics;
		std::vector<Wall> walls;
		int32_t renderwidth = 320;
		int32_t renderheight = 240;
		int32_t halfrenderwidth = 160;
		int32_t halfrenderheight = 120;
		static const uint32_t focshift = 7;
		std::vector<Quick> castgrads;
		std::vector<int32_t> zbuff;

		// I'm not sure how gloom does screen dimming, I've implemented my own lookup tables
		int32_t darkpalettes[16][16];
};