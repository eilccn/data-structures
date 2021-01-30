// Guessing Game in C
// param1:
// expected output:

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int playGame(int number){
	int current_guess;
	do {
		printf("Make a guess: ");
		scanf("%d", &current_guess);

		if (current_guess > number){
			printf("No guess lower!\n");
		}

		else if (current_guess < number){
			printf("No guess higher!\n");
		}

		else {
			printf("You got it!\n");
		}
	} while (current_guess != number);
	
	return 0;	
	
}

int main(){
	int i, number, current_guess, number_of_guesses;
	
	srand((unsigned)time(NULL));	

	for (i=0; i<5; i++){    
		
		printf("***************************\n");
		printf("CPU Says: Pick a number 1-10 \n");
		printf("***************************\n"); 
		number = rand()%10+1;	
		
		playGame(number);
	}	
	
	return 0;	


}
