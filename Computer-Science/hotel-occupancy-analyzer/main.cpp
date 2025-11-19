/////////////////////////////////////////////////////////////////////
//
// Name: Gavino Martinez
// Date: 4/4/2024
// Class: CSCI 1470.06
// Semester: Spring 2024
// CSCI 1470 Instructor: Mr. Dietrich
//
// Program Description:Reads hotel room occupancy data from a file and prints a table 
// showing the number of occupied rooms and occupancy rate per floor, as well as the 
// overall hotel occupancy rate.
/////////////////////////////////////////////////////////////////////


#include<iostream>

// Include here the libraries that your program needs to compile

#include <fstream>
#include <iomanip>

using namespace std;

// Insert here your function prototype

void printHotelOccupancy(ifstream & inFile);

int main()
{
// Enter here all the statements needed to use the input file
ifstream inFile;
inFile.open("occupants.txt");
// Check if there was an error opening the input file
if (!inFile){
 cout << "Error opening input file\n";
 return 1;
}
// Call the function to print the occupancy table
printHotelOccupancy(inFile);

// Close the input file
inFile.close();

  return 0;
}

//************************  Function definitions  *************************
// Read the handout carefully for detailed description of the functions that you have to implement


// This function receives an input file with data about rooms in a hotel.
// Each row of the file represents a floor in the hotel. You do not know ahead of time how many floors there are in the hotel.
// Each room is represented by a single digit: 1 (the room is occupied) or 0 (the room is not occupied).
// Because each floor can have a different number of rooms, the value -1 is used to indicate that the end of data for that floor has been reached.
// The function must print the header of the table followed by the floor number, the number of rooms occupied in that floor, and the occupancy
// rate (percentage of rooms occupied) for that floor. Below this information it must display the 
// overall occupancy rate (total number of occupied rooms/total number of rooms) for the whole hotel.
// The rates must be displayed real numbers with a single decimal digit.

void printHotelOccupancy(ifstream & inFile){

  int vacancy, occupiedRooms = 0, rooms = 0, floor = 1, occupants = 0, counter = 0;
  double rate, rateAvg;

  cout << setw(10) << "Floor " << "| " << setw(10) << "Occupants " << setw(10) << "Rate (%)\n"
  << "-------------------------------\n";

  while (!inFile.eof()){
    inFile >> vacancy;
    if (vacancy == -1){
        rate = static_cast<double>(occupants) / static_cast<double>(counter);
        cout << setw(9) << floor << " | " << setw(9) << occupants << setw(9) << fixed << setprecision(1) << rate*100. << endl;
        rooms += counter;
        occupiedRooms += occupants;
        ++floor;
        occupants = 1;
        counter = -1;
    }
    occupants += vacancy;
    ++counter;
  }
  floor -= 1;
  rateAvg = (static_cast<double>(occupiedRooms)/static_cast<double>(rooms))*100.;
  cout << "\nThe overall occupancy rate is: " << rateAvg << "%\n\n";
}