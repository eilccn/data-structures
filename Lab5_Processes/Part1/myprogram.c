#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	int idx;

	char* myargv[][4] = { {"/bin/ls", "-F", 0},
			      {"/bin/sh", "-c", "echo testing", 0},
			      {"/bin/nl", "example1.c", 0} };


//	myargv[0][0]="/bin/ls";
//	myargv[0][1]="-F";
//	myargv[0][2]=NULL;
//	myargv[1][0]="/bin/sh"; 
//	myargv[1][1]="-c";
//	myargv[1][2]="echo testing";
//	myargv[1][3]=NULL;
//	myargv[2][0]="/bin/nl";
//	myargv[2][1]="example1.c";
//	myargv[3][2]=NULL;


	for (idx=0; idx<3; idx++){
	
		if (fork()==0){
			execve(myargv[idx][0], &myargv[idx][0] ,NULL);
			printf("Child: Should never get here\n");
			exit(1);
		} else{
			wait(NULL);
			printf("This always prints last\n");
		}
	}

	return 0;
}
