/////////////////////////////////////////////////////////////////////
//
// Name: Gavino Martinez
// Due date: 2/28/2024
// Class: CSCI 1470.06
// Semester: Spring 2024
// CSCI 1470 Instructor: MR. DIETRICH
//
/////////////////////////////////////////////////////////////////////

//************************  Function definitions  *************************
// Read the handout carefully for detailed description of the functions that you have to implement

// round_off(): Rounds the value received in the first parameter to the number of digits received in the second parameter
double round_off(double value, int digits)
{
  return round(value * pow(10., digits)) / pow(10., digits);
}

// getData(): Gets two lengths from the keyboard and returns them to the caller
void getData(double & par1, double & par2)
{
  cout << "Please enter two lengths: ";
  cin >> par1 >> par2;
}

// printData(): Receives the output file, base of the rectangle, height of the rectangle, area of the rectangle,
// radius a of the ellipse, radius b of the ellipse, and area of the ellipse and prints the output to the file
void printData(ofstream & oFile, double b, double h, double ar, double ra, double rb, double ae)
{
  oFile << "The area of the rectangle with base " << setw(6) << fixed << setprecision(2) << b << " and height " << setw(6) << h << " is " << setw(6) << ar << endl << endl << "The area of the ellipse with radius " << setw(6) << ra << " and radius " << setw(6) << rb << " is " << setw(6) << ae << endl << endl;
}

// area_rectangle(): Calculates the area of the rectangle and returns it rounded to 1 decimal digit to the caller
double area_rectangle(double b, double h)
{
  double ar;
  ar = b * h;
  return round_off(ar, 1);
}

// area_ellipse(): Calculates the area of the area_ellipse and returns it rounded to 1 decimal digit to the caller
double area_ellipse(double ra, double rb)
{
  double ae;
  ae = PI * ra * rb;
  return round_off(ae, 1);
}