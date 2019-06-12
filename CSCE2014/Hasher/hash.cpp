//-----------------------------------------------------------
//  Purpose:    Implementation of HashTable class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include "hash.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;


//-----------------------------------------------------------
// Constructor
//-----------------------------------------------------------
HashTable::HashTable(int size)
{
   Size = size;
   Value = new int[Size];
   Key = new string[Size];

   for (int index = 0; index < Size; index++)
   {
      Value[index] = NONE;
      Key[index] = EMPTY;
   }
}

//-----------------------------------------------------------
// Copy constructor
//-----------------------------------------------------------
HashTable::HashTable(const HashTable & ht)
{
   Size = ht.Size;
   Value = new int[Size];
   Key = new string[Size];

   for (int index = 0; index < Size; index++)
   {
      Value[index] = ht.Value[index];
      Key[index] = ht.Key[index];
   }
}

//-----------------------------------------------------------
// Destructor
//-----------------------------------------------------------
HashTable::~HashTable()
{
   if (Value != NULL)
      delete[]Value;
   if (Key != NULL)
      delete[]Key;
   Value = NULL;
   Key = NULL;
   Size = 0;
}

//-----------------------------------------------------------
// Insert method
//-----------------------------------------------------------
bool HashTable::Insert(string key, int value)
{
   // Find desired key
   int index = Hash(key);
   while ((Key[index] != key) && (Key[index] != EMPTY))
      index = Hash2(index);

   // Insert value into hash table
   Value[index] = value;
   Key[index] = key;
   return true;
}

//-----------------------------------------------------------
// Search method
//-----------------------------------------------------------
bool HashTable::Search(string key, int &value)
{
   // Find desired key
   int index = Hash(key);
   while ((Key[index] != key) && (Key[index] != EMPTY))
      index = Hash2(index);

   // Return value from hash table
   if (Key[index] == key)
      value = Value[index];
   return (Key[index] == key);
}

//-----------------------------------------------------------
// Delete method
//-----------------------------------------------------------
bool HashTable::Delete(string key)
{
   // Find desired key
   int index = Hash(key);
   while ((Key[index] != key) && (Key[index] != EMPTY))
      index = Hash2(index);

   // Delete value from hash table
   if (Key[index] == key)
   {
      Value[index] = NONE;
      Key[index] = DELETED;
      return true;
   }
   return false;
}

//-----------------------------------------------------------
// Primary hash function
//-----------------------------------------------------------
int HashTable::Hash(string key)
{
   int num = 42;
   for (int i = 0; i < int(key.length()); i++){
      num = (num * 17 + key[i]) % Size; // Orig. Formula
//      num = (num * 10 + key[i]) % Size; // New Formula 1
//      num = (num * 5 + key[i]) % Size; // New Formula 2
//      num = (num * 34 + key[i]) % Size; // New Formula 3
}
   return num;
}

//-----------------------------------------------------------
// Secondary hash function
//-----------------------------------------------------------
int HashTable::Hash2(int index)
{
   // cout << "collision\n";
   collisions++;
   return (index + 1) % Size; // Linear Probing
//   return (index + 3) % Size; // Secondary Hashing
}

//-----------------------------------------------------------
// Print function for debugging
//-----------------------------------------------------------
void HashTable::Print()
{
   ofstream dout;
   dout.open("Words.txt");

   for (int index = 0; index < Size; index++)
      if (Value[index] > 0)
	 dout << Value[index] << " " << Key[index] << endl;
   dout << "There were " << collisions << " collisions" << endl;

   dout.close();
}
