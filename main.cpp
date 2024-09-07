#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cctype>

#include "utility.h"
#include "cards.h"

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  Cards alice;
  Cards bob;
  
  //Read each file
  // cout<<"Alice:\n";
  while (getline (cardFile1, line) && (line.length() > 0)){
    int val;
    string tempSuit;
    string tempVal;
    // cout<<line<<endl;
    if (line.length() == 3) {
      tempSuit = line.substr(0,1);
      tempVal = line.substr(2,1);
    }
    else {
      tempSuit = line.substr(0,1);
      tempVal = line.substr(2,2);
    }
    if (tempVal.compare("10") == 0)
      val = 10;
    else if (isdigit(tempVal[0]) == 0){
      if (tempVal.compare("k") == 0)
        val = 13;
      if (tempVal.compare("q") == 0)
        val = 12;
      if (tempVal.compare("j") == 0)
        val = 11;
      if (tempVal.compare("a") == 0)
        val = 1;
    }
    else {
          val = tempVal[0] - '0';
    }
    oneCard obj(val, tempSuit);
    alice.insert(obj);
    
  }
  cardFile1.close();

  // cout<<"Bob: \n";
  while (getline (cardFile2, line) && (line.length() > 0)){
    int val;
    string tempSuit;
    string tempVal;
    // cout<<line<<endl;
    if (line.length() == 3) {
      tempSuit = line.substr(0,1);
      tempVal = line.substr(2,1);
    }
    else {
      tempSuit = line.substr(0,1);
      tempVal = line.substr(2,2);
    }
    if (tempVal.compare("10") == 0)
      val = 10;
    else if (isdigit(tempVal[0]) == 0){
      if (tempVal.compare("k") == 0)
        val = 13;
      if (tempVal.compare("q") == 0)
        val = 12;
      if (tempVal.compare("j") == 0)
        val = 11;
      if (tempVal.compare("a") == 0)
        val = 1;
    }
    else {
          val = tempVal[0] - '0';
    }
    oneCard obj(val, tempSuit);
    bob.insert(obj);
  
  }
  cardFile2.close();

  Cards::Node *tempAlice = alice.getNodeFor(alice.getMin(), alice.root);
  Cards::Node *tempBob = bob.getNodeFor(bob.getMax(), bob.root);
  bool aliceTurn = true; //true if alice turn, false if bob turn
  bool GameOver = false; //if true game ends and outer while loop condition is false
  oneCard temp;
  // cout << endl << "Alice's cards:" << endl;
  // cout << endl << "Alice's cards:" << endl;
  // alice.printInOrder();
  // cout << endl << "Bob's cards:" << endl;
  // bob.printInOrder();


  while (!GameOver) { 
    while (aliceTurn) {
      // cout << tempAlice->currCard.getValue() << endl;
      if ((tempAlice == nullptr) || (tempAlice->currCard.getValue() == 0)) {
        //cout << "Alice has no cards right now." << endl;
        aliceTurn = false;
        GameOver = true; 
        break;
      }
      else {
        
        if (bob.contains(tempAlice->currCard)) {
          if (tempAlice->currCard == tempBob->currCard){
            tempBob = bob.getNodeFor(bob.getPredecessor(tempBob->currCard), bob.root);
            // cout  << "Bob: " << tempBob->currCard.getValue() << tempBob->currCard.getSuit() << endl;
          }
          cout << "Alice picked matching card ";
          alice.printCard(tempAlice);
          temp = tempAlice->currCard;
          tempAlice = alice.getNodeFor(alice.getSuccessor(tempAlice->currCard), alice.root);
          alice.remove(temp);
          bob.remove(temp); 
      
          // cout << "Alice's turn ended" << endl;
          aliceTurn = false;
        }
        else {
          //cout << alice.getSuccessor(tempAlice->currCard).getValue() << endl;
          tempAlice = alice.getNodeFor(alice.getSuccessor(tempAlice->currCard), alice.root);
          // if(tempAlice)
          //  cout  << "Alice: " << tempAlice->currCard.getValue() << tempAlice->currCard.getSuit() << endl;
          //cout << "No matching card on Alice's end" << endl;
          
        }
        
      }
      
      //cout << "Alice's turn ended" << endl;

    }


    while (!aliceTurn) {
      // cout << tempBob->currCard.getValue() << endl;
      if ((tempBob == nullptr) || (tempBob->currCard.getValue() == 0)) {
        
         //cout << "Bob has no cards right now." << endl;
         aliceTurn = true;
         GameOver = true;
         break;
      }
      else {
        //cout << tempBob->currCard.getValue() << endl;
        if (alice.contains(tempBob->currCard)) {
          if (tempAlice->currCard == tempBob->currCard)
            tempAlice = alice.getNodeFor(alice.getSuccessor(tempAlice->currCard), alice.root);
          cout << "Bob picked matching card ";
          bob.printCard(tempBob);
          temp = tempBob->currCard;
          tempBob = bob.getNodeFor(bob.getPredecessor(tempBob->currCard), bob.root);
          alice.remove(temp);
          bob.remove(temp);

          aliceTurn = true;
        
        }
        else {
          //cout << alice.getSuccessor(tempAlice->currCard).getValue() << endl;
          //cout << bob.getPredecessor(tempBob->currCard).getValue() << endl;
          //cout << "No matching card on Bob's end" << endl;
          
          tempBob = bob.getNodeFor(bob.getPredecessor(tempBob->currCard), bob.root);
          // if(tempBob)
          //   cout  << "Bob: " << tempBob->currCard.getValue() << tempBob->currCard.getSuit() << endl;
          //if (!tempAlice) cout << "null" << endl;
        }
      }
      //cout << "Bob's turn ended" << endl;
      
      // if(tempBob)
      //   cout  << "Bob: " << tempBob->currCard.getValue() << tempBob->currCard.getSuit() << endl;
      // if(tempAlice)
      //   cout  << "Alice: " << tempAlice->currCard.getValue() << tempAlice->currCard.getSuit() << endl;
     
    }
    
  }
 
  cout << endl << "Alice's cards:" << endl;
  alice.printInOrder();
  cout << endl << "Bob's cards:" << endl;
  bob.printInOrder();
  return 0;
  
}
