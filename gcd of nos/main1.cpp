#include <bits/stdc++.h>
using namespace std;

// Finding the gcd of 2 nos
int gcd(int a, int b)
{
  if (a == 0)
    return b;
  return gcd(b % a, a);
}

int main()
{
  int n1, n2;
  cout << "enter the first element :";
  cin >> n1;
  cout << "enter the second element :";
  cin >> n2;
  int x = gcd(n1, n2);
  cout << "gcd of two numbers is : " << x;
  return 0;
}