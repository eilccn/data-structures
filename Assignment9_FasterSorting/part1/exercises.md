**Instructions** 

- Discuss and answer the following questions (Make sure to elaborate and justify your responses):
- If you would like to hand write or draw your answers, then scan or take a picture of a file called exercises.pdf or exercises.png and put it in this directory.


# Exercises

1. Explain: What do you think the Big-O (worst-case) complexity of the merge sort algorithm is and why? 

The worst-case complexity is O(nlogn). The worst case will occur when merge sort will have to do a maximum amount of comparisons where every element of each subarray will be compared at least once. Since merge sort uses the divide and conquer method, the total number of stages in which the array is halved gives the algorithm a time complexity of log(n). The number of comparisons made at each stage gives the time complexity of O(nlogn).

2. Explain: What do you think the best-case complexity of the merge sort algorithm is and why?

The best case complexity is still O(nlogn). In the best case scenario, the array is already sorted; however, in both worst and best case, merge sort always divides the array into two halves and takes linear time to merge the two haves to give nlogn.

3. Does merge sort require any additional storage beyond the original array? If so how much and why?

Merge sort does not sort in place so it requires additional storage. The space required is linear to the size of the array. This means that it needs n for the first stage, n/2 for the second stage, etc. The space complexity, therefore, is O(n).

4. How much time in Big-O does it take to merge all of the subarrays together? Explain or draw why?

Merging the subarrays, made by dividing the original array of n elements requires a time complexity of O(n). This is because we are only taking into account the time complexity of merging all the subarrays at the final stage and not the entire mergesort process. Simply merging n elements together requires O(n) complexity. At each stage, the number of subarrays doubles, but the merging time halves, resulting in the doubling and halving canceling each other out. In other words, we can have 2 subarrays or 8 subarrays, but the complexity will always be O(n) because 2 * n/2 = n and 8 * n/8 = n. 

## Interview Prep (Optional +1% Bonus on assignment)

> **Rules** 
> 
> This is for bonus--and you may not ask TA's, Professors, or anyone about the question until after the homework is due.
> 
> Stratigically, you should not attempt this problem until you complete the rest of the homework (1% is less than 100% :) )

A bit ago a student asked me about this course, CS 5800, and other courses and how they may prepare you for interviews. I was recently talking to a Google, now Microsoft Engineer who told me that the reality is having a lot of LeetCode practice will help. LeetCode is a website to practice solving algorithmic challenges.

Let's finish off this exercise with a small C programming sample.

###

Solve the following: https://leetcode.com/problems/merge-sorted-array/

**Copy and paste your code into** a file in this directory called [challenge.c](./challenge.c) that solves the following problem.

**Given:** Two sorted integer arrays `nums1` and `nums2`, merge nums2 into nums1 as one sorted array and return the sorted array as a new array.

The number of elements initialized in `nums1` and `nums2` are *m* and *n* respectively.

Example 1:

```
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
```

Example 2:

```
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
```

Constraints:

```
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[i] <= 109
```
