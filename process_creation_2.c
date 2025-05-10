/*
 * Goals:
 * Parent process creates two child processes.
 * Each child processes runs "date --utc", and then exits.
 * Parent process waits for the child processes to complete and then exits.
 */

 #include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void printBye()
{
    printf("Process %d says Bye!\n", getpid());
}