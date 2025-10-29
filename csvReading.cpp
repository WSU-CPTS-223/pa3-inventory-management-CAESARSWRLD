#include "csvReading.h"
#include "product.h"
#include "productMap.h"
#include <sstream>
#include <fstream>


using namespace std;

void csvReading::readcsv()
{
	ifstream file(csvFilename);
	if (!file.is_open())
	{
		cerr << "Failed to open csv file" << endl;
		return;
	}

	string line;

	getline(file, line);//skip line

	while (getline(file, line))
	{
		vector<string> forProduct;
		string token;
		stringstream s(line);
		while(getline(s, token, '\,'))
		{
			forProduct.push_back(token);
		}
		product p(forProduct);
		
		//gets the field of index 1 which is the Uniq Id
		productHashTable.insert(p.getField(0), p);
	}
}