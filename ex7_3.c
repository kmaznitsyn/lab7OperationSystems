#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

const long MIN = 1;
const long MAX = 10000;
const long AMOUNT = 1000;
long WAIT_FOR_SECONDS = 3;

typedef struct toThread {
    char* str;
}ThreadData;

void * thread_2(void *args) {
    int numFromArgs = *(int*) args;
    int num;
    int i;
    for (i = 0; i < AMOUNT; i++) {
        num = (rand() % (MAX - MIN + 1)) + MIN;
        if (num = numFromArgs) {
            fprintf(stderr, "Ми знайшли число!\n");
            pthread_exit(NULL);
        }
    }
}

void * thread_1(void *args) {
    ThreadData data = * (ThreadData *) args;
    for (int i = 0; i < 10; i++) {
        fprintf(stderr, "Поток нащадок. Ітерація N %d. Повідомлення: %s\n", (i+1), data.str);
        sleep(WAIT_FOR_SECONDS);
    }

    return NULL;
}

void check_if_error(int result) {
    if (result != 0) {
        fprintf(stderr, "Error during thread creation\n");
        exit(1);
    }
}

int main() {
    ThreadData threadData;
    threadData.str = "Hahaha";
    int selected_num = 1000;


    pthread_t pthread1, pthread2;

    check_if_error(pthread_create(&pthread1, NULL, &thread_1, &threadData));
    if (pthread_join(pthread1, NULL) != 0) {
        fprintf(stderr, "Join error\n");
        return 1;
    }

    check_if_error(pthread_create(&pthread2, NULL, &thread_2, &selected_num));
    if (pthread_join(pthread2, NULL) != 0) {
        fprintf(stderr, "Join error\n");
        return 1;
    }

    fprintf(stderr, "Потоки main закінчились!!\n");

    return 0;
}
