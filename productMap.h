#ifndef PRODUCTMAP_H
#define PRODUCTMAP_H

#include <unordered_map>
#include <string>
#include <vector>
#include "product.h"

//hash map for products
template <typename Key, typename Value>
class productMap
{
	private:



		struct bucket
		{
			Key key;
			Value val;

			bucket* nextSpace;//for collisions
		};

		std::vector<bucket*> table;



		size_t tableSize;

		//using std::hash
		size_t hashKeyCreator(const Key& key) const
		{
			return std::hash<Key>{}(key) % tableSize;
		}

	public:

		//has 10005 buckets by default
		productMap(size_t newSize = 10005) : tableSize(newSize), table(newSize, nullptr) {}



		void insert(const Key& key, const Value& value)
		{
			size_t index = hashKeyCreator(key);
			bucket* newNode = new bucket{ key, value, table[index] };
			table[index] = newNode;
		}


		Value* findUsingKey(Key& key)
		{
			size_t i = hashKeyCreator(key);

			bucket* node = table[i];

			while (node)
			{
				if (node->key == key)
				{
					return &node->val;

				}

				node = node->nextSpace;
			}
			return nullptr;
		}


		void printTable()const
		{
			for (auto bucket : table)
			{
				while (bucket)
				{
					std::cout << bucket->key << "\n";

					bucket = bucket->nextSpace;
				}
			}
		}



		void listAllFromCategory(productMap<std::string, product>& table, const std::string& category)
		{

			bool found = false;

			
			for (size_t i = 0; i < table.tableSize; ++i)
			{
				auto* bucketNode = table.table[i];

				while (bucketNode != nullptr)
				{
					product& p = bucketNode->val;
					
					
					for (const auto& categoryToCheck : p.getField(4))
					{
						if (categoryToCheck == category)
						{
							std::cout << p.getField(0) << " " << p.getField(1) << std::endl;
							found = true;
							break;
						}
					}
					bucketNode = bucketNode->nextSpace;
				}
				
			}

			if (!found)
			{
				std::cout << "Invalid Category" << std::endl;
			}
		}

};

#endif