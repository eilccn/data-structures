// gcc factorial.c -o factorial
// ./factorial

#include <stdio.h>

// TODO: Implement iterative solution here
int factorial(long long int n){
	long long int res = 1, i;
	for (i = 2; i <= n; i++){
		res *= i;
	}
	return res;
}

// TODO: Implement recursive solution here
int factorial_rec(long long int n){
        if (n == 0){
                return 1;
        }
	return n * factorial(n - 1);
        
}

int main(){

  // Both of these should print the same result!
  printf("factorial(10) = %lld\n",factorial(10));
  printf("factorial_rec(10) = %lld\n",factorial_rec(10));


  return 0;
}
