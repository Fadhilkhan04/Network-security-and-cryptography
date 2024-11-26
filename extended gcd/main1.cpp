#include <iostream>
using namespace std;

int euclidean(int a, int b)
{
  if (a == 0)
    return b;
  return euclidean(b % a, a);
  // if (b == 0)
  //   return a;
  // return euclidean(b, a % b);
}
int main()
{

  int a, b;
  cout << "enter number 1 :" << endl;
  cin >> a;
  cout << "enter number 2 :" << endl;
  cin >> b;
  int gcd = euclidean(a, b);
  cout << "gcd is:" << gcd;
  return 0;
}