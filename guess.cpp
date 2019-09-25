#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;
/*
  Finn McKinley
  9/25/19
  A Guessing Game
 */
int main() {
  bool running = true;
  //Keep track of if the game is running
  while (running == true) {//While the game is running
    int RandNum;
    //Variable to keep track of the random #
    int input = 0;
    //Variable to keep track of the user's inputted #
    int guess = 0;
    //Variable to keep track of how many times the user guessed
    char playAgain;
    //Char for asking to play again
    srand(time(NULL));
    RandNum = rand() % 100;
    //Generate a random #
    while (input != RandNum) {//While the user's inputted # != the random number
      cout << "Guess a number between 0 and 100" << endl;
      //Tell them to guess a # between 0 and 100
      cin >> input;
      //Take the input
      //Add 1 to guess
      if (cin.fail()) {//Code from Stack Overflow, answer from user Doug T.
	//https://stackoverflow.com/questions/5864540/infinite-loop-with-cin-when-typing-string-while-a-number-is-expected
	//Prevents wrong variable types from throwing errors
	cout << "Error -- You did not enter a number." << endl;
	cin.clear();
	//Get rid of failure state
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//Discard the "bad" character
      }
      if (input < RandNum) {//If the inputted # is < the random
	cout << "Your guess was too low." << endl;
	//Tell the user that their guess was too low
	guess++;
	cout << guess << endl;
      }
      else if (input > RandNum) {//Else if inputted # is > the random #
	cout << "Your guess was too high." << endl;
	//Tell the user that their guess was too high
	guess++;
	cout << guess << endl;
      }
      else if (input == RandNum) {//Else if inputted # == the random #
	cout << "Your guess was correct!" << endl;
	//Tell the user that their guess was correct
	cout << "You took " << guess << " guesses" << endl;
	//Tell the user how many guesses it took them
	cout << "Do you want to play again? (Y/N)" << endl;
	//Ask the user if they want to play again
	cin >> playAgain;
	//Take the input
	if (playAgain == 'Y') {//If the user says yes
	  running = true;
	  //Keep running the program and start over
	}
	else if (playAgain == 'N') {//Else if they say no
	  running = false;
	  //Close the program
	}
	else {//If it's neither of those options
	  cout << "That's not a valid response" << endl;
	  //Tell the user that that's not a valid response
	  cout << "Do you want to play again? (Y/N)" << endl;
	  //Ask the user again if they want to play again
	  cin >> playAgain;
	  //Take the user's input
	  if (playAgain == 'Y') {
	    running = true;
	  }
	  else if (playAgain == 'N') {
	    running = false;
	  }
	}
      }
    }
  }
}
