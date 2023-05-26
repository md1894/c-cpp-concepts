#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define THREAD_NUM 4

typedef struct Task {
    int a, b;
} Task;

Task taskQueue[256];
int taskCount = 0;

pthread_mutex_t mutexQueue;
pthread_cond_t condQueue;

void executeTask(Task* task) {
    usleep(50000);
    int result = task->a + task->b;
    printf("The sum of %d and %d is %d\n", task->a, task->b, result);
}

void submitTask(Task task) {
    pthread_mutex_lock(&mutexQueue);
    taskQueue[taskCount] = task;
    taskCount++;
    pthread_mutex_unlock(&mutexQueue);
    pthread_cond_signal(&condQueue);
}

// 1 2 3 4 5
// 2 3 4 5

void* startThread(void* args) {
    while (1) {
        Task task;

        pthread_mutex_lock(&mutexQueue);
        while (taskCount == 0) {
            pthread_cond_wait(&condQueue, &mutexQueue);
        }

        task = taskQueue[0];
        int i;
        for (i = 0; i < taskCount - 1; i++) {
            taskQueue[i] = taskQueue[i + 1];
        }
        taskCount--;
        pthread_mutex_unlock(&mutexQueue);
        executeTask(&task);
    }
}

int main(int argc, char* argv[]) {
    pthread_t th[THREAD_NUM];
    pthread_mutex_init(&mutexQueue, NULL);
    pthread_cond_init(&condQueue, NULL);
    int i;
    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_create(&th[i], NULL, &startThread, NULL) != 0) {
            perror("Failed to create the thread");
        }
    }

    srand(time(NULL));
    for (i = 0; i < 100; i++) {
        Task t = {
            .a = rand() % 100,
            .b = rand() % 100
        };
        submitTask(t);
    }

    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join the thread");
        }
    }
    pthread_mutex_destroy(&mutexQueue);
    pthread_cond_destroy(&condQueue);
    return 0;
}

/*
The sum of 77 and 79 is 156
The sum of 56 and 56 is 112
The sum of 17 and 73 is 90
The sum of 42 and 89 is 131
The sum of 33 and 35 is 68
The sum of 74 and 24 is 98
The sum of 40 and 81 is 121
The sum of 41 and 91 is 132
The sum of 48 and 32 is 80
The sum of 62 and 2 is 64
The sum of 46 and 85 is 131
The sum of 48 and 9 is 57
The sum of 58 and 45 is 103
The sum of 53 and 18 is 71
The sum of 89 and 71 is 160
The sum of 96 and 9 is 105
The sum of 70 and 68 is 138
The sum of 98 and 4 is 102
The sum of 29 and 10 is 39
The sum of 26 and 39 is 65
The sum of 49 and 62 is 111
The sum of 39 and 39 is 78
The sum of 45 and 76 is 121
The sum of 19 and 39 is 58
The sum of 71 and 82 is 153
The sum of 41 and 17 is 58
The sum of 67 and 90 is 157
The sum of 78 and 77 is 155
The sum of 87 and 19 is 106
The sum of 0 and 40 is 40
The sum of 38 and 96 is 134
The sum of 1 and 16 is 17
The sum of 35 and 99 is 134
The sum of 20 and 5 is 25
The sum of 67 and 1 is 68
The sum of 68 and 69 is 137
The sum of 16 and 13 is 29
The sum of 45 and 7 is 52
The sum of 4 and 64 is 68
The sum of 46 and 75 is 121
The sum of 46 and 88 is 134
The sum of 44 and 65 is 109
The sum of 30 and 75 is 105
The sum of 94 and 69 is 163
The sum of 94 and 94 is 188
The sum of 61 and 32 is 93
The sum of 91 and 62 is 153
The sum of 1 and 78 is 79
The sum of 13 and 73 is 86
The sum of 36 and 81 is 117
The sum of 50 and 91 is 141
The sum of 75 and 4 is 79
The sum of 69 and 47 is 116
The sum of 50 and 74 is 124
The sum of 11 and 96 is 107
The sum of 1 and 58 is 59
The sum of 36 and 46 is 82
The sum of 75 and 18 is 93
The sum of 21 and 70 is 91
The sum of 87 and 15 is 102
The sum of 64 and 48 is 112
The sum of 0 and 7 is 7
The sum of 10 and 1 is 11
The sum of 86 and 24 is 110
The sum of 74 and 22 is 96
The sum of 57 and 1 is 58
The sum of 26 and 59 is 85
The sum of 44 and 95 is 139
The sum of 6 and 94 is 100
The sum of 69 and 17 is 86
The sum of 91 and 71 is 162
The sum of 27 and 27 is 54
The sum of 69 and 55 is 124
The sum of 46 and 42 is 88
The sum of 25 and 85 is 110
The sum of 57 and 41 is 98
The sum of 34 and 9 is 43
The sum of 49 and 96 is 145
The sum of 62 and 35 is 97
The sum of 72 and 89 is 161
The sum of 57 and 29 is 86
The sum of 90 and 35 is 125
The sum of 88 and 35 is 123
The sum of 30 and 46 is 76
The sum of 81 and 52 is 133
The sum of 75 and 43 is 118
The sum of 64 and 72 is 136
The sum of 52 and 96 is 148
The sum of 98 and 50 is 148
The sum of 38 and 75 is 113
The sum of 87 and 95 is 182
The sum of 17 and 21 is 38
The sum of 57 and 18 is 75
The sum of 70 and 19 is 89
The sum of 53 and 42 is 95
The sum of 8 and 62 is 70
The sum of 72 and 51 is 123
The sum of 97 and 12 is 109
The sum of 86 and 79 is 165
The sum of 11 and 19 is 30
*/