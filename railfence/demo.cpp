#include <stdio.h>
int extendedEuclidean(int a, int b, int *x, int *y)
{
  if (b == 0)
  {
    *x = 1;
    *y = 0;
    return a;
  }
  int x1, y1;
  int gcd = extendedEuclidean(b, a % b, &x1, &y1);
  *x = y1;
  *y = x1 - (a / b) * y1;
  return gcd;
}
int multiplicativeInverse(int a, int m)
{
  int x, y;
  int gcd = extendedEuclidean(a, m, &x, &y);

  if (gcd != 1)
  {
    printf("Multiplicative inverse doesn't exist.\n");
    return -1;
  }
  int inverse = (x % m + m) % m;
  return inverse;
}
int main()
{
  int a, b;
  printf("Enter the first number: ");
  scanf("%d", &a);
  printf("Enter the second number: ");
  scanf("%d", &b);
  int x, y;
  int gcd = extendedEuclidean(a, b, &x, &y);
  printf("GCD of %d and %d is: %d\n", a, b, gcd);
  printf("x: %d\n", x);
  int modInverse = multiplicativeInverse(a, b);
  if (modInverse != -1)
  {
    printf("Multiplicative inverse of %d in gf(%d) is: %d\n", a, b, modInverse);
  }
  return 0;
}
