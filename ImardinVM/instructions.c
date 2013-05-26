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

// -> SSS
// -> LSS
// -> SSP
// -> LSP

void _STORE (uint32_t arglength)
{
	if (arglength == 1)
	{
		pos++;
		int32_t storepos = PopInt32 ();
		int8_t value = PopInt8 ();
		Memory [storepos] = value;
	}
	else if (arglength == 2)
	{
		pos++;
		int32_t storepos = PopInt32 ();
		int16_t value = PopInt16 ();
		Memory [storepos] = value;
	}
	else if (arglength == 4)
	{
		pos++;
		int32_t storepos = PopInt32 ();
		int32_t value = PopInt32 ();
		Memory [storepos] = value;
	}
	else if (arglength == 8)
	{
		pos++;
		int32_t storepos = PopInt32 ();
		int64_t value = PopInt64 ();
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
		int32_t loadpos = PopInt32 ();
		int8_t value = Memory [loadpos];
		PushInt8 (value);
	}
	else if (arglength == 2)
	{
		pos++;
		ReadInt16 ();
		int32_t loadpos = PopInt32 ();
		int16_t value = 0;
		char* ptr = &value;
		ptr[0] = Memory [loadpos];
		ptr[1] = Memory [loadpos + 1];
		PushInt16 (value);
	}
	else if (arglength == 4)
	{
		pos++;
		ReadInt32 ();
		int32_t loadpos = PopInt32 ();
		int32_t value = 0;
		char* ptr = &value;
		ptr[0] = Memory [loadpos];
		ptr[1] = Memory [loadpos + 1];
		ptr[2] = Memory [loadpos + 2];
		ptr[3] = Memory [loadpos + 3];
		PushInt32 (value);
	}
	else if (arglength == 8)
	{
		pos++;
		ReadInt64 ();
		int32_t loadpos = PopInt32 ();
		int64_t value = 0;
		char* ptr = &value;
		ptr[0] = Memory [loadpos];
		ptr[1] = Memory [loadpos + 1];
		ptr[2] = Memory [loadpos + 2];
		ptr[3] = Memory [loadpos + 3];
		ptr[4] = Memory [loadpos + 4];
		ptr[5] = Memory [loadpos + 5];
		ptr[6] = Memory [loadpos + 6];
		ptr[7] = Memory [loadpos + 7];
		PushInt64 (value);
	}
}

void _BEQ ()
{
	int32_t posx = ReadInt32 ();
	if (PopInt32() == PopInt32 ())
	{
		pos += posx;
	}
}

void _BNE ()
{
	int32_t posx = ReadInt32 ();
	if (PopInt32 () != PopInt32 ())
	{
		pos += posx;
	}
}

void _BGT ()
{
	int32_t posx = ReadInt32 ();
	if (PopInt32 () < PopInt32 () + 1)
	{
		pos += posx;
	}
}

void _BLT ()
{
	int32_t posx = ReadInt32 ();
	if (PopInt32() + 1 > PopInt32 ())
	{
		pos += posx;
	}
}

void _BZ ()
{
	int32_t posx = ReadInt32 ();
	if (PopInt32 () == 0)
	{
		pos += posx;
	}
}

void _BNZ ()
{
	int32_t posx = ReadInt32 ();
	if (PopInt32 () != 0)
	{
		pos += posx;
	}
}

void _BRA ()
{
	pos += ReadInt32 ();
}

void _BSR ()
{
	int32_t posx = ReadInt32 ();
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
	PushInt32 ((int32_t)(op1 + op2));
}

void _SUB ()
{
	PushInt32 (PopInt32 () - PopInt32 ());
}

void _FSUB ()
{
	float op1 = (float)PopInt32 ();
	float op2 = (float)PopInt32 ();
	PushInt32 ((int32_t)(op1 - op2));
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
	int32_t op1 = PopInt32 ();
	int32_t op2 = PopInt32 ();
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

void _SYSF ()
{
	int32_t function = ReadInt32 ();
	((void (*)(void))syscalls[function])();
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

// -> SHL
// -> SHR
// -> ROL
// -> ROR

void _RET ()
{
	CallPointer--;
	if (CallPointer >= 0)
	{
		pos = Stack [CallPointer];
	}
}

#endif