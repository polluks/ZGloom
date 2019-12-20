#include <cstdint>

#include "gloommaths.h"

namespace GloomMaths
{
	static const uint16_t camrots[256][4] = {
		{ 0x7FFE, 0x0000, 0x0000, 0x7FFE },
		{ 0x7FF4, 0xFCDC, 0x0323, 0x7FF4 },
		{ 0x7FD6, 0xF9B8, 0x0647, 0x7FD6 },
		{ 0x7FA5, 0xF695, 0x096A, 0x7FA5 },
		{ 0x7F60, 0xF374, 0x0C8B, 0x7F60 },
		{ 0x7F07, 0xF055, 0x0FAA, 0x7F07 },
		{ 0x7E9B, 0xED38, 0x12C7, 0x7E9B },
		{ 0x7E1B, 0xEA1E, 0x15E1, 0x7E1B },
		{ 0x7D88, 0xE707, 0x18F8, 0x7D88 },
		{ 0x7CE1, 0xE3F4, 0x1C0B, 0x7CE1 },
		{ 0x7C27, 0xE0E6, 0x1F19, 0x7C27 },
		{ 0x7B5B, 0xDDDD, 0x2222, 0x7B5B },
		{ 0x7A7B, 0xDAD8, 0x2527, 0x7A7B },
		{ 0x7988, 0xD7DA, 0x2825, 0x7988 },
		{ 0x7882, 0xD4E1, 0x2B1E, 0x7882 },
		{ 0x776A, 0xD1EF, 0x2E10, 0x776A },
		{ 0x763F, 0xCF05, 0x30FA, 0x763F },
		{ 0x7502, 0xCC22, 0x33DD, 0x7502 },
		{ 0x73B3, 0xC946, 0x36B9, 0x73B3 },
		{ 0x7253, 0xC674, 0x398B, 0x7253 },
		{ 0x70E0, 0xC3AA, 0x3C55, 0x70E0 },
		{ 0x6F5D, 0xC0E9, 0x3F16, 0x6F5D },
		{ 0x6DC8, 0xBE33, 0x41CC, 0x6DC8 },
		{ 0x6C22, 0xBB86, 0x4479, 0x6C22 },
		{ 0x6A6B, 0xB8E4, 0x471B, 0x6A6B },
		{ 0x68A4, 0xB64D, 0x49B2, 0x68A4 },
		{ 0x66CD, 0xB3C1, 0x4C3E, 0x66CD },
		{ 0x64E6, 0xB141, 0x4EBE, 0x64E6 },
		{ 0x62F0, 0xAECD, 0x5132, 0x62F0 },
		{ 0x60EA, 0xAC66, 0x5399, 0x60EA },
		{ 0x5ED5, 0xAA0B, 0x55F4, 0x5ED5 },
		{ 0x5CB2, 0xA7BE, 0x5841, 0x5CB2 },
		{ 0x5A80, 0xA57F, 0x5A80, 0x5A80 },
		{ 0x5841, 0xA34D, 0x5CB2, 0x5841 },
		{ 0x55F4, 0xA12A, 0x5ED5, 0x55F4 },
		{ 0x5399, 0x9F15, 0x60EA, 0x5399 },
		{ 0x5132, 0x9D0F, 0x62F0, 0x5132 },
		{ 0x4EBE, 0x9B19, 0x64E6, 0x4EBE },
		{ 0x4C3E, 0x9932, 0x66CD, 0x4C3E },
		{ 0x49B2, 0x975B, 0x68A4, 0x49B2 },
		{ 0x471B, 0x9594, 0x6A6B, 0x471B },
		{ 0x4479, 0x93DD, 0x6C22, 0x4479 },
		{ 0x41CC, 0x9237, 0x6DC8, 0x41CC },
		{ 0x3F16, 0x90A2, 0x6F5D, 0x3F16 },
		{ 0x3C55, 0x8F1F, 0x70E0, 0x3C55 },
		{ 0x398B, 0x8DAC, 0x7253, 0x398B },
		{ 0x36B9, 0x8C4C, 0x73B3, 0x36B9 },
		{ 0x33DD, 0x8AFD, 0x7502, 0x33DD },
		{ 0x30FA, 0x89C0, 0x763F, 0x30FA },
		{ 0x2E10, 0x8895, 0x776A, 0x2E10 },
		{ 0x2B1E, 0x877D, 0x7882, 0x2B1E },
		{ 0x2825, 0x8677, 0x7988, 0x2825 },
		{ 0x2527, 0x8584, 0x7A7B, 0x2527 },
		{ 0x2222, 0x84A4, 0x7B5B, 0x2222 },
		{ 0x1F19, 0x83D8, 0x7C27, 0x1F19 },
		{ 0x1C0B, 0x831E, 0x7CE1, 0x1C0B },
		{ 0x18F8, 0x8277, 0x7D88, 0x18F8 },
		{ 0x15E1, 0x81E4, 0x7E1B, 0x15E1 },
		{ 0x12C7, 0x8164, 0x7E9B, 0x12C7 },
		{ 0x0FAA, 0x80F8, 0x7F07, 0x0FAA },
		{ 0x0C8B, 0x809F, 0x7F60, 0x0C8B },
		{ 0x096A, 0x805A, 0x7FA5, 0x096A },
		{ 0x0647, 0x8029, 0x7FD6, 0x0647 },
		{ 0x0323, 0x800B, 0x7FF4, 0x0323 },
		{ 0x0000, 0x8002, 0x7FFE, 0x0000 },
		{ 0xFCDC, 0x800B, 0x7FF4, 0xFCDC },
		{ 0xF9B8, 0x8029, 0x7FD6, 0xF9B8 },
		{ 0xF695, 0x805A, 0x7FA5, 0xF695 },
		{ 0xF374, 0x809F, 0x7F60, 0xF374 },
		{ 0xF055, 0x80F8, 0x7F07, 0xF055 },
		{ 0xED38, 0x8164, 0x7E9B, 0xED38 },
		{ 0xEA1E, 0x81E4, 0x7E1B, 0xEA1E },
		{ 0xE707, 0x8277, 0x7D88, 0xE707 },
		{ 0xE3F4, 0x831E, 0x7CE1, 0xE3F4 },
		{ 0xE0E6, 0x83D8, 0x7C27, 0xE0E6 },
		{ 0xDDDD, 0x84A4, 0x7B5B, 0xDDDD },
		{ 0xDAD8, 0x8584, 0x7A7B, 0xDAD8 },
		{ 0xD7DA, 0x8677, 0x7988, 0xD7DA },
		{ 0xD4E1, 0x877D, 0x7882, 0xD4E1 },
		{ 0xD1EF, 0x8895, 0x776A, 0xD1EF },
		{ 0xCF05, 0x89C0, 0x763F, 0xCF05 },
		{ 0xCC22, 0x8AFD, 0x7502, 0xCC22 },
		{ 0xC946, 0x8C4C, 0x73B3, 0xC946 },
		{ 0xC674, 0x8DAC, 0x7253, 0xC674 },
		{ 0xC3AA, 0x8F1F, 0x70E0, 0xC3AA },
		{ 0xC0E9, 0x90A2, 0x6F5D, 0xC0E9 },
		{ 0xBE33, 0x9237, 0x6DC8, 0xBE33 },
		{ 0xBB86, 0x93DD, 0x6C22, 0xBB86 },
		{ 0xB8E4, 0x9594, 0x6A6B, 0xB8E4 },
		{ 0xB64D, 0x975B, 0x68A4, 0xB64D },
		{ 0xB3C1, 0x9932, 0x66CD, 0xB3C1 },
		{ 0xB141, 0x9B19, 0x64E6, 0xB141 },
		{ 0xAECD, 0x9D0F, 0x62F0, 0xAECD },
		{ 0xAC66, 0x9F15, 0x60EA, 0xAC66 },
		{ 0xAA0B, 0xA12A, 0x5ED5, 0xAA0B },
		{ 0xA7BE, 0xA34D, 0x5CB2, 0xA7BE },
		{ 0xA57F, 0xA57F, 0x5A80, 0xA57F },
		{ 0xA34D, 0xA7BE, 0x5841, 0xA34D },
		{ 0xA12A, 0xAA0B, 0x55F4, 0xA12A },
		{ 0x9F15, 0xAC66, 0x5399, 0x9F15 },
		{ 0x9D0F, 0xAECD, 0x5132, 0x9D0F },
		{ 0x9B19, 0xB141, 0x4EBE, 0x9B19 },
		{ 0x9932, 0xB3C1, 0x4C3E, 0x9932 },
		{ 0x975B, 0xB64D, 0x49B2, 0x975B },
		{ 0x9594, 0xB8E4, 0x471B, 0x9594 },
		{ 0x93DD, 0xBB86, 0x4479, 0x93DD },
		{ 0x9237, 0xBE33, 0x41CC, 0x9237 },
		{ 0x90A2, 0xC0E9, 0x3F16, 0x90A2 },
		{ 0x8F1F, 0xC3AA, 0x3C55, 0x8F1F },
		{ 0x8DAC, 0xC674, 0x398B, 0x8DAC },
		{ 0x8C4C, 0xC946, 0x36B9, 0x8C4C },
		{ 0x8AFD, 0xCC22, 0x33DD, 0x8AFD },
		{ 0x89C0, 0xCF05, 0x30FA, 0x89C0 },
		{ 0x8895, 0xD1EF, 0x2E10, 0x8895 },
		{ 0x877D, 0xD4E1, 0x2B1E, 0x877D },
		{ 0x8677, 0xD7DA, 0x2825, 0x8677 },
		{ 0x8584, 0xDAD8, 0x2527, 0x8584 },
		{ 0x84A4, 0xDDDD, 0x2222, 0x84A4 },
		{ 0x83D8, 0xE0E6, 0x1F19, 0x83D8 },
		{ 0x831E, 0xE3F4, 0x1C0B, 0x831E },
		{ 0x8277, 0xE707, 0x18F8, 0x8277 },
		{ 0x81E4, 0xEA1E, 0x15E1, 0x81E4 },
		{ 0x8164, 0xED38, 0x12C7, 0x8164 },
		{ 0x80F8, 0xF055, 0x0FAA, 0x80F8 },
		{ 0x809F, 0xF374, 0x0C8B, 0x809F },
		{ 0x805A, 0xF695, 0x096A, 0x805A },
		{ 0x8029, 0xF9B8, 0x0647, 0x8029 },
		{ 0x800B, 0xFCDC, 0x0323, 0x800B },
		{ 0x8002, 0x0000, 0x0000, 0x8002 },
		{ 0x800B, 0x0323, 0xFCDC, 0x800B },
		{ 0x8029, 0x0647, 0xF9B8, 0x8029 },
		{ 0x805A, 0x096A, 0xF695, 0x805A },
		{ 0x809F, 0x0C8B, 0xF374, 0x809F },
		{ 0x80F8, 0x0FAA, 0xF055, 0x80F8 },
		{ 0x8164, 0x12C7, 0xED38, 0x8164 },
		{ 0x81E4, 0x15E1, 0xEA1E, 0x81E4 },
		{ 0x8277, 0x18F8, 0xE707, 0x8277 },
		{ 0x831E, 0x1C0B, 0xE3F4, 0x831E },
		{ 0x83D8, 0x1F19, 0xE0E6, 0x83D8 },
		{ 0x84A4, 0x2222, 0xDDDD, 0x84A4 },
		{ 0x8584, 0x2527, 0xDAD8, 0x8584 },
		{ 0x8677, 0x2825, 0xD7DA, 0x8677 },
		{ 0x877D, 0x2B1E, 0xD4E1, 0x877D },
		{ 0x8895, 0x2E10, 0xD1EF, 0x8895 },
		{ 0x89C0, 0x30FA, 0xCF05, 0x89C0 },
		{ 0x8AFD, 0x33DD, 0xCC22, 0x8AFD },
		{ 0x8C4C, 0x36B9, 0xC946, 0x8C4C },
		{ 0x8DAC, 0x398B, 0xC674, 0x8DAC },
		{ 0x8F1F, 0x3C55, 0xC3AA, 0x8F1F },
		{ 0x90A2, 0x3F16, 0xC0E9, 0x90A2 },
		{ 0x9237, 0x41CC, 0xBE33, 0x9237 },
		{ 0x93DD, 0x4479, 0xBB86, 0x93DD },
		{ 0x9594, 0x471B, 0xB8E4, 0x9594 },
		{ 0x975B, 0x49B2, 0xB64D, 0x975B },
		{ 0x9932, 0x4C3E, 0xB3C1, 0x9932 },
		{ 0x9B19, 0x4EBE, 0xB141, 0x9B19 },
		{ 0x9D0F, 0x5132, 0xAECD, 0x9D0F },
		{ 0x9F15, 0x5399, 0xAC66, 0x9F15 },
		{ 0xA12A, 0x55F4, 0xAA0B, 0xA12A },
		{ 0xA34D, 0x5841, 0xA7BE, 0xA34D },
		{ 0xA57F, 0x5A80, 0xA57F, 0xA57F },
		{ 0xA7BE, 0x5CB2, 0xA34D, 0xA7BE },
		{ 0xAA0B, 0x5ED5, 0xA12A, 0xAA0B },
		{ 0xAC66, 0x60EA, 0x9F15, 0xAC66 },
		{ 0xAECD, 0x62F0, 0x9D0F, 0xAECD },
		{ 0xB141, 0x64E6, 0x9B19, 0xB141 },
		{ 0xB3C1, 0x66CD, 0x9932, 0xB3C1 },
		{ 0xB64D, 0x68A4, 0x975B, 0xB64D },
		{ 0xB8E4, 0x6A6B, 0x9594, 0xB8E4 },
		{ 0xBB86, 0x6C22, 0x93DD, 0xBB86 },
		{ 0xBE33, 0x6DC8, 0x9237, 0xBE33 },
		{ 0xC0E9, 0x6F5D, 0x90A2, 0xC0E9 },
		{ 0xC3AA, 0x70E0, 0x8F1F, 0xC3AA },
		{ 0xC674, 0x7253, 0x8DAC, 0xC674 },
		{ 0xC946, 0x73B3, 0x8C4C, 0xC946 },
		{ 0xCC22, 0x7502, 0x8AFD, 0xCC22 },
		{ 0xCF05, 0x763F, 0x89C0, 0xCF05 },
		{ 0xD1EF, 0x776A, 0x8895, 0xD1EF },
		{ 0xD4E1, 0x7882, 0x877D, 0xD4E1 },
		{ 0xD7DA, 0x7988, 0x8677, 0xD7DA },
		{ 0xDAD8, 0x7A7B, 0x8584, 0xDAD8 },
		{ 0xDDDD, 0x7B5B, 0x84A4, 0xDDDD },
		{ 0xE0E6, 0x7C27, 0x83D8, 0xE0E6 },
		{ 0xE3F4, 0x7CE1, 0x831E, 0xE3F4 },
		{ 0xE707, 0x7D88, 0x8277, 0xE707 },
		{ 0xEA1E, 0x7E1B, 0x81E4, 0xEA1E },
		{ 0xED38, 0x7E9B, 0x8164, 0xED38 },
		{ 0xF055, 0x7F07, 0x80F8, 0xF055 },
		{ 0xF374, 0x7F60, 0x809F, 0xF374 },
		{ 0xF695, 0x7FA5, 0x805A, 0xF695 },
		{ 0xF9B8, 0x7FD6, 0x8029, 0xF9B8 },
		{ 0xFCDC, 0x7FF4, 0x800B, 0xFCDC },
		{ 0x0000, 0x7FFE, 0x8002, 0x0000 },
		{ 0x0323, 0x7FF4, 0x800B, 0x0323 },
		{ 0x0647, 0x7FD6, 0x8029, 0x0647 },
		{ 0x096A, 0x7FA5, 0x805A, 0x096A },
		{ 0x0C8B, 0x7F60, 0x809F, 0x0C8B },
		{ 0x0FAA, 0x7F07, 0x80F8, 0x0FAA },
		{ 0x12C7, 0x7E9B, 0x8164, 0x12C7 },
		{ 0x15E1, 0x7E1B, 0x81E4, 0x15E1 },
		{ 0x18F8, 0x7D88, 0x8277, 0x18F8 },
		{ 0x1C0A, 0x7CE1, 0x831E, 0x1C0A },
		{ 0x1F19, 0x7C27, 0x83D8, 0x1F19 },
		{ 0x2222, 0x7B5B, 0x84A4, 0x2222 },
		{ 0x2527, 0x7A7B, 0x8584, 0x2527 },
		{ 0x2825, 0x7988, 0x8677, 0x2825 },
		{ 0x2B1E, 0x7882, 0x877D, 0x2B1E },
		{ 0x2E10, 0x776A, 0x8895, 0x2E10 },
		{ 0x30FA, 0x763F, 0x89C0, 0x30FA },
		{ 0x33DD, 0x7502, 0x8AFD, 0x33DD },
		{ 0x36B9, 0x73B3, 0x8C4C, 0x36B9 },
		{ 0x398B, 0x7253, 0x8DAC, 0x398B },
		{ 0x3C55, 0x70E0, 0x8F1F, 0x3C55 },
		{ 0x3F16, 0x6F5D, 0x90A2, 0x3F16 },
		{ 0x41CC, 0x6DC8, 0x9237, 0x41CC },
		{ 0x4479, 0x6C22, 0x93DD, 0x4479 },
		{ 0x471B, 0x6A6B, 0x9594, 0x471B },
		{ 0x49B2, 0x68A4, 0x975B, 0x49B2 },
		{ 0x4C3E, 0x66CD, 0x9932, 0x4C3E },
		{ 0x4EBE, 0x64E6, 0x9B19, 0x4EBE },
		{ 0x5132, 0x62F0, 0x9D0F, 0x5132 },
		{ 0x5399, 0x60EA, 0x9F15, 0x5399 },
		{ 0x55F4, 0x5ED5, 0xA12A, 0x55F4 },
		{ 0x5841, 0x5CB2, 0xA34D, 0x5841 },
		{ 0x5A80, 0x5A80, 0xA57F, 0x5A80 },
		{ 0x5CB2, 0x5841, 0xA7BE, 0x5CB2 },
		{ 0x5ED5, 0x55F4, 0xAA0B, 0x5ED5 },
		{ 0x60EA, 0x5399, 0xAC66, 0x60EA },
		{ 0x62EF, 0x5132, 0xAECD, 0x62EF },
		{ 0x64E6, 0x4EBE, 0xB141, 0x64E6 },
		{ 0x66CD, 0x4C3E, 0xB3C1, 0x66CD },
		{ 0x68A4, 0x49B2, 0xB64D, 0x68A4 },
		{ 0x6A6B, 0x471B, 0xB8E4, 0x6A6B },
		{ 0x6C22, 0x4479, 0xBB86, 0x6C22 },
		{ 0x6DC8, 0x41CC, 0xBE33, 0x6DC8 },
		{ 0x6F5D, 0x3F16, 0xC0E9, 0x6F5D },
		{ 0x70E0, 0x3C55, 0xC3AA, 0x70E0 },
		{ 0x7253, 0x398B, 0xC674, 0x7253 },
		{ 0x73B3, 0x36B9, 0xC946, 0x73B3 },
		{ 0x7502, 0x33DD, 0xCC22, 0x7502 },
		{ 0x763F, 0x30FA, 0xCF05, 0x763F },
		{ 0x776A, 0x2E10, 0xD1EF, 0x776A },
		{ 0x7882, 0x2B1E, 0xD4E1, 0x7882 },
		{ 0x7988, 0x2825, 0xD7DA, 0x7988 },
		{ 0x7A7B, 0x2527, 0xDAD8, 0x7A7B },
		{ 0x7B5B, 0x2222, 0xDDDD, 0x7B5B },
		{ 0x7C27, 0x1F19, 0xE0E6, 0x7C27 },
		{ 0x7CE1, 0x1C0B, 0xE3F4, 0x7CE1 },
		{ 0x7D88, 0x18F8, 0xE707, 0x7D88 },
		{ 0x7E1B, 0x15E1, 0xEA1E, 0x7E1B },
		{ 0x7E9B, 0x12C7, 0xED38, 0x7E9B },
		{ 0x7F07, 0x0FAA, 0xF055, 0x7F07 },
		{ 0x7F60, 0x0C8B, 0xF374, 0x7F60 },
		{ 0x7FA5, 0x096A, 0xF695, 0x7FA5 },
		{ 0x7FD6, 0x0647, 0xF9B8, 0x7FD6 },
		{ 0x7FF4, 0x0323, 0xFCDC, 0x7FF4 } };

	void GetCamRot(uint8_t ang, Quick result[4])
	{
		for (auto i = 0; i < 4; i++)
		{
			// these appear to have been shifted down by one (sign extension/overflow reasons?) compared to a Blitz quick
			// there's a lot of 'add d0, d0' in the code to compensate, possibly
			int32_t val = camrots[ang][i] << 1;
			if (val & 0x10000) val |= 0xFFFF0000;
			result[i].SetVal(val);
		}
	}
}