#include <iostream>
#include <string>
#include "HashTable.h"
#define DEFAULT_SIZE 101
#define DEFAULT_LOADFACTOR 0.67

using namespace std;

/* default constructor - creates new array of size 101 and sets all values to an empty string */
HashTable::HashTable()
{
	HTsize = DEFAULT_SIZE;
	arr = new string[HTsize];
	primeValue = smallestPrime(HTsize / 2);
	currentSize = 0;
	for(int i = 0; i < HTsize; i ++)
		arr[i] = "";
}

/* constructor to store n items, which will have an underlying array size of the smallest prime greater or equal to 2 * n */
HashTable::HashTable(int n)
{
	HTsize = smallestPrime(2*n);
	primeValue = smallestPrime(HTsize / 2);
	
	arr = new string[HTsize];
	currentSize = 0;
	for(int i = 0; i < HTsize; i ++)
		arr[i] = "";
}

HashTable::~HashTable()
{
	delete[] arr; 
}

/* gets an integer and checks if n is a prime, if it isn't, it will check the values greater than n */
int HashTable::smallestPrime(int n)
{
	int ret = n;
	bool cont = true;
	while(cont)
	{	
		int j = 0; /* counter for if j is only divisible by 1 and 2 */
		for(int i = 1; i <= ret; i ++)
		{
			if(ret % i == 0)
				j ++;
		}
		/* exit while loop if only divisible by 2 numbers (1 and 2) */
		if(j == 2)
			cont = false;
		
		else
			ret ++;
	}
	primeValue = ret;
	return ret;
}
/* method to copy a hashtable */
HashTable::HashTable(const HashTable & HTcpy)
{
	/* call helper function */
	copyArray(HTcpy);
}

void HashTable::copyArray(const HashTable & HTcpy)
{
	/* set size to parameter's HT size and current size */
	HTsize = HTcpy.HTsize;
	currentSize = HTcpy.currentSize;
	/* create new array of new size */
	arr = new string[HTsize];

	/* copy elements */
	for(int i = 0; i < HTsize; i ++)
		arr[i] = HTcpy.arr[i];
}

HashTable& HashTable::operator=(const HashTable& HTcpy)
{
	/* parameter array is not the same as calling, delete and copy paramater's array */
	if(this != &HTcpy)
	{
		delete[] arr;
		copyArray(HTcpy);
	}

	return *this;
}

/* finds if string is in expected index, if not, use double hashing to check next index */
bool HashTable::find(string str) 
{
	/* first find where the string should be using hash1 */
	int index = hash1(str, h2);
	/* keep searching unless the array is empty, then the string is not in array */
	while(arr[index] != "")
	{
		/* used to circle back */
		if(index >= HTsize)
		{
			index -= HTsize;
		}
		if(arr[index] == str)
		{
			return true;
		}
		/* double hashing to check next index */
		else
		{
			index += h2;
		}
	}
	return false;
}

int HashTable::size() const
{
	return currentSize;
}

int HashTable::maxSize() const
{
	return HTsize;
}

float HashTable::loadFactor() const
{
	return ((1.0 * currentSize) / HTsize);
}

void HashTable::insert(string str)
{
	/* searches through array and return if matching string is found */
	if(find(str) == 1)
		return;

	/* get first index from hash1 function, as well as setting h2 to the correct value to calculate if collision occurs */
	int position = hash1(str, h2);
	if(arr[position] == "")
	{
		arr[position] = str;
	}
	/* while loop to find empty index using the value h2 from hash1 function */
	else
	{
		bool empty = true;
		
		position += h2;
		while(empty)
		{
			if(position >= HTsize)
			{
				position -= HTsize;
			}
			if(arr[position] == "")
			{
				arr[position] = str;
				empty = false;
			}
			else
			{
				position += h2;
			}
		} 
	}
	currentSize ++;
	
	/* if current size is almost equal to array size, create new array */
	if(loadFactor() > DEFAULT_LOADFACTOR)
	{
		int tempSize = smallestPrime(2 * HTsize);
		primeValue = smallestPrime(tempSize / 2);
		/* used for the for loop comparison */
		int arrHTsize = HTsize;
		
		string* temp = new string[tempSize];

		/* loop to put non empty strings to new temp array */
		for(int i = 0; i < arrHTsize; i ++)
		{
			if(arr[i] != "")
			{
				/* put string in appropriate index using hash1 function */
				int h1Index = hash1(arr[i], h2);

				/* if index is empty, store string there */
				if(temp[h1Index] == "")
				{
					temp[h1Index] = arr[i];
				}
				/* otherwise using double hashing */
				else
				{
					bool collision = true;
					
					h1Index += h2;
					/* while loop to keep adding h2 to index until empty spot is found */
					while(collision)
					{
						if(h1Index >= tempSize)
						{
							h1Index -= tempSize;
						}
						if(temp[h1Index] == "")
						{
							temp[h1Index] = arr[i];
							collision = false;
						}
						else
						{
							h1Index += h2;
						}
					}
				}
			}
		}
		/* assign HashTable size to new size */
		HTsize = tempSize;
		arr = temp;
	}
	
}


/* gets a string as parameter and converts it into an integer value using horner's method */
int HashTable::hash1(string str, int &h2) 
{
	/* set h2 to first letter value */
	h2 = str[0] - 96;
	int result = str[0] - 96;
	for(int i = 1; i < str.length(); i ++)
	{
		h2 = (h2 * 32) + (str[i] - 96);
		result = ((result * 32) + (str[i] - 96)) % HTsize;
	}
	/* h2 to store value in case of collision */
	int temp = primeValue - (h2 % primeValue);
	h2 = temp;
	return result;
}

void HashTable::print() const
{
	for(int i = 0; i < HTsize; i ++)
		cout << arr[i] << " ";
	cout << endl;
}


/* returns the string at position i */
string HashTable::getStr(int i) const
{
	return arr[i];
}