#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#define MX 5

void playfair(char ch1, char ch2, char key[MX][MX])
{
  int i, j, w, x, y, z;
  FILE *out;
  if ((out = fopen("cipher.txt", "a+")) == NULL)
  {
    printf("File corrupted.\n");
    return;
  }

  for (i = 0; i < MX; i++)
  {
    for (j = 0; j < MX; j++)
    {
      if (ch1 == key[i][j])
      {
        w = i;
        x = j;
      }
      else if (ch2 == key[i][j])
      {
        y = i;
        z = j;
      }
    }
  }

  if (w == y)
  {
    x = (x + 1) % 5;
    z = (z + 1) % 5;
    printf("%c%c ", key[w][x], key[y][z]);
    fprintf(out, "%c%c ", key[w][x], key[y][z]);
  }
  else if (x == z)
  {
    w = (w + 1) % 5;
    y = (y + 1) % 5;
    printf("%c%c ", key[w][x], key[y][z]);
    fprintf(out, "%c%c ", key[w][x], key[y][z]);
  }
  else
  {
    printf("%c%c ", key[w][z], key[y][x]);
    fprintf(out, "%c%c ", key[w][z], key[y][x]);
  }
  fclose(out);
}

void removeDuplicates(char str[])
{
  int hash[256] = {0};
  int currentIndex = 0;
  int lastUniqueIndex = 0;
  while (*(str + currentIndex))
  {
    char temp = *(str + currentIndex);
    if (0 == hash[temp])
    {
      hash[temp] = 1;
      *(str + lastUniqueIndex) = temp;
      lastUniqueIndex++;
    }
    currentIndex++;
  }
  *(str + lastUniqueIndex) = '\0';
}

int main()
{
  int i, j, k = 0, l, m = 0, n;
  char key[MX][MX], keyminus[25], keystr[10], str[25] = {0};
  char alpa[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

  printf("Enter key: ");
  gets(keystr);
  printf("Enter the text: ");
  gets(str);

  removeDuplicates(keystr);
  n = strlen(keystr);

  // Convert the key to uppercase and replace 'J' with 'I'
  for (i = 0; i < n; i++)
  {
    if (keystr[i] == 'j')
      keystr[i] = 'i';
    else if (keystr[i] == 'J')
      keystr[i] = 'I';
    keystr[i] = toupper(keystr[i]);
  }

  // Convert the plaintext to uppercase and replace 'J' with 'I'
  for (i = 0; i < strlen(str); i++)
  {
    if (str[i] == 'j')
      str[i] = 'i';
    else if (str[i] == 'J')
      str[i] = 'I';
    str[i] = toupper(str[i]);
  }

  // Construct the key matrix
  j = 0;
  for (i = 0; i < 26; i++)
  {
    for (k = 0; k < n; k++)
    {
      if (keystr[k] == alpa[i])
        break;
    }
    if (k == n)
    {
      keyminus[j] = alpa[i];
      j++;
    }
  }

  k = 0;
  for (i = 0; i < MX; i++)
  {
    for (j = 0; j < MX; j++)
    {
      if (k < n)
      {
        key[i][j] = keystr[k];
        k++;
      }
      else
      {
        key[i][j] = keyminus[m];
        m++;
      }
      printf("%c ", key[i][j]);
    }
    printf("\n");
  }

  // Process the plaintext and generate ciphertext
  printf("\nEntered text: %s\nOutput Text: ", str);
  for (i = 0; i < strlen(str); i++)
  {
    if (str[i + 1] == '\0')
      playfair(str[i], 'X', key);
    else
    {
      if (str[i] == str[i + 1])
        playfair(str[i], 'X', key);
      else
      {
        playfair(str[i], str[i + 1], key);
        i++;
      }
    }
  }
}