// =================== Support Code =================
// Hashmap 
//
// - Implement each of the functions to create a working hashmap.
// - Do not change any of the function declarations
//   - (i.e. hashmap_t* hashmap_create() should not have additional arguments)
// - You should not have any 'printf' statements in your functions other 
//   than functions that explicitly ask for printf  output. 
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// - You may add any helper functions that you think you need (if any, or otherwise for debugging)
// ==================================================
#ifndef MY_HASHMAP_T
#define MY_HASHMAP_T

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// A key value pair
// This is specifically for a (char*, char*) key value pair
typedef struct pair{
    char* key;
    char* value;
}pair_t;

// Each node holds a key and a value
typedef struct node{
    struct node* next;
    pair_t* kv;          // 'kv' stands for key/value pair
}node_t;


// Simple hash function that will put a key into a bucket
// You should not modify this
int stringHash(char* myKey, int numberOfBuckets){
    return strlen(myKey) % numberOfBuckets;
}

// Create a function prototype to a function that takes
// in a char* and an int.
typedef int(*hashFunctionPointer)(char*,int) ; 

// Chained implementation of a hashmap
typedef struct hashmap{
    unsigned int buckets;   // i.e. size of the hashmap
    node_t** arrayOfLists;  // An array of linked lists for our buckets
                            // Read another way
                            //      - an array of node_t*

    // A function pointer to a hash function
    // The hash_function must take in a 'char*' as a key, and have a
    // second parameter specifying the number of buckets.
    hashFunctionPointer hashFunction;
}hashmap_t;

// Creates a new hashmap
// Allocates memory for a new hashmap.
// Initializes the capacity(i.e. number of buckets)
hashmap_t* hashmap_create(unsigned int _buckets){
    // Allocate memory for our hashmap
	hashmap_t* map = (hashmap_t*)malloc(sizeof(hashmap_t));
    // Set the number of buckets
	map->buckets = _buckets;
    // Initialize our array of lists for each bucket
	map->arrayOfLists = (node_t**)malloc(sizeof(node_t*)* _buckets);
	for(int i=0; i<_buckets; i++){
		map->arrayOfLists[i] = NULL;
	}
    // Setup our hashFunction to point to our
    // stringHash function.
	map->hashFunction = stringHash;	
    // Return the new map that we have created
    return map;
}

// Frees a hashmap
// Responsibility to free a hashmap that has been previously allocated.
// Must also free all of the chains in the hashmap
// This function should run in O(n) time
void hashmap_delete(hashmap_t* _hashmap){
    if(_hashmap != NULL){
	//TODO
    }
}

// Returns a boolean value if a key has been put into
// the hashmap
//  - Returns a '1' if a key exists already
//  - Returns a '0' if the key does not exist
//  - Returns a '-9999' if the hashmap is NULL
// The algorithm is:
//  - Call the _hashmap's hash function on the key
//  - Search that bucket to see if the key exists.
// This function should run in average-case constant time
int hashmap_hasKey(hashmap_t* _hashmap, char* key){
	unsigned int bucket = _hashmap->hashFunction(key, _hashmap->buckets);
 
	if (_hashmap == NULL){
		return -999;
	}
	return 0;	 
}

// Insert a new key/value pair into a hashmap
// The algorithm is:
//  - If a key already exists, do not add it--return
//  - Call the _hashmap's hash function on the key
//  - Store the key/value pair at the end of the buckets chain
//      - You should malloc the key/value in this function
// This function should run in average-case constant time
void hashmap_insert(hashmap_t* _hashmap,char* key,char* value){
	if (hashmap_hasKey(_hashmap, key)== 1){
		return;
	}
	// Create new pair_t
	pair_t* newpair = (pair_t*)malloc(sizeof(pair_t));
	newpair->key = (char*)malloc(strlen(key)*sizeof(char)+1);
	newpair->value = (char*)malloc(strlen(value)*sizeof(char)+1);
	// Copy the string
	strcpy(newpair->key, key);
	strcpy(newpair->value, value);
	// Create new node
	node_t* newnode = (node_t*)malloc(sizeof(node_t));
	newnode->next = NULL;
	newnode->kv = newpair;

	// Figure out where to put key/value pair in hashmap
	unsigned int bucket = _hashmap->hashFunction(key, _hashmap->buckets);

	// Create iterator and set it to bucket we want
	// Iterate through bucket to end of chain	
	node_t* iter = _hashmap->arrayOfLists[bucket];
	if (iter==NULL){
		// If nothing in bucket, make this first node
		_hashmap->arrayOfLists[bucket] = newnode;
	} else{
		// Prepend to list in current bucket
		// Set new nodes next to not be NULL but the head
		newnode->next = _hashmap->arrayOfLists[bucket];
		// Set first node in bucket as newly created node
		_hashmap->arrayOfLists[bucket] = newnode;
	} 		
}

// Return a value from a key 
// Returns NULL if the key is not found
// The algorithm is:
//  - If the key does not exist, then--return NULL if not found.
//  - Call the _hashmap's hash function on the key
//  - Search the _hashmap's bucket for the key and return the value
// This function should run in average-case constant time
char* hashmap_getValue(hashmap_t* _hashmap, char* key){
	unsigned int bucket = _hashmap->hashFunction(key, _hashmap->buckets);
	
	// Search for bucket
	node_t* iter = _hashmap->arrayOfLists[bucket];
	// Return NULL if nothing in bucket
	if (iter==NULL){
		return NULL;
	}
	// Go through each key in bucket
	while (iter != NULL){
		// Return value if found
		if (strcmp(iter->kv->key, key) == 0){
			return iter->kv->value;
		}
		// Go to next key if available
		iter = iter->next;
	}
	// If this point is reached, there were >=1 buckets but no key match
	return NULL;	
}

// TODO NOTE THAT I DID NOT FINISH REMOVE KEY BECAUSE...
// Remove a key from a hashmap
// The algorithm is:
//  - Determine if the key exists--return if it does not.
//  - Call the _hashmap's hash function on the key
//  - Search the _hashmap's bucket for the key and then remove it
// This function should run in average-case constant time
void hashmap_removeKey(hashmap_t* _hashmap, char* key){
	unsigned int bucket = _hashmap->hashFunction(key, _hashmap->buckets);

	// Search for bucket
	node_t* iter = _hashmap->arrayOfLists[bucket];

	// Return if bucket is empty
	if (iter == NULL){
		return;
	}
	

	// Go through each bucket until end is reached or matching key found
	if (iter->kv->key == NULL){
		return;
	}
	while (iter != NULL){
		// Check key
		if (strcmp(iter->kv->key, key) == 0){
			free(iter->kv->key);
			free(iter->kv->value);
			free(iter);

			return;
		}
	}
}

// Update a key with a new Value
// The algorithm is:
//  - Returns immediately if the key does not exist
//  - Call the _hashmap's hash function on the key
//  - Updates the value of the key to the new value
// This function should run in average-case constant time
void hashmap_update(hashmap_t* _hashmap, char* key, char* newValue){
	unsigned int bucket = _hashmap->hashFunction(key, _hashmap->buckets);
	
	// Search for bucket
	node_t* iter = _hashmap->arrayOfLists[bucket];
	
	// If bucket is empty, update key immediately
	if (iter == NULL){
		hashmap_insert(_hashmap, key, newValue);
		return;
	}
	
	// Go through each entry until either end reached
	// or matching key found
	if (iter->kv->key == NULL){
		return;
	}
	while (iter != NULL){
		// Check key
		if (strcmp(iter->kv->key, key) == 0){
			// Replace value for match found
			free(iter->kv->value);
			iter->kv->value = malloc(strlen(newValue) + 1);
			strcpy(iter->kv->value, newValue);
			return;
		} else {
			return;
		}
	}
}

// Prints all of the keys in a hashmap
// The algorithm is:
//  - Iterate through every bucket and print out the keys
// This function should run in O(n) time
void hashmap_printKeys(hashmap_t* _hashmap){
	// Iterate through all buckets
	for (int i=0; i < _hashmap->buckets; i++){
		printf("Bucket# %d/n", i);
		// Iterate through all the lists
		// starting at each bucket
		node_t* iter = _hashmap->arrayOfLists[i];
		while (iter != NULL){
			// Node consists of a key/value
			printf("/tKey=%s/tValues=%s/n", iter->kv->key, iter->kv->value);
			// Move iterator in that particular bucket
			// forward one node until we reach the end
			iter = iter->next;
		}
	}
}

int main(){

	hashmap_t* map = hashmap_create(8);
	hashmap_insert(map, "red", "10");
	hashmap_insert(map, "orange", "11");
	hashmap_insert(map, "yellow", "12");
	hashmap_insert(map, "green", "13");
	hashmap_insert(map, "blue", "14");
	hashmap_insert(map, "pink", "15");
	hashmap_insert(map, "purple", "16");
	hashmap_insert(map, "violet", "23");
	hashmap_insert(map, "black", "23");
	hashmap_insert(map, "gold", "40");
	hashmap_insert(map, "silver", "23");
	
	hashmap_printKeys(map);
	
	return 0;
}
#endif
