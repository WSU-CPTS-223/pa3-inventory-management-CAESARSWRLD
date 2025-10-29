#include <iostream>
#include <string>
#include "csvReading.h"

using namespace std;

void printHelp()
{
    cout << "Supported list of commands: " << endl;
    cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
    cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
        << endl;
    cout << " Use :quit to quit the REPL" << endl;
}

bool validCommand(string line)
{
    return (line == ":help") ||
        (line.rfind("find", 0) == 0) ||
        (line.rfind("listInventory") == 0);
}


static productMap<string, product> hashMap;

const std::string& filename = "amazonData.csv";
csvReading c(filename, hashMap);



void evalCommand(string line)
{
    if (line == ":help")
    {
        printHelp();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
        // Look up the appropriate datastructure to find if the inventory exist
        
        string inventoryId = line.substr(5);
        //cout << "ENTERED: " << inventoryId << endl;
        

        if (c.productHashTable.findUsingKey(inventoryId) == nullptr)
        {
            cout << "Inventory not found" << endl;
        }
        else
        {
            c.productHashTable.findUsingKey(inventoryId)->printLine();
        }
    }
    // if line starts with listInventory
    else if (line.rfind("listInventory") == 0)
    {
        // Look up the appropriate datastructure to find all inventory belonging to a specific category
        string inventoryId = line.substr(5);
    }
}

void bootStrap()
{
    cout << "\n Welcome to Amazon Inventory Query System" << endl;
    cout << " enter :quit to exit. or :help to list supported commands." << endl;
    
    // TODO: Do all your bootstrap operations here
    // example: reading from CSV and initializing the data structures
    // Don't dump all code into this single function
    // use proper programming practices




    

    //cout << "Loading data" << endl;

    c.readcsv();

    /*cout << "Done loading data" << endl;

    
    c.productHashTable.printTable();
    */
    cout << "\n> ";
}

int main(int argc, char const* argv[])
{
    

    string line;
    bootStrap();
    while (getline(cin, line) && line != ":quit")
    {
        if (validCommand(line))
        {
            evalCommand(line);
        }
        else
        {
            cout << "Command not supported. Enter :help for list of supported commands" << endl;
        }
        cout << "> ";
    }
    return 0;
}
