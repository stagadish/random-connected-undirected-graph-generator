//
//  TestRandomGraph.cpp
//  union-find-graph-generator-xcode
//
//  Created by Gil Dekel on 4/27/16.
//  Copyright © 2016 Gil Dekel. All rights reserved.
//


#include "UndirectedGraph.hpp"
#include "DisjointSet.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>


int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << "||||| Should be: <MAXIMUM_NUMBER_OF_VERTICES>" << std::endl;
        return 0;
    }
    std::cout << "The maximus number of vertices is " << argv[1] << std::endl;
    
    
    // Try to translate MAXIMUM_NUMBER_OF_VERTICES
    // to size_t in order to determine the number of vertices.
    try {
        long num_of_nodes = std::stoi(argv[1]);
        if (num_of_nodes < 0) {
            std::cout << "Invalid argument for MAXIMUM_NUMBER_OF_NODES::Must be a positive integer!::TERMINATING PROGRAM\n";
            exit(1);
        }
        
        const size_t max_val = num_of_nodes;
        UndirectedGraph<size_t> testGraph;
        DisjointSet<size_t> testDS;
        
        size_t counter = 1;
        while (counter <= num_of_nodes) {
            testGraph.AddVertex(counter);
            testDS.AddNewNode(counter);
            ++counter;
        }
        
        std::cout << "Made the graph! WOOT!\n";

        srand(time(0)); //use current time as seed for random generator
        while (testDS.Size() > 1) {
            int i1 = rand() % max_val + 1;
            int i2 = rand() % max_val + 1;
            if (testGraph.AddEdge(i1, i2)) {
                testDS.Union(i1, i2);
            }
        }
        
//        testGraph.printGraph();
        testGraph.PrintGraphStats();
        
    } catch (std::invalid_argument) {
        std::cout << "Invalid argument for MAXIMUM_NUMBER_OF_NODES::Must be a positive integer::TERMINATING PROGRAM\n";
        exit(1);
    }
    
    
    return 0;
}

