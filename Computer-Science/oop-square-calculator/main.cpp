//******************************************************************************
// CSCI 1470.06 Spring 2024
// Gavino Martinez
// 
// 
// Using your own words, write here a description of what the program does.
// Program that uses a header file and an input file to show the area, perimeter, and diagonal of each sqaure from the input file.
//******************************************************************************

//CLIENT PROGRAM THAT WORKS WITH SQUARES

#include <iostream>
#include <fstream>

// include the header file for squares
#include "square.h"

using namespace std;

int main()
{
  ifstream inFile;
  int s1, s2, s3;  // declare three int variables
  // declare 3 objects of type square named sq1, sq2, and sq3 initializing the third one to 10
  square sq1, sq2, sq3;
  sq3.setSide(10);

inFile.open("input_hw4.txt");
if(!inFile)
{
  cout << "Could not open input file!" << endl << endl;
  // This is to pause the execution of the program
  cout << "Press Enter to continue ...";
  cin.sync();
  cin.get();
  return 1;
}

// Access members using dot operator
cout << "Before assigning values to the squares their sides are:" << endl;
cout << "Square 1: " << sq1.getSide() << endl;// Show the initial side of Square 1
cout << "Square 2: " << sq2.getSide() << endl;// Show the initial side of Square 2
cout << "Square 3: " << sq3.getSide() << endl;// Show the initial side of Square 3
cout << endl << "............Starting to process the file............" << endl << endl;
inFile >> s1 >> s2 >> s3;  // read 3 sides from the file (priming read)
while(inFile)
{
  cout << "Storing the values read into the side of squares..." << endl << endl;
  sq1.setSide(s1);    // store s1 in Square 1
  sq2.setSide(s2);    // store s2 in Square 2
  sq3.setSide(s3);    // store s3 in Square 3
  cout << "Displaying the new side of squares" << endl;
  cout << "Square 1: " << sq1.getSide() << endl;// Show the new side of Square 1
  cout << "Square 2: " << sq2.getSide() << endl;// Show the new side of Square 2
  cout << "Square 3: " << sq3.getSide() << endl;// Show the new side of Square 3
  cout << endl << "Testing other member functions" << endl << endl;
  cout << "Area of Square 2: " << sq2.area() << endl;// show the area of Square 2
  cout << "Perimeter of Square 3: " << sq3.perimeter() << endl;// show the perimeter of Square 3
  cout << "Diagonals of Square 1: " << sq1.diagonals() << endl;// show the length of the diagonals of Square 1

  cout << endl << "..........Done with this set of values :-).........." << endl << endl;

  inFile >> s1 >> s2 >> s3;  // read next set of 3 sides
}
inFile.close();
return 0;
}