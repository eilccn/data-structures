// Implement your part 2 solution here
// gcc -lpthread threads.c -o threads

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NTHREADS 64

int counter = 0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

// Thread with variable arguments
void *thread(void *vargp){
	pthread_mutex_lock(&mutex1);
		counter = counter + 1;
	pthread_mutex_unlock(&mutex1);
	return NULL;
}

int main(){
	// Store Pthread ID
	pthread_t tids[NTHREADS];
	printf("Counter starts at: %d\n", counter);
	
	// Create and execute multiple threads
	for (int i=0; i < NTHREADS; ++i){
		pthread_create(&tids[i], NULL, thread, NULL);
	}

	// Create and execute multiple threads
	for (int i=0; i < NTHREADS; ++i){
		pthread_join(tids[i], NULL);
	}

	printf("Final Counter value: %d\n", counter);

	// End program
	return 0;
}
