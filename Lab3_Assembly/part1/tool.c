// Implement your cycle count tool here.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum{MAXW = 1000};

int main(int argc, char** argv){
	
	FILE* input = fopen(argv[1], "r");
	
	char buf[4]; 
	char* words[] = {"ADD", "SUB", "MUL", "DIV", "MOV",
			"LEA", "PUS", "POP", "RET", NULL};
	int freq[MAXW] = {0}, n=0; // Word frequency array


	while ((fscanf(input, "%s", buf)) != EOF){
		int i;
		for (i=0; words[i]; i++){
			if (strcmp(words[i], buf) == 0)
				break;
		}

		if (words[i]) {
			freq[i]++;
			continue;
		}

		for (int i=0; words[i]; i++){
			printf("%s = %d\n", words[i], freq[i]);
			free(words[i]);
		}
	}
	fclose(input);
		

return 0;
}
		
