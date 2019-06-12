//-----------------------------------------------------------
//  Purpose:    Header file for the List class.
//  Author:     John Gauch
//-----------------------------------------------------------

#include <time.h>
#include <iostream>
using namespace std;

//-----------------------------------------------------------
// List data node definition
//-----------------------------------------------------------
class LNode
{
 public:
   float Value;
   LNode *Next;
};

//-----------------------------------------------------------
// Define the List class interface 
//-----------------------------------------------------------
class List
{
 public:
   // Constructors
   List();
   List(const List & list);
    ~List();

   // Methods
   bool InsertHead(float value);
   bool InsertTail(float value);
   bool Search(float value);
   bool Delete(float value);
   void Print();
   bool IsEmpty();

 private:
   bool InsertTail(float value, LNode * ptr);
   void Print( LNode * ptr);
   bool Search(float value, LNode * ptr);
   LNode * Head;
};