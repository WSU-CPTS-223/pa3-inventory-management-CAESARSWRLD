#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <sstream>

class product
{
private:
    std::vector<std::string> fieldsVec;
   

public:

   

    
    product() = default;

    product(const std::vector<std::string>& fieldData) : fieldsVec(fieldData) {}


    const std::string& getField(size_t index)const
    {
        if (index >= fieldsVec.size())
        {
            static const std::string empty = "";
            return empty;
        }

        return fieldsVec[index];
    }

    
    void setField(size_t index, const std::string& newValue)
    {
        if (index < fieldsVec.size())
        {
            fieldsVec[index] = newValue;
        }
    }

    
    

    
    

    
    void printLine() const;

};

#endif