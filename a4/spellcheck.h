#pragma once
#include <vector>
#include <algorithm>
#include "HashTable.h"

using namespace std;

 
vector<string> extraLetter(const HashTable & ht, string word)
{
	vector<string> result;
	HashTable t = ht;
	/* if word is found, return word */
	if(t.find(word) == 1)
	{
		result.push_back(word);
		return result;
	}
	vector<string> closeWords;
	int length = word.length();
	/* counter for every incorrect corresponding position of letters */
	int counter;
	int j;
	int h;
	/* go through hashtable */
	for(int i = 0; i < ht.maxSize(); i ++)
	{
		string temp = ht.getStr(i);
		/* do the following if length of string in hashtable is 1 less than word's length */
		if(temp.length() == length - 1)
		{
			counter = 0;
			j = 0;
			h = 0;
			while(counter <= 1 && j < temp.length() && h < length)
			{
				/* go to next index if letters are in corresponding indices */
				if(temp[j] == word[h])
				{
					j ++;
					h ++;
				}
				/* if letter is found 1 index after, increment count and the indices correspondingly
				ex. abcd compare with eabcd, compares a and a, which increments count and next to compare 
				should be b from first string and b from second, therefore add 2 to index for second string */

				else if(temp[j] == word[h + 1])
				{
					counter ++;
					j ++;
					h += 2;
				}
				/* similar to above */
				else if(temp[j + 1] == word[h])
				{
					counter ++;
					j += 2;
					h ++;
				}
				else
				{
					counter ++;
				}
			}
			/* add to vector if string is found */
			if(counter <= 1)
			{
				closeWords.push_back(temp);
			}
		}
	}	
	return closeWords;
}

vector<string> transposition(const HashTable & ht, string word) 
{
	vector<string> result;
	HashTable t = ht;
	/* first check if word is in hashtable */
	if(t.find(word) == 1)
	{
		result.push_back(word);
		return result;
	}
	int length = word.length();
	/* check the words that have same length as 'word' */
	for(int i = 0; i < ht.maxSize(); i ++)
	{
		string temp = ht.getStr(i);
		if(temp.length() == length)
		{
			for(int j = 0; j < length; j ++)
			{
				/* swap neighboring letters and compare */
				string compare = word;
				char letter = compare[j];
				compare[j] = compare[j + 1];
				compare[j + 1] = letter;
				if(compare == temp)
				{
					/* if word is found in HashTable after swapping letters, add to vector result */
					result.push_back(temp);
					goto outer; /* exit inner for loop */
				}
			}
		}
		outer:;
	}

	return result;

}

vector<string> missingSpace(const HashTable & ht, string word) 
{
	/* return word using find function if found */
	vector<string> result;
	HashTable t = ht;
	if(t.find(word) == 1)
	{
		result.push_back(word);
		return result;
	}
	/* sort hashtable using vector */
	vector<string> temp;
	for(int i = 0; i < ht.maxSize(); i ++)
	{
		temp.push_back(ht.getStr(i));
	}
	std::sort(temp.begin(), temp.begin() + ht.maxSize());


	/* create vector to return words */
	vector<string> mSpace;
	
	int wordLength = word.length();
	int i = 0;
	int length;
	/* while loop to traverse through array */
	while(i < temp.size())
	{
		/* do the following if first letter in vector is equal to first letter of word */
		if(temp[i][0] == word[0])
		{
			string s1(temp[i]);
			/* if first string in vector is found in word parameter, do the following below */
			if(word.find(s1) != string::npos)
			{
				/* get length of first string to use when comparing length of the strings and word */
				length = s1.length();
				
				/* find another string in vector that is found in word */
				for(int j = 0; j < temp.size(); j ++)
				{
					string s2(temp[j]);
					if((s1 != s2) && (word.find(s2) != string::npos))
					{
						/* add to strings' length */
						length += s2.length();

						/* if the strings' length = word's length, append the two strings with a space and push onto vector */
						if(length == wordLength)
						{
							s1.append(" ");
							s1.append(s2);
							mSpace.push_back(s1);
						}
					}
				}
			}
		}
		/* control variable for traversing through vector */
		i ++;
	}
	return mSpace;
	
}

vector<string> missingLetter(const HashTable & ht, string word)
{
	/* if word is found in hashtable, return word */
	vector<string> result;
	HashTable t = ht;
	if(t.find(word) == 1)
	{
		result.push_back(word);
		return result;
	}

	/* otherwise, create a vector to return words */
	vector<string> words;
	
	int j;
	int h;
	int counter;
	
	/* go through hashtable */
	for(int i = 0; i < ht.maxSize(); i ++)
	{	

		string temp = ht.getStr(i);
		/* do the following if string's length in hashtable is 1 less than word's */
		if(word.length() == temp.length() - 1)
		{
			j = 0;
			h = 0;
			/* a counter for same letter in different indices */
			counter = 0;

			/* do the following until indices starting from 0 reach length of either strings or if counter >= 2*/
			while((counter <= 1) && (j < temp.length()) && (h < word.length()))
			{
				/* check if 1st letter of both strings are in right place */
				if(temp[j] == word[h])
				{
					j ++;
					h ++;
				}
				/* or if the letter from string or word can be found in the next index of other string, compare next letters and increment counter */
				else if(temp[j + 1] == word[h] || temp[j] == word[h + 1])
				{
					j ++;
					h ++;
					counter ++;
				}
				/* if letter is not found in corresponding indices, break the loop */
				else
				{
					counter ++;
				}

			}
			/* insert into vector if word can be made by adding 1 letter anywhere in word */
			if(counter < 2)
			{
				words.push_back(temp);
			}
		}
	}
	return words;
}


vector<string> incorrectLetter(const HashTable & ht, string word)
{
	vector<string> result;
	HashTable t = ht;
	if(t.find(word) == 1)
	{
		result.push_back(word);
		return result;
	}

	int j;
	int h;
	int counter;

	vector<string> incLetter;
	/* go through elements in hashtable */
	for(int i = 0; i < ht.maxSize(); i ++)
	{
		string temp = ht.getStr(i);
		/* do the following if the lengths of the strings are the same */
		if(temp.length() == word.length())
		{
			j = 0;
			h = 0;
			/* counter for every incorrect position of letter */
			counter = 0;
			while(counter <= 1 && j < temp.length() && i < word.length())
			{
				/* check each letters to make sure they are in the corresponding position as the other string
				if letters are the same at the same index, increment the indices. otherwise increment counter as well */
				if(temp[j] == word[h])
				{
					j ++;
					h ++;
				}
				else
				{
					j ++;
					h ++;
					counter ++;
				}
			}
			/* add to vector if string is found */
			if(counter <= 1)
			{
				incLetter.push_back(temp);
			}
		}
	}
	return incLetter;
}