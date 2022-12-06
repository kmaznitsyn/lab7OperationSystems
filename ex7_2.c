#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

long WAIT_FOR_SECONDS = 3;

typedef struct toThread {
    char* name;
    char* baseStr;
    int num;
}ThreadData;

void * func_for_threads(void *args) {
    ThreadData my_structure = * (ThreadData* ) args;

    for (int i = 0; i < my_structure.num; ++i) {
        printf("Потік %s. Str %d/%d. Повідомлення: %s\n", my_structure.name, (i+1), my_structure.num, my_structure.baseStr);
    }
}

void check_if_error(int result) {
    if (result != 0) {
        fprintf(stderr, "Помилка при створенні потоку !!!\n");
        exit(1);
    }
}

int main(void) {

    ThreadData potik_1, potik_2, potik_3, potik_4;

    potik_1.name = "Потік 1";
    potik_1.baseStr = "Так";
    potik_1.num = 2;

    potik_2.name = "Потік 2";
    potik_2.baseStr = "Ні";
    potik_2.num = 5;

    potik_3.name = "Потік 3";
    potik_3.baseStr = "Можливо";
    potik_3.num = 7;

    potik_4.name = "Потік 4";
    potik_4.baseStr = "Точно";
    potik_4.num = 3;

    pthread_t thread_1, thread_2, thread_3, thread_4;
    check_if_error(pthread_create(&thread_1, NULL, &func_for_threads, &potik_1));
    check_if_error(pthread_create(&thread_2, NULL, &func_for_threads, &potik_2));
    check_if_error(pthread_create(&thread_3, NULL, &func_for_threads, &potik_3));
    check_if_error(pthread_create(&thread_4, NULL, &func_for_threads, &potik_4));

    sleep(WAIT_FOR_SECONDS);

    return 0;
}
