#ifndef __IMARDIN_SYSCALLS_H
#define __IMARDIN_SYSCALLS_H

void* syscalls [255];

void sysf_print_str ()
{
	uint32_t string = PopInt32 ();
	FILE* outstream = stdout;
	while (Memory [string] != 0)
	{
		fprintf (outstream, "%c", Memory [string]);
		string++;
	}
}

void sysf_print_int ()
{
	uint32_t integer = PopInt32 ();
	FILE* outstream = stdout;
	fprintf (outstream, "%d", Memory [integer]);
}

void sysf_read ()
{
	PopInt32 ();
	char* str = (char*)malloc (200);
	fgets (str, 200, stdin);
	str [strlen (str) - 1] = 0;
	memcpy (Memory + heap, str, strlen (str) + 1);
	PushInt32 (heap);
	heap += strlen (str) + 2;
}

void InitializeSyscalls ()
{
	syscalls [1] = sysf_print_str;
	syscalls [2] = sysf_print_int;
	syscalls [3] = sysf_read;
}

#endif