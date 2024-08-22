#include <iostream>
using namespace std;

int extendedEuclidean(int a, int b, int &x, int &y)
{
  if (b == 0)
  {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int gcd = extendedEuclidean(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return gcd;
}

int multiplicativeInverse(int a, int b)
{
  int x, y;
  int gcd = extendedEuclidean(a, b, x, y);
  if (gcd != 1)
  {
    cout << "multiplicative inverse doesnt exist" << endl;
    return -1;
  }
  int inverse = (x % b + b) % b;
  return inverse;
}

int main()
{
  int a, b;
  cout << "enter number 1 :";
  cin >> a;
  cout << "enter number 2 :";
  cin >> b;

  int x, y;
  int gcd = extendedEuclidean(a, b, x, y);

  cout << "GCD of " << a << " and " << b << " is:" << gcd << endl;

  cout << "x =" << x << endl;

  int modInverse = multiplicativeInverse(a, b);

  if (modInverse != -1)
  {
    cout << "Multiplicative inverse is :" << modInverse << endl;
  }
  return 0;
}