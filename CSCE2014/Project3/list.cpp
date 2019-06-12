//----------------------------------------------
// Purpose: Implement simple List class.
// Author:  John Gauch
//----------------------------------------------

#include "list.h"
#include <stdlib.h>

//----------------------------------------------
// Constructor function.
//----------------------------------------------
List::List()
{
   Head = NULL;
}

//----------------------------------------------
// Constructor function.
//----------------------------------------------
List::List(const List & list)
{
   // Create first node
   LNode *copy = new LNode();
   Head = copy;

   // Walk list to copy nodes
   LNode *ptr = list.Head;
   while (ptr != NULL)
   {
      copy->Next = new LNode();
      copy = copy->Next;
      copy->Value = ptr->Value;
      copy->Next = NULL;
      ptr = ptr->Next;
   }

   // Tidy first node
   copy = Head;
   Head = copy->Next;
   delete copy;
}

//----------------------------------------------
// Destructor function.
//----------------------------------------------
List::~List()
{
   // Walk list to delete nodes
   while (Head != NULL)
   {
      LNode *ptr = Head;
      Head = Head->Next;
      delete ptr;
   }
}

//----------------------------------------------
// Insert data into linked list.
//----------------------------------------------
bool List::InsertHead(float value)
{
   // Create new node
   LNode *ptr = new LNode();
   ptr->Value = value;
   ptr->Next = Head;

   // Insert new node
   Head = ptr;
   return true;
}

//----------------------------------------------
// Insert data into linked list.
//----------------------------------------------
bool List::InsertTail(float value)
{
    InsertTail(value, Head);
}

bool List::InsertTail(float value, LNode* ptr)
{
    // Create new node
    LNode *tmp = new LNode();
    tmp->Value = value;
    
    // Insert new node
    if ((ptr != NULL) && (ptr->Next == NULL))
    {
        tmp->Next = NULL;
        ptr->Next = tmp;
    }
    // Find tail node
    else if ((ptr != NULL) && (ptr->Next != NULL))
        InsertTail(value, ptr->Next);
    
    return true;
}

//----------------------------------------------
// Search for data in linked list.
//----------------------------------------------
bool List::Search(float value)
{
    Search(value, Head);
}

//----------------------------------------------
// Delete data from linked list.
//----------------------------------------------
bool List::Delete(float value)
{
   // Walk list to deletion point
   LNode *curr = Head;
   LNode *prev = Head;
   while ((curr != NULL) && (curr->Value != value))
   {
      prev = curr;
      curr = curr->Next;
   }

   // Check if value was found
   if (curr == NULL)
      return false;

   // Delete node from list
   if (curr == Head)
      Head = curr->Next;
   else
      prev->Next = curr->Next;
   delete curr;
   return true;
}

//----------------------------------------------
// Print all records in linked list.
//----------------------------------------------
void List::Print()
{
    Print(Head);
}

//----------------------------------------------
// Check to see if list is empty.
//----------------------------------------------
bool List::IsEmpty()
{
   return (Head == NULL);
}

bool List::Search(float value, LNode *ptr)
{
    if (ptr == NULL){
       return false;
   }
    
    if (value == ptr->Value){
        return true;
    }
    
   if ((ptr != NULL) && (ptr->Value != value))
   {
       return (Search(value, ptr->Next));
   }
}

void List::Print(LNode * ptr)
{
    if (ptr == NULL){
        return;
    }
    else{
        cout << ptr->Value << endl;
        Print(ptr->Next);
    }
    
    return;
}