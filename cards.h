// cards.h
// Nikita Sharma, Anvitha Kosuri
// All class declarations go here


#ifndef CARDS_H
#define CARDS_H


#include <iostream>

#include "utility.h"

using namespace std;


class Cards {

public:
  Cards();                   // constructor
  ~Cards();                  // destructor
  bool insert(oneCard sourceCard);     // insert value; return false if duplicate
  //void printPreOrder() const; // prints tree data pre-order to cout

  struct Node {
    oneCard currCard;
    Node *left, *right, * parent;
    // useful constructors:
    Node(int v=0) : currCard(), left(0), right(0), parent(0) { }
    Node(oneCard sourceCard) : currCard(sourceCard.getValue(), sourceCard.getSuit()), left(0), right(0), parent(0) { }
  };

  // just one instance variable (pointer to root node):
  Node *root;

  bool contains(oneCard sourceCard) const;  // true if value is in tree
  void printCard() const;          // prints out the suit and value of a card
  void printCard(Node *n) const;
  void printInOrder() const; 
   

  oneCard getMin() const;
  oneCard getMax() const;
  Node* getNodeFor(oneCard sourceCard, Node* n) const; // IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists

  oneCard getPredecessor(oneCard sourceCard) const;       // returns the predecessor value of the given value or 0 if there is none
  oneCard getSuccessor(oneCard sourceCard) const;         // returns the successor value of the given value or 0 if there is none
  bool remove(oneCard sourceCard);             // deletes the Node containing the given value from the tree


private:

  // recursive utility functions for use by public methods above
  void clear(Node *n); // for destructor
  bool insert(oneCard sourceCard, Node *n); // note overloading names for simplicity
  void printInOrder(Node *n) const;
  int count(Node *n) const;

  // these should be used by getPredecessor and getSuccessor, and ONE of them should be used by remove
  Node* getSuccessorNode(oneCard sourceCard) const;   // returns the Node containing the successor of the given value
  Node* getPredecessorNode(oneCard sourceCard) const; // returns the Node containing the predecessor of the given value
};





#endif
