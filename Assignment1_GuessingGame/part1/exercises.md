# Exercises

In order to start thinking a bit algorithmically, modify this file and answer the following questions. Be sure to add/commit/push any changes made to this file to our repository.

1. In the worst case in our guessing game--how many guesses could it take to get the right number if we had no hint at all? Explain.
2. In the worst case in our guessing game--how many guesses does it take to get the right number if we get a hint of 'higher or lower' when guessing numbers 1-10? *Hint* In your answer show this mathematically with the [log function](https://www.mathsisfun.com/algebra/logarithms.html).

## Answers

1. It would take 10 guesses. The user is given a range of ten numbers 1-10 and one out of the 10 is the correct number. In the worst case scenario, the user would fail to guess the correct number 9 times, ruling out every number except the correct number, before guessing correctly on their 10th guess. 
2. It would take roughly the log base 2 of 10 guesses. We use base 2 since the hint of higher or lower divides the number of guesses the user needs to take by 2 with each new  guess.  
