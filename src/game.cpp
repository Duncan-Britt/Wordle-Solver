#include "game.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::string;

void Game::guess(const string& input) {

    //I will somehow make notInWord and inWord private members but currently there are some scoping issues with the lamdas.

    //Stores letters included in the secret word.
    std::vector<char> inWord;

    //Stores letters not included in the secret word.
    //All elements are removed after a guess is made.
    std::vector<char> notInWord;

    for (int i=0; i<5; i++) {
        if (input[i] == '0') {
            notInWord.push_back(currGuess[i]);
        } else if (input[i] == '1') {
            // TODO...
        } else if (input[i] == '2') {
            letterAndPosition.insert(std::make_pair(currGuess[i], i));
        } else {
            cout << "That is not a valid input!" << endl;
            break;
        }
    }

    //Removes all words from the list-words that contain letters not in the secret word.
    words.remove_if([&notInWord](const string& str) {
        return std::any_of(str.begin(), str.end(), [&notInWord](char ch) {
            return std::find(notInWord.begin(), notInWord.end(), ch) != notInWord.end();
        });
    });

    // TODO...

    //currGuess = ;
}

void Game::printGuess() const {
    cout << "Guess: " << currGuess << endl;
}

void Game::printCurrentGame() const {
    cout << "List of Previous Guesses: " << endl;
    for (int i=0; i<guessWords.size(); i++) {
        cout << "Guess " << i+1 << ":" << guessWords[i] << endl;
    }
}

Game::Game() {
    //Change word-list.csv to .txt file because idk how to traverse a csv file
    string wordFile = "word-list.csv";
    string word;
    std::ifstream file(wordFile);
    while (getline(file, word)) {
        words.push_back(word);
    }
}
