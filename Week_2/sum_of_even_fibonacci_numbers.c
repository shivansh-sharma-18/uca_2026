#include <stdio.h>

// Brute Force Approach

long long bruteForceFibonacci(long long n) {
  long long first = 1;
  long long second = 1;
  long long sum = 0;

  while (first <= n) {
    if (first % 2 == 0) {
      sum += first;
    }

    long long next = first + second;
    first = second;
    second = next;
  }

  return sum;
}

// Optimized Approach

long long optimizedFibonacci(long long n) {
  if (n < 2) {
    return 0;
  }

  long long sum = 0;

  long long previousEven = 2;
  long long currentEven = 8;

  while (previousEven <= n) {
    sum += previousEven;

    long long nextEven = (4 * currentEven) + previousEven;

    previousEven = currentEven;
    currentEven = nextEven;
  }

  return sum;
}

int main() {
  long long n;

  printf("Enter the value of n: ");
  scanf("%lld", &n);

  printf("\n");
  printf("Brute Force Result : %lld\n", bruteForceFibonacci(n));
  printf("Optimized Result   : %lld\n", optimizedFibonacci(n));

  return 0;
}
