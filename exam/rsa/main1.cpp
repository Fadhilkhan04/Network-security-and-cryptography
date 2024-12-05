#include <iostream>
#include <cstdlib>
using namespace std;

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int func(int a, int b, int c)
{
  int t;
  if (b == 1)
    return a;

  t = func(a, b / 2, c);

  if (b % 2 == 0)
    return (t * t) % c;
  else
    return (((t * t) % c) * a) % c;
}

int main()
{
  int p, q, n, phi, e, d;
  cout << "Enter the p value :" << endl;
  cin >> p;
  cout << "Enter the q value:" << endl;
  cin >> q;
  n = p * q;
  phi = (p - 1) * (q - 1);
  cout << "the n value is:" << n << endl;
  cout << "the phi value is:" << phi << endl;
  do
  {
    e = rand() % phi;
  } while (gcd(phi, e) != 1 || e <= 1);

  do
  {
    d = rand() % phi;
  } while ((d * e) % phi != 1);

  cout << "the public key is :" << e << endl;
  cout << "the private key is :" << d << endl;

  int m, c;
  cout << "enter the number to encrypt :" << endl;
  cin >> m;
  cout << "the encrypted number is:" << func(m, e, n);
  cout << "enter the number to decrypt :" << endl;
  cin >> c;
  cout << "the decrypted number is:" << func(c, d, n);

  return 0;
}