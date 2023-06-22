#ifndef GUARD_game_h
#define GUARD_game_h

#include <string>

// The game class will keep track of the state of the game, meaning
// - what guesses have been made so far, 
// - what clues have been given,
// - and what words have not yet been ruled out.
// It will also contain the logic for making a guess (the hard part!)
class Game {
public:
  Game();
  void guess(const std::string&) const; 
  void printGuess() const; 
  void printCurrentGame() const;
private:
  
};

#endif//GUARD_game_h
