#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "productMap.h"
#include "testFunctions.h"






class testProduct 
{
public:
   

    std::vector<std::string> fieldsVec;

    testProduct() = default;

    testProduct(const std::vector<std::string>& fieldData) : fieldsVec(fieldData) {}

    
};

inline void testListAllFromACategory()
{
    productMap<std::string, product> table(5);

    table.insert("001", product({ "001", "Legos", "", "", "Toys|Building" }));
    table.insert("002", product({ "002", "Car", "", "", "Toys|Electronics" }));
    table.insert("003", product({ "003", "Vacuum", "", "", "Appliances" }));

    auto capture = [&](const std::string& cat)
        {
        std::ostringstream buf;
        std::streambuf* old = std::cout.rdbuf(buf.rdbuf());
        table.listAllFromCategory(table, cat);
        std::cout.rdbuf(old);
        return buf.str();
        };

    //normal
    std::string out = capture("Toys");
    assert(out.find("001 Legos") != std::string::npos);

    assert(out.find("002 Car") != std::string::npos);


    //normal
    out = capture("Appliances");
    assert(out.find("003 Vacuum") != std::string::npos);

    //edge case
    out = capture("Food");
    assert(out.find("Invalid Category") != std::string::npos);


    std::cout << "testListAllFromCategory passed\n";
}



inline void testInsertThenFind()
{
    productMap<std::string, testProduct> table(5);

    

    std::string word = "1234";
    std::string word2 = "4399";
    std::string word3 = "This one doesnt exist";

    //normal cases
    std::vector<std::string> p1data = { word, "other thing" };
    std::vector<std::string> p2data = { word2, "THIS", "Legos!" };

    testProduct p1(p1data);
    testProduct p2(p2data);

    table.insert(p1.fieldsVec[0], p1);
    table.insert(p2.fieldsVec[0], p2);

   

    testProduct* first = table.findUsingKey(word);
    testProduct* second = table.findUsingKey(word2);
    assert(first != nullptr && first->fieldsVec[1] == "other thing");
    assert(second != nullptr && second->fieldsVec[1] == "THIS");

    //edge cases
    testProduct* third = table.findUsingKey(word3);
    assert(third == nullptr);

    std::cout << "testInsertAndFind passed\n";
}