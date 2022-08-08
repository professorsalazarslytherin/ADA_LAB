/*C program to find the GCD of two numbers using Euclid's,modified Eucild's and
 * Consecutive integer checking method*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main() {
  srand(time(NULL));
  int a, b, m, n, gcd, rem = 0, count = 0, min, temp1, temp2;
  // C program to find GCD of two numbers using Euclid's division
  a = rand() % 100;
  b = rand() % 100;
  m = a;
  n = b;
  while (n != 0) {
    rem = m % n;
    m = n;
    n = rem;
    count++;
  }
  gcd = m;
  printf("\nThe GCD of %d and %d is %d performed in %d iterations", a, b, gcd,
         count);
  count = 0;
  // To find GCD using modified Euclid's algorithm
  if (a == 0 || b == 0) {
    printf("\nThe Modified Euclid's algorithm and consecutive integer checking "
           "doesn't work if either of the integer is 0");
    exit(0);
  }
  m = a;
  n = b;
  while (m != n) {
    count++;
    if (m > n)
      m = m - n;
    else
      n = n - m;
  }
  gcd = m;
  printf("\nThe GCD of %d and %d using Modified Euclid's algorithm is %d with "
         "%d iterations ",
         a, b, gcd, count);
  // To fid GCD of two numbers using Consecutive integer checking method
  count = 0;
  m = a;
  n = b;
  if (m > n)
    n = min;
  else
    m = min;
  while (min != 1) {
    count++;
    temp1 = m % min;
    if (temp1 == 0) {
      temp2 = n % min;
      if (temp2 == 0) {
        gcd = min;
        break;
      }
    }
    min--;
    gcd = min;
  }
  printf("\nThe GCD of %d and %d is %d using Consecutive integer checking "
         "method with %d iterations",
         a, b, gcd, count);
}
