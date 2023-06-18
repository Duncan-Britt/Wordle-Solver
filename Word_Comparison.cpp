#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool tempFix(int start,string wordSol, string wordGuess, unordered_map<char,int> letterCount) {
  for (int i=start+1; i<5; i++) {
    if (wordGuess[start]==wordGuess[i] && wordGuess[i]==wordSol[i]) {
      return true;
    }
  }
  return false;
}

string clues(string wordSol, string wordGuess) {
  unordered_map<char,int> letterCount;

  for (int i = 0; wordSol[i]; i++) {
    if (letterCount.find(wordSol[i]) == letterCount.end())
      letterCount.insert(make_pair(wordSol[i], 1));
    else
      letterCount[wordSol[i]]++;
  }

  string wordStatus = "";

  for (int i=0; i < 5; i++) {
    if (wordSol.find(wordGuess[i]) != string::npos) {
      if (letterCount[wordGuess[i]] == 0) {
        wordStatus.push_back('0');
      }
      else if (wordGuess[i]==wordSol[i]) {
        wordStatus.push_back('2');
        letterCount[wordGuess[i]]--;
      }
      else {
        if (i!=4 && tempFix(i, wordSol, wordGuess, letterCount)) {
          wordStatus.push_back('0');
        }
        else {
          wordStatus.push_back('1');
          letterCount[wordGuess[i]]--;
        }
      }
    }
    else {
      wordStatus.push_back('0');
    }
  }

  return wordStatus;
}

int main() {    
  char loop = 'y';
  
  while (loop == 'y') {
        
    string wordSol;
    string wordGuess;
    string wordStatus = "";
  
    cout << "Enter Wordle Solution: ";
    cin >> wordSol;

    /*
      for (auto& it : letterCount) {
      cout << it.first << ' ' << it.second << '\n';
      }
    */
    
    cout << "\nEnter Wordle Guess: ";
    cin >> wordGuess;
    
    /*
      for (auto& it : letterCount) {
      cout << it.first << ' ' << it.second << endl;
      }
    */

    cout << endl << clues(wordSol, wordGuess) << endl;
    
    cout << "\nContinue: ";
    cin >> loop;
  }
}
