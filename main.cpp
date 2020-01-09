// mainLab4.cpp (a good start)
// This program tests various operations of a linked stack
// (without any input error checks)
// Written by (Your name goes here) 02/27/2017

#include <fstream>
#include <iomanip>
#include <string>
#include "linkedStack.h"            // more implementation is necessary

using namespace std;
string getString(int num);
void title();
void converter();

template <class Type>
void readData(linkedStackType<Type> & stk);

template <class Type>
void printOrigReversed(linkedStackType<Type> stk);

template <class Type>
void printOrig(linkedStackType<Type> stk);

ifstream fin ("Input0.txt");
ofstream fout("Output.txt");
ifstream fin2("InputS.txt");
ofstream fout2("InputS.txt");

//print source stack get replaced

int main()
{
	linkedStackType<int> iStack;    // stack object accepting int inputs
	title();						// prints the title
	readData(iStack);               // read the data into the stack (pass by ref)
	cout << iStack.getSize();
	//printOrigReversed(iStack);      // demonstrates a non-destructive print
    printOrig(iStack);      // demonstrates a non-destructive print uncomment please
    cout << endl << endl;
    iStack.sortLinkedStack(); //sort in ascending order
    printOrigReversed(iStack); //print stack in orginal order and write to fout
    converter();
	fin.close();                    // close the input file (notice it was not used)
	fout.close();					// close the output file
//	system("pause");				// just pause the run, until user keys
    return 0;						// return 0 to indicate OS is ok
}

void title()
{
	cout << setw(63) << "T H E    O R I G I N A L    U N S O R T E D    L I S T" << endl;
	cout << setw(63) << "======================================================" << endl << endl;
	cout << setw(35) << "Written by" << " Kurt Jennings" << endl  << endl  << endl;

	fout << setw(63) << "T H E    O R I G I N A L    U N S O R T E D    L I S T" << endl;
	fout << setw(63) << "======================================================" << endl << endl;
	fout << setw(35) << "Written by" << " Kurt Jennings" << endl  << endl  << endl;
}

template <class Type>
void readData(linkedStackType<Type> & s)
{
    int deciOrig;                   // declare local int for reading

    fin >> deciOrig;                // priming read for the 1st decimal number
    while( !fin.eof() )             // loop while data exists
    {
        s.push(deciOrig);           // push the int into the stack
        fin >> deciOrig;            // read the next int
    }
}

// a function to convert a decimal number to base n
void converter()
{
    string getString[] = {"0", "1", "2", "3",   // cleverly converts int index to a string
                          "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };
    // converts the input number to a string of digits in the base
    // begin bottom up coding

    linkedStackType<string> localstk; // creates local stack of strings

    int decimal = 2783;
    int decisave = decimal;
    cout << "orig number is: "<< decimal << endl;

    // skip to binary
    string sRemainder= "";
    int quotient = 1 ;
    int base[]= {16,8,2};
    int i = 0; // index for base array

    while (i<3)
    {
        int decimal = decisave;
        int divisor = base[i] ; //
        int remainder;
        do
        {

            quotient = decimal / divisor ;
               remainder = decimal % divisor;
               sRemainder = getString[remainder]; // you came in class right here
               localstk.push(sRemainder);
               decimal = quotient;
        }while (quotient != 0 );


        while(!localstk.isEmptyStack())
        {

           // cout << localstk.top();    // look, but don't remove
            //fout << setw(40) << localStk.top() << endl;      // look, but don't remove
            localstk.pop();                                  // remove the top integer


        }
        cout << endl;
        i++;
    }



}

// displays the data in the same order as it was just read in.  (backwards stack)
template <class Type>
void printOrigReversed(linkedStackType<Type> stk)
{
	while(!stk.isEmptyStack())
	{
		cout << setw(40) << stk.top() << endl;      // look, but don't remove
		fout << setw(40) << stk.top() << endl;      // look, but don't remove
		stk.pop();                                  // remove the top integer
	}
	cout << endl;
   // cout << setw(67) << "Oops! Output should be in the same order as the data!\n\n" << endl;
	fout << endl;
    //fout << setw(67) << "Oops! Output should be in the same order as the data!\n\n" << endl;
    fout.close();
}
template <class Type>
void printOrig(linkedStackType<Type> stk)
{

    linkedStackType<int> localStk;
	while(!stk.isEmptyStack())
	{
	    localStk.push(stk.top());


	//	cout << setw(40) << stk.top() << endl;      // look, but don't remove
		//fout << setw(40) << stk.top() << endl;      // look, but don't remove
		stk.pop();                                  // remove the top integer
	}
	cout << endl;

	fout << endl;


  while(!localStk.isEmptyStack())
	{



        cout << setw(40) << localStk.top() << endl;      // look, but don't remove
		fout << setw(40) << localStk.top() << endl;      // look, but don't remove
		localStk.pop();                                  // remove the top integer
	}
}

