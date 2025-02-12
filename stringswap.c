#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char firstName[20];
    char lastName[20];
} Person;

void swap(void* first, void* second, size_t numBytes)
{
    void* temp = malloc(numBytes);
    if (temp == NULL)
    {
        printf("Failed to allocate memory.\n");
        exit(1);
    }

    memcpy(temp, first, numBytes);
    memcpy(first, second, numBytes);
    memcpy(second, temp, numBytes);

    free(temp); 

}