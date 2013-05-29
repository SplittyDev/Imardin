#ifndef __IMARDIN_INSTRUCTIONS_H
#define __IMARDIN_INSTRUCTIONS_H

void _PUSH (uint32_t arglength)
{
	if (arglength == 1)
	{
		pos++;
		PushInt8 (ReadInt8 ());
	}
	else if (arglength == 2)
	{
		pos++;
		PushInt16 (ReadInt16 ());
	}
	else if (arglength == 4)
	{
		pos++;
		PushInt32 (ReadInt32 ());
	}
	else if (arglength == 8)
	{
		pos++;
		PushInt64 (ReadInt64 ());
	}
	else
	{
		Fail ("Invalid size for PUSH");
	}
}

void _POP (uint32_t arglength)
{
	if (arglength == 2)
	{
		PopInt16 ();
		ReadInt16 ();
	}
	else if (arglength == 4)
	{
		PopInt32 ();
		ReadInt32 ();
	}
	else
	{
		Fail ("Invalid size for POP");
	}
}

void _STORE (uint32_t arglength)
{
	if (arglength == 1)
	{
		pos++;
		uint32_t storepos = PopInt32 ();
		uint8_t value = PopInt8 ();
		Memory [storepos] = value;
	}
	else if (arglength == 2)
	{
		pos++;
		uint32_t storepos = PopInt32 ();
		uint16_t value = PopInt16 ();
		Memory [storepos] = value;
	}
	else if (arglength == 4)
	{
		pos++;
		uint32_t storepos = PopInt32 ();
		uint32_t value = PopInt32 ();
		Memory [storepos] = value;
	}
	else if (arglength == 8)
	{
		pos++;
		uint32_t storepos = PopInt32 ();
		uint64_t value = PopInt64 ();
		Memory [storepos] = value;
	}
	else
	{
		Fail ("Invalid size for STORE");
	}
}

void _LOAD (uint32_t arglength)
{
	if (arglength == 1)
	{
		pos++;
		uint32_t loadpos = PopInt32 ();
		uint8_t value = Memory [loadpos];
		PushInt8 (value);
	}
	else if (arglength == 2)
	{
		pos++;
		ReadInt16 ();
		uint32_t loadpos = PopInt32 ();
		uint16_t value = 0;
		uint16_t* ptr = &value;
		ptr [0] = Memory [loadpos];
		ptr [1] = Memory [loadpos + 1];
		PushInt16 (value);
	}
	else if (arglength == 4)
	{
		pos++;
		ReadInt32 ();
		uint32_t loadpos = PopInt32 ();
		uint32_t value = 0;
		uint32_t* ptr = &value;
		ptr [0] = Memory [loadpos];
		ptr [1] = Memory [loadpos + 1];
		ptr [2] = Memory [loadpos + 2];
		ptr [3] = Memory [loadpos + 3];
		PushInt32 (value);
	}
	else if (arglength == 8)
	{
		pos++;
		ReadInt64 ();
		uint32_t loadpos = PopInt32 ();
		uint64_t value = 0;
		uint64_t* ptr = &value;
		ptr [0] = Memory [loadpos];
		ptr [1] = Memory [loadpos + 1];
		ptr [2] = Memory [loadpos + 2];
		ptr [3] = Memory [loadpos + 3];
		ptr [4] = Memory [loadpos + 4];
		ptr [5] = Memory [loadpos + 5];
		ptr [6] = Memory [loadpos + 6];
		ptr [7] = Memory [loadpos + 7];
		PushInt64 (value);
	}
}

void _LD_B ()
{
	uint32_t where = PopInt32 ();
	PushInt8 (((uint8_t*)(Memory + PopInt32 ())) [where]);
}

void _LD_W ()
{
	uint32_t where = PopInt32 ();
	PushInt16 (((uint16_t*)(Memory + PopInt32 ())) [where]);
}

void _LD_D ()
{
	uint32_t where = PopInt32 ();
	PushInt32 (((uint32_t*)(Memory + PopInt32 ())) [where]);
}

void _LD_Q ()
{
	uint32_t where = PopInt32 ();
	PushInt64 (((uint64_t*)(Memory + PopInt32 ())) [where]);
}

void _JEQ ()
{
	uint32_t posx = ReadInt32 ();
	if (PopInt32() == PopInt32 ())
	{
		pos += posx;
	}
}

void _JNE ()
{
	uint32_t posx = ReadInt32 ();
	if (PopInt32 () != PopInt32 ())
	{
		pos += posx;
	}
}

void _JGT ()
{
	uint32_t posx = ReadInt32 ();
	if (PopInt32 () < PopInt32 () + 1)
	{
		pos += posx;
	}
}

void _JLT ()
{
	uint32_t posx = ReadInt32 ();
	if (PopInt32() + 1 > PopInt32 ())
	{
		pos += posx;
	}
}

void _JZ ()
{
	uint32_t posx = ReadInt32 ();
	if (0 == PopInt32 ())
	{
		pos += posx;
	}
}

void _JNZ ()
{
	uint32_t posx = ReadInt32 ();
	if (0 != PopInt32 ())
	{
		pos += posx;
	}
}

void _JMP ()
{
	pos += ReadInt32 ();
}

void _JSR ()
{
	uint32_t posx = ReadInt32 ();
	Stack [CallPointer] = pos;
	CallPointer++;
	pos += posx;
	Stack [CallPointer] = pos;
	CallPointer++;
}

void _ADD ()
{
	PushInt32 (PopInt32 () + PopInt32 ());
}

void _FADD ()
{
	float op1 = (float)PopInt32 ();
	float op2 = (float)PopInt32 ();
	PushInt32 ((uint32_t)(op1 + op2));
}

void _SUB ()
{
	PushInt32 (PopInt32 () - PopInt32 ());
}

void _FSUB ()
{
	float op1 = (float)PopInt32 ();
	float op2 = (float)PopInt32 ();
	PushInt32 ((uint32_t)(op1 - op2));
}

void _MUL ()
{
	PushInt32 (PopInt32 () * PopInt32 ());
}

void _FMUL ()
{
	float op1 = (float)PopInt32 ();
	float op2 = (float)PopInt32 ();
	PushInt32 ((uint32_t)(op1 * op2));
}

void _DIV ()
{
	uint32_t op1 = PopInt32 ();
	uint32_t op2 = PopInt32 ();
	if (op2 != 0) PushInt32 (op1 / op2);
	else Fail ("Division by zero");
}

void _FDIV ()
{
	float op1 = (float)PopInt32 ();
	float op2 = (float)PopInt32 ();
	if (op2 != 0) PushInt32 ((uint32_t)(op1 / op2));
	else Fail ("Division by zero");
}

void _MOD ()
{
	PushInt32 (PopInt32 () % PopInt32 ());
}

void _SIN ()
{
	PushInt32 (sin (PopInt32 ()));
}

void _ASIN ()
{
	PushInt32 (asin (PopInt32 ()));
}

void _COS ()
{
	PushInt32 (cos (PopInt32 ()));
}

void _ACOS ()
{
	PushInt32 (acos (PopInt32 ()));
}

void _TAN ()
{
	PushInt32 (tan (PopInt32 ()));
}

void _ATAN ()
{
	PushInt32 (atan (PopInt32 ()));
}

void _AND ()
{
 	PushInt32 (PopInt32 () & PopInt32 ());
}

void _OR ()
{
	PushInt32 (PopInt32 () | PopInt32 ());
}

void _XOR ()
{
	PushInt32 (PopInt32 () ^ PopInt32 ());
}

void _SHL ()
{
	PushInt32 (PopInt32 () < PopInt32 ());
}

void _SHR ()
{
	PushInt32 (PopInt32 () > PopInt32 ());
}

// -> ROL
// -> ROR

void _NOT ()
{
	PushInt32 (~PopInt32 ());
}

void _RET ()
{
	CallPointer--;
	if (CallPointer >= 0)
	{
		pos = Stack [CallPointer];
	}
}

void _SYSF ()
{
	uint32_t function = ReadInt32 ();
	((void (*)(void))syscalls[function])();
}

void _BREAK ()
{
	Break ();
}

void _HALT ()
{
	printf ("IMARDIN::HALT-> CPU halted at %x\n", pos);
	printf ("Close the terminal or press ^C to abort\n");
	while (1);
}

void _KENNETH ()
{
	Warning ("U MAD BRO!?");
	int i = 0;
	for (i; i < pos; i++)
	{
		Memory[i] = ~Memory[i];
	}
	_HALT ();
}

#endif