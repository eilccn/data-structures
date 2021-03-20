# Exercises

Discuss and answer the following questions (Please make sure to elaborate and justify your responses):

1. Explain what do you think the Big-Oh (worst-case) complexity of this algorithm is? Why?
2. What do you think the best-case complexity of this algorithm is?
   - Provide an example of an array of elements that fit the best-case.
3. Does insertion sort require any additional storage beyond the original array? Explain why or why not.
4. What is a 'stable sorting' algorithm? Is insertion sort a 'stable' algorithm, why or why not?

## Answers:

1. The Big-O worst case complexity for insertion sort is O(n^2). This is because the worst case will occur when the input is in decreasing order. In the sort function, the while loop executes as long as i > j and array[i] < array[j]. As a result, the total number of while loop iterations is the same as the number of numbers being swapped. The overall time complexity of the algorithm is O(n + f(n)) where f(n) is the number of swaps; therefore, the worst case is O(n^2).
2. The best case complexity is O(n). This would occur when the input list is already sorted or mostly sorted.
3. Insertion sort only requires a constant amount O(1) of additional memory space because it utilizes in-place sorting. As a result, no additional arrays are needed in order to temporarily store data. 
4. Stable sorting algorithms sort repeated elements in the same order that they appear in the input. Insertion sort is a stable algorithm because we only swap elements if the element is larger than the key -- in other words, we do not swap elements when they are equal to each other so their positions in the array do not change. 
