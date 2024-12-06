#include <iostream>
#include <string>

using namespace std;

string encrypt(string text, int key)
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

string decrypt(string text, int key)
{
  string result(text.length(), '*');
  int len = text.length();
  int index = 0;

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
  int ch;
  cout << "1.encryption" << endl;
  cout << "2.decryption" << endl;
  cout << "Enter your choice:" << endl;
  cin >> ch;

  if (ch == 1)
  {
    string plaintext;
    int key;
    cin.ignore();
    cout << "enter the plaintext:" << endl;
    getline(cin, plaintext);
    cout << "enter the key:" << endl;
    cin >> key;
    cout << "Encrypted text is :" << encrypt(plaintext, key);
  }
  else if (ch == 2)
  {
    string ciphertext;
    int key;
    cin.ignore();
    cout << "enter the ciphertext:" << endl;
    getline(cin, ciphertext);
    cout << "enter the key:" << endl;
    cin >> key;
    cout << "Encrypted text is :" << decrypt(ciphertext, key);
  }
  else
  {
    cout << "errorr..";
  }
  return 0;
}