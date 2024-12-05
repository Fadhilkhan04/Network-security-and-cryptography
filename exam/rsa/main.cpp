#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

long int gcd(long long int a, long long int b)
{
  if (a == 0)
    return b;
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

long int func(long long int a, long long int b, long long int c)
{

  long long int t;
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
  long long int p, q, n, phi, e, d;

  cout << "\nEnter the P value: ";
  cin >> p;
  cout << "\nEnter the Q value: ";
  cin >> q;

  n = p * q;
  phi = (p - 1) * (q - 1);

  do
  {
    e = rand() % phi;
  } while (gcd(phi, e) != 1 || e <= 1);

  do
  {
    d = rand() % phi;
  } while (((d * e) % phi) != 1);

  cout << "\nTwo prime numbers (p and q) are: " << p << " and " << q << endl;
  cout << "n (p * q) = " << p << " * " << q << " = " << n << endl;
  cout << "(p - 1) * (q - 1) = " << phi << endl;

  cout << "Public key (n, e): (" << n << ", " << e << ")\n";
  cout << "Private key (n, d): (" << n << ", " << d << ")\n";

  long long int m;
  cout << "enter the plain text:" << endl;
  cin >> m;
  cout << "encrypted :" << func(m, e, n) << endl;
  cout << endl;
  long long int c;
  cout << "enter the cipher text:" << endl;
  cin >> c;
  cout << "decrypted :" << func(c, d, n) << endl;
  cout << endl;
}