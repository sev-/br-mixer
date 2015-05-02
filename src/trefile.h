#pragma once

#include <stdint.h>
#include <fstream>
#include <vector>

class TreFile
{
private:
	std::ifstream& in;
	int32_t numEntries;
	int32_t length; // length of the dat file
	std::vector<int32_t> indexes;
	std::vector<int32_t> offsets;	

public:
	TreFile(std::ifstream& in, int32_t length);
	~TreFile(void);

	int32_t count(void) const { return numEntries; }
	std::string loadStringEntry(int i);
};