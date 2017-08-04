#pragma once
#include <stdint.h>

struct sGDMode
{
	uint32_t videoModeId;
	uint32_t height;
	uint32_t width;
	uint32_t depth;
	uint8_t __unk_pad_1[20];
	uint8_t __unknown1;
	uint8_t __unk_pad_2;
	uint8_t __unknown2;
	uint8_t __unk_pad_3[11];
	uint32_t __unknown3;
};