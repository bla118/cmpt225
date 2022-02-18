#include <iostream>
#include <string>
#include "StringSet.h"

StringSet::StringSet()
{
  // initialize arraySize and currentSize of array and create array of size 2
  arraySize = 2;
  currentSize = 0;
  arr = new string[arraySize];
}

StringSet::StringSet(const StringSet & sSet)
{
  // call copy function
  copyStringSet(sSet);
}


StringSet::~StringSet()
{
  delete[] arr;
}

void StringSet::copyStringSet(const StringSet & sSet)
{
  arraySize = sSet.arraySize;
  currentSize = sSet.currentSize;
  // make a new array
  arr = new string[arraySize];
  // copy elements in original array
  for(int i = 0; i < currentSize; i ++)
  {
    arr[i] = sSet.arr[i];
  }
}

StringSet& StringSet::operator=(const StringSet & sSet)
{
  /* delete arr and copy if calling object's address != parameter object's address */
  if(this != &sSet)
  {
    delete[] arr;
    copyStringSet(sSet);
  }
  // if it's the same, return the dereferenced string
  return *this;
}

bool StringSet::insert(string str)
{
  // compare enteredString with strings in array
  // return false if enteredString matches string in array
  for(int i = 0; i < currentSize; i ++)
  {
    if(arr[i] == str)
    {
      return false;
    }
  }
  // double array size if full
  if(currentSize == arraySize)
  {
    arraySize = arraySize * 2;
    // create temp array
    string* temp = new string[arraySize];
    // copy content into temp array
    for(int i = 0; i < currentSize; i ++)
    {
      temp[i] = arr[i];
    }

    delete[] arr;
    // set arr to temp
    arr = temp;

  }
  // add string into array and increment currentSize
  arr[currentSize++] = str;

  return true;
}

bool StringSet::remove(string str)
{
  int index;
  for(int i = 0; i < currentSize; i ++)
  {
    // if found, set index
    if(arr[i] == str)
    {
      index = i;

      /*if matching string is the last in the array, then just return true */
      if((index + 1) == currentSize)
      {
        currentSize--;
        return true;
      }
      else
      {
        arr[index] = arr[currentSize - 1];
        currentSize--;
        return true;
      }
    }
  }
  return false;
}

int StringSet::find(string findstr) const
{
  // go through each string in array
  for(int i = 0; i < currentSize; i ++)
  {
    // return index if found
    if(arr[i] == findstr)
    {
      return i;
    }
  }
  return -1;
}

int StringSet::size() const
{
  return currentSize;
}

void StringSet::getSet()
{
  for(int i = 0; i < currentSize; i ++)
    cout << arr[i] << " ";
  cout << endl;
}


StringSet StringSet::unions(const StringSet & sSet) const
{
  // get current size of calling object and parameter
  int lengthsSet = sSet.currentSize;
  int lengthThis = currentSize;
  StringSet unionSet;
  /* using insert method and its 'check for duplicates before inserting' case to returns StringSet object */
  for(int i = 0; i < lengthThis; i ++)
    unionSet.insert(arr[i]);

  for(int j = 0; j < lengthsSet; j ++)
    unionSet.insert(sSet.arr[j]);

  return unionSet;
}

StringSet StringSet::intersection(const StringSet &set) const
{
  // get current sizes
  int lengthSet = set.currentSize;
  int lengthThis = currentSize;
  StringSet tempSet;
  StringSet interSet;
  // insert contents into tempSet for comparing
  for(int i = 0; i < lengthThis; i ++)
  {
    tempSet.insert(arr[i]);
  }
  for(int j = 0; j < lengthSet; j ++)
  {
    /* if inserting string into tempSet returns false, as in there is a duplicate in tempSet, insert into returning object */
    if(!tempSet.insert(set.arr[j]))
      interSet.insert(set.arr[j]);
  }

  return interSet;
}

StringSet StringSet::difference(const StringSet &set) const
{
  // size of calling object and parameter
  int lengthSet = set.currentSize;
  int lengthThis = currentSize;
  // create two objects of StringSet
  StringSet tempSet;
  StringSet diffSet;
  // insert contents into tempSet for comparing
  for(int i = 0; i < lengthSet; i ++)
  {
    tempSet.insert(set.arr[i]);
  }
  for(int j = 0; j < lengthThis; j ++)
  {
    /* using find method
    if the string is not found in tempSet, then insert into the object that will be returned*/
    if(tempSet.find(arr[j]) == -1)
      diffSet.insert(arr[j]);

  }

  return diffSet;
}
