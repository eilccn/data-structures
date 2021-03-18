# Exercises

1. What do you think the Big-O (worst-case) complexity of this algorithm is? 
2. What do you think the best-case complexity of this algorithm is? 
	- Note-- assume you do not have any information about if the array is already sorted or not.
3. Does selection sort require any additional storage beyond the original array? 
	- i.e. Did you have to allocate any extra memory to perform the sort?
5. Would the Big-O complexity change if we used a linked list instead of an array?

## Answers:

1. The worst case Big-O complexity of this algorithm is O(n*n) because this is a selection sort, in which the smallest element in an array is repeatedly found in ascending order from an unsorted part of the array and placed in the beginning of an array. This algorithm maintains two subarrays in a given array.
2. Without knowing if the array is already sorted or not, the best case time complexity is O(n*n).
3. I did not have to allocate any extra memory in order to perform the sort.
4. It would not change for a linked-list. It would still be O(n*n).
