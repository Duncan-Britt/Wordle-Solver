#include <algorithm>
#include <cctype>
#include <iostream>
#include "font.h"
#include "game.h"

using std::cout;
using std::endl;        
using std::cin;
using std::string;

/*
  .       __         .                                       __   __                                          
  /       |    ___   |     ___    __.  , _ , _     ___       |    |    ___    ____   ____   ___    ___.   ___ 
  |       |  .'   `  |   .'   ` .'   \ |' `|' `. .'   `      |\  /|  .'   `  (      (      /   ` .'   ` .'   `
  |  /\   /  |----'  |   |      |    | |   |   | |----'      | \/ |  |----'  `--.   `--.  |    | |    | |----'
  |,'  \,'   `.___, /\__  `._.'  `._.' /   '   / `.___,      /    /  `.___, \___.' \___.' `.__/|  `---| `.___,
  \___/       
  ===============
  Welcome to the Wordle Solver. Enter P to play, I for instructions, or Q to quit.
  _                .                        .                          
  | , __     ____ _/_   .___  ,   .   ___  _/_   `   __.  , __     ____
  | |'  `.  (      |    /   \ |   | .'   `  |    | .'   \ |'  `.  (    
  | |    |  `--.   |    |   ' |   | |       |    | |    | |    |  `--. 
  / /    | \___.'  \__/ /     `._/|  `._.'  \__/ /  `._.' /    | \___.'
                                                                      
  ============

  Come up with a secret 5 letter word. After each guess the computer makes,
  enter clues. Your clues will be in the form of a 0, 1, or 2 under each
  letter in the word. E.g.

  > Guess: CAKED
  > Clues: 01020

  0: The above letter does not appear in the word.
  1: The above letter appears at least once in the word, but never in that spot.
  2: The above letter appears at least once in the word, and one of
  those appearances is in that exact spot.

  There are other commands:
  I: View these instructions again. You will not lose your progress in the game.
  R: Restart the game.
  Q: Quit the program. You're progress will not be saved.
  P: Print the guesses and clues in the current game.

  We recommend playing with our companion application for generating the correct
  clues in response to each guess.

  .___   .                 
  /   \  |     ___  ,    . 
  |,_-'  |    /   ` |    ` 
  |      |   |    | |    | 
  /     /\__ `.__/|  `---|.
  \___/ 
  ====

  > Guess: CAKED
  > Clues: 01020

  > Guess: MAYER
  > Clues: 
*/

bool areDigits(const string& input);
void displayWelcomeMessage();
string downcase(string s);
bool isClue(const string& input);
void printVictoryMessage();
void printInstructions();

int main () {
    const Game game;
    displayWelcomeMessage();
  
    // GAME LOOP
    string input;
    while (getline(cin, input)) {
        cout << endl;
    
        if (downcase(input) == "q") {
            break;
        } else if (isClue(input)) {
            if (input == "22222") { // correct guess
                printVictoryMessage();
                break;
            }
            game.guess(input);
            game.printGuess();
            cout << Fonts::prompt << "> " << Fonts::message << "Clues: " << Fonts::input;
        } else if (downcase(input) == "p") {
            game.printCurrentGame();
        } else if (downcase(input) == "i") {
            printInstructions();
            cout << Fonts::prompt << "> " << Fonts::input;
        } else {
            cout << Fonts::message << "Invalid input: " << Fonts::input << input << endl
                 << Fonts::prompt << "> " << Fonts::input;
        }
    }

    cout << Fonts::message << "Tata for now!" << endl;
  
    return 0;
}

bool areDigits(const string& input) {
    return std::all_of<string::const_iterator>(input.begin(), input.end(), isdigit);
}

void displayWelcomeMessage() {
    cout << Fonts::message
         << "Welcome to the Wordle Solver. Enter P to play, I for instructions, or Q to quit." << endl
         << Fonts::prompt << "> " << Fonts::input; 
}

string downcase(string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::tolower(c); });
    return s;
}

bool isClue(const string& input) {
    // return input.length() == 5 && areDigits(input);
    return input.length() == 5 &&
        std::all_of<string::const_iterator>(input.begin(), input.end(), [](auto c) {
            return c == '0' || c == '1' || c == '2';
        });
}

void printInstructions() {
    const string message = "Come up with a secret 5 letter word. After each guess the computer makes,\n"
        "enter clues. Your clues will be in the form of a 0, 1, or 2 under each\n"
        "letter in the word. E.g.\n"
        "\n"
        "> Guess: CAKED\n"
        "> Clues: 01020\n"
        "\n"
        "0: The above letter does not appear in the word.\n"
        "1: The above letter appears at least once in the word, but never in that spot.\n"
        "2: The above letter appears at least once in the word, and one of\n"
        "those appearances is in that exact spot.\n"
        "\n"
        "There are other commands:\n"
        "I: View these instructions again. You will not lose your progress in the game.\n"
        "R: Restart the game.\n"
        "Q: Quit the program. You're progress will not be saved.\n"
        "P: Print the guesses and clues in the current game.\n"
        "\n"
        "We recommend playing with our companion application for generating the correct\n"
        "clues in response to each guess.\n"
        "\n"
        "Enter P to play (or print game state), I for instructions, or Q to quit.\n";

    cout << Fonts::message << message << Fonts::input << endl;
}

void printVictoryMessage() {
    cout << Fonts::message
         << "Wordle Solved!"
         << Fonts::input << endl;
}
