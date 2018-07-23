/*
1. Project Introduction
	This problem simulates process in merging tables
	It is a project to practice creating disjoint sets by tree structure.
	The tree will make use of heuristics such as "union by rank" and "path compression".
	The problem set and starter file is provided by Coursera.
2. Problem Description
	a) Task
		There are ""n"" number of tables.
		These tables can have real data, or symbolic link to one of other tables.
		When two tables with real data are merged, one will have all of real data 
			and the other will have symbolic link to the real data.
		When table with symbolic link is merged, the program will trace links and find real data to merge.
		When table is merged with itself, nothing happens.
		Merging two tables will change table sizes of both, as one will have all the rows
			and the other will have zero row and symbolic link.
		Therefore, the program can biggest size of table and its row size.
	b) Input Format
		The first line of the input contains two integers ""n"" and ""m""
			n: the number of tables in the database 
			m: the number of merge queries to perform, respectively.
		The second line of the input contains number of rows for each table.
		Then follow ""m"" lines describing merge queries. 
			Each of them contains two indices of tables to merge.
	c) Constraints
		1 <= n, m <= 100000
		0 <= number of rows for each table <= 10000
		1 <= indices of tables to merge <= n
	d) Output Format
		Maximum size of table after each query
*/
