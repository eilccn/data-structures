# Exercises

Discuss and answer the following questions (Make sure to elaborate and justify your responses):

1. How good is the provided hash function--are we really getting constant time operations with our hashmap?
2. What is one other way you could implement the hash function? Anything creative is acceptable in this answer.
3. If I have to resize the hashmap to add more buckets, what is th Big-O complexity?
4. What is 'open addressing' in regards to hash maps and hash tables?

## Answers:

1. Constant time means that an operation will execute in a certain amount of time independent of the input size. A good hash function should uniformly distribute the keys into each of the buckets. With our hash function, we are distributing the keys by dividing the key string length by the number of buckets, obtaining the remainder of that operation, and mapping the key to the remainder value. This is called hashing by division and since it uses a single division operation, it is fast. This method, however, often results in collision, where many keys can end up being mapped to the same bucket. When this happens, we need to be able to store multiple values at each bucket in the array and in our hashmap, we have created linked lists for each bucket. Each time that we need to complete a linear search down linked list when looking up a key, we are operating on linear time. This is why our hashmap operates on "average case" constant time -- looking up a key and arriving at the correct bucket takes constant time, but if there are collisions and a linear search down a linked list is necessary, then we need to operate on linear time. If the linked lists are short enough, then on average the hashmap runs on constant time; however, if the hashmap ends up with longer linked lists then "re-hashing" may be necessary, in which we create a new hashmap that is bigger and insert all of the data back into it.   

2. We could create a hash function with a higher likelihood of generating more unique hashes by incorporating a prime number. 

unsigned int hash(const char *key){
	unsigned long int value = 0;
	unsigned int i = 0;
	unsigned int key_len = strlen(key);
	
	for (i=0; i<key_len; ++i){
		value = value * 37 + key[i];
	}

	value = value % map_size;
	return value;
}
 
3. If we have to resize the hashmap, it means that the Big-O complexity has reached worst-case O(n). This occurs when there are too many collisions hashed into the same keys, requiring longer lookup time through linked lists.  

4. Similar to creating an array of linked lists, open addressing is another method for handling collisions. All elements are stored in the hash table itself so the size of the hashmap should be greater than or equal to the number of keys. In other words, the hashmap does not create an array of linked lists but stores just one key per slot. This method has more predictable memory usage since new nodes are not allocated when keys are inserted. There is also just less memory being used since there are no next pointers used. It inserts keys by probing until an empty slot is found, searches for keys by probing until the same key is found or until an empty slot is reached, and deletes keys by probing until the same key is found and deleting it. Since searching terminates once an empty slot is found, usually slots are just marked as deleted as opposed to being emptied.   


