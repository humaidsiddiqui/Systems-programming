#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * Compile using:
   cc stringmodify.c -o stringmodify
 * Run using:
   ./stringmodify message
*/

#define MESSAGE_LENGTH 200
void modify(char* message, int (*visitor)(int))
{
    int index; 

    if (message == NULL)
    {
        printf("message cannot be null.\n");
        exit(1);
    }
    for (index = 0; message[index] != '\0'; index++)
    {
        message[index] = visitor(message[index]);
    }

}
