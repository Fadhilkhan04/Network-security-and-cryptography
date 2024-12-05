#include <iostream>
#include <string>
using namespace std;

string Encrypt(string text, int key)
{
  string result;
  int len = text.length();

  for (int i = 0; i < key; i++)
  {
    int step1 = 2 * (key - i - 1);
    int step2 = 2 * i;
    int pos = i;
    bool toggle = true;

    while (pos < len)
    {
      result += text[pos];
      if (step1 == 0 || step2 == 0)
      {
        pos += step1 + step2;
      }
      else
      {
        pos += toggle ? step1 : step2;
        toggle = !toggle;
      }
    }
  }

  return result;
}

string Decrypt(string text, int key)
{
  string result(text.length(), '*');
  int len = text.length(), index = 0;

  for (int i = 0; i < key; i++)
  {
    int step1 = 2 * (key - i - 1);
    int step2 = 2 * i;
    int pos = i;
    bool toggle = true;

    while (pos < len)
    {
      result[pos] = text[index++];
      if (step1 == 0 || step2 == 0)
      {
        pos += step1 + step2;
      }
      else
      {
        pos += toggle ? step1 : step2;
        toggle = !toggle;
      }
    }
  }

  return result;
}

int main()
{
  cout << "1.Encryption" << endl;
  cout << "2.Decryption" << endl;
  int ch;
  cout << "enter the choice:" << endl;
  cin >> ch;

  if (ch == 1)
  {
    string plaintext;
    cin.ignore();
    cout << "enter the plaintext:" << endl;
    getline(cin, plaintext);
    int key;
    cout << "enter the key" << endl;
    cin >> key;
    cout << "the cipher text is:" << Encrypt(plaintext, key) << endl;
  }
  else if (ch == 2)
  {
    string ciphertext;
    cin.ignore();
    cout << "enter the ciphertext:" << endl;
    getline(cin, ciphertext);
    int key;
    cout << "enter the key" << endl;
    cin >> key;
    cout << "the plain text is:" << Decrypt(ciphertext, key) << endl;
  }
  else
  {
    cout << "error" << endl;
  }
  return 0;
}