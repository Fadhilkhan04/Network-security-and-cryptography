#include <iostream>
using namespace std;

int extendedGcd(int a, int b, int &x, int &y)
{
  if (b == 0)
  {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int gcd = extendedGcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return gcd;
}

int mult(int a, int b)
{
  int x, y;
  int gcd = extendedGcd(a, b, x, y);

  if (gcd != 1)
  {
    cout << "multiplicative inverse doesnt exist." << endl;
    return -1;
  }
  int modInverse = (x % b + b) % b;
  return modInverse;
}

int main()
{

  int a, b, x, y;
  cout << "Enter number 1:" << endl;
  cin >> a;
  cout << "Enter number 2:" << endl;
  cin >> b;

  int gcd = extendedGcd(a, b, x, y);
  cout << "Gcd is:" << gcd << endl;
  cout << "X is:" << x;

  int modInverse = mult(a, b);

  if (modInverse != -1)
  {
    cout << "multiplicative inverse is:" << modInverse << endl;
  }
  return 0;
}