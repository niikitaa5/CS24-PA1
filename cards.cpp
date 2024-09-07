// cards.cpp
// Nikita Sharma, Anvitha Kosuri
// Implementation of the classes defined in cards.h

#include "cards.h"
#include "utility.h"

#include <iostream>

using namespace std;

// constructor sets up empty tree
Cards::Cards() {
 root = nullptr;
}


// destructor deletes all nodes
Cards::~Cards() {
 clear(root);
}

// recursive helper for destructor
void Cards::clear(Node *n) {
 if (n){
     clear(n->left);
     clear(n->right);
     delete n;
 }
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
Cards::Node* Cards::getNodeFor(oneCard sourceCard, Node* n) const{
 if (n == nullptr)
     return nullptr;
 else if (n->currCard == sourceCard)
     return n;
 else {
     if (n->currCard > sourceCard)
         return(getNodeFor(sourceCard, n->left));
     else
         return(getNodeFor(sourceCard, n->right));
 }
}


// insert value in tree; return false if duplicate
bool Cards::insert(oneCard sourceCard) {
 if (!root) {
     root = new Node(sourceCard);
     return true;
 }
 else
     return (insert(sourceCard, root));
}

// recursive helper for insert (assumes n is never 0)
bool Cards::insert(oneCard sourceCard, Node *n) {
 if (contains(sourceCard) == true)
     return false;
 if (n->currCard > sourceCard) {
     if (n->left != nullptr)
         return(insert(sourceCard, n->left));
     else {
         Node *insertedNode = new Node(sourceCard);
         insertedNode->parent = n;
         n->left = insertedNode;
         return true;
     }
 }
 else if (n->currCard < sourceCard) {
     if (n->right != nullptr)
         return(insert(sourceCard, n->right));
     else {
         Node *insertedNode = new Node(sourceCard);
         insertedNode->parent = n;
         n->right = insertedNode;
         return true;
     }
 }
}

// returns true if value is in the tree; false if not
bool Cards::contains(oneCard sourceCard) const {
 if (getNodeFor(sourceCard, root))
     return true;
 return false;
}




//prints out the suit and value of root
void Cards::printCard() const {
 printCard(root);
}

//prints out the suit and value of root
void Cards::printCard(Node *n) const {
 char cardValue = 0;
 if (n->currCard.getValue() == 1)
     cardValue = 'a';
 else if (n->currCard.getValue() == 11)
     cardValue = 'j';
 else if (n->currCard.getValue() == 12)
     cardValue = 'q';
 else if (n->currCard.getValue() == 13)
     cardValue = 'k';
 if (cardValue == 0)
     cout << n->currCard.getSuit() << " " << n->currCard.getValue() << endl;
 else
     cout << n->currCard.getSuit() << " " << cardValue << endl;
}

void Cards::printInOrder() const {
 printInOrder(root);
}

void Cards::printInOrder(Node *n) const {
 if(n == nullptr)
     return;
 printInOrder(n->left);
 printCard(n);
 printInOrder(n->right);
}


oneCard Cards::getMin() const {
   Node *n = root;
   if (n == nullptr)
       return oneCard();
   else if (n->left == nullptr)
       return n->currCard;
   else {
       while (n->left)
           n = n->left;
       return n->currCard;
   }
}
 oneCard Cards::getMax() const {
   Node *n = root;
   if (n == nullptr) {
       return oneCard();
   }
   else if (n->right == nullptr)
       return n->currCard;
   else {
       while (n->right)
           n = n->right;
       return n->currCard;
   }
}


// returns the Node containing the predecessor of the given value
Cards::Node* Cards::getPredecessorNode(oneCard sourceCard) const{
 Node *n = getNodeFor(sourceCard, root);
 if (n == nullptr)
     return nullptr;
 else if (n->left == nullptr) {
     //cout << "a1" << endl;
     //printCard(n);
     if (n->parent == nullptr) 
        return nullptr;
     while (n->parent) {
         //cout << "a3" << endl;
         if (n->currCard > n->parent->currCard)
             return n->parent;
         n = n->parent;
         if (n == root) {
             //Node *minPredecessor = new Node(0);
             //return minPredecessor;
             //cout << "a2" << endl;
             return nullptr;
         }
     }
 }
 else {
     n = n->left;                                                                                                 
     while (n->right)
         n = n->right;
     return n;
 }
}


// returns the predecessor value of the given value or 0 if there is none
oneCard Cards::getPredecessor(oneCard sourceCard) const{
 Node *n = getPredecessorNode(sourceCard);
 //cout << "getpredecessor" << endl;
 if (n == nullptr) 
    return oneCard();
 return n->currCard;
}



// returns the Node containing the successor of the given value
Cards::Node* Cards::getSuccessorNode(oneCard sourceCard) const{
 Node *n = getNodeFor(sourceCard, root);
 if (n == nullptr)
     return nullptr;
 else if (n->right == nullptr) {
    if (n->parent == nullptr) 
        return nullptr;
     while (n->parent) {
         if (n->currCard < n->parent->currCard)
             return n->parent;
         n = n->parent;
         if (n == root) {
             //Node *maxSuccessor = new Node(0);
             //return maxSuccessor;
             return nullptr;
         }
     }
 }
 else {
     n = n->right;                                                                                                 
     while (n->left)
         n = n->left;
     return n;
 }
}



// returns the successor value of the given value or 0 if there is none
oneCard Cards::getSuccessor(oneCard sourceCard) const{
  Node *n = getSuccessorNode(sourceCard);
  if (n == nullptr) 
    return oneCard();
  return n->currCard;
 //return (getSuccessorNode(sourceCard)->currCard);
}

bool Cards::remove(oneCard sourceCard){
    if (!getNodeFor(sourceCard, root)) 
        return false;
    Node *n = getNodeFor(sourceCard,root);
    if ((!n->left) && (!n->right)) { //if leaf child: set left or right pointer to null
        if (n->parent) {
            if ((n->currCard) > (n->parent->currCard))
                n->parent->right = nullptr;
            else
                n->parent->left = nullptr;
            delete n; 
        }
        else {   //if node is root
            root = nullptr; 
            delete n;
        }
    }

    else if(n->left && !n->right){ //no right child only left child
        if (n->parent) {
            n->left->parent = n->parent;    
            if (n->parent->left == n)  
               n->parent->left = n->left;  
            else                        
            n->parent->right = n->left;
        }
        else{   //if node is root
            n->left->parent = nullptr;
            root = n->left;
        }
        delete n;
    }
   
    else if ((!n->left) && (n->right)){ //no left child only right child
        if (n->parent) {
            n->right->parent = n->parent;  
            if(n->parent->left == n)     
                n->parent->left = n->right; 
            else                        
                n->parent->right = n->right;
        }
        else {   //if node is root
            n->right->parent = nullptr; 
            root = n->right;
        }
        delete n;
    }

    else if(n->left && n->right){ //node has two children
        Node *succNode = getSuccessorNode(sourceCard);
        if (n->right != succNode) {
            Node *temp = nullptr;
            temp = succNode->right;
            succNode->right = n->right;
            succNode->right->parent = succNode;
            succNode->parent->left = temp;
            if(temp)
                temp->parent = succNode->parent;
        }
        succNode->parent = n->parent;
        succNode->left = n->left;
        succNode->left->parent = succNode;
        if(n->parent) {
            if(n->parent->left == n)    
                n->parent->left = succNode;
            else                        
                n->parent->right = succNode;

        }
        else
            root = succNode;
        delete n;
    }
    return true;
}











