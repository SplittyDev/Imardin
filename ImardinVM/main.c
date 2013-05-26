#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "memory.c"
#include "imardin.c"

int main(int argc, char* argv[])
{
    int origin = 0;
    int memory = 0xFFFF;

    FILE* binary;

    if (argc < 2)
    {
        printf ("Invalid syntax!\n");
        printf ("Syntax: imardin <binary> [args]\n");
    }
    else if (argc >= 2)
    {
        if (strcmp ("-help", &argv[1][0]) == 0 || strcmp ("-?", &argv[1][0]) == 0)
        {
            printf ("Imardin Help\n");
            printf ("Syntax: imardin <binary> [args]\n\n");
            printf ("Argument       Description\n");
            printf ("-org <value>   Change origin\n");
            printf ("-ram <value>   Change available memory\n");
            return 0;
        }

        binary = fopen (argv[1], "r");

        int i = 2;
        for (i; i < argc; i++)
        {
            if (strcmp ("-org", &argv[i][0]) == 0)
            {
                ++i;
                char* sorigin = (char*) &argv[i][0];
                origin = atoi (sorigin);
            }
            else if (strcmp ("-ram", &argv[i][0]) == 0)
            {
                ++i;
                char* sram = (char*) &argv[i][0];
                memory = atoi (sram);
            }
        }

        char current;
        int position = 0;

        InitializeVM (memory);

        fseek (binary, 0L, SEEK_END);
        int filesize = ftell (binary);
        fseek (binary, 0L, SEEK_SET);

        while (position < filesize)
        {
            current = fgetc (binary);
            Memory [origin + position] = current;
            ++position;
        }

        heap = origin + filesize;

        RunVM (origin);

        fclose (binary);
        return 0;
    }
}
