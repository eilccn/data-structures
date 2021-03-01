#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>


// Functions for built in commands
int cd_cmd(char **args);
int help_cmd(char **args);
int exit_cmd(char **args);
int game_cmd(char **args);

// Array of built in commands
char *builtin_str[] = { "cd", "help", "exit", "game" };

// Array of function pointers
int (*builtin_fxn[]) (char **) = {
	&cd_cmd, &help_cmd, &exit_cmd, &game_cmd
};

// Returns number of builtin functions
int num_builtins(){
       return sizeof(builtin_str) / sizeof(char *);
}

// cd builtin command
// input: list of args, args[0] is cd, args[1] is the directory
// return: always returns 1 to continue executing
int cd_cmd(char **args){
	chdir(args[1]);
}

// help builtin command
// input: list of args
// return: always returns 1 to continue executing
int help_cmd(char **args){
	int i;
	printf("This is the mini-shell\n");
	printf("The following programs are builtin:\n");

	for (i = 0; i < num_builtins(); i++){
		printf("  %s\n", builtin_str[i]);
	}

	printf("Use the man command for info on other programs.\n");
	return 1;
}

// exit builtin command
// input: list of args
// return: always returns 0, terminates execution
int exit_cmd(char **args){
	return 0;
}

// guessing game builtin command
// input: user inputs a number 1-10 until they guess the correct number
// they will do this until they have completed 5 games
// return: summary of how many guesses the user made for each game
int game_cmd(char **args){
	int i, number, current_guess, num_guesses;
	int array[i];

	srand((unsigned)time(NULL));	

	for (i=0; i<5; i++){    	
		printf("***************************\n");
		printf("CPU Says: Pick a number 1-10 \n");
		printf("***************************\n");
 
		number = rand()%10+1;	
		num_guesses = 0;
	
		do{
			printf("Make a guess: ");
			scanf("%d", &current_guess);
			array[i] = num_guesses++;

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
	}
	
	printf("***************************\n");
	printf("Here are your results!\n");
	printf("***************************\n");
	for (i=0; i<5; i++){
		printf("Game %d took you %d guesses\n", i,
		array[i]);	
	}
	return 1;
}

// Starts a program and waits for it to terminate
// input: args Null terminated list of arguments (including program)
// return: always returns 1, continues to execution
int start_program(char **args){
	pid_t pid;
	int status;

	pid = fork();
	
        if (pid == 0){     // for the child process
                if (execvp(args[0], args) == -1){
                        printf("Error: forking child process failed\n");
                        exit(1);
                }
	
	} else if (pid < 0){
		// Error forking
		printf("Error: forking child process failed\n");
		exit(1);
	} else {     // for the parent process
		do{
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return 1;
}

// Executes a program
// input: args Null terminated list of arguments
// returns 1 if the shell should keep running, 0 if it should terminate
int execute(char **args){
	int i;

	if (args[0] == NULL){     // empty command
		return 1;
	}

	for (i = 0; i < num_builtins(); i++){
		if (strcmp(args[0], builtin_str[i]) == 0){
			return (*builtin_fxn[i])(args);
		}
	}

	return start_program(args);
}

// Reads line of input from stdin
// input: line input from stdin
// returns: line of input from stdin
char *read_line(void){
#ifdef GETLINE
	char *line = NULL;
	ssize_t bufsize = 0;
	if (getline(&line, &bufsize, stdin) == 1){
			if (feof(stdin)){
				exit(EXIT_SUCCESS); // received an EOF
			} else{
				perror("Failed to get line: \n");
				exit(EXIT_FAILURE);
			}
	}
	return line;
#else
#define READLINE_BUFFER 80
	int bufsize = READLINE_BUFFER;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer) {
		fprintf(stderr, "Error\n");
		exit(EXIT_FAILURE);
	}

	while (1){
		// Read a character
		c = getchar();

		if (c == EOF){
			exit(EXIT_SUCCESS);
		} else if (c == '\n'){
			buffer[position] = '\0';
			return buffer;
		} else {
			buffer[position] = c;
		}
		position++;

		// If buffer exceeded, reallocate
		if (position >= bufsize){
			bufsize += READLINE_BUFFER;
			buffer = realloc(buffer, bufsize);
			if (!buffer){
				fprintf(stderr, "Error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
#endif
}

// Splits line into tokens
// input: line
// returns: null terminated array of tokens
#define TOK_BUFFER 64
#define TOK_DELIM "\t\r\n\a"
char **split_line(char *line){
	int bufsize = TOK_BUFFER, position = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token, **tokens_backup;

	if (!tokens){
		fprintf(stderr, "Error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOK_DELIM);
	while (token != NULL){
		tokens[position] = token;
		position++;

		if (position >= bufsize){
			bufsize += TOK_BUFFER;
			tokens_backup = tokens;
			tokens = realloc(tokens, bufsize * sizeof(char*));
			if (!tokens){
				free(tokens_backup);
			fprintf(stderr, "Error\n");
			exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, TOK_DELIM);
	}

	tokens[position] = NULL;
	return tokens;
}

// Loop for executing shell
void loop(void){
	char *line;
	char **args;
	int status;

	do {
		printf("mini-shell> ");
		line = read_line();
		args = split_line(line);
		status = execute(args);

		free(line);
		free(args);
	} while (status);
}

// Main
int main(int argc, char *argv){

	loop();

	return EXIT_SUCCESS;

}










