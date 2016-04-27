//
//  TestRandomGraph.cpp
//  union-find-graph-generator-xcode
//
//  Created by Gil Dekel on 4/27/16.
//  Copyright © 2016 Gil Dekel. All rights reserved.
//


#include "UndirectedGraph.cpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>


int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << "||||| Should be: <MAXIMUM_NUMBER_OF_NODES>" << std::endl;
        return 0;
    }
    std::cout << "The maximus number of nodes is " << argv[1] << std::endl;
    
    
    // Try to translate STARTING_VERTEX to int in order to queue dijkstra's algorithm.
    try {
        size_t num_of_nodes = std::stoi(argv[1]);
        const int max_val = 1000;
        UndirectedGraph<int> testGraph;
        
        srand(time(0)); //use current time as seed for random generator
        while (num_of_nodes > 0) {
            if (testGraph.AddVertex(rand() % max_val + 1)) {
                --num_of_nodes;
            }
        }
        
        testGraph.printGraph();
        
    } catch (std::invalid_argument) {
        std::cout << "Invalid argument for MAXIMUM_NUMBER_OF_NODES::::TERMINATING PROGRAM\n";
        exit(1);
    }
    
    
    return 0;
}

