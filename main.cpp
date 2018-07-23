#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::vector;

struct DisjointSetsElement {
	int numberOfRows;
	int parent;
	int rank;

	DisjointSetsElement(int rowSize = 0, int newParent = -1, int newRank = 0) :
		numberOfRows(rowSize), parent(newParent), rank(newRank) {}
};

struct DisjointSets {
	int numberOfTables;
	int max_table_size;
	vector <DisjointSetsElement> eachTable;

	// Constructor of tables
	//		Gets number of tables as input
	//		Set each table to have itself as parent
	//		and have 0 row (row size will be set later)
	DisjointSets(int newNumberOfTables) : numberOfTables(newNumberOfTables), max_table_size(0), eachTable(0) 
	{
		int tableIndex = 0;
		for (tableIndex = 0; tableIndex < newNumberOfTables; tableIndex++)
		{
			eachTable[tableIndex].parent = tableIndex;
		}
	}

	int findData(int table) {
		// find parent and compress path
	}

	void mergeTables(int table1, int table2) {
		int data1 = findData(table1);
		int data2 = findData(table2);
		if (data1 != data1) {
			// merge two components
			// use union by rank heuristic
			// update max_table_size
		}
	}
};

int main() 
{
	// Get number of tables and how many times they will be merged
	int numberOfTables, numberOfMerges;
	cin >> numberOfTables >> numberOfMerges;

	DisjointSets tables(numberOfTables);

	// Get rows of eachtable
	for (auto &table : tables.eachTable) 
	{
		cin >> table.numberOfRows;
		tables.max_table_size = max(tables.max_table_size, table.numberOfRows);
	}

	// Get merge queries and merge
	// Display result for each query
	for (int i = 0; i < numberOfMerges; i++) {
		int table1, table2;
		cin >> table1 >> table2;
		--table1;
		--table2;
	
		tables.mergeTables(table1, table2);
		cout << tables.max_table_size << endl;
	}

	return 0;
}
