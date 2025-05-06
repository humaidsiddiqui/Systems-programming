#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/*
 Compile using:
 cc copy.c -o copy
 Run using:
 ./copy source destination
*/

#define BUFFER_SIZE 10
int main(int argc, char* argv[])
{
    int sourceFd, destinationFd;
    int status;
    char buffer[BUFFER_SIZE]; // byte array
    int numRead, numWritten;

    if (argc != 3 ||
        strcmp(argv[1], "-h") == 0 ||
        strcmp(argv[1], "--help") == 0)
    {
        printf("Usage: %s source destination\n", argv[0]);
        exit(1);
    }

    /* Open the source file for reading */
    sourceFd = open(argv[1], O_RDONLY);
    if (sourceFd == -1)
    {
        printf("Failed to open source file for reading.\n");
        exit(1);
    }
     /* Open the destination file for writing */
     destinationFd = open(
        argv[2], 
        O_CREAT | O_WRONLY | O_TRUNC,
        S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
    );
    if (destinationFd == -1)
    {
        printf("Failed to open destination file.\n");
        exit(1);
    }

    numRead = read(sourceFd, buffer, BUFFER_SIZE);
    while(numRead > 0)
    {
        numWritten = write(destinationFd, buffer, numRead);
        if (numWritten < numRead)
        {
            printf("Partial write error.\n");
            exit(1);
        }
        numRead = read(sourceFd, buffer, BUFFER_SIZE);
    }

    if (numRead == -1)
    {
        printf("Failed to read source file.\n");
        exit(1);
    }
     /* Close the source file */
     status = close(sourceFd);
     if (status == -1)
     {
         printf("Failed to close source file.\n");
         exit(1);
     }
 
     /* Close the destination file */
     status = close(destinationFd);
     if (status == -1)
     {
         printf("Failed to close destination file.\n");
         exit(1);
     }
 
 
 
 
 }
    