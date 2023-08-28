#include <iostream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cctype>
using namespace std;

// the functions are declared 
void PolyEncrypt(string word);
void PolyDecrypt(string word);
void RailEncrypt(int key, string word);
void RailDecrypt(int key, string word);

int main() 
{
  // add the makefile and test in jupyterslab
  // make the readme

// the variables are declared 
  ifstream myIn;
  int funct;
  int key;
  string word;

// the file is opened and verified that it was opened 
  myIn.open("test.txt");
  assert(myIn);

// while a function number and key value can be passed from the file 
  while (myIn >> funct >> key)
  {
// the newline character is skipped and the word or phrase is read in
    myIn.ignore();
    getline(myIn, word);

// if 1 is passed in the funct variable, the RailEncrypt function is 
// is called with the given word and key variables 
    if (funct == 1)
    {
      cout << "Rail Fence Encryption: " << endl;
      RailEncrypt(key, word);
      cout << endl;
    }

// if 2 is passed in the funct variable, the RailDecrypt function is 
// is called with the given word and key variables 
    else if (funct == 2)
    {
      cout << "Rail Fence Decryption: " << endl;
      RailDecrypt(key, word);
      cout << endl;
    }

// if 3 is passed in the funct variable, the PolyEncrypt function is 
// is called with the given word 
    else if (funct == 3)
    {
      cout << "Polyalphabetic Encryption: " << endl;
      PolyEncrypt(word);
      cout << endl;
    }

// if 4 is passed in the funct variable, the PolyDecrypt function is 
// is called with the given word 
    else if (funct == 4)
    {
      cout << "Polyalphabetic Decryption: " << endl;
      PolyDecrypt(word);
      cout << endl;
    }
    
  }
  
}

// this function takes the given word and encrypts it using a
// polyalphabetic cipher 
void PolyEncrypt(string word)
{
// the function variables are declared and the given word is displayed
  string start, finish;
  cout << "Given message: " << word << endl;

// for every charatcer in the word string, if a space is found it's removed
// from the other letters in the string and the new string is stored
  for (char x : word)
  {
        if (!isspace(x))
        {
            start += x;
        }
    }

// for every character in the start string, every letter is capitalized for 
// the sake of one of substitution ciphers in the program
  for (char & y : start)
  {
    y = toupper(y);
  }

// for every character in the start string, a loop occurs after a set of five 
// characters are processed
  for (int i = 0; i < start.length(); i += 5)
  {
// within this loop of five charatcers, the current character being processed 
// is assigned to the variable z
    for (int j = 0; j < 5 && i + j < start.length(); j++)
    {
      char z = start[i + j];
      
// cipher M1 shifts a charcter to the left by 3 letters
      char M1 = ((z - 'A' - 3 + 26) % 26) + 'A';

// the character is exchanged using M2A and M2B
      string M2A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      string M2B = "DKVQFIBJWPECSXHTMYAUOLRGZN";

// cipher M3 shifts a charcter to the right by 5 charcters
      char M3 = ((z - 'A' + 5) % 26) + 'A';

// if the character is the 4th character in the set, cipher M1 is performed 
// and the encrypted character is added to the finish string 
      if (j == 3)
      {
        finish += M1;
      }

// if the character is the 1st or the 3rd charcter in the set, cipher M2 is 
// performed and the encrypted charcter is added to the finish string 
      else if ((j == 0) || (j == 2))
      {
// while looking for the given character's match in the M2A string, once the 
// match is found, the index of the found character is applied to M2B and the 
// encrypted charcter is added
        for (size_t i = 0; i < M2A.length(); i++)
        {
          if(M2A[i] == z)
          {
            finish += M2B[i];
            break;
          }
        }
      }

// if the charatcer is the 2nd or the 5th charcter in the set, cipher M3 is 
// performed and the encrypted charcter is added to the finish string 
      else if ((j == 1) || (j == 4))
      {
        finish += M3;
      }
    }
  }

// the finished encrypted message is displayed 
  cout << "Encrypted message: " << finish << endl;
}

// this function takes the given word and decrypts it by reversing
// a polyalphabetic cipher
void PolyDecrypt(string word)
{
// the function variables are declared and the given word is displayed
  string start, finish;
  cout << "Given message: " << word << endl;

// for every charatcer in the word string, if a space is found it's removed
// from the other letters in the string and the new string is stored  
  for (char x : word)
  {
    if (!isspace(x))
    {
      start += x;
    }
  }

// for every character in the start string, every letter is capitalized for 
// the sake of one of substitution ciphers in the program
  for (char & y : start)
  {
     y = toupper(y);
  }

// for every character in the start string, a loop occurs after a set of five 
// characters are processed
  for (int i = 0; i < start.length(); i += 5)
  {
// within this loop of five charatcers, the current character being processed 
// is assigned to the variable z
   for (int j = 0; j < 5 && i + j < start.length(); j++)
   {
     char z = start[i + j];

// cipher M1 shifts a charcter to the right by 3 letters
     char M1 = ((z - 'A' + 3 + 26) % 26) + 'A';

// the character is exchanged using M2A and M2B
     string M2A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
     string M2B = "DKVQFIBJWPECSXHTMYAUOLRGZN";

// cipher M3 shifts a charcter to the right by 5 charcters
     char M3 = ((z - 'A' - 5) % 26) + 'A';

// if the character is the 4th character in the set, cipher M1 is performed 
// (reversed) and the encrypted character is added to the finish string 
     if (j == 3)
     {
       finish += M1;
     }

// if the character is the 1st or the 3rd charcter in the set, cipher M2 is 
// performed (reversed) and the encrypted charcter is added to the finish string 
     else if ((j == 0) || (j == 2))
     {
// while looking for the given character's match in the M2B string, once the 
// match is found, the index of the found character is applied to M2A and the 
// encrypted charcter is added
       for (size_t i = 0; i < M2B.length(); i++)
       {
         if(M2B[i] == z)
         {
           finish += M2A[i];
           break;
         }
       }
     }

// if the charatcer is the 2nd or the 5th charcter in the set, cipher M3 is 
// performed (reversed) and the encrypted charcter is added to the finish string 
     else if ((j == 1) || (j == 4))
     {
       finish += M3;
     }
   }
  }
  
// the finished decrypted message is displayed 
  cout << "Decrypted message: " << finish << endl;
}

// this function takes the given word and key and encrypts the
// word using the rail fence cipher 
void RailEncrypt(int key, string word)
{
// the function variables are declared and the given word is displayed
  int len = word.length();
  char array[key][100]; 
  string start, finish;
  int rail = 0;
  int move = 1; 
  cout << "Given message: " << word << endl;

// for every charatcer in the word string, if a space is found it's removed
// from the other letters in the string and the new string is stored
  for (char x : word)
  {
    if (!isspace(x))
    {
      start += x;
    }
  }

// the length of the updated word is stored
  len = start.length();

// for every coordinate of the 2D array, "-" is stored in its space as a 
// temporary filler
  for (int i = 0; i < key; i++)
  {
    for (int j = 0; j < len; j++)
    {
      array[i][j] = '-';
    }
  }
    
// for the length of the word
  for (int i = 0; i < len; i++)
  {
// characters from the word are stored in their designated location and then 
// the program moves onto the next position in the cipher 
    array[rail][i] = start[i];
    rail += move;

// if the top or bottom of the rail has been reached, the direction of the cipher
// is changed
    if (rail == 0 || rail == key - 1)
    {
      move *= -1; 
    }
  }

// for every coordinate in the 2D array, if the coordinate is not filled by a "-",
// the letter is added to the finish string 
  for (int i = 0; i < key; i++)
  {
    for (int j = 0; j < len; j++)
    {
      if (array[i][j] != '-')
      {
        finish += array[i][j];
      }
    }
  } 

// the encrypted message is displayed 
  cout << "Encrypted message: " << finish << endl;
}

// this function takes the given word and key and decrypts the
// word using the rail fence cipher 
void RailDecrypt(int key, string word)
{
// the function variables are declared and the given word is displayed
  int len = word.length();
  char array[key][100];
  int rail = 0;
  int move = 1;
  int index = 0;
  string finish;
  cout << "Given message: " << word << endl;

// for every coordinate of the 2D array, "-" is stored in its space as a 
// temporary filler
  for (int i = 0; i < key; i++)
  {
    for (int j = 0; j < len; j++)
    {
      array[i][j] = '-';
    }
  }
    
// the direction of the cipher is marked out in the array with "*" and 
// then the program moves onto the next position in the cipher 
  for (int i = 0; i < len; i++)
  {
    array[rail][i] = '*'; 
    rail += move;
    
// if the top or bottom of the rail has been reached, the direction of 
// the cipher is changed
    if (rail == 0 || rail == key - 1)
    {
      move *= -1;
    }
  }
    
// the "*" markers are replaced with the letters from the word string into 
// the array 
  for (int i = 0; i < key; i++)
  {
    for (int j = 0; j < len; j++)
    {
      if (array[i][j] == '*' && index < len)
      {
        array[i][j] = word[index++];
      }
    }
  }
    
// the rail and move variables are reset 
  rail = 0;
  move = 1;

// for every coordinate in the rail design, the letter is added to the finish 
// string, and then the program moves onto the next position in the cipher 
  for (int i = 0; i < len; i++)
  {
    finish += array[rail][i];
    rail += move;

// if the top or bottom of the rail has been reached, the direction of the cipher
// is changed
    if (rail == 0 || rail == key - 1)
    {
      move *= -1;
    }
  }
  
// the decrypted message is displayed 
  cout << "Decrypted message: " << finish << endl;
}
