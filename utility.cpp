// utility.cpp
// Author: Your name
// Implementation of the classes defined in utility.h


#include "utility.h"


#include <iostream>
#include <cstring>


using namespace std;




oneCard::oneCard() {
   suit = '\0';
   value = 0;
}
      
oneCard::oneCard(int num, string sign) {
   suit = sign;
   value = num;
}


oneCard::oneCard(string royal, string sign) {
   suit = sign;
   if (royal == "a")
       value = 1;
   else if (royal == "j")
       value = 11;
   else if (royal == "q")
       value = 12;
   else if (royal == "k")
       value = 13;


}




int oneCard::getValue() const {
   return value;
}


string oneCard::getSuit() const {
   return suit;
}


int oneCard::suitNum() {
   int suitNum = 0;
   if (suit.compare("c") == 0)
       suitNum = 1;
   else if (suit.compare("d") == 0)
       suitNum = 2;
   else if (suit.compare("s") == 0)
       suitNum = 3;
   else if (suit.compare("h") == 0)
       suitNum = 4;
   return suitNum;
}


bool oneCard::operator<(const oneCard& source) {
   oneCard c = source;
   if (suitNum() < c.suitNum())
       return true;
   else if (suitNum() > c.suitNum())
       return false;
   else
       if (getValue() < source.getValue())
           return true;
       return false;
}


bool oneCard::operator>(const oneCard& source) {
   oneCard c = source;
   if (suitNum() > c.suitNum())
       return true;
   else if (suitNum() < c.suitNum())
       return false;
   else
       if (getValue() > c.getValue())
           return true;
       return false;
}


bool oneCard::operator==(const oneCard& source) const{
   oneCard c = source;
   return ((value == c.getValue()) && (suit.compare(c.getSuit()) == 0));
}


oneCard& oneCard::operator=(oneCard const& source) {
   if (this != &source) {
       value = source.getValue();
       suit = source.getSuit();
   }
   return *this;
}




// int main() {
//     oneCard c1(5, "H");
//     oneCard c2(5, "s");
//     //cout << c2.getValue() << endl << c1.getValue() << endl << c2.getSuit() << endl << c1.getSuit() << endl;
//     //cout << c2.suitNum() << endl;
//     c1 = c2;
//     cout << c1.getValue() << endl << c1.getSuit() << endl;
// }

