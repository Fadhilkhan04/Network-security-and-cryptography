
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
			result += ' ';
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
			result += char(int(ciphertext[i] - key - 97) % 26 + 97);

		else
			result += ' ';
	}
	return result;
}

int main()
{
	cout << "MENU";
	cout << "\n1.encrypt";
	cout << "\n2.decrypt";
	int ch;
	cout << "\nenter the choice : (1/2)";
	cin >> ch;

	if (ch == 1)
	{
		string plaintext;
		cin.ignore();
		cout << "\nEnter the plain text :";
		getline(cin, plaintext);
		int key;
		cout << "\nEnter the key :";
		cin >> key;
		cout << "\nPlainText : " << plaintext;
		cout << "\nkey : " << key;
		cout << "\nCipher : " << encrypt(plaintext, key);
	}
	else if (ch == 2)
	{
		string ciphertext;
		cin.ignore();
		cout << "\nEnter the cipher text :";
		getline(cin, ciphertext);
		int key;
		cout << "\nEnter the key :";
		cin >> key;
		cout << "\ncipherText : " << ciphertext;
		cout << "\nkey : " << key;
		cout << "\nPlaintext : " << decrypt(ciphertext, key);
	}
	else
	{
		cout << "\nenter the correct choice";
	}
	return 0;
}
