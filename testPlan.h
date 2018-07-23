
// Input: number of table / number of merge
//		   row of each table
//		   Merge(m): Where to merge  what to merge

/*
1. Test1
	- Purpose:	Table without symbolic link is merged properly
	- Input
3 2
1 1 1
2 3
1 2
	- Expected output
2
3

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

2. Test2
	- Purpose:	Table with symbolic link is merged properly
	- Input
4 3
1 1 1 1
4 3
2 1
4 2
	- Expected output
2
2
4

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

3. Test3
	- Purpose:	Table with no row is merged properly
	- Input
3 2
0 0 0
3 2
2 1
	- Expected output
0
0

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

4. Test4
	- Purpose:	Merge to itself does not change any result
	- Input
3 3
10 5 2
1 1
2 2
3 3
	- Expected output
10
10
10

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

5. Test5
	- Purpose:
	- Input


*/