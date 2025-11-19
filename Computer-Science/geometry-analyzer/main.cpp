//******************************************************************************
//  
// CSCI 1470.06
// Spring 2024
// 
// Gavino Martinez
// 
// Using your own words, write here a description of what the program does.
// Program that reads an input file with coordinates and finds the distance between them and the area of the triangle that those coordinates form. It then outputs all that information to an output file.
//******************************************************************************

#include <typeinfo>				// to be able to use operator typeid

// Include here the libraries that your program needs to compile
#include <iostream>      // to be able to use cout
#include <iomanip>       // to be able to use setprecision
#include <fstream>       // to be able to open files
#include <cmath>         // to be able to use round
using namespace std;

// Ignore this; it's a little function used for making tests
inline void _test(const char* expression, const char* file, int line)
{
  cerr << "test(" << expression << ") failed in file " << file;
  cerr << ", line " << line << "." << endl << endl;
}
// This goes along with the above function...don't worry about it
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

// Insert here the prototypes of the functions
double round_off(double value, int digits);
double square(double x);
double calcLength(double x1, double y1, double x2, double y2);
void getPoint(ifstream & inFile, double & x, double & y);
double semiPerimeter(double ab, double bc, double ca);
double calcArea(double ab, double bc, double ca);
void printDistance(ofstream & oFile, double x1, double y1, double x2, double y2, double distance);


int main()
{

 // Algorithm written in pseudocode
    /*

    Declare input and output file variable
    Declare variables for area, coordinates, and distances between those coordinates
    Open input and output files
    Recieve the coordinates from the input file from the three vertices by calling the getPoint void function
    Calculate the distance between the three vertices by calling the calcLength value-returning function
    Calculate the area of the triangle by calling the calcArea value-returning function
    Print the results to the output file by calling the printDistance void function
    Close the files

    */

// Declare input and output file variable
ifstream inFile;
ofstream outFile;

// Declare variables for area, coordinates, and distances between those coordinates
double area, x1, y1, x2, y2, x3, y3, distance1, distance2, distance3;

// Open input and output files
inFile.open("input.txt");
  if(!inFile.is_open()){
    cout << "Input.txt file could not be opened" << endl << endl;
    return 1;
  }
outFile.open("output.txt");
  if(!outFile.is_open()){
    cout << "Output.txt file could not be opened" << endl << endl;
    return 1;
  }

// Recieve the coordinates from the input file from the three vertices by calling the getPoint void function
  getPoint(inFile, x1, y1);
  getPoint(inFile, x2, y2);
  getPoint(inFile, x3, y3);

// Calculate the distance between the three vertices by calling the calcLength value-returning function
  distance1 = calcLength(x1, y1, x2, y2);
  distance2 = calcLength(x2, y2, x3, y3);
  distance3 = calcLength(x1, y1, x3, y3);

// Calculate the area of the triangle by calling the calcArea value-returning function
  area = calcArea(distance1, distance2, distance3);

// Print the results to the output file by calling the printDistance void function
  printDistance(outFile, x1, y1, x2, y2, distance1);
  printDistance(outFile, x2, y2, x3, y3, distance2);
  printDistance(outFile, x1, y1, x3, y3, distance3);
  outFile << endl << "The area of this triangle is: " << area << endl;

// Close the files
  inFile.close();
  outFile.close();

// Do NOT remove or modify the following statements

  cout << endl << "Testing your solution" << endl << endl;

  test(fabs(round_off(calcLength(1.0, 1.2, 6.0, 6.1), 2) - 7.00) < .001);			// Incorrect calculation of length
  test(fabs(round_off(calcLength(6.0, 6.1, 3.2, 6.5), 2) - 2.83) < .001);			// Incorrect calculation of length
  test(fabs(round_off(calcLength(1.0, 1.2, 3.2, 6.5), 2) - 5.74) < .001);			// Incorrect calculation of length
  test(fabs(calcArea(calcLength(1.0, 1.2, 6.0, 6.1), calcLength(6.0, 6.1, 3.2, 6.5), calcLength(1.0, 1.2, 3.2, 6.5)) - 7.86) < .001);			// Incorrect calculation of area

  test(fabs(round_off(calcLength(1.2, 1.2, 7.6, 4.3), 2) - 7.11) < .001);			// Incorrect calculation of length
  test(fabs(round_off(calcLength(7.6, 4.3, 9.2, 3.4), 2) - 1.84) < .001);			// Incorrect calculation of length
  test(fabs(round_off(calcLength(1.2, 1.2, 9.2, 3.4), 2) - 8.30) < .001);			// Incorrect calculation of length
  test(fabs(calcArea(calcLength(1.2, 1.2, 7.6, 4.3), calcLength(7.6, 4.3, 9.2, 3.4), calcLength(1.2, 1.2, 9.2, 3.4)) - 5.36) < .001);			// Incorrect calculation of area

  test(fabs(round_off(calcLength(5.0, 5.0, 9.0, 9.0), 2) - 5.66) < .001);			// Incorrect calculation of length
  test(fabs(round_off(calcLength(1.0, 1.0, 5.0, 5.0), 2) - 5.66) < .001);			// Incorrect calculation of length
  test(fabs(round_off(calcLength(1.0, 1.0, 9.0, 9.0), 2) - 11.31) < .001);		// Incorrect calculation of length
  test(fabs(calcArea(calcLength(1.0, 1.0, 5.0, 5.0), calcLength(5.0, 5.0, 9.0, 9.0), calcLength(1.0, 1.0, 9.0, 9.0)) - 0.00) < .001);			// Incorrect calculation of area

  return 0;		
}

//************************  Function definitions  *************************
// Read the handout carefully for detailed description of the functions that you have to implement

// round_off(): Rounds the value received in the first parameter to the number of digits received in the second parameter
double round_off(double value, int digits){
  return round(value * pow(10., digits)) / pow(10., digits);
}

// Calculates the square of the value received and rounds it to two decimal places
double square(double x){
  return round_off(x*x, 2);
}

// Calculates the length between two points
double calcLength(double x1, double y1, double x2, double y2){
  double calcLength = sqrt(square(x1-x2) + square(y1-y2));
return round_off(calcLength,10);
}

//getPoint is used to get the values from the input file
void getPoint(ifstream & inFile, double & x, double & y){
  inFile >> x >> y;
  x = round_off(x,1);
  y = round_off(y,1);
}

//Calculates the semi-perimeter by receiving the three lengths and rounds to ten decimal places.
double semiPerimeter(double ab, double bc, double ca) {
  double semiPerimeter = 1./2. * (ab + bc + ca);
  return round_off(semiPerimeter, 10);
}

//Calculates the area of the triangle by receiving the three lengths and rounds to two decimal places.
double calcArea(double ab, double bc, double ca){
  double s = semiPerimeter(ab, bc, ca);
  double triArea = sqrt((s*(s-ab)*(s-bc)*(s-ca)));
  return round_off(triArea, 2);
}

// Prints the distance between the coordinates to the output file
void printDistance(ofstream & oFile, double x1, double y1, double x2, double y2, double distance){
  oFile << "The distance between (" << fixed << setprecision(1) << x1 << "," << y1 << ") and (" << x2 << "," << y2 << ") is " << setprecision(2) << distance << endl;
}