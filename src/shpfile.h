#pragma once

#include <fstream>
#include <stdint.h>
#include <string>
#include <png.hpp>

#pragma pack(push, 1)
struct ShpHeader
{
	int32_t width;
	int32_t height;
	int32_t length;
};
#pragma pack(pop)

class ShpFile
{
private:
	int32_t numImages;
	std::vector<png::image<png::rgb_pixel>> images;

public:
	ShpFile(std::ifstream& in);
	~ShpFile(void);

	// Saves the image at the specified index from this SHP to a file.
	void saveAsPng(int idx, const std::string& filename);
	int32_t count() const { return numImages; }
};