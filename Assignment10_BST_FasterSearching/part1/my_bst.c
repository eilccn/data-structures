// Include our header file for our my_bst.c
#include "my_bst.h"

// Include any other libraries needed
#include <stdio.h>
#include <stdlib.h>

// Creates a BST
// Returns a pointer to a newly created BST.
// The BST should be initialized with data on the heap.
// The BST fields should also be initialized to default values(i.e. size=0).
bst_t* bst_create(){
    // Modify the body of this function as needed.
	bst_t* myBST= (bst_t*)malloc(sizeof(bst_t)); 
	myBST->size = 0;
	myBST->root = NULL;
	return myBST;
}

// Added Helper Function
// Creates a node 
bstnode_t* new_node(int item){
	bstnode_t* temp = (bstnode_t*)malloc(sizeof(bstnode_t));
	temp->data = item;
	temp->leftChild = NULL;
	temp->rightChild = NULL;
	return temp;
}

// BST Empty
// Check if the BST is empty
// Returns 1 if true (The BST is completely empty)
// Returns 0 if false (the BST has at least one element)
int bst_empty(bst_t* t){
	if (t==NULL){
		return 1;
	}
	return 0;
}

// Adds a new node containng item to the BST
// The item is added in the correct position in the BST.
//  - If the data is less than or equal to the current node we traverse left
//  - otherwise we traverse right.
// The bst_function returns '1' upon success
//  - bst_add should increment the 'size' of our BST.
// Returns a -1 if the operation fails.
//      (i.e. the memory allocation for a new node failed).
// Your implementation should should run in O(log(n)) time.
//  - A recursive imlementation is suggested.
int bst_add(bst_t* t, int item){  

	if (new_node(item)==NULL){
		return -1;
	}

	if (t==NULL){
		t->root->data = item;
		bst_add(t, item);
	}

	if (item < t->root->data){
		t->root->leftChild->data = bst_add(t, item);
	} else if (item > t->root->data){
		t->root->rightChild->data = bst_add(t, item);
	}
	return 1;
}

// Helper function for traversing in ascending order
void traverse(bstnode_t *root){
	traverse(root->leftChild);
        printf(" %d", root->data);
	traverse(root->rightChild);
}

// Helper function for traversing in descending order
void d_traverse(bstnode_t *root){
	d_traverse(root->rightChild);
        printf(" %d", root->data);
	d_traverse(root->leftChild);
}

// Prints the tree in ascending order if order = 0, otherwise prints in descending order.
// For NULL tree -- print "(NULL)".
// It should run in O(n) time.
void bst_print(bst_t *t, int order){
	if(NULL == t){
		printf("(NULL)");
	}
	if (order==0){
		traverse(t->root);
	} else {
		d_traverse(t->root);
	} 
}

// Returns the sum of all the nodes in the bst. 
// exits the program for a NULL tree. 
// It should run in O(n) time.
int bst_sum(bst_t *t){
  return 0;
}

// Returns 1 if value is found in the tree, 0 otherwise. 
// For NULL tree it exists the program. 
// It should run in O(log(n)) time.
int bst_find(bst_t * t, int value){
  return 0;
}

// Returns the size of the BST
// A BST that is NULL exits the program.
// (i.e. A NULL BST cannot return the size)
unsigned int bst_size(bst_t* t){
    return 0;
}

// Free BST
// Removes a BST and ALL of its elements from memory.
// This should be called before the proram terminates.
void bst_free(bst_t* t){

}

