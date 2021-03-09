// Implement your part 1 solution here
// gcc vfork.c -o vfork


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


// Global array
// Canvas
// 64 rows by 64 columns (each pixel stores 3 colors RGB)
int colors[64][64*3];

// Paint function
void paint(int workID){
	printf("Artist %d is painting\n", workID);

	// workID = artist
	// Each artist has one row to paint on
	// Each artist paints one pixel at a time 
	// with an RGB value
	int i, j;
	for (i=0; i < 64; i++){
		for (j=0; j< 64*3; j++){
			colors[i][j] = (i+j) & 255; 
		}
	}
}

int main(int argc, char** argv){
	
	// Number of child processes
	int numberOfArtists = 64;
	// Store process id
	pid_t pid;
	
	int i;	
	for (i=0; i < numberOfArtists; i++){
		pid = vfork();
		
		// Child process
		if (pid ==0){
			paint(i);
			exit(0);
		}
		// Log info in parent
		printf("Child created: %d\n", pid);
		
	}

	// Parent process
	printf("Masterpiece(vfork.ppm) is being assembled\n");
	
	// PPM file
	FILE *fp;
	fp = fopen("vfork.ppm", "w+");
	fputs("P3\n", fp);
	fputs("64 64\n", fp);
	fputs("255\n", fp);
	int j;
	for (i=0; i<64; i++){
		for (j=0; j<64*3; j++){
			fprintf(fp, "%d", colors[i][j]);
			fputs(" ", fp);
		}
		fputs("\n", fp);
	}
	fclose(fp);
		
	return 0;
}
