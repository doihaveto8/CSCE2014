//-----------------------------------------------------------
// Main program.
//-----------------------------------------------------------
#include "Stack.h"
#include <stdlib.h>
#include <string.h>

int main()
{
    Stack stack;
    string str = "";
    int num1, num2;
    int result = 0;
    
    cout << "Enter boolean expression: ";
    while (str != "?")
    {
	cin >> str;
	if ((str == "==") or (str == "<") or (str == ">") or (str == "<=")
	   or (str == "!=") or (str == ">=") or (str == "&&") or (str == "||")) {
		if (stack.GetLength() < 2) {
			cout << "ERROR: VARIABLE COUNT TOO LOW" << endl;
			return 0;
		}
		stack.Pop(num2);
		stack.Pop(num1);

		if (str == "==") {
		stack.Push(num1 == num2);	
		}

		else if (str == "<") {
		stack.Push(num1 < num2);
		}

		else if (str == "<=") {
		stack.Push(num1 <= num2);
		}

		else if (str == ">") {
		stack.Push(num1 > num2);
		}

		else if (str == ">=") {
		stack.Push(num1 >= num2);
		}

		else if (str == "!=") { 
		stack.Push(num1 != num2);
		}

		else if (str == "&&") {
		stack.Push(num1 and num2);
		}

		else if (str == "||") {
		stack.Push(num1 or num2);
		}
	} 

	else if (str != "?") { 
		stack.Push(stoi(str)); //The program exits on it's own when str isn't a number
	}
    }

	stack.Pop(result);
	cout << "The result for the expression you entered is ";
	if (result == 1)
		cout << "TRUE" << endl;
	else if (result == 0)
		cout << "FALSE" << endl;
	return 0;
}

