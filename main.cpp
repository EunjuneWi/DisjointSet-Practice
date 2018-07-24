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
	int maxTableSize;
	vector <DisjointSetsElement> eachTable;

	// Constructor of tables
	//		Gets number of tables as input
	//		Set each table to have itself as parent
	//		and have 0 row (row size will be set later)
	DisjointSets(int newNumberOfTables) : numberOfTables(newNumberOfTables), maxTableSize(0), eachTable(newNumberOfTables)
	{
		int tableIndex = 0;
		for (tableIndex = 0; tableIndex < newNumberOfTables; tableIndex++)
		{
			eachTable[tableIndex].parent = tableIndex;
		}
	}

	// +++++ TODO +++++
	// find parent and compress path
	int findData(int tableIndex) 
	{
		//		Traverse edge until it reaches root
		//		Root's parent is itself
		int nodeIndex = tableIndex;

		while (eachTable.at(nodeIndex).parent != nodeIndex)
		{
			// While it is traversing, if its parent is not root
			// Change it to the root.
			eachTable.at(nodeIndex).parent = findData(eachTable.at(nodeIndex).parent);
			nodeIndex = eachTable.at(nodeIndex).parent;
		}

		return nodeIndex;
	}

	// +++++ TODO +++++
	// merge two components
	// use union by rank heuristic
	// update max_table_size
	void mergeTables(int tableIndex1, int tableIndex2) 
	{
		int dataIndex1 = findData(tableIndex1);
		int dataIndex2 = findData(tableIndex2);

		// If tables are not merged (when they don't have same root in the tree)
		// Merge
		if (dataIndex1 != dataIndex2) 
		{
			// Find where to merge
			int rank1 = eachTable.at(dataIndex1).rank;
			int rank2 = eachTable.at(dataIndex2).rank;

			// When table2 goes under table1
			if (rank1 > rank2)
			{
				// Change parent of table2 to table1
				eachTable.at(dataIndex2).parent = dataIndex1;

				// Change rows
				eachTable.at(dataIndex1).numberOfRows += eachTable.at(dataIndex2).numberOfRows;
				eachTable.at(dataIndex2).numberOfRows = 0;

				// Change maximum table size
				if (eachTable.at(dataIndex1).numberOfRows > this->maxTableSize)
				{
					this->maxTableSize = eachTable.at(dataIndex1).numberOfRows;
				}
			}
			else
			{
				// Change parent of table1 to table2
				eachTable.at(dataIndex1).parent = dataIndex2;
				
				// Change rank if both table has same rank
				if (rank1 == rank2)
				{
					++(eachTable.at(dataIndex2).rank);
				}

				// Change rows
				eachTable.at(dataIndex2).numberOfRows += eachTable.at(dataIndex1).numberOfRows;
				eachTable.at(dataIndex1).numberOfRows = 0;

				// Change maximum table size
				if (eachTable.at(dataIndex2).numberOfRows > this->maxTableSize)
				{
					this->maxTableSize = eachTable.at(dataIndex2).numberOfRows;
				}
				
			}
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
		tables.maxTableSize = max(tables.maxTableSize, table.numberOfRows);
	}

	// Get merge queries and merge
	// Display result for each query
	for (int i = 0; i < numberOfMerges; i++) {
		int table1, table2;
		cin >> table1 >> table2;
		--table1;
		--table2;
	
		tables.mergeTables(table1, table2);
		cout << tables.maxTableSize << endl;
	}

	return 0;
}
