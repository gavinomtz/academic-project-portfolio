//******************************************************************************
// CSCI 1470      Spring 2024                    
// Gavino Martinez
// 
// Using your own words, write here a description of what the program does: 
//  The program allows the user to input the amount of Mexican pesos and Euros that they 
//  want to convert to U.S. Dollars and outputs the sum.
//******************************************************************************

#include <iostream>				// to be able to use cout
#include <typeinfo>				// to be able to use operator typeid

// Include here all the libraries that you need for your program to compile.

#include <cmath>    // to be able to use round
#include <iomanip>  // to be able to use setprecision and setw

using namespace std;

// Ignore this; it's a little function used for making tests
inline void _test(const char* expression, const char* file, int line)
{
  cerr << "test(" << expression << ") failed in file " << file;
  cerr << ", line " << line << "." << endl << endl;
}
// This goes along with the above function...don't worry about it
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

int main()
{
// Enter here your algorithm as a series of MEANINGFUL steps.

/*

Declare constant variables DOL2MEX and DOL2EURO to hold double precision real numbers
Declare variables pesos and euros to hold double precision real numbers entered by the user
Declare variables wholedollarsp, centdollarsp, wholedollarse, centdollarse, wholetotal, and centtotal to hold whole numbers
Display the prompt "Mexican Peso and Euro to U.S. Dollar converter"
Prompt the user to enter the amount and hold the amount of pesos to be converted
Convert the amount of pesos to USD
  // Convert the dollar amount
  // Convert the cent amount
Prompts the user to enter the amount and hold the amount of euros to be converted
Convert the amount of euros to USD
  // Conver the dollar amount
  // Convert the cent amount
Display the prompt "Mexican Peso and Euro to U.S. Dollar converter" after two new lines
Display the amount of pesos and euros to be converted to USD in real numbers in fixed format showing two decimal places
Declare a variable and define it to be able to format the output of cents to round up to the next dollar when over at or over 100 cents
Calculate the total amount of dollars and cents
Output the total amount of dollars and cents converted to USD

*/

// Write below EACH step of the algorithm the C++ statement that implements it.

// Declare constant variables DOL2MEX and DOL2EURO to hold double precision real numbers
  const double DOL2MEX = 17.47;
  const double DOL2EURO = 0.94;

// Declare variables pesos and euros to hold double precision real numbers entered by the user
  double pesos, euros;

// Declare variables wholedollarsp, centdollarsp, wholedollarse, centdollarse, wholetotal, and centtotal to hold whole numbers
  int wholedollarsp, centdollarsp, wholedollarse, centdollarse, wholetotal, centtotal;

// Display the prompt "Mexican Peso and Euro to U.S. Dollar converter"
  cout << "Mexican Peso and Euro to U.S. Dollar converter" << endl;

// Prompt the user to enter the amount and hold the amount of pesos to be converted
  cout << "\nPlease enter the amount in Pesos: ";
  cin >> pesos;

// Convert the amount of pesos to USD
  // Convert the dollar amount
  wholedollarsp = pesos / DOL2MEX;

  // Convert the cent amount
  centdollarsp = round((pesos / DOL2MEX - wholedollarsp) * 100);

// Prompt the user to enter the amount and hold the amount of euros to be converted
  cout << "Please enter the amount in Euros: ";
  cin >> euros;

// Convert the amount of euros to USD
  // Conver the dollar amount
  wholedollarse = euros / DOL2EURO;

  // Convert the cent amount 
  centdollarse = round((euros / DOL2EURO - wholedollarse) * 100);

// Display the prompt "Mexican Peso and Euro to U.S. Dollar converter" after two new lines
  cout << endl << endl << "Mexican Peso and Euro to U.S. Dollar converter\n" << endl << endl;

// Display the amount of pesos and euros to be converted to USD in real numbers in fixed format showing two decimal places
  cout << fixed << setprecision(2);
  cout << setw(10) << pesos << " pesos: " << setw(10) << wholedollarsp << " US dollars with " << centdollarsp << " cents\n\n";
  cout << setw(10) << euros << " euros: " << setw(10) << wholedollarse << " US dollars with " << centdollarse << " cents\n\n";

// Declare a variable and define it to be able to format the output of cents to round up to the next dollar when over at or over 100 cents
  int centro = (centdollarsp + centdollarse) / 100;

// Calculate the total amount of dollars and cents
  wholetotal = wholedollarsp + wholedollarse + centro;
  centtotal = (centdollarsp + centdollarse) - (centro *100);

// Output the total amount of dollars and cents converted to USD
  cout << setw(18) << "Total: " << setw(10) << wholetotal << " US dollars with " << centtotal << " cents\n\n";


// ----------------------------- Your code ends here -----------------------------

// Do NOT remove or modify the following statements

  cout << endl << "Testing your solution" << endl << endl;
  test(typeid(DOL2MEX) == typeid(1.));			// Incorrect data type used for DOL2MEX
  test(typeid(DOL2EURO) == typeid(1.));			// Incorrect data type used for DOL2EURO
  test(typeid(euros) == typeid(1.));				// Incorrect data type used for euros
  test(typeid(pesos) == typeid(1.));				// Incorrect data type used for pesos
  test(typeid(wholedollarsp) == typeid(1));		// Incorrect data type used for wholedollarsp
  test(typeid(centdollarsp) == typeid(1));		// Incorrect data type used for centdollarsp
  test(typeid(wholedollarse) == typeid(1));		// Incorrect data type used for wholedollarse
  test(typeid(centdollarse) == typeid(1));		// Incorrect data type used for centdollarse
  test(typeid(wholetotal) == typeid(1));			// Incorrect data type used for wholetotal
  test(typeid(centtotal) == typeid(1));			// Incorrect data type used for centtotal
  if (pesos == 254.19 && euros == 48.36)			// Does not pass test 1
  {
    test(wholedollarsp == 14 && centdollarsp == 55);
    test(wholedollarse == 51 && centdollarse == 45);
    test(wholetotal == 66 && centtotal == 0);
  }
  if (pesos == 188.25 && euros == 130.00)				// Does not pass test  2
  {
    test(wholedollarsp == 10 && centdollarsp == 78);
    test(wholedollarse == 138 && centdollarse == 30);
    test(wholetotal == 149 && centtotal == 8);
  }
  if (pesos == 200.00 && euros == 200.00)			// Does not pass test  3
  {
    test(wholedollarsp == 11 && centdollarsp == 45);
    test(wholedollarse == 212 && centdollarse == 77);
    test(wholetotal == 224 && centtotal == 22);
  }
  if (pesos == 856.70 && euros == 93.07)				// Does not pass test  4
  {
    test(wholedollarsp == 49 && centdollarsp == 4);
    test(wholedollarse == 99 && centdollarse == 1);
    test(wholetotal == 148 && centtotal == 5);
  }

  return 0;
}