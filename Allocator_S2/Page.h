#pragma once
#include "Block.h"
#include <vector>


using namespace std;
class Page
{
	size_t location;
	unsigned short int size;
	state pageState = _free;
	unsigned short blocks = 0;
	unsigned short blockSize = 0;
	unsigned short freeBlocks = 0;
	vector<Block> blocksVector = vector<Block>();
public:
	Page(size_t location, unsigned short size);
	~Page();

	size_t getLocation() const;
	void setPageState(state newState);
	state getPageState() const;
	bool isFree() const;
	void setBlockState(size_t location, state newState);
	//void setBlockSize(unsigned short newBlockSize);
	//unsigned short getBlockSize() const;

	// build a method, which returns link to free 
	// block in this page, decrementing freeBlocks
	// and making the block busy state
	// or returns 0 if there are no free or suitable
	// sized blocks

	bool findPageForBlock(unsigned short size) const;
	void buildVectorOfBlocks();
	void cutIntoBlocks(unsigned short blockSize);
	void* allocateBlock();
	void* cutAndAlloc(unsigned short blockSize);

};

