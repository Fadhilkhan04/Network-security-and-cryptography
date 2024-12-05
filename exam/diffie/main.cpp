#include <cmath>
#include <iostream>
using namespace std;

long long int func(long long int a, long long int b, long long int c)
{
  if (b == 1)
  {
    return a;
  }
  else
  {
    return (((long long int)pow(a, b)) % c);
  }
}

int main()
{
  long long int q, alpha, Xa, Xb, Ya, Yb, k1, k2;

  q = 7;
  alpha = 5;

  cout << "The Prime no is : " << q << endl;
  cout << "The primitive root is : " << alpha << endl;

  Xa = 3;
  Xb = 4;

  Ya = func(alpha, Xa, q);
  Yb = func(alpha, Xb, q);

  cout << "the public key of a is :" << Ya << endl;
  cout << "the public key of b is :" << Yb << endl;

  k1 = func(Yb, Xa, q);
  k2 = func(Ya, Xb, q);
  cout << "The shared keys are :" << k1 << "," << k2 << endl;

  return 0;
}