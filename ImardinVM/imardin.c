#ifndef __IMARDIN_IMARDIN_H
#define __IMARDIN_IMARDIN_H

void Fail (char* errormessage)
{
	printf ("IMARDIN::ERROR-> %s\n", errormessage);
	exit (1);
}

void Break ()
{
	printf ("IMARDIN::BREAK-> Break at 0x%x\n", pos);
	while (1);
}

void Warning (char* warningmessage)
{
	printf ("IMARDIN::WARNING-> %s\n", warningmessage);
}

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
			case PUSH   : _PUSH 	(length); 			break;
			case POP	: _POP		(length); 			break;

			case STORE	: _STORE	(length);			break;

			case LOAD	: _LOAD		(length);			break;
			case LD_B	: _LD_B		();					break;
			case LD_W	: _LD_W		();					break;
			case LD_D	: _LD_D		();					break;
			case LD_Q	: _LD_Q		();					break;

			case JEQ	: _JEQ		();					break;
			case JNE	: _JNE 		();					break;
			case JGT	: _JGT		();					break;
			case JLT	: _JLT		();					break;
			case JZ		: _JZ		();					break;
			case JNZ	: _JNZ		();					break;
			case JSR	: _JSR		();					break;
			case JMP	: _JMP		();					break;

			case ADD	: _ADD		();					break;
			case FADD	: _FADD		();					break;
			case SUB	: _SUB		();					break;
			case FSUB	: _FSUB		();					break;
			case MUL	: _MUL		();					break;
			case FMUL	: _FMUL		();					break;
			case DIV	: _DIV		();					break;
			case FDIV	: _FDIV		();					break;
			case MOD	: _MOD		();					break;
			case SIN	: _SIN		();					break;
			case ASIN	: _ASIN		();					break;
			case COS	: _COS		();					break;
			case ACOS	: _ACOS		();					break;
			case TAN	: _TAN		();					break;
			case ATAN	: _ATAN		();					break;

			case AND	: _AND		();					break;
			case OR		: _OR		();					break;
			case XOR	: _XOR		();					break;
			case SHL	: _SHL		();					break;
			case SHR	: _SHR		();					break;
			// ROL
			// ROR
			case NOT	: _NOT		();					break;

			case SYSF	: _SYSF		();					break;
			case BREAK	: _BREAK	();					break;
			case HALT	: _HALT		();					break;
			case KENNETH: _KENNETH	();					break;

			default     : Warning   ("Invalid opcode!");	Break ();
		}
	}
}

#endif
