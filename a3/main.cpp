#include"a3.h"
void basicTest();
int main()
{
	basicTest();
	cout << endl;
	return 0;
}
void basicTest()
{
	int cost = 0;
	int n = 0;
	cout << "CARTESIANPRODUCT" << endl;
	int arr1[] = {1,2,3,4};
	n = 4;
	cost = cartesianProduct(arr1, n);
	cout << "#operation = " << cost << endl;
	cout << "------------------------" << endl << endl;
	cout << "TRIANGLE" << endl;
	n = 7;
	cost = triangle(7);
	cout << "#operation = " << cost << endl;
	cout << "------------------------" << endl << endl;
	cout << "REMOVEDUPLICATES" << endl;
	int arr2[] = {1,1,1,1,1,1,1,1,1,1,1};
	cost = 0;
	n = 10;
	vector<int> v = removeDuplicates(arr2, n, cost);
	cout << "#operation = " << cost << endl;
	cout << "------------------------" << endl << endl;
	cout << "MATRIXSELFMULTIPLY" << endl;
	int arr3[] = {1,2,3,4,5,6,7,8,9};
	cost = 0;
	n = 3;
	
	int* result = matrixSelfMultiply(arr3, n, cost);
	delete[] result;
	cout << "#operation = " << cost << endl;
	cout << "------------------------" << endl << endl;
	
	cout << "SELECTION SORT" << endl;
	int arr4[] = {1,2,3,4,5,6};
	n = 6;
	cost = ssort(arr4, n, 0);
	cout << "#operation = " <<cost << endl;
	cout << "------------------------" << endl <<endl;

	cout << "PATTERN"<< endl;
	n = 7;
	cost = pattern(n, 0);
	cout << "#operation = "<< cost << endl;
	cout << "------------------------" << endl << endl;
	
}


