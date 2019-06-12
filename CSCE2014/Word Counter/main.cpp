#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string words[1000000];
string phrases[1000000];
//------------------------------------------------------------------
// Read a single word from din
//------------------------------------------------------------------
void create_words(string & word, ifstream & din, int & i, bool & end)
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
         words[i] = word + " ";
         i++;
      }
      
      if (din.eof() || din.fail()){
          end = true;
      }
   }
}

void create_phrases()
{
    int done = 0;
    for (int j = 0; done = 1; j++) {
        if (words[j+1] == "") {
            done = 1;
	    return;
	}
        else {
            phrases[j] = words[j] + words[j+1];
	}
    }
}

void merge_sort(string data[], int low, int high)
{
   // Check terminating condition
   int range = high - low + 1;
   if (range > 1)
   {
      // Divide the array and sort both halves
      int mid = (low + high) / 2;
      merge_sort(data, low, mid);
      merge_sort(data, mid + 1, high);

      // Create temporary array for merged data
      string *copy = new string[range];

      // Initialize array indices
      int index1 = low;
      int index2 = mid + 1;
      int index = 0;

      // Merge smallest data elements into copy array
      while (index1 <= mid && index2 <= high)
      {
	 if (data[index1] < data[index2])
	    copy[index++] = data[index1++];
	 else
	    copy[index++] = data[index2++];
      }

      // Copy any remaining entries from the first half
      while (index1 <= mid)
	 copy[index++] = data[index1++];

      // Copy any remaining entries from the second half
      while (index2 <= high)
	 copy[index++] = data[index2++];

      // Copy data back from the temporary array
      for (index = 0; index < range; index++)
	 data[low + index] = copy[index];
      delete[]copy;
   }
}

//---------------------------------------------------------------------
// Main program to read and print words from an ASCII file
//---------------------------------------------------------------------
int main(int argc, char *argv[])
{
   // Get file names
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
      create_words(word, din, i, end);
   }

   create_phrases();
   merge_sort(phrases, 1, i); // Sorts the phrases array in alphabetical order, so all like phrases are next to eachother

   string phrase = phrases[0];
   string counts[100000]; // This array will contain each unique phrase & the # of times it's used
   int count = 0;
   int size = 0; // Used to count the number of unique phrases in the text file

   for (int l = 0; l < i; l++) {
	if (phrase == phrases[l]) {
		count++;
	}
	else if (phrase != phrases[l]) {
		counts[size] = to_string(count) + " ";
		counts[size] = counts[size] + phrase;
		count = 1; // Because if there's a new phrase, you know there's at least 1 of it
		phrase = phrases[l];
		size = size + 1; // Size increases by one because a new unique phrase was found
	}
   }

   ofstream dout;
   dout.open("top_phrases.txt"); // This file stores unsorted list of phrases and # of times they're used

   for (int m = 0; m < size; m++)
	dout << counts[m] << endl;

   // Close files
   din.close();
   dout.close();

// IMPORTANT: this program requires the use of std=c++11 to run, also use the sort -nr filename > top.txt command to get sorted list
}
