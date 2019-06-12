#include "hash.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

//------------------------------------------------------------------
// Read a single word from din
//------------------------------------------------------------------
void create_words(string & word, ifstream & din, int & i, bool & end, HashTable & ht)
{
   // Initialize variables
   word = "";
   bool found_word = false;
   
   // Loop reading characters until word is found
   while (!din.fail() && !din.eof() && !found_word)
   {
      // Read next character from file
      char ch;
      din.get(ch);

      // Append lower case letter to word
      if (ch >= 'a' && ch <= 'z')
	 word = word + ch;

      // Convert upper case letter to lower case and append
      else if (ch >= 'A' && ch <= 'Z')
	 word = word + char(ch - 'A' + 'a');

      // Return word if length greater than zero
      else if (word.length() > 0){
         found_word = true;
         int count = 0;
		ht.Search(word, count);
		ht.Insert(word, count + 1);
         i++;
      }
      
      if (din.eof() || din.fail()){
          end = true;
      }
   }
}

//---------------------------------------------------------------------
// Main program to read and print words from an ASCII file
//---------------------------------------------------------------------
int main(int argc, char *argv[])
{
   // Get file names
   HashTable ht(28000);
   cout << "Enter name of input file: ";
   string name1;
   bool end = false;
   int i = 0;
   cin >> name1;
   
   // Open files
   ifstream din;
   din.open(name1.c_str());
   if (din.fail()) {
	cout << "File does not exist" << endl;
	return 0;
}

   // Read and print words
   string word;
   while (!end) {
      create_words(word, din, i, end, ht);
   }

	ht.Print();

   // Close files
   din.close();

// IMPORTANT: this program requires the use of std=c++11 to run, also use the sort -nr filename > top.txt command to get sorted list
}
