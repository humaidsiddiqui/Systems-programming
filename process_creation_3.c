/*
 * Goals:
 * Parent process creates two child processes.
 * The child processes sleep for 2 seconds and 1 second, respectively, and then exit.
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

int main()
{
    pid_t parentPid, child;
    pid_t childPid[2];
    unsigned int delay[2] = {2, 1};
    int childStatus, status, index;