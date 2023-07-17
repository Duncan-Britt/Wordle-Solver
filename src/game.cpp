#include "game.h"
#include <iostream>
#include <fstream>
#include <unordered_set>
#include <cstdlib>
#include <time.h>
#include "font.h"

using std::cout;
using std::endl;
using std::string;
// using std::unordered_set;
using std::vector;

void Game::guess(const string& input) const {

    //Adds the previous computer guess to the vec guessWords
    // guessWords.push_back(currGuess);

    //I will somehow make notInWord and inWord private members but currently there are some scoping issues with the lamdas.
    //Just in case we want to add an option where the player wants us to print out this info.

    //Stores letters included in the secret word.
    std::unordered_set<char> inWord;

    //Stores letters not included in the secret word.
    //All elements are removed after a guess is made.
    std::unordered_set<char> notInWord;

    //This part of the code still doesn't fully work because of certain cases:
    //(secret word is pasta)
    //Guess: taste
    //Clue: 02220
    //This part of the code will read it as 'a' is not in the secret word because the last 'a' gives a 0.
    for (int i=0; i<5; i++) {
        switch(input[i]) {
            case '0':
                // notInWord.insert(currGuess[i]);
                break;
            case '1':
                // TODO...
                break;
            case '2':
                // letterAndPosition.insert(std::make_pair(currGuess[i], i));
                break;
            default:
                cout << "That is not a valid input!" << endl;
                break;
        }
    }

    //If input only contained 1's and 2's, this code doesn't need to run.
    if (!notInWord.empty()) {

        //Stores all words that need to be removed in the vec wordsToRemove.
        for (const auto& str : words) {
            if (std::any_of(str.begin(), str.end(), [&notInWord](char ch) {
                return notInWord.find(ch) != notInWord.end();
            })) {
                // wordsToRemove.insert(str);
            }
        }
    }

    //All words stored in wordsToRemove are removed from words.
    removeWords();

    //If the previous computer guess yielded no 2's, then this code doesn't need to run.
    if (!letterAndPosition.empty()) {

        //Stores all words for removal that don't contain letters in specific positions.
        for (const auto& str : words) {
            bool allTrue = true;
            for (const auto& item : letterAndPosition) {
                if (str[item.second] != item.first) {
                    allTrue = false;
                    break;
                }
            }
            if (!allTrue) {
                // wordsToRemove.insert(str);
            }
        }

        //All words stored in wordsToRemove are removed from words.
        removeWords();
    }

    // TODO...

    //currGuess = ;
}

void Game::removeWords() const {
    for (const auto& str : wordsToRemove) {
        // words.erase(str);
    }
    // wordsToRemove.clear();
}

void Game::printGuess() const {
    // cout << "Guess: " << currGuess << endl;
    cout << Fonts::prompt << "> " << Fonts::message << "Guess: " << guessWords[guessWords.size()-1] << endl;
}

void Game::printCurrentGame() const {
    // cout << "List of Previous Guesses: " << endl;
    // for (int i=0; i<guessWords.size(); i++) {
    //     cout << "Guess " << i+1 << ":" << guessWords[i] << endl;
    // }

    int i = 0;
    for (; i < clues.size(); i++) {
        cout << Fonts::prompt << "> " << Fonts::message << "Guess: " << guessWords[i] << endl
             << Fonts::prompt << "> " << Fonts::message << "Clues: " << clues[i] << endl
             << endl;
    }

    if (i < guessWords.size()) {
        cout << Fonts::prompt << "> " << Fonts::message << "Guess: " << guessWords[i] << endl
             << Fonts::prompt << "> " << Fonts::message << "Clues: " << Fonts::input;
    }
}

Game::Game() {
    //Change word-list.csv to .txt file because idk how to traverse a csv file
    string wordFile = "word-list.csv";
    string word;
    std::ifstream file(wordFile);
    while (getline(file, word)) {
        // words.insert(word);
        words.emplace_back(word);
    }
    
    // Guess randomly for the first guess
    srand(time(NULL));
    const vector<string>::size_type randWordIdx = rand() % words.size();
    // cout << words.size() << endl;
    // cout << words[randWordIdx] << endl;    
    guessWords.emplace_back(words[randWordIdx]);
    words.erase(words.begin() + randWordIdx);
    // cout << words.size() << endl;
}
