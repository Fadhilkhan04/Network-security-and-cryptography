#include <iostream>

using namespace std;

string encrypt(string plaintext, int key)
{
  string result = "";
  for (int i = 0; i < plaintext.length(); i++)
  {
    if (isupper(plaintext[i]))
      result += char(int(plaintext[i] + key - 65) % 26 + 65);

    else if (islower(plaintext[i]))
      result += char(int(plaintext[i] + key - 97) % 26 + 97);

    else
    {
      result += " ";
    }
  }
  return result;
}
string decrypt(string ciphertext, int key)
{
  string result = "";
  for (int i = 0; i < ciphertext.length(); i++)
  {
    if (isupper(ciphertext[i]))
      result += char(int(ciphertext[i] - key - 65) % 26 + 65);

    else if (islower(ciphertext[i]))
      result += char(int(ciphertext[i] - key - 97)) % 26 + 97;

    else
    {
      result += " ";
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
    cout << "the cipher text is:" << encrypt(plaintext, key) << endl;
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
    cout << "the plain text is:" << decrypt(ciphertext, key) << endl;
  }
  else
  {
    cout << "error" << endl;
  }
  return 0;
}