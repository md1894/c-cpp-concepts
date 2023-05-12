#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

void* thread_func(void* arg)
{
    // Block SIGUSR1 signal in this thread
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);
    pthread_sigmask(SIG_BLOCK, &mask, NULL);

    // Wait for SIGUSR1 signal
    int sig;
    sigwait(&mask, &sig);

    // Handle signal
    printf("Thread received signal %d\n", sig);

    return NULL;
}

int main()
{
    // Create thread
    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, NULL);

    // Wait a few seconds
    sleep(5);

    // Send signal to thread
    pthread_kill(thread, SIGUSR1);

    // Wait for thread to finish
    pthread_join(thread, NULL);

    return 0;
}

