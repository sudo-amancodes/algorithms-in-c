#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// In Euclid's algorithm, (we know in detail about it because it was talked in detail in his treatise -> Elements) he states
// based on the fact that if u > v, then the common divisor of u and v is the same as the greatest common divisor of v and u - v.

// This can be see in the example below:
//      int u = 16; int v = 4;

// Then, gcd(16, 4) -> 16/4 = 4/1.
// This is obtained by 16-4 -> u-v -> 12-4 -> 8-4 -> 4 > 4 (Since the prior is not true, it stops).
// Thus resulting in obtaining the greatest common divisor.

// If v > u, you flip the variable definition.

// 3. Implement a procedure to reduce a given fraction to lowest terms, using a
//    struct fraction { int numerator; int denominator; } .
struct fraction
{
  int numerator;
  int denominator;
};

// Subroutine
// 1. Implement the classical version of Euclid's algorithm as described in the text.
int gcd(int u, int v)
{
  // Create a temp variable t. (Before while scope).
  int t;
  while (u > 0)
  {
    // If u < v (3 < 7).
    // Use the temp variable to flip the values of u and v.
    if (u < v)
    {
      t = u;
      u = v;
      v = t;
    }
    // Keep subtracting u by v (7-3 -> 4-3 -> 3-1 -> 2-1 -> 1-1 (Breaks while loop) and return v -> GCD = 1)
    u = u - v;
  }
  return v;
}

// 461952, 116298
int gcd_large(int u, int v)
{
  int rem, t;
  // 461952 % 116298 = 113058
  while ((u % v) > 0)
  {
    // if 116298, 461952 -> 461952, 116298
    if (u < v)
    {
      t = u;
      u = v;
      v = t;
    }
    // rem = 113058

    rem = u % v;
    // u = 116298
    u = v;
    // v = 113058
    v = rem;
    // 2. Check what values your C system computes for u % v when u and v are not necessarily positive.
    // printf("%d %d %d \n", u, v, rem);
  }
  return v;
}

int gcd_fraction(struct fraction frac)
{
  int rem, t;
  // 461952 % 116298 = 113058
  while ((frac.numerator % frac.denominator) > 0)
  {
    // if 116298, 461952 -> 461952, 116298
    if (frac.numerator < frac.denominator)
    {
      t = frac.numerator;
      frac.numerator = frac.denominator;
      frac.denominator = t;
    }
    // rem = 113058

    rem = frac.numerator % frac.denominator;
    // frac.numerator = 116298
    frac.numerator = frac.denominator;
    // frac.denominator = 113058
    frac.denominator = rem;

    // 2. Check what values your C system computes for frac.numerator % frac.denominator when frac.numerator and frac.denominator are not necessarily positive.
    // printf("%d %d %d \n", frac.numerator, frac.denominator, rem);
  }
  return frac.denominator;
}

// 4. Write a function int convert() that reads a decimal number one character
//    (digit) at a time, terminated by a blank, and returns the value of that number.
int convert()
{
  int number = 0;
  char ch;

  while ((ch = getchar()) != ' ')
  {
    if (isdigit(ch))
    {
      number = number * 10 + (ch - '0');
    }
    else
    {
      printf("Invalid input. Only digits are allowed.\n");
      return -1;
    }
  }
  return 0;
}

// 5. Write a function binary(int x) that prints out the binary equivalent of a number.
void binary(int x)
{
  if (x > 1)
  {
    binary(x / 2);
  }
  printf("%d", x % 2);
}

// 6. Write a program to compute the greatest common divisor of three integers u, v, and w.
int gcd_multiple(int u, int v, int w)
{
  return gcd_large(gcd_large(u, v), w);
}

// Driver
int main()
{
  int x, y, z;

  while (scanf("%d %d %d", &x, &y, &z) != EOF)
  {
    // if (x > 0 && y > 0)
    // struct fraction frac = {x, y};
    // printf("%d %d %d \n", x, y, gcd_fraction(frac));
    printf("%d %d %d \n", x, y, gcd_multiple(x, y, z));
  }
}