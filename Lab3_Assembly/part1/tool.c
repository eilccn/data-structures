// Implement your cycle count tool here.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char** argv){
	
	FILE* input = fopen(argv[1], "r");
	
	char buf[64]; 
	char* words[10] = {"ADD", "SUB", "MUL", "DIV", "MOV",
			"LEA", "PUSH", "POP", "RET", NULL};

	// Initialize Counters
	int add_counter = 0;
	int sub_counter = 0;
	int mul_counter = 0;
	int div_counter = 0;
	int mov_counter = 0;
	int lea_counter = 0;
	int push_counter = 0;
	int pop_counter = 0;
	int ret_counter = 0;
	
	while (fscanf(input, "%s", buf) != EOF){
		
		// Counts for each word
		if (strstr(buf, "ADD") != NULL){
			add_counter++;
		}
		else if (strstr(buf, "SUB") != NULL){
			sub_counter++;
		}
		else if (strstr(buf, "MUL") != NULL){
                        mul_counter++;
                }
                else if (strstr(buf, "DIV") != NULL){
                        div_counter++;
                }
		else if (strstr(buf, "MOV") != NULL){
                        mov_counter++;
                }
                else if (strstr(buf, "LEA") != NULL){
                        lea_counter++;
                }
		else if (strstr(buf, "PUSH") != NULL){
                        push_counter++;
                }
                else if (strstr(buf, "POP") != NULL){
                        pop_counter++;
                }
		else if (strstr(buf, "RET") != NULL){
                        ret_counter++;
                }

	}
	
	fclose(input);
	
	// Print Results	
	printf("ADD %d\n", add_counter);
	printf("SUB %d\n", sub_counter);	
	printf("MUL %d\n", mul_counter);
        printf("DIV %d\n", div_counter);
	printf("MOV %d\n", mov_counter);
        printf("LEA %d\n", lea_counter);
	printf("PUSH %d\n", push_counter);
        printf("POP %d\n", pop_counter);
	printf("RET %d\n", ret_counter);

	//Print Total Counts
	int sum;
	sum = add_counter + sub_counter + mul_counter +
	div_counter + mov_counter + lea_counter +
        push_counter + pop_counter +  ret_counter;

	printf("Total Instructions %d", sum);  

return 0;
}
		
