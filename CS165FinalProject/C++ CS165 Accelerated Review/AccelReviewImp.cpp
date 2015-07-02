/************************************************************
** Program Filename: AccelReviewImp.cpp
** Author: Wayne Cordrey    ONID: 932304741
** Date: Mar 14, 2014
** Description:   Implementation file for CS165AccelReview.cpp
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
//#include<boost/random/random_number_generator.hpp>
//#include<boost/random/uniform_int.hpp>
#include"AccelReview.h"
using namespace std;

/**********) Class Definitions < **************
/**************************************************
** Class: Shape 
** Description: Base class polymorphic
** contains virtual calcArea function 
***************************************************/
// default constructor
Shape::Shape()
{
	this-> ID = 0; 
	this-> weight = 0; 
}

Shape::Shape(int weight, int ID)
{
	this-> weight = weight; 
	this-> ID = ID; 
}

// copy constructor:  assigns input object to new object
Shape::Shape(const Shape& source)
{
	cout << "\nCopy Constructor invoked. " << endl; 
	this-> weight = source.weight; 
	this-> ID = source.ID; 
}

// overloaded assignment operator
Shape& Shape::operator=(const Shape& source)
{
	cout << "\nOverloaded operator invoked. " << endl; 
	// test for self assignment
	if(this == &source)
	{
		return *this;  
	}
	this-> weight = source.weight; 
	this-> ID = source.ID; 

	return *this; 
}

// destructor
Shape::~Shape()
{
	cout << "\nInvoked destructor for ID: " << this->ID << endl; 
	cout << "No dynamic memory, so no delete needed. \n" << endl; 
}

// accessor and mutators
void Shape::setWeight(int weight)
{
	this-> weight = weight; 
}
// set ID
void Shape::setID(int ID)
{
	this-> ID = ID; 
}
// get weight
int Shape::getWeight()
{
	return this-> weight; 
}
// get ID
int Shape::getID()
{
	return this-> ID; 
}	

// virtual function 
int Shape::calcArea()
{
	/* forwards calcArea task to calcArea member function of
	specific type, Rectangle or Circle */
	return  NULL;   
}

/**************************************************
** Class: Rectangle
** Description: derived from Shape class
** Parameters: polymorphic, calc area member func
** is virtual
***************************************************/
Rectangle::Rectangle() : Shape()
{
	this->length = 0; 
	this->width = 0; 
}

Rectangle::Rectangle(int w, int l) : Shape()
{
	width = w; 
	length = l; 
}

// virtualized derived from Shape class
int Rectangle::calcArea()
{
	return(width * length); 
}

Circle::Circle() : Shape() 
{
	this->radius = 0; 
}

Circle::Circle(int r) : Shape()
{
	this->radius = r; 
}

// virtualized derived from Shape class
int Circle::calcArea()
{
	return((int)(3.14159 * radius * radius));
}

/*********) Function Definitions (***************

/**************************************************
** Function: 1. Binary
** Description: 
** Parameters: 
** Pre-Conditions
** Post-Conditions: 
***************************************************/
void binary()
{
	int binary =0; 
	int decimal = 0;  
	int array[100]; 

	cout <<"\nEnter an 8 bit binary number: "; 
	cin >> binary; 
	cout << "\nThe decimal equivalent is: " ; 
	cout << endl; 
	for(int i = 0; binary != 0; i++)
	{
		array[i] = binary % 10; 
		decimal += array[i] * pow(2, i); 
		binary = binary / 10; 
	}

	cout << decimal; 
	cout << endl; 
}

/**************************************************
** Function: 2.  Twos Complement 
** Description: Calculates decimal value of 
** binary value.  
** called from doChoice
***************************************************/
void twosCompliment()
{
	const int BITS = 8; 
	char binary[BITS+1] = "10000011";
	int power = 128; 
	int sum = 0; 

	for(int i = 0; i < BITS; i++)
	{
		if(i == 0 && binary[i] != '0')
		{
			sum = -128; 
		}
		else 
		{
			sum += (binary[i] - '0') * power; 
		}
		power/= 2; 
	}

	cout << "Binary number: " << binary << endl; 
	cout << "Decimal conversion: " << sum << endl; 
}

/**************************************************
** Function: 3. Macros
** Description: Displays examples of predefined 
** macros.  
** Called from doChoice()
***************************************************/
void macro()
{
	cout << "\nHere is an example of predefined macros. " << endl; 
	cout << "\nThe source file name is " << __FILE__ << endl; 
	cout << "The date is " << __DATE__ << endl; 
	cout << "This is line number "<< __LINE__ << endl; 
	cout << endl; 
}

/**************************************************
** Function: 4. Simple Output
** Description: Simple cout to display
** Called from doChoice()
***************************************************/
void simpleOutput()
{
	cout << endl;
	cout << "This is an example of simple console output using cout.  " << endl; 
	cout << endl; 
}

/**************************************************
** Function: 5. Simple input
** Description: CIN input into variable
** called from doChoice()
***************************************************/
void simpleInput()
{
	int input; 
	cout << "\nEnter an integer to demonstrate simple input: "; 
	cin >> input; 
	cout << "The value entered is " << input << endl; 
	cout << endl; 
}

/**************************************************
** Function: 6. Type Casting 
** Description: demonstrates typecasting double to int
** called from doChoice()
***************************************************/
void typeCasting()
{
	int valueA = 2;
	double valueB = 3.00;
	double dresult = 0; 
	int iresult; 
	dresult = valueB/valueA; 
	cout << "\nThe result of 3.0/2 before type casting is: " << dresult << endl ;
	iresult = static_cast<int>( valueB )/ valueA ; 
	cout << "\nThe result of 3.0/2 after type casting to int is: " << iresult << endl;
	cout << endl;  
}

/**************************************************
** Function: 7. Conditional
** Description: Demonstrates if/else conditional
** and simple use of try/Catch
** called from doChoice() for item 7 and item 38
***************************************************/
void condition()
{
	int input; 
	double testVal = 10;
	char reply = ' ';  

	cout << "\nHere, we demonstrate an if/else conditional " << endl; 
	cout << "and use a simple try/catch to catch a " << endl; 
	cout << "divide by zero error.  " << endl; 

	do{
		try
		{
		cout << "\nEnter a number to test a conditional statement "; 
		cout << "or -1 to exit.  " << endl; 
		cin >> input; 

		if(input == -1)
		{
			cout << "Exiting Choice 7 Conditional.  " << endl; 
			break; 
		}

		// if number is zero throw exception
		if(input == 0)
			throw input; 
		else if(input > 0)
			cout << "The number divided by " << testVal << endl; 
			cout << "is " << input/testVal << endl; 
		}
	
		catch(int e)
		{
			cout << "We prefer not to divide by zero. " << endl;
			cout << "Want to enter another number? (y/n) " << endl; 
			cin >> reply;  
		}
	}while(reply == 'y' || reply == 'Y');
	cout << "\nOK, Exiting Choice 7 Conditional. " << endl; 
}

/**************************************************
** Function: 8. Logical
** Description: Demonstrates OR logic function
** called from doChoice()
***************************************************/
void logical()
{
	int a = 10; 
	int b = 10;
	int c = 15; 
	cout << "a = 10, b = 10, c = 15 " << endl; 
	cout << "So ((a + b ) == 20 || (b + c) == 20) is " << endl;
	cout << "the conditional logic test.  "  << endl; 
	cout << "'||' is true if either one equal 20. " << endl; 
	cout << "The test is met by the first occurance, and  " << endl; 
	cout << "displays the result.  " << endl; 
	cout << "\nIf (a + b) or (b + c) = 20 then output a phrase.  " << endl; 
	if((a + b ) == 20 || (b + c) == 20)
		cout << "One or the other  equals 20.  " << endl; 
	cout << endl;
}

/**************************************************
** Function: 9. Loop
** Description: Simple demonstration of for loop
** called from doChoice()
***************************************************/
void forLoop()
{
	cout << "This is output of a for loop.  " << endl; 
	cout << "\t"; 
	for(int i = 0; i < 10; i++)
		cout << i * i << ", " ; 
	cout << endl; 
}

/**************************************************
** Function: 10 Random Number
** Description: Generates random number in range
** using stl random function, then creates random
** password using Boost random function
** called from doChoice() 
***************************************************/
void randNumber() 
{
	int hi = 999; 
	int low = 100; 
	srand(time(NULL)); 
	signed int number = 0; 
	char reply = ' '; 

	cout << "\nHere we have random numbers generated by rand() " << endl;
	
	do{
		number = rand() % 899 + 100; 
		cout << "\nHere's a random number between 100 and 999:  " << number << endl; 
		cout << "Enter 'Y' for another random number. "; 
		cin >> reply; 
	}while(reply == 'y' || reply == 'Y'); 

	/*cout << "\nHere is a random password generator using BOOST.  " << endl; 
	cout << "\nThis example comes from Boost.org documentation. " << endl; 
	string chars("abcdefghikjlmnopqrstuvwxyz"
				"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
				"1234567890"
				"!@#$%^&*()");
	boost::random::random_number_generator rng; 
	boost::random::uniform_int <> index_dist(0, chars.size() -1); 
	cout << "\tRandom Password: " ; 
	for(int i = 0; i < 8; i++)
	{
		cout << chars[index_dist(rng)] ;
	}*/
	cout << endl; 
}

/**************************************************
** Function: 11. Error Categories errorCat()
** Description: Simple text explanation of error
** types
** called by doChoice() 
***************************************************/
void errorCat()
{
	cout << "There are three general types of errors; " << endl;
	cout << "\nSyntax errors:  These are errors of grammar of the"<< endl; 
	cout << "\tprogramming language.  These errors are caught by the" <<endl;
	cout << "\tcompiler during compilation. " << endl; 
	cout << "\tAn example might be:  \"cin << reply \" " << endl;
	cout << "\tHere, the insertion operator \" >> \" should be used, " << endl;
	cout << "\tnot the extraction operator.  This is a syntax error. " << endl; 

	cout << "\nLogical Errors:  These are errors that cause a program to not "<< endl;
	cout << "\tgive the desired output due to improper logic or calculations "<< endl;
	cout << "\tAn example might be using a wrong operator, like \\ instead of %.  " << endl;
	cout << endl; 
	cout << "\nRunTime errors:  These are errors found during execution of a program due to "<< endl;
	cout << "\tunexpected input or output.  The most noticible is division by zero,"<< endl;
	cout << "\twhich may compile but will produce an error at runtime. " << endl;
	cout << endl; 
	cout << endl; 
}

/**************************************************
** Function: 12. Debug Tricks
** Description: Simple demo of debugging tricks
** Pre-Conditions; calls debugXYZ helper function
** called from doChoice() 
***************************************************/
void debugTricks()
{
	cout << "\nCalling debugXYZ function from inside debugTricks. " << endl; 
	cout << "To trace flow and help with debugging. " << endl; 
	debugXYZ(0); 
}

/**************************************************
** Function:  debugXYZ  
** Description: helper to 12. Debug Tricks
** called from debugTricks 
***************************************************/
void debugXYZ(int N)
{
	cout << "\nThis is a stub inside debugXYZ function. " << endl; 
	cout << "Use stubs to test function calls and trace program structure  " << endl; 
	cout << "\nThe value of N inside debugXYZ is " << N << endl; 
	cout << " This allows you to verify what values are passed into "<< endl; 
	cout << " the function.  " << endl; 

	if(N == 0)
		cout << "\nDivide by Zero problem " << endl; 
	cout << "If you see this, you have a possible divide by zero problem in debugXYZ. " << endl; 
	cout << "\nAnother similar test is to check for upper and lower case when asking " << endl; 
	cout << "for (Y/N) in play again loops. " << endl; 
	cout << "An example of this can be found in code for 10, Random Numbers. " <<endl; 
	cout << "We test for both cases like this: (reply == 'y' || reply == 'Y') " << endl; 
	cout << endl; 
}

/**************************************************
** Function: 13.  Function
** Description: Simple example of basic function
** called from doChoice()
***************************************************/
void function()
{
	cout << "The basic function is used dozens of times in this " << endl; 
	cout << "project.  " << endl; 
	cout << "\nTest function .  Now inside function(); " << endl;  
	cout << "\nEach menu selection in this program uses a function. " << endl; 
	cout << endl; 
}

/**************************************************
** Function: 14. Functional Decomposition
** Description: function full of code, with code
** separated to functions and calls at the end.  
** called from doChoice(): 
***************************************************/
void functionDecomp()
{
	cout << "\nHere I will write code without functions " << endl; 
	cout << "and then rewrite into functions. " << endl;
	cout << "This shows how problem solving can be broken down into " << endl;
	cout << "individual parts and be made easier to trace and understand.  " << endl; 
	cout << "This demonstrates basic functional decomposition. " << endl;

	// 18. String
	string fName; 
	string lName;
	int number = 0; 
	int	result = 0; 
	cout << "\nEnter your first name: " ; 
	cin >> fName; 
	cout << "Enter your last name: " ; 
	cin >> lName; 
	cout << "Welcome, " << fName  << " " << lName; 
	cout << endl; 

	// 19. Recursion
	cout << "Enter a number to check for prime. ";
	cin >> number ; 
	result = isPrime(number, 2); 
	if(result == 1 )
		cout << "Number is prime.  " << endl;
	else if( result != 1)
		cout << "Number is NOT prime. " << endl; 

	// 20. Multidimensional Array
	const int ROWS = 4; 
	const int COLS = 3;
	int grid [ROWS][COLS]; 
	  // fill array
	for(int i = 0; i < ROWS ; i++)
		for(int j = 0; j < COLS; j++)
			grid[i][j] = 0; 
	  // print array
	cout << endl;
	cout << "Here is a two dimensional array, filled"; 
	cout << " and printed out.  " << endl; 

	for(int i = 0; i < ROWS; i++)
	{
		for(int j = 0; j< COLS; j++)
		{
			cout << setw(5) << grid[i][j] << " ";
		}
		cout << endl; 
	}

	// 21. Dynamic Array
	const int MAXSIZE = 30; 
	int *dArray; 
	dArray = new int[MAXSIZE]; 
	
	dArray[0] = 21; 
	dArray[1] = 13; 
	dArray[2] = 99; 
	dArray[3] = 21; 
	
	cout << endl; 
	cout << "This is an example of a dynamic array. " << endl; 
	for(int i = 0; i < 4; i++)
	{
		cout << "\tThe element at " << i << " contains " << dArray[i]<< endl; 
	}
	delete[] dArray; 
	cout << "Dynamic arrays must be deleted after use using the delete keyword. " << endl; 

	cout << "Calling functions for each of the above code blocks- " << endl; 
	cout << "The code is cleaner, easier to follow.  " << endl;  
	cout <<  endl; 
	stringVar();  // calls function from item 18 
	recursion();  // calls function from item 19
	multiDimArray(); // calls function from item 20
	dynArray(); // calls function from item 21
}

/**************************************************
** Function: 15. scopeExample
** Description: Demonstrates scope in code blocks
** called by doChoice()  
***************************************************/
void scopeExample()
{
	int x = 22; 
	int y = 33; 
	cout << "\nThis is a demonstration of SCOPE using variables. " <<endl; 
	cout << "\nIn the OUTER block, the value of x created here is available here: " << x << endl; 
	cout << "In the OUTER block, the value of X created in the inner block is not available. " << endl; 
	
	if(x == 22)
	{
		int X = 99; 
		cout << "Inside the inner block, the value of x, which was " << endl; 
		cout << "initialized OUTSIDE the block, is available: " << x << endl; 
		cout << "\nInside the inner block, the value of X, " << endl; 
		cout << "which was created INSIDE the inner block is: " << X << endl; 
	}
	cout << "\nThis shows that blocks of nested code have a one-direction availability. " << endl; 
	cout << "Blocks inside other blocks can access data from outer blocks, " << endl; 
	cout << "but outside blocks cannot access data " << endl; 
	cout << "defined inside inner blocks.  This is SCOPE. " << endl; 
}

/**************************************************
** Function: 16 passingMechanisms
** Description: Demonstrates passing by value and 
** by reference
** Preconditons: uses helper function passHelper()
** called by doChoice() 
***************************************************/
void passingMechanisms()
{
	int value = 10; 
	int reference = 30; 
	cout << "\nHere is an example of passing by value " << endl; 
	cout << "and passing by reference. " << endl; 
	cout << "\nInitially, the value stored in value is " << value << endl; 
	cout << "and the value of reference is " << reference << endl; 
	cout << "\nFirst, we'll send the values to a helper function. " << endl; 
	
	passHelper(value, reference); 

	cout << "\nNow, after changing values inside the helper function, " << endl; 
	cout << "the value of value is " << value << endl; 
	cout << "and the value of reference is " << reference << endl; 
	cout << "\nData types passed by reference can change because they refer to " << endl; 
	cout << "the address that stores the data, not the data itself.  " << endl; 

	cout << "\nFinally, lets change values outside the function and see how they change inside. " << endl; 
	value = 33; 
	reference = 44; 
	cout << "Now we'll call the function with new values:\n " << endl; 
	passHelper(value, reference);
}

void passHelper(int value, int& reference)
{
	cout << "\nHere inside the helper function, the passed-in value of value is "<< value << endl; 
	cout << "and the pass by reference value of reference is " << reference << endl; 
	value = 77; 
	reference = 99; 
}

/**************************************************
** Function: 17. overload
** Description: Demonstrates basic function overloading
** Pre-Conditions; uses overloadHelper()
** called by doChoice() 
***************************************************/
void overload()
{
	int a = 5; 
	int b = 3; 
	string c = "I'm helping. " ; 
		
	cout << "\nOverloading allows you to use the same " << endl; 
	cout << "function name, but pass different parameters.  " << endl; 
	cout << "Here, the first function takes two parameters " << endl; 
	cout << "and multiplies them, returning a product:  "; 
	
	overloadHelper(a, b); 
	
	cout << "\nThe second function, with the same name " << endl; 
	cout << "but one more parameter, returns addition result: " << endl; 
	
	overloadHelper(a, b, c);
}

/**************************************************
** Function: Overload helper 1
** Description: Helper function for 17. Overload
** called by overload()
***************************************************/
void overloadHelper(int a, int b)
{
	cout <<"Product is: " <<  a*b << endl;  
}

/**************************************************
** Function: Overload helper 2
** Description: helper function for 17. Overload
** called by overload()
***************************************************/
void overloadHelper(int a, int b, string c)
{
	cout << "Sum is : " << a+b << endl; 
	cout << "Value of C is: " << c  << endl; 
}

/**************************************************
** Function: 18  stringVar
** Description: Demonstrates string variable 
** called from doChoice()
***************************************************/
void stringVar()
{
	string fName; 
	string lName;
	int number = 0; 
	int	result = 0; 
	cout << "This is simple example of string variables.  " << endl; 
	cout << "This is from the StringVar function. " << endl; 
	cout << "\nEnter your first name: " ; 
	cin >> fName; 
	cout << "Enter your last name: " ; 
	cin >> lName; 
	cout << "Welcome, " << fName  << " " << lName; 
	cout << endl; 
}

/**************************************************
** Function: 19.  recursion 
** Description: demonstrates recursive function
** Pre-Conditions: calls isPrime recursive function
** called by doChoice()
***************************************************/
void recursion()
{
	int number; 
	int result; 
	cout << "\nThis is from the recursion function: " << endl; 
	cout << "Enter a number to check for prime. ";
	cin >> number ; 
	result = isPrime(number, 2); 
	if(result == 1 )
		cout << "Number is prime.  " << endl;
	else if( result != 1)
		cout << "Number is NOT prime. " << endl; 
		cout << endl;
}

/**************************************************
** Function: isPrime()
** Description: calculates prime numbers using recursion
** Parameters: takes input integer, counter int 
** returns true if number is prime
** helper function called by 19. Recursion
***************************************************/
bool isPrime(int p, int i )
{
	if (i==p) return 1;
	if (p%i == 0) return 0;
	return isPrime (p, i+1);
}

/**************************************************
** Function: 20. multiDimArray()
** Description: Demonstrates a 2D array
** Post-Conditions: called from doChoice()
***************************************************/
void multiDimArray()
{
	const int ROWS = 4; 
	const int COLS = 3;
	int grid [ROWS][COLS]; 
	  // fill array
	for(int i = 0; i < ROWS ; i++)
		for(int j = 0; j < COLS; j++)
			grid[i][j] = 20 + i; 
	  // print array
	cout << "\nThis is from the multidimensional array function. " << endl; 
	cout << endl;
	cout << "Here is a two dimensional array, filled"; 
	cout << " and printed out.  " << endl; 

	for(int i = 0; i < ROWS; i++)
	{
		for(int j = 0; j< COLS; j++)
		{
			cout << setw(5) << grid[i][j] << " ";
		}
		cout << endl; 
	}
}

/**************************************************
** Function: 21. dynArray()
** Description: Demonstrates a 2d dynamic array
** called from doChoice()
***************************************************/
void dynArray()
{
	const int MAXSIZE = 30; 
	int *dArray; 
	dArray = new int[MAXSIZE]; 
	
	dArray[0] = 21; 
	dArray[1] = 13; 
	dArray[2] = 99; 
	dArray[3] = 21; 
	
	cout << endl; 
	cout << "This is from inside dynArray function.  " << endl; 
	cout << "\nThis is an example of a dynamic array. " << endl; 
	for(int i = 0; i < 4; i++)
	{
		cout << "\tThe element at " << i << " contains " << dArray[i]<< endl; 
	}
	delete[] dArray; 
	cout << "Dynamic arrays must be deleted after use using the delete keyword. " << endl; 
	cout << endl; 
}

/**************************************************
** Function: 22. Command Line
** Description: Takes a single int from command line
** input and outputs it and doubles it. 
** Parameters: value from command line arg in main
** Called from doChoice() 
***************************************************/
void commandLine(int arg)
{
	cout << "\nTo use this menu item, enter a unsigned interger value at the command line. " ;
	cout << "\nThe integer value of the command line argument is: " << arg; 
	cout << "\nDouble that value is: " << arg * 2 << endl; 
}

/**************************************************
** Function: 23 structExample()
** Description: Demonstrates struct and basic 
** file I/O
** Pre-Conditions requires employee.txt file in 
** same directory
** Called from doChoice() 
***************************************************/
void structExample()
{
	string filename; 
	cout << "\nThis item creates an array of structs, reads data" << endl; 
	cout << "from a file, and outputs from the array of structs. " << endl; 
	cout << "\nEnter the text filename: (employee.txt) " ; 
	cin >> filename; 

	ifstream inFile;  
	inFile.open(filename);

	struct employee
	{
		string firstName; 
		string lastName; 
		int ID; 
		double wage; 
	};

	employee crew[5]; 
	
	while(!inFile.eof())
	{
		for(int i = 0; i < 5; i++)
		{
			inFile  >> crew[i].firstName 
					>> crew[i].lastName 
					>> crew[i].ID 
					>> crew[i].wage;
		}
	}
	 
	for(int i = 0; i < 5; i++)
	{
		cout << crew[i].firstName << " " 
			<< crew[i].lastName << " "; 
		cout << setprecision(2) << crew[i].wage << endl; 
	}

	inFile.close(); 
}

/**************************************************
** Function: 24. classObject
** Description: Demonstrates class and objects
** Uses Rectangle class
** Called from doChoice() 
***************************************************/
void classObject()
{
	cout << "\nHere we use class Rectangle to " << endl; 
	cout << "create an object and return an " << endl; 
	cout << "area calculation from that object. " << endl; 

	Rectangle rectangle1(5, 9); 
	cout << "\n Area of object rectangle1: " << rectangle1.calcArea() << endl; 
	cout << endl; 
}

/**************************************************
** Function: 25 pointerArray
** Description: Demonstrates pointer to array
** called from doChoice()
***************************************************/
void pointerArray()
{
	cout << "\nHere is a dynamically allocated 2d array: " << endl; 
	cout << "NOTE: This is my attempt to recover from the Exam 2 question on arrays. " << endl; 

	// create 2d dynamic array
	int** numberArray = new int*[5]; 
	for(int i = 0; i < 5; i++)
	{
		numberArray[i] = new int[5]; 
	}

	// fill array
	for(int i = 0; i < 5; i++)
	{
		for(int j=0; j < 5; j++)
		{
			numberArray[i][j] = i * j; 
		}
	}

	// display the array
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			cout << "\t" << numberArray[i][j]  << " " ; 
		}
		cout << endl; 
	}
	cout << endl; 

	// delete the dynamic array starting with rows
	for(int i =0; i < 5; i++)
	{
		delete [] numberArray[i];
	}
	delete [] numberArray; 

}

// 26. void pointerStruct located in CS165AccelReview.cpp

/**************************************************
** Function: 27. Pointer to an Object
** Description: Demonstrates pointer to an object
** Called from doChoice() 
***************************************************/
void pointerObject()
{
	cout << "\nHere we create an object, and then " << endl; 
	cout << "create a pointer to it.  We use the " << endl; 
	cout << "pointer to access the object's " << endl;
	cout << "area function.  " << endl; 

	// create object of derived class
	Rectangle Rec(5, 4); 
	
	// create pointers to this objects
	Rectangle* shapeRec = &Rec; 
	
	cout <<"\nArea of shape : " << shapeRec->calcArea() << endl; 
	
	cout << endl; 
}

// 28. namespace located in CS165AccelReview.cpp

/**************************************************
** Function: 29. Header File
** Description: Narrative of header file contents
** called from doChoice()
***************************************************/
void headerFile()
{
	cout << "\nHeader files are used to separate implementation " << endl; 
	cout << "details from code available to the user.  Programmers " << endl; 
	cout << "can hide implementation details from users, but still " << endl; 
	cout << "provide a clean interface where users can find  " << endl; 
	cout << "necessary information to use classes,  " << endl;
	cout << "without needing to know implementationd details.  " <<	endl; 
	cout << endl; 
	cout << "I moved all classes and almost all functions into " << endl; 
	cout << "a single pair of header and implementation files. " << endl; 
	cout << endl;  
}

/**************************************************
** Function: 30. make()
** Description: Comment on makefile used in this project
** called by doChoice()
***************************************************/
void make()
{
	cout << "\nThis project uses a makefile to compile " << endl; 
	cout << "its files.  The makefile includes variables " << endl; 
	cout << "that allow updating of files, and allow me to " << endl; 
	cout << "use the makefile as a template for other projects. " << endl; 
	cout << endl; 
}

/**************************************************
** Function: 31. numberVector()
** Description: Demonstrates a vector of objects
** requires class Shape for objects
** called by doChoice()
***************************************************/
void numberVector()
{
	cout << "\nThis is an example of vectors " << endl; 
	cout << "Its also an example of using the STL  " << endl; 
	cout << "library for both vector and iterator. " << endl; 

	// create vector  (member of STL library)
	vector<int> numbers; 

	// fill vector with 5 numbers
	for(int i=0; i< 5; i++)
	{
		numbers.push_back(i); 
	}

	vector<int>::iterator iter; // member of STL library
	 
	 cout << "\nVector output using iterator: " << endl; 
	  cout << "\t ";
	 for(iter = numbers.begin(); iter < numbers.end(); iter++)
	 {
		cout << *iter << " "; 
	 }
	 	 
	 cout << "\nVector output using reverse iterator. " << endl; 
	 vector<int>::reverse_iterator revIter; 
	 cout << "\t ";
	  for(revIter = numbers.rbegin(); revIter < numbers.rend(); revIter++)
	 {
		cout << *revIter << " "; 
	 }
	 cout << endl;
}

/**************************************************
** Function: 32. bigThree()
** Description: Demonstrates default constructor, 
** copy constructor, and destructor
** Uses Shape objects
** called by doChoice() 
***************************************************/
void bigThree()
{
cout << "\nBig Three refers to three essential class members: " << endl;
cout << "Default constructor, copy constructor, and destructor.  " << endl; 
cout << "The Shape class has these three elements.  " << endl; 
cout << "\nThe default constructor is called when a Shape object is created, " << endl; 
cout << "but doesn't provide input data.  " << endl; 
cout << "This produces an object with default characteristics.  In this case " << endl; 
cout << "That means no values stored in the object.  " << endl; 
Shape object1; 
cout << "The value of ID in Shape object1 is: " << object1.getID() << endl;
cout << endl; 
object1.setID(99); 
cout << "After setting ID in object1, value in ID is: " << object1.getID() << endl; 
Shape object2(object1); 
cout << "After passing object1 to the copy constructor, ID in object 2 is: " << object2.getID() << endl; 
cout << endl; 
cout << "The destructor is called on each object at the exit of the function. " << endl; 
cout << "It frees memory used by object1 and object2.  " << endl; 

}

/**************************************************
** Function: 33. overloadOp()
** Description: Demonstrates operator overloading
** Uses Shape class
** called by doChoice()
***************************************************/
void overloadOp()
{
	cout << "This is an example of operator overloading. " << endl; 
	cout << "\nThe ' = ' is overloaded, " << endl; 
	cout << "which allows objects to be assigned. " << endl; 

	Shape object1(3, 44); 
	cout << "\nObject1 ID is: " << object1.getID() << endl; 

	Shape object2(5, 99); 
	cout << "Object 2 ID is: " << object2.getID() << endl; 

	object1 = object2; 

	cout << "After 'object1 = object2' , " << endl; 
	cout << "Object 1 ID is: " << object1.getID() << endl; 
	cout << "Object 2 was assigned to Object1.  " << endl; 
}

// 34. File I/O calls structExample(), which reads file

// 35  STL or Boost Example calls randNumber(), which uses Boost Random lib
//      I was not able to get the link to Boost to work on FLIP. 

/**************************************************
** Function: 36. inheritance()
** Description: Demonstrates inheritance from base 
** class to derived class.   
** called by doChoice(): 
***************************************************/
void inheritance(){
	cout << "\nHere we have an example of inheritance. " << endl; 
	cout << "Class Shape contains weight and ID, "<< endl; 
	cout << "Because Rectangle class is deived from Shape " << endl; 
	cout << "we can set and display weight and ID for Rectangle  " << endl; 
	cout << "objects because they are INHERITED from class Shape. " << endl; 
	cout << "This is an example of inheritance.  " << endl; 

	Rectangle rectObject(4,6); 
	rectObject.setWeight(200); 
	rectObject.setID(999); 
	cout << "\nThe weight of Rectangle, inherited from the base class, " << endl; 
	cout << "is "  << rectObject.getWeight() << endl; 
	cout << "\nThe ID of Rectangle, inherited from base class, " << endl; 
	cout << "is " << rectObject.getID() << endl; 
}

/**************************************************
** Function: 37. polymorphism()
** Description: Demonstrates polymorphism from 
** base class to derived classes.  
** uses Shape class and derived Rectangle and Circle 
***************************************************/
void polymorphism()
{
	cout << "\nHere, we create a base class Shape, " << endl;
	cout << "and two derived classes, Rectangle and " << endl; 
	cout << "Circle.  We virtualize the area function " << endl; 
	cout << "in Shape so that when objects of either " << endl; 
	cout << "derived class are created, they use the " << endl; 
	cout << "appropriate area function. \n "  << endl; 
	cout << endl;  

	// create objects of derived class
	Rectangle Rec(5, 4); 
	Circle Cir(7); 

	// create pointers to these objects
	Shape* shapeRec = &Rec; 
	Shape* shapeCir = &Cir; 

	// create an array of pointers to objects and output from base class	
	cout << "Area obtained by pointing to base class virtual function.  " << endl; 
	Shape* shapes[] = {shapeRec, shapeCir}; 
	for(int i = 0; i < 2; i++)
	{
		cout <<"Area of shape " << i+1 << ": " << shapes[i]->calcArea() << endl; 
	}
	cout << endl; 
}

// 38. Exceptions calls condition() to demonstrate try/catch










