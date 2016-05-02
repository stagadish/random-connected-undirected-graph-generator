i. Which parts of your assignment were completed

	All parts are completed and operating as requested.

ii. Any bugs that you have encountered

	One problem. Not a bug per se, but more of an issue I could not resolve with
	the execution time of a random graph with many nodes (1,000,000 and up).

	For some reason, it take ~5min or more to terminate.
	As a comparison, James Kluz's algorithm terminates after ~45 second.
	Couldn't find the source of this bleed.

iii. Complete instructions of how to run your program(s).

	0) make all 	to compile all sections.

	1) make testGraph ARGS="<GRAPH_INPUT> <GRAPH_QUERY>" 	to run part I of the assignment.

		e.g. make testGraph ARGS="Graph1.txt AdjacencyQueries1.txt" to build a graph
		with Graph1.txt as an input, and query it using AdjacencyQueries1.txt.

	2) make findPath ARGS="<GRAPH_INPUT> <ORIGIN_VERTEX>" 	to run part II of the assignment.

		e.g. make findPath ARGS="Graph2.txt 1" to build a graph with
		Graph2.txt as an input, and find all the shortest paths from 1
		to the other vertices.

	3) make randomGraph ARGS="<MAXIMUM_NUMBER_OF_VERTICES>" 	to run part III of the assignment.

		e.g. make randomGraph ARGS="1000" to generate a connected, undirected
		and unweighted graph with 1,000 nodes using the union-find data structure.

	4) make clean 	to remove all *.o and executable files.


	NOTE: ARGS' default value is: "Graph1.txt AdjacencyQueries1.txt"

iv. the input file (if any) and the output files (if any).

	Input Files:			Query Files:
		1) Graph1.txt			1) AdjacencyQueries1.txt
		2) Graph2.txt			2) AdjacencyQueries1.txt

	Output Files:
		None.