#ifndef __IMARDIN_MEMORY_H
#define __IMARDIN_MEMORY_H

char* Memory;
int heap = 0;
int pos = 0;

uint64_t ReadInt64 ()
{
	uint64_t ret = ((uint64_t*)(Memory + pos))[0];
	pos += 8;
	return ret;
}

uint32_t ReadInt32 ()
{
	uint32_t ret = ((uint32_t*)(Memory + pos))[0];
	pos += 4;
	return ret;
}

uint16_t ReadInt16 ()
{
	uint16_t ret = ((uint16_t*)(Memory + pos))[0];
	pos += 2;
	return ret;
}

uint8_t ReadInt8 ()
{
	uint8_t ret = ((uint8_t*)(Memory + pos))[0];
	pos++;
	return ret;
}

#endif
