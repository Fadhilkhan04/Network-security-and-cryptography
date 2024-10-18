#include <cmath>
#include <iostream>
using namespace std;

// func is a function used to return calculated value of ((a ^ b) mod P)
long long int func(long long int g, long long int h,
                   long long int Ps)
{
  if (h == 1)
    return g;
  else
    return (((long long int)pow(g, h)) % Ps);
}

// Main Code
int main()
{
  long long int Ps, Gs, p, g, q, h, K_A, K_B;

  // Both persons agrees on public keys Gs and Ps
  Ps = 23; // A prime number Ps
  cout << "Value of Ps is: " << Ps << endl;
  Gs = 9; // Gs is primitive root for Ps
  cout << "Value of Gs is: " << Gs << endl;
  // g is the private key chosen by Joy
  g = 4; // The chosen private key is g
  cout << "Private key g is: " << g << endl;
  p = func(Gs, g, Ps); // fetches the generated key
  // h will be the chosen private key by Happy
  h = 3; // The chosen private key is h
  cout << "Private key h is: " << h << endl;
  q = func(Gs, h, Ps); // fetches the generated key
  // After the exchange of keys, generating the secret key
  K_A = func(q, g, Ps); // Joy's Secret key
  K_B = func(p, h, Ps); // Happy's Secret key
  cout << "Joy's Secret key is: " << K_A << endl;
  cout << "Happy's Secret key is: " << K_B << endl;
  return 0;
}