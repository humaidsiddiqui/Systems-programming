// thread.c

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

volatile int count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* increment(void* arg)
{
    int n1 = *((int*) arg);
    int status;

    for (int i = 0; i < n1; i++)
    {
        status = pthread_mutex_lock(&mutex);
        if (status != 0)
        {
            printf("Failed to lock mutex.\n");
            exit(EXIT_FAILURE);
        }

        count++;

        status = pthread_mutex_unlock(&mutex);
        if (status != 0)
        {
            printf("Failed to unlock mutex.\n");
            exit(EXIT_FAILURE);
        }
    }

    pthread_exit(NULL);
}
void* decrement(void* arg)
{
    int n2 = *((int*) arg);
    int status;

    for (int i = 0; i < n2; i++)
    {
        status = pthread_mutex_lock(&mutex);
        if (status != 0)
        {
            printf("Failed to lock mutex.\n");
            exit(EXIT_FAILURE);
        }

        count--;

        status = pthread_mutex_unlock(&mutex);
        if (status != 0)
        {
            printf("Failed to unlock mutex.\n");
            exit(EXIT_FAILURE);
        }
    }

    pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
    pthread_t thread1, thread2;
    int n1, n2;
    int status;

    if (argc != 3 ||
        strcmp(argv[1], "-h") == 0 ||
        strcmp(argv[1], "--help") == 0)
    {
        printf("Usage: ./thread n1 n2\n");
        exit(1);
    }

    n1 = atoi(argv[1]);
    n2 = atoi(argv[2]);

    if (n1 <= 0 || n2 <= 0)
    {
        printf("Usage: ./thread n1 n2\n");
        exit(1);
    }
    status = pthread_create(&thread1, NULL, increment, (void*)&n1);
    if (status != 0)
    {
        printf("Failed to create increment thread.\n");
        exit(EXIT_FAILURE);
    }

    status = pthread_create(&thread2, NULL, decrement, (void*)&n2);
    if (status != 0)
    {
        printf("Failed to create decrement thread.\n");
        exit(EXIT_FAILURE);
    }

    status = pthread_join(thread1, NULL);
    if (status != 0)
    {
        printf("Failed to join increment thread.\n");
        exit(EXIT_FAILURE);
    }

    status = pthread_join(thread2, NULL);
    if (status != 0)
    {
        printf("Failed to join decrement thread.\n");
        exit(EXIT_FAILURE);
    }

    printf("%d\n", count);

    exit(EXIT_SUCCESS);
}