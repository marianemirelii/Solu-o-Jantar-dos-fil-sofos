#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

#define NUMERO_FILOSOFOS 5

// Semáforos para cada hashi e um mutex para controlar a região crítica
sem_t hashis[NUMERO_FILOSOFOS];
sem_t mutex;

void* filosofo(void* num) {
    int id = *(int*)num;
    while (1) {
        printf("O filosofo %d esta pensando...\n", id+1);
        sleep(1);

        // Região crítica para pegar os hashis
        sem_wait(&mutex);

        sem_wait(&hashis[id]);
        sem_wait(&hashis[(id + 1) % NUMERO_FILOSOFOS]);

        // Sai da região crítica para que outros possam tentar pegar os hashis
        sem_post(&mutex);

        printf("O filosofo %d esta comendo...\n", id+1);
        sleep(2);

        // Libera os hashis
        sem_post(&hashis[id]);
        sem_post(&hashis[(id + 1) % NUMERO_FILOSOFOS]);
    }
}

void main() {
    pthread_t threads[NUMERO_FILOSOFOS];
    int ids[NUMERO_FILOSOFOS];

    sem_init(&mutex, 0, 1);
    int x;

    for ( x = 0; x < NUMERO_FILOSOFOS; x++) {
        sem_init(&hashis[x], 0, 1);
        ids[x] = x;
        pthread_create(&threads[x], NULL, filosofo, &ids[x]);
    }

    for ( x = 0; x < NUMERO_FILOSOFOS; x++) {
        pthread_join(threads[x], NULL);
    }

    getch ();
}