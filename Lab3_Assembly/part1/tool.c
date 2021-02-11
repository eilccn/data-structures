// Implement your cycle count tool here.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//int sum(int arr[], int n){
//	int sum = 0;
//	for (int i=0; i<n; i++){
//		sum+= arr[i];
//		return sum;
//	}
//}

int main(int argc, char* argv[]){
	
	FILE* input = fopen(argv[1], "r");
	
	char buf[64] = ""; 
	char* words[10] = {"ADD", "SUB", "MUL", "DIV", "MOV",
			"LEA", "PUS", "POP", "RET", NULL};
	int freq[100] = {}; // Word frequency array


	while (fscanf(input, "%s[^\n]", buf) == 1){
		
		int i;
		for (i=0; words[i]; i++)
			if (strstr(buf, words[i]) != NULL)
				break;
		

		if (words[i]) {
			freq[i]++;
			continue;
		}

		for (int i=0; i<8; i++){
			printf("%s = %d\n", words[i], freq[i]);
			//int n = sizeof(freq) / sizeof(freq[0]);
			//("\nTotal Instructions = ", sum(freq, n))		
			//printf("\nTotal Cycles = ", 
		}
	}
	fclose(input);
		

return 0;
}
		
