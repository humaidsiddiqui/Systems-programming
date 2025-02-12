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

int main(int argc, char* argv[])
{
    int x, y;
    Person first = {"Adam", "Smith"};
    Person second = {"John", "Doe"};

    if (argc != 3 ||
        strcmp(argv[1], "-h") == 0 ||
        strcmp(argv[1], "--help") == 0)
    {
        printf("Usage: %s n1 n2\n", argv[0]);
        exit(1);
    }

    x = atoi(argv[1]);
    y = atoi(argv[2]);

    printf("Before: %d %d\n", x, y);
    swap(&x, &y, sizeof(int));
    printf("After: %d %d\n", x, y);

    printf(
        "Before: %s %s, %s %s\n", 
        first.firstName, 
        first.lastName,
        second.firstName,
        second.lastName
    );
    swap(&first, &second, sizeof(Person));
    printf(
        "After: %s %s, %s %s\n", 
        first.firstName, 
        first.lastName,
        second.firstName,
        second.lastName
    );


    exit(0);
}