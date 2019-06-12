//-----------------------------------------------------------
//  Purpose:    Header file for the integer Stack class.
//  Author:     John Gauch
//-----------------------------------------------------------

#include <cmath>
#include <iostream>
using namespace std;

//-----------------------------------------------------------
// Stack data node definition
//-----------------------------------------------------------
struct StackNode
{
   int Number;
   StackNode *Next;
};

//-----------------------------------------------------------
// Define the Stack class interface 
//-----------------------------------------------------------
class Stack
{
 public:
   // Constructors
   Stack();
   Stack(const Stack & stack);
   ~Stack();

   // Methods
   bool IsFull();
   bool IsEmpty();
   void Push(int Number);
   void Pop(int &Number);
   void Top(int &Number);
   int GetLength();
   void Print();

 private:
   StackNode *Head;
   int Length;
};
