#ifndef READCSV_H
#define READCSV_H


#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include "productMap.h"

class csvReading
{
public:
    productMap<std::string, product>& productHashTable;



    std::string csvFilename;

    csvReading(const std::string& newCsvFilename, productMap<std::string, product>& newHashTable)
        : csvFilename(newCsvFilename), productHashTable(newHashTable) {}

    void readcsv();

    //void cmdReaderHelper(std::ifstream& file);  
};

#endif