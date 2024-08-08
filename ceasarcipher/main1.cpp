#include <iostream>
#include <string>

using namespace std;

// Function to encrypt a string using Caesar Cipher
string encryptCaesarCipher(const string &text, int key)
{
  string result = "";
  key = key % 26; // Ensure the key is within the range of 0-25

  for (size_t i = 0; i < text.length(); ++i)
  {
    char c = text[i];
    if (isalpha(c))
    {
      char base = isupper(c) ? 'A' : 'a';
      c = (c - base + key) % 26 + base;
    }
    result += c;
  }
  return result;
}

// Function to decrypt a string using Caesar Cipher
string decryptCaesarCipher(const string &text, int key)
{
  return encryptCaesarCipher(text, 26 - (key % 26)); // Decryption is just encryption with a negative key
}

int main()
{
  string text;
  int key;
  int choice;

  cout << "Choose an option:\n";
  cout << "1. Encrypt\n";
  cout << "2. Decrypt\n";
  cout << "Enter your choice: ";
  cin >> choice;

  cin.ignore(); // Ignore any newline character left in the input buffer
  cout << "Enter the text: ";
  getline(cin, text);

  cout << "Enter the key: ";
  cin >> key;

  switch (choice)
  {
  case 1:
    cout << "Encrypted text: " << encryptCaesarCipher(text, key) << endl;
    break;
  case 2:
    cout << "Decrypted text: " << decryptCaesarCipher(text, key) << endl;
    break;
  default:
    cout << "Invalid choice. Please select 1 or 2." << endl;
    break;
  }
}