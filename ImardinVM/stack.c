#ifndef __IMARDIN_STACK_H
#define __IMARDIN_STACK_H

int Stackseg = 0;
int StackPointer = 0;
char* Stack = NULL;
int CallPointer = 0;

void PushInt64(uint64_t qword)
{
	((uint64_t*)(Memory + Stackseg + StackPointer))[0] = qword;
	StackPointer += 8;
}

void PushInt32(uint32_t dword)
{
	((uint32_t*)(Memory + Stackseg + StackPointer))[0] = dword;
	StackPointer += 4;
}

void PushInt16(uint16_t word)
{
	((uint16_t*)(Memory + Stackseg + StackPointer))[0] = word;
	StackPointer += 2;
}

void PushInt8(uint8_t byte)
{
	Memory[Stackseg + StackPointer] = byte;
	StackPointer++;
}

uint64_t PopInt64()
{
	StackPointer = StackPointer - 8;
	return ((uint64_t*)(Memory + Stackseg + StackPointer))[0];

}

uint32_t PopInt32()
{
	StackPointer -= 4;
	return ((uint32_t*)(Memory + Stackseg + StackPointer))[0];

}

uint16_t PopInt16()
{
	StackPointer -= 2;
	return ((uint16_t*)(Memory + Stackseg + StackPointer))[0];
}

uint8_t PopInt8()
{
	StackPointer--;
	return (uint8_t)(Memory[Stackseg + StackPointer ]);
}

#endif
