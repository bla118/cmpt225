#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <stdexcept>

using namespace std;
vector<string>readFile(string infile)
	{
		ifstream ist(infile.c_str());
		if(ist.fail())
			throw runtime_error(infile+"notfound");
		istream_iterator<string>start(ist),end;
		vector<string>result(start,end);
		ist.close();
		return result;
	} 