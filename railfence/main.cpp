#include <iostream>
#include <string>
using namespace std;

string railCipherEncrypt(const string &text, int key)
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

string railCipherDecrypt(const string &text, int key)
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
  int choice, key;

  cout << "Enter the key: ";
  cin >> key;

  while (true)
  {
    cout << "\n1. Encrypt\n2. Decrypt\n3. Exit\nEnter Choice: ";
    cin >> choice;
    cin.ignore(); // To handle newline characters

    if (choice == 1)
    {
      string plaintext;
      cout << "Enter plaintext: ";
      getline(cin, plaintext);
      cout << "Encrypted: " << railCipherEncrypt(plaintext, key) << endl;
    }
    else if (choice == 2)
    {
      string ciphertext;
      cout << "Enter ciphertext: ";
      getline(cin, ciphertext);
      cout << "Decrypted: " << railCipherDecrypt(ciphertext, key) << endl;
    }
    else if (choice == 3)
    {
      cout << "Exiting..." << endl;
      break;
    }
    else
    {
      cout << "Invalid choice. Please try again." << endl;
    }
  }

  return 0;
}
