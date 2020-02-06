#include "hud.h"

// ripped from PPM conversion
static const uint32_t wepraw[5][81*3] =
{ 
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 153, 0, 0, 153, 0, 0,
		153, 0, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		153, 0, 0, 153, 0, 0, 255, 119, 0, 255, 136, 34, 255, 136, 34,
		153, 0, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0, 153, 0, 0,
		255, 136, 34, 238, 238, 102, 238, 238, 102, 238, 238, 102, 255, 136, 34,
		153, 0, 0, 0, 0, 0, 153, 0, 0, 153, 0, 0, 255, 136, 34,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 238, 238, 102, 255, 119, 0,
		153, 0, 0, 153, 0, 0, 255, 136, 34, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 238, 238, 102, 255, 119, 0, 153, 0, 0,
		153, 0, 0, 255, 119, 0, 238, 238, 102, 255, 255, 255, 238, 238, 102,
		255, 255, 255, 255, 136, 34, 153, 0, 0, 153, 0, 0, 153, 0, 0,
		153, 0, 0, 255, 136, 34, 238, 238, 102, 238, 238, 102, 255, 136, 34,
		255, 119, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0, 153, 0, 0,
		153, 0, 0, 153, 0, 0, 255, 136, 34, 153, 0, 0, 153, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 153, 0, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0
	},
	{
		0, 0, 0, 0, 0, 0, 0, 68, 0, 0, 136, 102, 0, 136, 102,
		0, 136, 102, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 102, 68, 136, 204, 136, 238, 238, 102, 238, 238, 102, 238, 238, 102,
		136, 204, 136, 0, 102, 68, 0, 0, 0, 0, 68, 0, 136, 204, 136,
		238, 238, 102, 238, 238, 102, 255, 255, 255, 238, 238, 102, 238, 238, 102,
		136, 204, 136, 0, 68, 0, 0, 102, 68, 136, 204, 136, 238, 238, 102,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 238, 238, 102, 238, 238, 102,
		0, 102, 68, 0, 102, 68, 238, 238, 102, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 238, 238, 102, 0, 102, 68,
		0, 102, 68, 238, 238, 102, 238, 238, 102, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 238, 238, 102, 238, 238, 102, 0, 102, 68, 0, 68, 0,
		136, 204, 136, 238, 238, 102, 238, 238, 102, 255, 255, 255, 238, 238, 102,
		238, 238, 102, 136, 204, 136, 0, 68, 0, 0, 0, 0, 0, 102, 68,
		136, 204, 136, 238, 238, 102, 238, 238, 102, 238, 238, 102, 136, 204, 136,
		0, 102, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 68, 0,
		0, 136, 102, 0, 136, 102, 0, 136, 102, 0, 68, 0, 0, 0, 0,
		0, 0, 0
	},
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 68, 0, 0, 68, 0,
		0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 136, 102, 136, 204, 136, 221, 204, 255, 136, 204, 136,
		0, 102, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 136, 204, 136,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		0, 102, 68, 0, 0, 0, 0, 68, 0, 221, 204, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 136, 204, 136,
		0, 0, 0, 0, 68, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 136, 204, 136, 0, 68, 0,
		0, 0, 0, 221, 204, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 136, 204, 136, 0, 68, 0, 0, 0, 0,
		0, 136, 102, 238, 238, 102, 238, 238, 102, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 136, 102, 136, 204, 136, 221, 204, 255, 136, 204, 136, 0, 102, 68,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 68, 0, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0
	},
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 102, 68,
		0, 102, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 136, 119, 238, 136, 204, 136, 136, 119, 238,
		85, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		136, 119, 238, 221, 204, 255, 255, 255, 255, 255, 255, 255, 221, 204, 255,
		85, 0, 153, 0, 0, 0, 0, 0, 0, 85, 51, 204, 221, 204, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 221, 204, 255,
		0, 102, 68, 0, 68, 0, 136, 119, 238, 221, 204, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 221, 204, 255, 85, 0, 153,
		0, 102, 68, 136, 119, 238, 221, 204, 255, 221, 204, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 221, 204, 255, 85, 0, 153, 0, 68, 0,
		136, 204, 136, 238, 238, 102, 255, 255, 255, 255, 255, 255, 221, 204, 255,
		221, 204, 255, 136, 119, 238, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		85, 0, 153, 136, 119, 238, 221, 204, 255, 221, 204, 255, 136, 119, 238,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 68, 0, 0, 102, 68, 0, 102, 68, 0, 0, 0,
		0, 0, 0
	},
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 85, 0, 153,
		85, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 85, 0, 153, 136, 119, 238, 221, 204, 255, 136, 119, 238,
		85, 17, 187, 0, 0, 0, 0, 0, 0, 0, 0, 0, 85, 51, 204,
		221, 204, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 221, 204, 255,
		85, 0, 153, 0, 0, 0, 0, 0, 0, 85, 51, 204, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 136, 119, 238,
		0, 0, 0, 0, 0, 0, 221, 204, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 221, 204, 255, 85, 0, 153,
		0, 0, 0, 136, 119, 238, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 136, 119, 238, 0, 0, 0, 0, 0, 0,
		85, 51, 204, 221, 204, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		221, 204, 255, 85, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		136, 119, 238, 221, 204, 255, 255, 255, 255, 221, 204, 255, 85, 51, 204,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		85, 0, 153, 85, 51, 204, 85, 0, 153, 0, 0, 0, 0, 0, 0,
		0, 0, 0
	}
};

Hud::Hud()
{
	healthbar = SDL_CreateRGBSurface(0, 2 + 25 * 2, 9, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
	healthbaron = SDL_CreateRGBSurface(0, 2 + 25 * 2, 9, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
	weaponbar = SDL_CreateRGBSurface(0, 2 + 25 * 2, 9, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);

	for (int x = 0; x < (25 * 2 + 2); x++)
	{
		for (int y = 0; y < 9; y++)
		{
			uint32_t* pix = (uint32_t*)(healthbar->pixels) + x + y*(healthbar->pitch/4);
			uint32_t* hpix = (uint32_t*)(healthbaron->pixels) + x + y*(healthbar->pitch / 4);
			uint32_t* wpix = (uint32_t*)(weaponbar->pixels) + x + y*(weaponbar->pitch / 4);

			if ((y == 0) || (x==0))
			{
				*pix = 0xFF008866;
				*hpix = 0xFF008866;
			}
			else if ((y == 8) || (x == (2*25+1)))
			{
				*pix = 0xFF004400;
				*hpix = 0xFF004400;
			}
			else if ((y == 1) || (y == 7))
			{
				*pix = (x & 1) ? 0xff5511bb : 0xff550099;
				*hpix = (x & 1) ? 0xffbb0000 : 0xff880000;
			}
			else
			{
				*pix = (x & 1) ? 0xff5533CC : 0xff5511bb;
				*hpix = (x & 1) ? 0xffff0000 : 0xffbb0000;
			}

			*wpix = *pix;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		weaponsprites[i] = SDL_CreateRGBSurface(0, 9, 9, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 9; x++)
			{
				uint32_t pix = 0xFF000000;

				pix |= wepraw[i][3 * (x + y * 9) + 0] << 16;
				pix |= wepraw[i][3 * (x + y * 9) + 1] <<  8;
				pix |= wepraw[i][3 * (x + y * 9) + 2] <<  0;
				if (pix == 0xFF000000) pix = 0;

				*((uint32_t*)(weaponsprites[i]->pixels) + x + y*weaponsprites[i]->pitch / 4) = pix;
			}
		}
	}
}

void Hud::Render(SDL_Surface* surface, int weapon, int reload, int health)
{
	SDL_Rect dstrect;
	SDL_Rect srcrect;
	dstrect.x = 10;
	dstrect.y = 2;
	dstrect.w = 25 * 2 + 2;
	dstrect.h = 8;

	srcrect.x = 0;
	srcrect.y = 0;
	srcrect.w = health * 2 + 1;
	srcrect.h = 9;

	SDL_BlitSurface(healthbar, NULL, surface, &dstrect);
	SDL_BlitSurface(healthbaron, &srcrect, surface, &dstrect);

	dstrect.y += 12;

	SDL_BlitSurface(weaponbar, NULL, surface, &dstrect);

	for (int i = 0; i < (6-reload); i++)
	{
		dstrect.x = 11 + 40 - 10 * i;
		SDL_BlitSurface(weaponsprites[weapon], NULL, surface, &dstrect);
	}
}