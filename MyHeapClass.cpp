
// CS110C
// Joakim Dahl
// Assignment 11
// MyHeapClass
// File 2 of 2

#ifndef MY_HEAP_CLASS
#define MY_HEAP_CLASS

#include <string>
#include <iostream>

using namespace std;

const int DEFAULT_CAPACITY = 100;

class MyHeapClass
{
   private:
      int heapSize;
      string* arrayHeap;
   public:
      MyHeapClass();
      virtual ~MyHeapClass();
      bool add(string newPatient);
      bool remove();
      string peekTop();
};

#endif

void swap(string& patient1, string& patient2)
{
   string temp;
   temp = patient1;
   patient1 = patient2;
   patient2 = temp;
}

int leftChildIndex(int i)
{
   return (2 * i) + 1;
}

int rightChildIndex(int i)
{
   return (2 * i) + 2;
}

void heapRebuild(int rootIndex, string array[], int arraySize)
{
   if(leftChildIndex(rootIndex) <= arraySize)
   {
      int largerChildIndex = leftChildIndex(rootIndex);
      if(rightChildIndex(rootIndex) <= arraySize)
      {
         int rightChild = rightChildIndex(rootIndex);
         if(array[rightChild] > array[largerChildIndex])
            largerChildIndex = rightChild;
      }
      if(array[rootIndex] < array[largerChildIndex])
      {
         swap(array[rootIndex], array[largerChildIndex]);
         heapRebuild(largerChildIndex, array, arraySize);
      }
   }
}

MyHeapClass::MyHeapClass() : heapSize(0)
{
   arrayHeap = new string[DEFAULT_CAPACITY];
}

MyHeapClass::~MyHeapClass()
{
   delete[] arrayHeap;
}

string MyHeapClass::peekTop()
{
   return arrayHeap[0];
}

bool MyHeapClass::add(string newPatient)
{
   if(heapSize == DEFAULT_CAPACITY)
      return 0;
   
   arrayHeap[heapSize] = newPatient;

   int newPatientIndex = heapSize;
   bool inPlace = 0;
   while(newPatientIndex > 0 && !inPlace)
   {
      int parentIndex = (newPatientIndex - 1) / 2;
      if(arrayHeap[newPatientIndex] < arrayHeap[parentIndex])
         inPlace = 1;
      else
      {
         swap(arrayHeap[newPatientIndex], arrayHeap[parentIndex]);
         newPatientIndex = parentIndex;
      }
   }
   heapSize++;
   return 1;
}

bool MyHeapClass::remove()
{
   if(heapSize <= 0)
      return 0;
   else if(heapSize == 1)
   {
      heapSize--;
   }
   else
   {
      arrayHeap[0] = arrayHeap[heapSize-1];
      heapSize--;
      heapRebuild(0, arrayHeap, heapSize);
   }
   return 1;
}
