/************************************************************
**	Program Filename: AccelReview.h
**	Author: Wayne Cordrey    ONID: 932304741
**	Date: Mar 12, 2014
**	Description: header file for CS165AccelReview.cpp 
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
//#include</boost/random/random_number_generator.hpp>
//#include</boost/random/uniform_int.hpp>

using namespace std; 

/**********) Classes   (***************************/

/**************************************************
** Class: Shape
** Description: Base class 
** Contains virtual calcArea function
** Two derived classes: Rectangle, Circle
***************************************************/
class Shape
{
	public:
	// BIG THREE:  
		Shape(); // default constructor
		Shape(int weight, int ID);
		Shape(const Shape& source); // copy constructor
		Shape& operator=(const Shape& source); // operator overload
		~Shape(); // destructor
		
		// accessor and mutator functions
		void setWeight(int weight);
		void setID(int ID);
		int getWeight();
		int getID();

		virtual int calcArea();
	protected:
		int weight; 
		int ID; 
};

/**************************************************
** Class: Rectangle
** Description: Derived class w/ virtual area function
***************************************************/
class Rectangle : public Shape
{
	public: 
		Rectangle(); 
		Rectangle(int w, int l); 
		int calcArea();
	private:
		int width; 
		int length;
};

/**************************************************
** Class: Circle
** Description: derived class w/ virtual area func
***************************************************/
class Circle: public Shape
{
	public:
		Circle(); 
		Circle(int r); 
		int calcArea();
	private:
		int radius; 
};

/**********) menu prototypes (*********************/
void binary(); 
void twosCompliment(); 
void macro(); 
void simpleOutput();
void simpleInput(); 
void typeCasting(); 
void condition(); 
void logical();
void forLoop(); 
void randNumber();
void errorCat(); 
void debugTricks();
void function();
void functionDecomp();
void scopeExample();
void passingMechanisms();
void overload();   
void stringVar();
void recursion(); 
void multiDimArray(); 
void dynArray();
void commandLine(int); 
void structExample();
void classObject(); 
void pointerArray();
void pointerStruct(struct Numbers *Numbers1);
void pointerObject(); 
void namespaces(); 
void headerFile(); 
void make();
void numberVector(); 
void bigThree();
void overloadOp();
void inheritance();
void polymorphism(); 

/**********) Menu item helper functions (*********************/
void debugXYZ(int N);
bool isPrime(int p, int i); 
void passHelper(int value, int& reference); 
void overloadHelper(int a, int b); 
void overloadHelper(int a, int b, string c);


