// Implement your part 2 solution here
// gcc -lpthread threads.c -o threads

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NTHREADS 64

int colors[64][64*3];
int counter = 0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

// Paint function
void paint(int workID){
	printf("Artist %d is painting\n", workID);

	for (int i=0; i< 64*3; ++i){
		colors[workID][i] = workID;
	}
}

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

	printf("Masterpiece(threads.ppm) is being assembled\n");

	// PPM file
	FILE *fp;
	fp = fopen("threads.ppm", "w+");
	fputs("P3\n", fp);
	fputs("64 64\n", fp);
	fputs("255\n", fp);
	for (int i=0; i<64; ++i){
		for (int j=0; j< 64*3; ++j){
			fprintf(fp, "%d", colors[i][j]);
			fputs(" ", fp);
		}
		fputs("\n", fp);
	}
	fclose(fp);
	
	// End program
	return 0;
}
