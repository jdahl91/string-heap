
// CS110C
// Joakim Dahl
// Assignment 11
// main
// File 1 of 2

#include <string>
#include <iostream>
#include "MyHeapClass.cpp"

using namespace std;

int main()
{
   MyHeapClass* ER = new MyHeapClass();

   ER->add("5 Bob");
   ER->add("9 Mary");
   ER->add("1 Max");

   cout << ER->peekTop() << " will now see the doctor. (Should be 9 Mary)\n";

   ER->remove();
   ER->add("3 Julio");
   ER->add("7 Stacy");
   ER->add("4 Paul");
   ER->add("2 Reiko");
   ER->add("6 Jennifer");
   ER->add("5 Chang");

   cout << ER->peekTop() << " will now see the doctor. (Should be 7 Stacy)\n";
   ER->remove();
   cout << ER->peekTop() << " will now see the doctor. (Should be 6 Jennifer)\n";
   ER->remove();

   cout << ER->peekTop() << " will now see the doctor. (Should be 5 Chang or 5 Bob)\n";
   ER->remove();
   
   delete ER;

   return 0;
}

/*
*************
SAMPLE OUTPUT
*************
[jdahl3@hills ~]$ g++ assignment11.cpp && ./a.out
9 Mary will now see the doctor. (Should be 9 Mary)
7 Stacy will now see the doctor. (Should be 7 Stacy)
6 Jennifer will now see the doctor. (Should be 6 Jennifer)
5 Chang will now see the doctor. (Should be 5 Chang or 5 Bob)
*/