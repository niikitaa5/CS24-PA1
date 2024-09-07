// tests.cpp
// Nikita Sharma, Anvitha Kosuri
 
#include "utility.h"
#include "cards.h"

 int main() {
    Cards cardBST;
    oneCard c1(2, "c");
    oneCard c2(3, "s");
    oneCard c3(5, "d");
    Cards::Node *cardBSTRoot = new Cards::Node(c1);
    oneCard c4;
    c4 = c3;
    oneCard c6(12, "s");
    oneCard c7(1, "c");
    oneCard c5 = c1;
    cardBST.insert(c1);
    cardBST.insert(c2);
    cardBST.insert(c3);

    cardBST.remove(c3);

    cardBST.insert(c4);
    cardBST.insert(c5);
    cardBST.insert(c7);

    cardBST.contains(c5);
    cardBST.contains(c6);

   cardBST.getMin();
   cardBST.getMax();
   cardBST.getPredecessor(c4);
   cardBST.getSuccessor(c6);
   cardBST.printCard();
   cardBST.printCard(cardBSTRoot);
   cardBST.getNodeFor(c6, cardBSTRoot);
   cardBST.printInOrder();

   cardBST.remove(c2);
   cardBST.remove(c5);
   cardBST.remove(c6);
    
   cardBST.printInOrder();


   Cards bstTwo; 

   oneCard c10("k", "s");
   oneCard c11("q", "h");
   oneCard c12("a", "d"); 

Cards::Node *bstPoint = new Cards::Node(c11);

   bstTwo.insert(c10);
   bstTwo.insert(c11);
   bstTwo.insert(c12);
   bstTwo.getNodeFor(c12,bstPoint);
   bstTwo.getMax();
   bstTwo.getMin();
   bstTwo.remove(c11);
   bstTwo.remove(c10);
   bstTwo.remove(c12);
   bstTwo.insert(c1);
   bstTwo.printInOrder();





 }