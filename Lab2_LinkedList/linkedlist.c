// Modify this file
// compile with: gcc linkedlist.c -o linkedlist

#include <stdio.h>
#include <stdlib.h> // contains the functions free/malloc

// Create your node_t type here
typedef struct node{
	struct node* next; 
	int wins;
	int years;
} node_t;

// Write your functions here                                       // There should be 1.) create_list 2.) print_list 3.) free_list
// You may create as many helper functions as you like.  
node_t* create_list(){
	node_t* year2018 = malloc(sizeof(node_t));
	node_t* year2017 = malloc(sizeof(node_t)); 
	node_t* year2016 = malloc(sizeof(node_t));
	node_t* year2015 = malloc(sizeof(node_t)); 
	node_t* year2014 = malloc(sizeof(node_t));

	// setting up data in each node
	year2018->years = 2018;
	year2017->years = 2017;
	year2016->years = 2016;
	year2015->years = 2015;
	year2014->years = 2014;	

	year2018->wins = 108;
	year2017->wins = 93;
	year2016->wins = 93;
	year2015->wins = 78;
	year2014->wins = 71;

	//link the list
	year2018->next = year2017;
	year2017->next = year2016;
	year2016->next = year2015;
	year2015->next = year2014;
	year2014->next = NULL;

	return year2018;  
}

void print_list(node_t* node){
	node_t* iterator = node; //point to head of list
	while(iterator != NULL){
		printf("Wins in %d are %d\n", iterator->years,
			iterator->wins);
		iterator = iterator->next;
	}
}

void free_list(node_t* node){
	node_t* iterator = node;
	while(iterator != NULL){
		if (node == NULL){
			return;
		iterator = iterator->next;
		}
	}
}

int main(){
	
	node_t* redsox = NULL;

	//create list	
	redsox = create_list();
	
	//print list
	print_list(redsox);

	//free memory
	free_list(redsox);
	
    return 0;
}
