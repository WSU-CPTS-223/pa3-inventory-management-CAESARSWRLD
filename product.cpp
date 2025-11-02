#include "product.h"
#include "csvReading.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

void product::printLine()const
{
	
	/*ifstream file("amazonData.csv");
	if (!file.is_open())
	{
		cerr << "Failed to open csv file" << endl;
		return;
	}

	string firstLine;
	getline(file, firstLine);
	vector<string> firstLineVec;
	string token;
	stringstream s(firstLine);
	while (getline(s, token, ','))
	{
		firstLineVec.push_back(token);
	}*/
	




	
    for (size_t i = 0; i < fieldsVec.size(); ++i)
    {

        cout << i << ": " << fieldsVec.at(i) << endl;
    }
}