// =================== Support Code =================
// Doubly Linked List ( DLL ).
//
//
//
// - Implement each of the functions to create a working DLL.
// - Do not change any of the function declarations
//   - (i.e. dll_t* create_dll() should not have additional arguments)
// - You should not have any 'printf' statements in your DLL functions. 
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
//   - (You may write helper functions to help you debug your code such as print_list etc)
// ==================================================
#ifndef MYDLL_H
#define MYDLL_H

// Create a node data structure to store data within
// our DLL. In our case, we will stores 'integers'
typedef struct node{
	int data;
	struct node* next;
  	struct node* previous;
}node_t;

// Create a DLL data structure
// Our DLL holds a pointer to the first node in our DLL called head,
// and a pointer to the last node in our DLL called tail.
typedef struct DLL{
	int count;		// count keeps track of how many items are in the DLL.
	node_t* head;		// head points to the first node in our DLL.
        node_t * tail;          //tail points to the last node in our DLL.
}dll_t;

// Create new node
// Return pointer to next node and previous node
node_t* new_node(int data){
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	newNode->data = data;
	newNode->previous = NULL;
	newNode->next = NULL;
	
	return newNode;
}	

// Creates a DLL
// Returns a pointer to a newly created DLL.
// The DLL should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The DLLs fields should also be initialized to default values.
// Returns NULL if we could not allocate memory.
dll_t* create_dll(){
	// Modify the body of this function as needed.	
	dll_t* myDLL = (dll_t*)malloc(sizeof(dll_t));	
	
	myDLL->count = 0;
	myDLL->head = NULL;
	myDLL->tail = NULL;
	
	if (myDLL == NULL){
		return NULL;
	}

	return myDLL;
}

// DLL Empty
// Check if the DLL is empty
// Returns 1 if true (The DLL is completely empty)
// Returns 0 if false (the DLL has at least one element enqueued)
// Returns -1 if the dll is NULL.
int dll_empty(dll_t* l){
	if (l->head == NULL){
		return 1;
	} else {
		return 0;
	}

	if (l == NULL){
		return -1;
	}
}

// push a new item to the front of the DLL ( before the first node in the list).
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// Returns -1 if DLL is NULL.
// (i.e. the memory allocation for a new node failed).
int dll_push_front(dll_t* l, int item){
	node_t* newNode = new_node(item);
 
	if (l == NULL){
		return -1;
	}
	if (newNode == NULL){
		return 0;
	}

	newNode->next = l->head;
	newNode->previous = NULL;

	if (dll_empty(l) == 1){
		newNode->previous = NULL;
		l->head = newNode;
		l->tail = newNode;
	} else{
		newNode->next = l->head;
		l->head->previous = newNode;
		l->head = newNode;	
	}	
	return 1;
}

// push a new item to the end of the DLL (after the last node in the list).
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// Returns -1 if DLL is NULL.
// (i.e. the memory allocation for a new node failed).
int dll_push_back(dll_t* l, int item){	
	node_t* newNode = new_node(item);

	if (l == NULL){		
		return -1;
	}
	if (newNode == NULL){
		return 0;
	}
	
	newNode->next = NULL;
	
	if (dll_empty(l) == 1){
		newNode->previous = NULL;
		l->head = newNode;
		l->tail = newNode;
	} else {
		newNode->previous = l->tail;
		l->tail->next = newNode;
		l->tail = newNode;
	}
	
		
	return 1; 
}

// Returns the first item in the DLL and also removes it from the list.
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Returns a -1 if the DLL is NULL. 
// Assume no negative numbers in the list or the number zero.
int dll_pop_front(dll_t* t){
	node_t* cur = t->head;
	return cur->data;
	
	if (t->head == NULL){
		return -1;
	}
	if (dll_empty(t) == 1){
		return 0;
	}
	
	
	if (cur->next == NULL){
		t->head = NULL;
			
	} else {
		t->head = cur->next;
		(t->head)->previous = NULL;
	}	
	
	free(cur);
}


// Returns the last item in the DLL, and also removes it from the list.
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Returns a -1 if the DLL is NULL. 
// Assume no negative numbers in the list or the number zero.
int dll_pop_back(dll_t* t){
	node_t* cur = t->tail;
	return cur->data;

	if (t->head == NULL){
                return -1;
        }
        if (dll_empty(t) == 1){
                return 0;
        }

	cur->previous->next = NULL;
	free(cur);			
}

// Inserts a new node before the node at the specified position.
// Returns 1 on success
// Retruns 0 on failure:
//  * we couldn't allocate memory for the new node
//  * we tried to insert at a negative location.
//  * we tried to insert past the size of the list
//   (inserting at the size should be equivalent as calling push_back).
// Returns -1 if the list is NULL
int dll_insert(dll_t* l, int pos, int item){
	node_t* newNode = new_node(item);

	if (l->head == NULL){
		return -1;
	}
	if (pos < 0 || pos > (l->count)){
		return 0;
	}
	if (newNode == NULL){
		return 0;
	}
	else {
		node_t* currentnode = l->head;
		while (currentnode != NULL && currentnode->data != pos){
			currentnode = currentnode->next;
		}
		if (currentnode == NULL){
			return 0;
		}
		if (currentnode->next == NULL){
                currentnode->next = newNode;
                newNode->previous = currentnode;
                (l->tail) = newNode;
        	}
		else {
			node_t* nextnode = currentnode->next;
			currentnode->next = newNode;
			newNode->previous = currentnode;
			newNode->next = nextnode;
			nextnode->previous = newNode;
		}  			
	}
	return 1;	 		 	 
}

// Returns the item at position pos starting at 0 ( 0 being the first item )
//  (does not remove the item)
// Retruns 0 on failure:
//  * we tried to get at a negative location.
//  * we tried to get past the size of the list
// Returns -1 if the list is NULL
// Assume no negative numbers in the list or the number zero.
int dll_get(dll_t* l, int pos){
	if (l->head == NULL){
		return -1;
	}
	
	if (pos < 0 || pos > (l->count)){
		return 0;
	}

	node_t* cur = l->head;
	while (cur != NULL && cur->data != pos){
		cur = cur->next;
	} 
	return cur->data;
					
}

// Removes the item at position pos starting at 0 ( 0 being the first item )
// Retruns 0 on failure:
//  * we tried to remove at a negative location.
//  * we tried to remove get past the size of the list
// Returns -1 if the list is NULL
// Assume no negative numbers in the list or the number zero.
int dll_remove(dll_t* l, int pos){
        if (pos < 0 || pos > (l->count)){
                return 0;
        }

        node_t* cur = l->head;
        while (cur != NULL && cur->data != pos){
		cur = cur->next;
	}
        
	// Null cur
	if (cur == NULL){
		return -1;
	}

	// Handle first item
	if (cur->previous == NULL){
		if (cur->next == NULL){
		// If only item
			l->head = NULL;
			free(cur);
		} else {
		// If more items
			l->head = cur->next;
			(l->head)->previous = NULL;
			free(cur);
		}
	}

	// Handle last item
	if (cur->next == NULL){
		cur->previous->next = NULL;
		free(cur);
	}

	// Handles middle item
	if (cur->previous != NULL && cur->next != NULL){
		cur->previous->next = cur->next;
		cur->next->previous = cur->previous;
		free(cur);
	}	
return 1;	
}

// DLL Size
// Queries the current size of a DLL
// Returns -1 if the DLL is NULL.
int dll_size(dll_t* t){
	if ((t->head) == NULL){
		return -1;
	}
	(t->head) = (t->head)->next;
	return (t->count)++;			
}

// Free DLL
// Removes a DLL and all of its elements from memory.
// This should be called before the proram terminates.
void free_dll(dll_t* t){
	node_t* cur = t->head;
	
	while(cur != NULL){
		node_t* next = cur->next;
		free(cur);
		cur = next;
	}
}



#endif
