
#include <iostream>
using namespace std;

int func(int a, int b, int c)
{

  int t;

  if (b == 1)
  {
    return a;
  }

  t = func(a, b / 2, c);

  if (b % 2 == 0)
  {
    return (t * t) % c;
  }
  else
  {
    return (((t * t) % c) * a) % c;
  }
}

int main()
{
  int q, alpha, Xa, Xb, Ya, Yb, k1, k2;

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