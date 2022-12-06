#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

long WAIT_FOR_SECONDS = 2;

void * my_func(void * args) {
    for (int i = 0; i < 10; i++) {
        fprintf(stderr, "Поток нащадок. Ітерація N %d\n", (i+1));
        sleep(WAIT_FOR_SECONDS);
    }
    return NULL;
}
int main(void) {
    pthread_t thread;
    int res;
    res = pthread_create(&thread, NULL, &my_func, NULL);
    if (res != 0) {
        fprintf(stderr, "Error\n");
        return 1;
    }
    for (int i = 0; i < 10; i++) {
        fprintf(stderr, "Батьківський поток. Ітерація N %d\n", (i+1));
        sleep(WAIT_FOR_SECONDS);
    }
    return 0;
}
