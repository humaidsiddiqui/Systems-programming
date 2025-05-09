/*
 * Goals:
 * Parent process creates a child process.
 * Child process goes to sleep for 2 seconds and then exits.
 * Parent process waits for the child process to complete and then exits.
 * The exit system call is _exit()
 * The library function exit() is for running exit handler (if registered) after which it calls _exit()
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