/////////////////////////////////////////////////////////////////////
//
// Name: Gavino Martinez
// Date: 4/19/2024
// Class: CSCI 1470.06
// Semester: Spring 2024
// CSCI 1470 Instructor: Mr. Dietrich
//
// Program Description: Program that gets a file of students names and grade and outputs that 
// along with their curved grade and a graph to an output file up to 40 students
/////////////////////////////////////////////////////////////////////

#include <iostream>

// Include here the libraries that your program needs to compile
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

// Insert here your function prototypes
void getData(ifstream& inFile, ofstream& oFile, string student[], int grade[], int& totalStudents);
int getMax(const int grade[], int totalStudents);
void printData(ofstream& oFile, const string student[], const int grade[], int totalStudents, int maxGrade);
int curveGrade(int grade, int maxGrade);

// Declare here global constant MAX
const int MAX = 40;

int main()
{
  // Declare all the variables that will be used to process the data
    ifstream iFile;
    ofstream oFile;
    string student[MAX];
    int grade[MAX];
    int maxGrade;
    int totalStudents;
  // Open the files ensuring they are opened

    iFile.open("input.txt");
    if(!iFile){
        cout << "File not found!\n\n";
        return 1;
    }

    oFile.open("output.txt");
    if(!oFile){
        cout << "File not found!\n\n";
        return 1;
    }

  // Call the functions to process the data

    getData(iFile, oFile, student, grade, totalStudents);
    maxGrade = getMax(grade, totalStudents);
    printData(oFile, student, grade, totalStudents, maxGrade);

  // Close the files
    iFile.close();
    oFile.close();

return 0;		
}


//************************  Function definitions  *************************
// Read the handout carefully for detailed description of the functions that you have to implement


// Receives the input file, the array of students’ names, and the array of students’ grades.
// It reads the input data from the file into the corresponding arrays and returns them along
// with the quantity of students processed to main().Although there should be no more than 40
// students, this function must ensure that if the file has more than 40 records it reads only
// the first 40 and displays a warning on the screen indicating that the maximum has been exceeded.

void getData(ifstream& inFile, ofstream& oFile, string student[], int grade[], int& totalStudents)
{
  // WRITE THE BODY OF THIS FUNCTION
  for(totalStudents = 0; !inFile.eof(); ++totalStudents){
      if(totalStudents == 40){
          oFile << "Warning!, maximum capacity reached. Only recording first 40 grades and names.\n\n";
          break;
      }
      else{
      inFile >> student[totalStudents] >> grade[totalStudents];
      }
  }
}

// Receives the array of students’ grades and the quantity of grades to process. It determines
// and returns to main() the highest grade of the class.

int getMax(const int grade[], int totalStudents)
{
  // WRITE THE BODY OF THIS FUNCTION
  int i = 0, max = 1;
    do{
        if(grade[i] > grade[max]){
            max = i;
        }
        ++i;
    }while(i < totalStudents);
    return grade[max];
}


// Receives the output file, the array of students’ names, the array of students’ grades, the
// quantity of students to process, and the highest grade of the class.It sends the output
// to the output file as shown in Figure 2. This function must call a function named curveGrade()
// to get the values for the curved grades(curved grade = actual grade / highest grade * 100).

void printData(ofstream& oFile, const string student[], const int grade[], int totalStudents, int maxGrade)
{
  // WRITE THE BODY OF THIS FUNCTION
  int i, curve, quantity, count;

  oFile << setw(12) << "Student" << setw(15) << "Actual" << setw(12) << "Curved" << setw(15) << "Graph\n"
  << setw(10) << "Name" << setw(17) << "Grade" << setw(13) << "Grade\n" << "-----------------" << setw(12)
  << "--------" << setw(12) << "--------" << setw(15) << "-----------";

  for(i = 0; i < totalStudents; ++i){
      curve = curveGrade(grade[i], maxGrade);
      oFile << endl << setw(14) << student[i] << setw(12) << grade[i] << setw(12) << curve << setw(8) << '|';
      quantity = (curve+5)/10;
      for(count = 0; count < quantity; ++count){
          oFile << '*';
      }
  }
}

// Receives the actual grade of a student and the highest grade of the class and returns the curved grade.
// The arguments that it receives are whole numbers. The result of the division must be rounded off to
//  the nearest integer before it is returned by the function.

int curveGrade(int grade, int maxGrade)
{
  // WRITE THE BODY OF THIS FUNCTION
  double curve = static_cast<double>(grade)*100/static_cast<double>(maxGrade);
  return static_cast<int>(round(curve));
}