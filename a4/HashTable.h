#pragma once
#include <iostream>
#include <string>

using namespace std;


class HashTable
{
public:
	HashTable();
	HashTable(int n);
	HashTable(const HashTable & HTcpy);
	~HashTable();
	HashTable& operator=(const HashTable& HTcpy);
	void insert(string str);
	bool find(string str) ;
	int size() const;
	int maxSize() const;
	float loadFactor() const;
	void print() const;
	
	/* used to spellcheck */
	string getStr(int i) const;

private:
	string* arr;
	int HTsize;
	int h2;
	int currentSize;
	void copyArray(const HashTable & HTcpy);
	int smallestPrime(int n);
	int primeValue;
	int hash1(string str, int &h2);


};

	