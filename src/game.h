#ifndef GUARD_game_h
#define GUARD_game_h

#include <iostream>
#include <unordered_set>

using std::string;
using std::cout;
using std::endl;

// The game class will keep track of the state of the game, meaning
// - what guesses have been made so far, 
// - what clues have been given,
// - and what words have not yet been ruled out.
// It will also contain the logic for making a guess (the hard part!)
class Game {
public:
    //Game() constructor transfers all
    //words from "word-list.csv" to an unordered_set.
    Game();

    //guess() eliminates the possible options
    //given the player's clues and assigns
    //new currGuess.
    void guess(const string&);

    //Removes all words from wordsToRemove.
    void removeWords();

    //printGuess() prints currGuess.
    void printGuess() const;

    //printCurrentGame() prints all previous computer guesses.
    void printCurrentGame() const;
private:
    //Stores all possible words.
    //words is an unordered_set because it has random access and constant time deletion.
    std::unordered_set<string> words;

    //Stores the words previously guessed.
    std::vector<string> guessWords;

    //The current computer guess.
    //Assigned by function guess().
    //Starting guess will be "crane" for simplicity.
    string currGuess = "crane";

//    //Stores letters not included in the secret word.
//    //All elements are removed after a guess is made.
//    std::unordered_set<char> notInWord;

//    //Stores letters included in the secret word.
//    std::unordered_set<char> inWord;

    //Stores all words that need to be removed.
    //After removeWords() is called, wordsToRemove is cleared.
    std::unordered_set<string> wordsToRemove;

    //Stores letters included in the secret word plus its position.
    std::unordered_map<char,int> letterAndPosition;
};

#endif//GUARD_game_h
