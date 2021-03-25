Please edit this document below with your responses. Each question is worth 1/8 of your lab.

# Exercise 1

1. Record here how long it took you to run bubblesort and csort (Note: If you want to run several trials, say '10' and take an average that is an even better result!).

bubblesort results:
real   0m0.345s
user   0m0.343s
sys    0m0.002s

csort results:
real   0m0.008s
user   0m0.005s
sys    0m0.003s

# Exercise 2

What is the Big-O complexity of bubblesort?

O(n*n)

# Exercise 3

Do a little research and discover what algorithm qsort is in the C standard library. What is the algorithm? https://en.wikipedia.org/wiki/Qsort

qsort is a polymorphic sorting algorithm. Polymorphism is the ability to sort different kinds of data.

# Exercise 4

What is the Big-O complexity of 'qsort' that we use in the csort program?

The best case Big-O is O(nlogn) and the worst case is O(n*n).

# Exercise 5

Is qsort's Big-O complexity better or worse than bubblesort? (Anser: Yes it is better/ No it is worse/ It is equal)

It is equal (worst-case).

# Exercise 6

List the following functions in terms of their Big-O complexity from **smallest** to **largest**.
<img src="./media/bigo.jpg"/>

logn, n, n^2, n^3, 2^n, n!

# Exercise 7

- Given: f(n) = 3n^3 + n^2 + 27
- What is the O(n) of f(n)?

O(n^3)

# Exercise 8

- Given: f(n) = 3n^3 + n^2 + 27
- What are two constants c and k that prove your answer in exercise 7.

c=31 and n=1
