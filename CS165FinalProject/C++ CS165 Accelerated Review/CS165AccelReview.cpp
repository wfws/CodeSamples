/************************************************************
**	Program Filename: CS165AccelReview.CPP
**	Author: Wayne Cordrey    ONID: 932304741
**	Date: Mar 14, 2014
**	Description: Accelerated Review of CS165   
**	Input: Reuires User Y response to access
**  NOTE:  REQUIRES COMMAND LINE SINGLE DIGIT INTEGER !!! 
**  NOTE:  Also requires "employee.txt" in same directory
**	Output: Program outputs to console display
*************************************************************/

#include<string>
#include<iostream>
#include<iomanip>
#include<ctime>
#include<cmath>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<iomanip>
#include<vector>
#include"AccelReview.h"
using namespace std;

/**************************************************
** Function: Struct Numbers
** Description: helper file for 23 Struct
***************************************************/
struct Numbers
{
	int firstNumber; 
	int nextNumber; 
}Numbers1; 

/**************************************************
** Function: Namespace cordreyw
** Description: helper function for 28. Namespace
***************************************************/
namespace cordreyw
{
	int twoNumbers(int x, int y)
	{
		return x + y; 
	}
}

/**************************************************
** Function: ElmerFudd namespace 
** Description: helper namespace for 28 Namespace 
****************************************************/
namespace ElmerFudd
{
	int twoNumbers(int x, int y)
	{
		return x * y; 
	}	
}



/*********) Program Structure Functions (***********************/
void intro(); 
int menu();
void doChoice(int choice, int arg); 

/**********************)   MAIN   (******************************/
int main( int argc, char *argv[])
{
	// code related to menu item 22, Command line argument.  
	 int commandArg = (*argv[1]-48); 
	
	char reply; 
	intro(); 
	do{
		doChoice(menu(), commandArg);   // execute menu choice based on user input
		cout << "Enter another menu choice? (Y/N): " ; 
		cin>> reply; 
	}while(reply == 'Y' || reply == 'y'); 
	
	cout << "\nThank you for a great class! \n" << endl; 
	//system("pause");
	return 0; 
} 

/***************)  Intro   function  (*************
** Function: Intro
** Description: Introduction to program with choice
** to start or exit. 
***************************************************/
void intro()
{
	char reply; 
	cout << " **********************)  CS165 Accelerated Review  (*************************"; 
	cout << "\nProgrammed by Wayne Cordrey" << endl; 
	cout << "\nThis is an accelerated review of what I learned in CS165.  "  << endl; 
	cout << "Its a valuable collection of code examples " << endl; 
	cout << "from almost everything covered in class. " << endl; 
	cout << "\nNOTE:  I am trying to recover some points lost on the exam for " << endl; 
	cout << "Question 17, output from 2D array.  " << endl; 
	cout <<"\nSelect a menu item to see a brief example " << endl; 
	cout << "\nof each of the project requirements. "<< endl;
	cout << endl; 
	cout << "Press Y to begin, or N to exit. "; 
	cin >> reply; 
	if(reply == 'Y' || reply == 'y')
		return;  
	else if(reply == 'N' || reply == 'n') 
	{
		cout << "Goodbye. " << endl; 
		exit; 
	}
	return; 
}

/*****************)  Menu function  (**************
** Function: Menu
** Description: Displays choices, takes user choice input
** Pre-Conditions: called from Main
** Post-Conditions: returns int choice
***************************************************/
int menu()
{
	int choice = 0; 
	cout << endl; 
	cout << " **********************)  Menu Choices  (*************************"<< endl; 
	
	cout << endl << endl; 
	cout << setw(5) << "1." << setw(3) << " Binary numbers " << setw(15) << "2. " << setw(3) << " Two's Complement " << endl;
	cout << setw(5) << "3." << setw(3) << " Macros " << setw(23) << "4. " << setw(3) << " Simple Output " << endl;
	cout << setw(5) << "5." << setw(3) << " Simple Input " << setw(17) << "6. " << setw(3) << " Type Casting " << endl;
	cout << setw(5) << "7." << setw(3) << " Conditional " << setw(18) << "8. " << setw(3) << " Logic Operator " << endl;
	cout << setw(5) << "9." << setw(3) << " Looping " << setw(22) <<"10. " << setw(3) << " Random Number " << endl;
	cout << setw(5) << "11." << setw(3) << " Error Categories " << setw(13) << "12. " << setw(3) << " Debugging Tricks " << endl;
	cout << setw(5) << "13." << setw(3) << " Functions " << setw(20) << "14. " << setw(3) << " Function Decomposition " << endl;
	cout << setw(5) << "15." << setw(3) << " Scope " << setw(24) << "16. " << setw(3) << " Passing Mechanisms  " << endl;
	cout << setw(5) << "17." << setw(3) << " Function Overloading " << setw(9) << "18. " << setw(3) << " String Variable " << endl;
	cout << setw(5) << "19." << setw(3) << " Recursion " << setw(20) << "20. " << setw(3) << " Multi-Dimensional Array " << endl;
	cout << setw(5) << "21." << setw(3) << " Dynamic Array " << setw(16) << "22. " << setw(3) << " Command Line Argument " << endl;
	cout << setw(5) << "23." << setw(3) << " Structs " << setw(22) << "24. " << setw(3) << " Class and Object " << endl;
	cout << setw(5) << "25." << setw(3) << " Pointer to Array " << setw(13) << "26. " << setw(3) << " Pointer to Struct " << endl;
	cout << setw(5) << "27." << setw(3) << " Pointer to Object " << setw(12) << "28. " << setw(3) << " Namespace " << endl;
	cout << setw(5) << "29." << setw(3) << " Header File " << setw(18) << "30. " << setw(3) << " Makefile " << endl;
	cout << setw(5) << "31." << setw(3) << " Vector " << setw(23) << "32. " << setw(3) << " Big Three " << endl;
	cout << setw(5) << "33." << setw(3) << " Overloaded Operator " << setw(10) << "34. " << setw(3) << " File I/O " << endl;
	cout << setw(5) << "35." << setw(3) << " Using STL  " << setw(19) << "36. " << setw(3) << " Inheiritance " << endl;
	cout << setw(5) << "37." << setw(3) << " Polymorphism " << setw(17) << "38. " << setw(3) << " Exceptions " << endl;
	cout << endl;
	
	cout <<"Enter your choice: " ; 
	cin >> choice; 
	return choice; 
}

/*****************) Choice function  (*************
** Function: doChoice
** Description: Switch list of choices, launches 
** selected menu item via function call. 
** Parameters: int choice, passes command arg
** Pre-Conditions: called from main
** Post-Conditions: calls function or defaults
***************************************************/
void doChoice(int choice, int arg)
{
	switch (choice)
	{
	case 1:
		cout << endl; 
		cout <<"Choice 1: Binary. " << endl;
		binary(); 
		break;  
	case 2:
		cout << endl; 
		cout <<"Choice 2: Two's Complement. " << endl; 
		twosCompliment(); 
		break; 
	case 3:
		cout << endl; 
		cout <<"Choice 3: Macros: " << endl;
		macro(); 
		break;
	case 4:
		cout << endl;
		cout <<"Choice 4: Simple Output. " << endl;
		simpleOutput(); 
		break;
	case 5:
		cout << endl; 
		cout <<"Choice 5: Simple Input. " << endl;
		simpleInput(); 
		break;
	case 6:
		cout << endl; 
		cout <<"Choice 6: Type Casting. " << endl;
		typeCasting(); 
		break;
	case 7:
		cout << endl; 
		cout <<"Choice 7: Conditional " << endl;
		condition(); 
		break;
	case 8:
		cout << endl; 
		cout <<"Choice 8: Logical Operators. " << endl;
		logical(); 
		break;
	case 9:
		cout << endl; 
		cout <<"Choice 9: Loop. " << endl;
		forLoop(); 
		break;
	case 10:
		cout << endl;
		cout <<"Choice 10: Random Numbers. " << endl;
		randNumber();
		break;
	case 11:
		cout << endl; 
		cout <<"Choice 11: Error Categories. " << endl;
		errorCat(); 
		break;
	case 12:
		cout << endl;
		cout <<"Choice 12: Debugging. " << endl;
		debugTricks();
		break;
	case 13:
		cout << endl; 
		cout <<"Choice 13: Function. " << endl;
		function();
		break;
	case 14:
		cout << endl; 
		cout <<"Choice 14: Function Decomposition. " << endl;
		functionDecomp();
		break;
	case 15:
		cout << endl; 
		cout <<"Choice 15: Scope. " << endl;
		scopeExample(); 
		break;
	case 16:
		cout << endl; 
		cout <<"Choice 16: Passing Mechanisms. " << endl;
		passingMechanisms();
		break;
	case 17:
		cout << endl; 
		cout <<"Choice 17: Overloading " << endl;
		overload(); 
		break;
	case 18:
		cout << endl; 
		cout <<"Choice 18: String. " << endl;
		stringVar();  
		break;
	case 19:
		cout << endl; 
		cout <<"Choice 19: Recursion " << endl;
		recursion(); 
		break;
	case 20:
		cout << endl; 
		cout <<"Choice 20: Multi-dimensional Array.  " << endl;
		multiDimArray(); 
		break;
	case 21:
		cout << endl; 
		cout <<"Choice 21: Dynamic Array. " << endl;
		dynArray();
		break;
	case 22:
		cout << endl;
		cout <<"Choice 22: Command Line " << endl;
		commandLine(arg); 
		break;
	case 23:
		cout << endl;
		cout <<"Choice 23: Struct " << endl;
		structExample();
		break;
	case 24:
		cout << endl;
		cout <<"Choice 24: Class and Object " << endl;
		classObject(); 
		break;
	case 25:
		cout << endl;
		cout <<"Choice 25: Pointer to Array. " << endl;
		pointerArray(); 
		break;
	case 26:
		cout << endl;
		cout <<"Choice 26: Pointer to Struct. " << endl;
		pointerStruct(&Numbers1); 
		break;
	case 27:
		cout << endl; 
		cout <<"Choice 27: Pointer to an Object. " << endl;
		pointerObject();
		break;
	case 28:
		cout << endl; 
		cout <<"Choice 28: Namespace. " << endl;
		namespaces(); 
		break;
	case 29:
		cout << endl; 
		cout <<"Choice 29: Header file " << endl;
		headerFile(); 
		break;
	case 30:
		cout << endl; 
		cout <<"Choice 30: MakeFile " << endl;
		make(); 
		break;
	case 31:
		cout << endl; 
		cout <<"Choice 31: Vector " << endl;
		numberVector(); 
		break;
	case 32:
		cout << endl; 
		cout <<"Choice 32: Big Three. " << endl;
		bigThree(); 
		break;
	case 33:
		cout << endl; 
		cout <<"Choice 33: Overloaded Operators. " << endl;
		overloadOp(); 
		break;
	case 34:
		cout << endl; 
		cout <<"Choice 34: File I/O. " << endl;
		structExample(); 
		break;
	case 35:
		cout << endl; 
		cout <<"Choice 35: STL or BOOST. " << endl;
		numberVector();
		break;
	case 36:
		cout << endl; 
		cout <<"Choice 36: Inheritance. " << endl;
		inheritance(); 
		break;
	case 37:
	cout << endl;
		cout <<"Choice 37: Polymorphism. " << endl;
		polymorphism(); 
		break;
	case 38:
		cout << endl; 
		cout <<"Choice 38: Exceptions. " << endl;
		condition();
		break;
	default:
		cout <<"Sorry I can't use that input. " << endl; 
	}// end switch
}

/**************************************************
** Function: 26. Pointer to Struct
** Description: Choice 26:  Pointer to Struct
** Parameters: receives pointer to struct
** Pre-Conditions: called from 
** Post-Conditions: output to console
***************************************************/
void pointerStruct(struct Numbers *Numbers1)
{
	struct Numbers Number2; 
	struct Numbers *ptrNumber2 = &Number2; 

	ptrNumber2->firstNumber = 25; 
	ptrNumber2->nextNumber = 5;

	struct Numbers *ptrNumber1 = Numbers1;
	ptrNumber1->firstNumber = 3; 
	ptrNumber1->nextNumber = 8; 

	cout << "\nFirst number in struct Number2 is: "<<ptrNumber2->firstNumber << endl; 
	cout << "Next number in struct Number2 is: " << ptrNumber2->nextNumber << endl; 

	cout << "\nFirst number in struct Numbers1 is: "<<ptrNumber1->firstNumber << endl; 
	cout << "Next number in struct Numbers1 is: " << ptrNumber1->nextNumber << endl; 
	cout << endl; 
}

/**************************************************
** Function: 28. Namespace
** Description: Choice 28: Namespace
** Parameters: none
** Pre-Conditions: called from doChoice
** Post-Conditions: outputs to console
***************************************************/
void namespaces()
{
	using namespace std;
	cout << "\nNOTE: I am trying to use this item to recover some " << endl; 
	cout << "points from Exam 2 where I missed the question about namespace. " << endl; 
	cout << "\nTo demonstrate namespaces, we have two namespaces that have a function " << endl; 
	cout << "with the same name and parameters.  An error would result if they were " << endl; 
	cout << "in the same namespace " << endl; 
	cout << "\nBut since we have two namespaces, we can specify which function to call " << endl; 
	cout << "by specifying the namespace using the scope resolution operator. " << endl; 
	cout << "\nIn cordeyw namespace the function twoNumbers(3,4) returns: " <<  cordreyw::twoNumbers(3, 4) << endl; 
	cout << "\nIn ElmerFudd namespace the function twoNumber(3,4) returns: " << ElmerFudd::twoNumbers(3,4) << endl; 
	cout << endl; 
}
