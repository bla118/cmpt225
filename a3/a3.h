#include <iostream>
#include <vector>
using namespace std;


int cartesianProduct(int arr[],int n)
{
	int i = 0; 
	int ops = 1; /* initialization of i */

	while(i < n)
	{
		int j = 0;
		ops += 2; /* intialization of j and outer loop comparison */
		while(j < n)
		{
			cout<< "{" << arr[i] << "," << arr[j] << "}";
			j ++;
			cout << "";
			ops += 4; /* above 3 statements and inner loop comparison */
		}
		cout << endl;
		i ++;
		ops += 3; /* above 2 statements and terminating inner while loop comparison */
	}
	ops ++;	/* terminating outer while loop comparison*/
	
	return ops;
}


int triangle(int x)
{
	int i = 0;
	int ops = 1; /* initialization of i */
	while(i < x)
	{
		int j = 0;
		ops += 2; /* outerloop comparison and initialization of j */
		while(j <= i)
		{
			cout << j << "";
			j ++;
			ops += 3; /* above 2 statements and inner while loop comparison */
		}
		cout << endl;
		i ++;
		ops += 3; /* above 2 statements and terminating inner while loop comparison */
	}
	ops += 1; /* terminating outer while loop comparison */
	while(i > 0)
	{
		i--;
		int j = 0;
		ops += 3; /* above 2 statements and outer while loop comparison */
		while(j <= i)
		{
			cout << j << "";
			j ++;
			ops += 3; /* above 2 statements and inner while loop comparison */
		}
		cout << endl;
		ops += 2; /* above statemenet and terminating inner while loop comparison */
	}
	ops += 1; /*terminating outer while loop comparison */

	return ops;
}


vector<int> removeDuplicates(int arr[],int n, int& ops)
{
	vector<int> result;
	int i = 0;
	ops = 2; /* above 2 statements */
	while(i < n)
	{
		int iResult = 0;
		bool duplicate = false;
		ops += 3; /* above 2 statements and outer while loop comparison */
		while(iResult < (int)result.size() && !duplicate)
		{
			// note 4
			ops += 1; /* inner while loop comparison */
			if(arr[i] == result[iResult])
			{
				duplicate = true;
				ops += 2; /* above statement and if statement */
			}
			iResult ++;
			ops += 2; /* above statement and terminating if comparison */
		}
		ops ++; /* terminating inner while loop comparison */
		if(!duplicate)
		{
			result.push_back(arr[i]); //note 4
			ops += 2; /* above statement and if statement */
		}
		i++;
		ops += 2; /* above statement and terminating if statement */
	}
	ops ++;
	/* above statement and terminating outer while loop comparison */
	return result;
}


int rcIndex(int r, int c, int columns)
{
	return r * columns + c;
}


int* matrixSelfMultiply(int* m, int rows, int & ops)
{
	// Create result array
	int columns = rows;
	int* result = new int[rows * columns];

	int r = 0;

	ops = 3; /* above 3 statements */
	while(r < rows)
	{
		int c = 0;
		ops += 2; /* above statement and outer while loop comparison */
		while(c < columns) // columns == rows
		{
			int next = 0;
			int iNext = 0;
			ops += 3; /* above 2 satements and while loop comparison */

			while(iNext < rows)
			{
				next += m[rcIndex(r, iNext, columns)] * m[rcIndex(iNext, c, columns)];
				iNext ++;
				ops += 3; /* above 2 statements and inner while loop comparison. function call to rcIndex() is constant */
			}
			result[rcIndex(r, c, columns)] = next;
			c ++;
			ops += 3 ; /* above 2 statements and terminating inner while loop comparison */
		}
		r ++;
		ops += 2; /* above statement and terminating while loop comparison */
	}
	ops ++; /* terminating outer while loop comparison */	

	return result;
}


int ssort(int arr[], int n, int i)
{
	int ops = 0;
	if(i < n - 1)
	{
		int next = i + 1;
		int smallest = i; 
		ops += 3; /* above 2 statements and if comparison */
		while(next < n)
		{
			ops ++; /* while loop comparison */
			if(arr[next] < arr[smallest])
			{
				smallest = next;
				ops += 2; /* above statement and if comparison */
			}
			next ++;
			ops += 2; /* above statement and if statement comparison where false */
		}
		ops ++; /* terminating while loop comparison */
		int temp = arr[i];
		arr[i] = arr[smallest];
		arr[smallest] = temp;
		ops += 3; /* above 3 statements */
		ops += ssort(arr, n, i + 1);
	}
	ops ++; /* if comparison where false */

	return ops;
}


int pattern(int n , int i)
{
	int ops = 0;
	if(n > 0)
	{
		ops += pattern(n / 2, i);

		cout << string(i, ' ');
		int ast = 0;
		ops += 3; /* for above 2 statements and if comparison */
		while(ast < n)
		{
			cout << "* ";
			ast ++;
			ops += 3; /* above 2 statements and while loop comparison */
		}
		ops ++; /* terminating while loop comparison */
		
		cout << endl;
		i += n;
		ops += 2; /* above 2 statements */
		
		ops += pattern(n / 2, i);

	}
	ops ++; /* if comparison where false */
	return ops;
}