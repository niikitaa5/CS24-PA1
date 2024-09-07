// utility.h
// Nikita Sharma, Anvitha Kosuri
// All class declarations go here


#ifndef UTILITY_H
#define UTILITY_H


#include <iostream>


using namespace std;


class oneCard {
   public:
       oneCard();
       oneCard(int num, string sign);
       oneCard(string royal, string sign);


       int getValue() const;
       string getSuit() const;
       int suitNum();
       oneCard& operator=(oneCard const& source);


       bool operator<(const oneCard& source); //overloading <
       bool operator>(const oneCard& source); //overloading >
       bool operator==(const oneCard& source) const; //overloading ==


   private:
       int value;
       string suit;
};


#endif