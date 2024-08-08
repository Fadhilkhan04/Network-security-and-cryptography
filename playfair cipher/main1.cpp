#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void prepareKeyMatrix(string key, char keyMatrix[5][5])
{
      bool exists[26] = {false};
      exists['J' - 'A'] = true;

      int index = 0;
      for (int i = 0; i < key.size(); i++)
  {
            char c = toupper(key[i]);
            if (!exists[c - 'A'])
    {
                  keyMatrix[index / 5][index % 5] = c;
                  exists[c - 'A'] = true;
                  index++;
             
    }
       
  }
      for (char c = 'A'; c <= 'Z'; c++)
  {
            if (!exists[c - 'A'])
    {
                  keyMatrix[index / 5][index % 5] = c;
                  exists[c - 'A'] = true;
                  index++;
             
    }
       
  }
}

pair<int, int> findPosition(char keyMatrix[5][5], char c)
{
      if (c == 'J') c = 'I';
      for (int i = 0; i < 5; i++)
  {
            for (int j = 0; j < 5; j++)
    {
                  if (keyMatrix[i][j] == c)
      {
                        return make_pair(i, j);
                   
      }
             
    }
       
  }
      return make_pair(-1, -1);
}

string processText(string text)
{
      text.erase(remove(text.begin(), text.end(), ' '), text.end());
      for (int i = 0; i < text.size(); i++)
  {
            text[i] = toupper(text[i]);
            if (text[i] == 'J') text[i] = 'I';
       
  }
      return text;
}

string prepareDigraphs(string text)
{
      string preparedText;
      for (int i = 0; i < text.length(); i++)
  {
            preparedText += text[i];
            if (i + 1 < text.length() && text[i] == text[i + 1])
    {
                  preparedText += 'X';
             
    }
       
  }
      if (preparedText.length() % 2 != 0)
  {
            preparedText += 'X';
       
  }
      return preparedText;
}

string encrypt(string text, char keyMatrix[5][5])
{
      text = processText(text);
      text = prepareDigraphs(text);
      string encryptedText;
      for (int i = 0; i < text.length(); i += 2)
  {
            pair<int, int> pos1 = findPosition(keyMatrix, text[i]);
            pair<int, int> pos2 = findPosition(keyMatrix, text[i + 1]);

            if (pos1.first == pos2.first)
    {
                  encryptedText += keyMatrix[pos1.first][(pos1.second + 1) % 5];
                  encryptedText += keyMatrix[pos2.first][(pos2.second + 1) % 5];
             
    }
    else if (pos1.second == pos2.second)
    {
                  encryptedText += keyMatrix[(pos1.first + 1) % 5][pos1.second];
                  encryptedText += keyMatrix[(pos2.first + 1) % 5][pos2.second];
             
    }
    else
    {
                  encryptedText += keyMatrix[pos1.first][pos2.second];
                  encryptedText += keyMatrix[pos2.first][pos1.second];
             
    }
       
  }
      return encryptedText;
}

string decrypt(string text, char keyMatrix[5][5])
{
      text = processText(text);
      string decryptedText;
      for (int i = 0; i < text.length(); i += 2)
  {
            pair<int, int> pos1 = findPosition(keyMatrix, text[i]);
            pair<int, int> pos2 = findPosition(keyMatrix, text[i + 1]);

            if (pos1.first == pos2.first)
    {
                  decryptedText += keyMatrix[pos1.first][(pos1.second + 4) % 5];
                  decryptedText += keyMatrix[pos2.first][(pos2.second + 4) % 5];
             
    }
    else if (pos1.second == pos2.second)
    {
                  decryptedText += keyMatrix[(pos1.first + 4) % 5][pos1.second];
                  decryptedText += keyMatrix[(pos2.first + 4) % 5][pos2.second];
             
    }
    else
    {
                  decryptedText += keyMatrix[pos1.first][pos2.second];
                  decryptedText += keyMatrix[pos2.first][pos1.second];
             
    }
       
  }
      return decryptedText;
}

int main()
{
      char keyMatrix[5][5];
      string key, text;
      char choice;

      cout << "Enter key: ";
      cin >> key;
      transform(key.begin(), key.end(), key.begin(), ::toupper);
      prepareKeyMatrix(key, keyMatrix);

      cout << "Enter E to encrypt or D to decrypt: ";
      cin >> choice;
      choice = toupper(choice);

      if (choice == 'E')
  {
            cout << "Enter text to encrypt: ";
            cin.ignore();
            getline(cin, text);
            transform(text.begin(), text.end(), text.begin(), ::toupper);
            cout << "Encrypted text: " << encrypt(text, keyMatrix) << endl;
       
  }
  else if (choice == 'D')
  {
            cout << "Enter text to decrypt: ";
            cin.ignore();
            getline(cin, text);
            transform(text.begin(), text.end(), text.begin(), ::toupper);
            cout << "Decrypted text: " << decrypt(text, keyMatrix) << endl;
       
  }
  else
  {
            cout << "Invalid choice!" << endl;
       
  }

      return 0;
}