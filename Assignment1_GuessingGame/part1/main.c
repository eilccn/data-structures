// Guessing Game in C
// input: user inputs a number 1-10 until they guess the correct number. they will do this until they have completed 5 games. 
// expected output: at the end of 5 games user is given a summary of how many guesses they made in each game.

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
	int i, number, current_guess, num_guesses;
	
	srand((unsigned)time(NULL));	

	for (i=0; i<5; i++){    
		
		printf("***************************\n");
		printf("CPU Says: Pick a number 1-10 \n");
		printf("***************************\n");
 
		number = rand()%10+1;	
		num_guesses = playGame(number);
	}
	
	printf("***************************\n");
	printf("Here are your results!\n");
	printf("***************************\n");
	for (i=0; i<5; i++){
		printf("Game %d took you %d guesses\n", i,
		num_guesses);	
	}
	return 0;	


}
