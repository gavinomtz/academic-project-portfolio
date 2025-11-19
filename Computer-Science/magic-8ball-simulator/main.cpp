/////////////////////////////////////////////////////////////////////
//
// Name: Gavino Martinez
// Due date: 3/21/2024
// Class: CSCI 1470.06
// Semester: Spring 2024
// CSCI 1470 Instructor: Mr. Dietrich
//
// Using your own words describe below what the program does 
// Program Description: Program that simulates a Magic 8-Ball. The user asks a question, 
// and the program generates a random answer using two methods: 
// one with multi-branch if-else statements and one with a switch statement.
//
/////////////////////////////////////////////////////////////////////

#include <iostream>				// to use cin and cout
#include <typeinfo>				// to be able to use operator typeid

// Include here the libraries and anything else that your program needs to compile


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
int randNumGen(int lowRange, int highRange);
string fortuneTellerA(int ranNum);
string fortuneTellerB(int ranNum);
int main()
{
  // Declare a variable named randomNumber that holds whole numbers
int randomNumber;
  // Declare a variable named lowRange that holds whole numbers and initializes it to 0
int lowRange = 0;
  // Declare a variable named highRange that holds whole numbers and initializes it to 4
int highRange = 4;
  // Seed the random number generator using expression 1) on my handout
srand(static_cast<int> (time(NULL)));
  // Prompt the user to enter a question
cout << "Ask the Magic 8 Ball a question: ";
  // Ignore the user input
cin.ignore();
  // Call function randNumGen() to generate a random number and assign it to randomNumber
randomNumber = randNumGen(lowRange, highRange);
  // Display title "Part A solution"
cout << "\nPart A solution\n\n";
  // Display the message shown below
  //	"Answer:  , call function fortuneTellerA() to get the answer
cout << "Answer: " << fortuneTellerA(randomNumber);
  // Display title "Part B solution"
cout << "\n\nPart B solution\n\n";
  //Displays the message shown below
  //	"Answer:  , call function fortuneTellerB() to get the answer
cout << "Answer: " << fortuneTellerB(randomNumber) << endl << endl;

  // Do NOT remove or modify the following statements
  cout << endl << "Testing your solution" << endl << endl;

  test(randomNumber >= 0 && randomNumber <= 4);			// Incorrect random number (out of range)

  test(fortuneTellerA(0) == "Yes");						// Incorrect answer
  test(fortuneTellerA(1) == "Maybe");						// Incorrect answer
  test(fortuneTellerA(2) == "No");						// Incorrect answer
  test(fortuneTellerA(3) == "Ask again later");			// Incorrect answer
  test(fortuneTellerA(4) == "I don't know");				// Incorrect answer
  test(fortuneTellerA(14) == "I don't know");				// Incorrect answer

  test(fortuneTellerB(0) == "Yes");						// Incorrect answer
  test(fortuneTellerB(1) == "Maybe");						// Incorrect answer
  test(fortuneTellerB(2) == "No");						// Incorrect answer
  test(fortuneTellerB(3) == "Ask again later");			// Incorrect answer
  test(fortuneTellerB(4) == "I don't know");				// Incorrect answer
  test(fortuneTellerB(14) == "I don't know");				// Incorrect answer

  return 0;
}

//************************  Function definitions  *************************
// Read the handout carefully for detailed description of the functions that you have to implement

// This function generates a random number within a specified range.
// It receives two whole numbers : the first one is the upper boundary and
// the second one is the lower boundary used to generate the random number.
// Returns the random number generated using expression 2) on my handout
int randNumGen(int lowRange, int highRange){
  return ( rand() % (highRange - lowRange + 1) ) + lowRange;
}

// Thisfunction uses multi - branch if - else statements to determine the answer to be 
// returned based on the number received.
// It receives the random number(whole number) and returns the corresponding answer
// based on the table shown on my handout
//
// Important: in this solution make your function directly return the answer in each
// branch of the multi - branch if - else statements.
string fortuneTellerA(int ranNum){
  if(ranNum == 0){
    return "Yes";
  }
  else if(ranNum == 1){
    return "Maybe";
  }
  else if(ranNum == 2){
    return "No";
  }
  else if(ranNum == 3){
    return "Ask again later";
  }
  else{
    return "I don't know";
  }
}


// This function uses switch statements to determine the answer to be 
// returned based on the number received.
// It receives the random number(whole number) and returns the corresponding answer
// based on the table shown on my handout
//
// Important: in this solution declare a local variable that holds text and assign
// the corresponding answer in each case of the switch statement. Upon exiting the
// switch return the value in the local variable.
string fortuneTellerB(int ranNum){
  string answer;
  switch(ranNum){
    case 0:
      answer = "Yes";
      break;
    case 1:
      answer = "Maybe";
      break;
    case 2:
      answer = "No";
      break;
    case 3:
      answer = "Ask again later";
      break;
    default:
      answer = "I don't know";
  }
  return answer;
}