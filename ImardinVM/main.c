#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "memory.c"
#include "imardin.c"

int main(int argc, char* argv[])
{
    int origin = 0;
    int memory = 0xFFFF;

    FILE* binary = NULL;

    if (argc < 2)
    {
        printf ("--- Imardin Virtual Machine\n");
        printf ("Invalid syntax!\n");
        printf ("Syntax: imardin <binary> [args]\n");
        printf ("---\n");
        printf ("Close the terminal or press ^C to abort\n");
        while (1);
    }
    else if (argc >= 2)
    {
        if (strcmp ("-help", &argv[1][0]) == 0 || strcmp ("-?", &argv[1][0]) == 0)
        {
            printf ("--- Imardin Virtual Machine\n");
            printf ("Imardin Help\n");
            printf ("Syntax: imardin <binary> [args]\n\n");
            printf ("Argument       Description\n");
            printf ("-org <value>   Change origin\n");
            printf ("-ram <value>   Change available memory\n");
            printf ("---\n");
            printf ("Close the terminal or press ^C to abort\n");
            while (1);
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
    }

    char current;
    int position = 0;

    InitializeVM (memory);

    fseek (binary, 0L, SEEK_END);
    int filesize = ftell (binary);
    fseek (binary, 0L, SEEK_SET);

    if (binary == 0 || filesize == 0)
    {
        printf ("--- Imardin Virtual Machine\n");
        printf ("Invalid file!\n");
        printf ("---\n");
        fclose (binary);
        printf ("Close the terminal or press ^C to abort\n");
        while (1);
    }

    while (position < filesize)
    {
        current = fgetc (binary);
        Memory [origin + position] = current;
        position++;
    }

    heap = origin + filesize;

    RunVM (origin);

    fclose (binary);

    printf ("IMARDIN::EOF-> End of File.\n");
    printf ("Close the terminal or press ^C to abort\n");
    while (1);

    return 0;
}