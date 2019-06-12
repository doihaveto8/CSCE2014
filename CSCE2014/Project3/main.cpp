//-----------------------------------------------------------
// Testing function
//-----------------------------------------------------------
#include "list.h"
using namespace std;

int main()
{
   const int size = 10;
   float num[size] = { 0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.5, 7.6, 8.7, 9.8 };
   List list;

   // Test insert head
   for (int count = 0; count < size; count++)
   {
      int index = rand() % size;
      if (list.InsertHead(num[index]))
	 cout << "InsertHead " << num[index] << " ok\n";
      else
	 cout << "InsertHead " << num[index] << " failed\n";
   }
   list.Print();

   // Test copy 
   cout << "Copy\n";
   List copy(list);
   copy.Print();
   // Test search 
   for (int count = 0; count < size; count++)
   {
      int index = rand() % size;
      float search = num[index];
      if (list.Search(search) == true)
	 cout << "Search " << num[index] << " found\n";
      else
	 cout << "Search " << num[index] << " not found\n";
   }
   list.Print();

   // Test delete 
   for (int count = 0; count < size; count++)
   {
      int index = rand() % size;
      if (list.Delete(num[index]) == true)
	 cout << "Delete " << num[index] << " ok\n";
      else
	 cout << "Delete " << num[index] << " failed\n";
   }
   list.Print();

   // Test copy 
   cout << "Copy\n";
   List copy_2(list);
   copy_2.Print();

   // Test insert tail
   for (int count = 0; count < size; count++)
   {
      int index = rand() % size;
      if (copy_2.InsertTail(num[index]))
	 cout << "InsertTail " << num[index] << " ok\n";
      else
	 cout << "InsertTail " << num[index] << " failed\n";
   }
   copy_2.Print();
   cout << "All done" << endl;
}