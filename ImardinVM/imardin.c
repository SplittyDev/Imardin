#ifndef __IMARDIN_IMARDIN_H
#define __IMARDIN_IMARDIN_H

void Fail (char* errormessage)
{
	printf ("IMARDIN> ERROR: %s\n", errormessage);
	exit (1);
}

void Warning (char* warningmessage)
{
	printf ("IMARDIN> WARNING: %s\n", warningmessage);
}

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "opcodes.c"
#include "stack.c"
#include "syscalls.c"
#include "instructions.c"

void InitializeVM (int32_t memorysize)
{
	Memory = (char*) malloc (memorysize);
	Stack = (char*) malloc (1024);
	InitializeSyscalls ();
}

void RunVM (uint32_t origin)
{
	pos = origin;

	while (Memory[pos] != 0)
	{
		char opcode = Memory[pos];
		pos++;
		char length = Memory[pos];
		pos++;

		switch (opcode)
		{
			case PUSH   : _PUSH 	(length); 				break;
			case POP	: _POP		(length); 				break;
			case SSS	: Warning   ("Unimplemented: SSS"); break;
			case LSS	: Warning   ("Unimplemented: LSS"); break;
			case SSP	: Warning   ("Unimplemented: SSP"); break;
			case LSP	: Warning   ("Unimplemented: LSP"); break;
			case STORE	: _STORE	(length);				break;
			case LOAD	: _LOAD		(length);				break;
			case BEQ	: _BEQ		();						break;
			case BNE	: _BNE 		();						break;
			case BGT	: _BGT		();						break;
			case BLT	: _BLT		();						break;
			case BZ		: _BZ		();						break;
			case BNZ	: _BNZ		();						break;
			case BRA	: _BRA		();						break;
			case BSR	: _BSR		();						break;
			case ADD	: _ADD		();						break;
			case FADD	: _FADD		();						break;
			case SUB	: _SUB		();						break;
			case FSUB	: _FSUB		();						break;
			case MUL	: _MUL		();						break;
			case FMUL	: _FMUL		();						break;
			case DIV	: _DIV		();						break;
			case FDIV	: _FDIV		();						break;
			case SYSF	: _SYSF		();						break;
			case AND	: _AND		();						break;
			case OR		: _OR		();						break;
			case XOR	: _XOR		();						break;
			default     : Warning   ("Invalid opcode!");    break;
		}
	}
}

#endif
