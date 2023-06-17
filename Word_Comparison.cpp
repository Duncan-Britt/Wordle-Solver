#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main() {
  char loop = 'y';
  
  while (loop == 'y') {

    unordered_map<char,int> letterCount;
    string wordSol;
    string wordGuess;
    string wordStatus = "";
  
    cout << "Enter Wordle Solution: ";
    cin >> wordSol;

    for (int i = 0; wordSol[i]; i++) {
        if (letterCount.find(wordSol[i]) == letterCount.end())
            letterCount.insert(make_pair(wordSol[i], 1));
        else
            letterCount[wordSol[i]]++;
    }

/*
    for (auto& it : letterCount) {
        cout << it.first << ' ' << it.second << '\n';
    }
*/
    
    cout << "\nEnter Wordle Guess: ";
    cin >> wordGuess;
    
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
          wordStatus.push_back('1');
          letterCount[wordGuess[i]]--;
        }
      }
      else {
        wordStatus.push_back('0');
      }
    }

    cout << "\n" << wordStatus << "\n";
    
/*
    for (auto& it : letterCount) {
        cout << it.first << ' ' << it.second << endl;
    }
*/
    
    cout << "\nContinue: ";
    cin >> loop;
  }
}
