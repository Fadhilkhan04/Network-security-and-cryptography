#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void displayMatrix(char arr[5][5])
{
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
}

// to remove the keyword characters from the alphabets
string removeoccurence(string alphabets, string key)
{
  for (int i = 0; i < alphabets.size(); i++)
  {
    for (int j = 0; j < key.size(); j++)
    {
      if (alphabets[i] == key[j])
      {
        // int n = alphabets.find(alphabets[i]);
        alphabets.erase(alphabets.begin() + i);
      }
    }
  }
  return alphabets;
}

// to remove the duplicate alphaabets from the key
string removeduplicates(string str)
{
  string result = "";
  int i, j;
  for (i = 0; i < str.size(); i++)
  {
    for (j = 0; j < i; j++)
    {
      if (str[i] == str[j])
      {
        break;
      }
    }
    if (j == i)
    {
      result += str[i];
    }
  }
  return result;
}

int main()
{

  string key;
  string plaintext;

  cout << "Enter the key :";
  getline(cin, key);

  // cin.ignore();

  cout << "Enter the plaintext :";
  getline(cin, plaintext);

  string uniquetext = removeduplicates(key); // function call to remove duplicates

  string alphabets = "abcdefghiklmnopqrstuvwxyz";

  string uniquealphabets = removeoccurence(alphabets, uniquetext);

  string final = uniquetext + uniquealphabets;

  char arr[5][5];

  // matrix created
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      arr[i][j] = final[i * 5 + j];
    }
  }

  displayMatrix(arr); // display matrix

  return 0;
}