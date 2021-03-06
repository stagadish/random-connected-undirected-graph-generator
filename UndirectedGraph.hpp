//
//  UndirectedGraph.hpp
//  union-find-graph-generator-xcode
//
//  Created by Gil Dekel on 4/27/16.
//  Last updated by Gil Dekel on 4/29/16.
//  Copyright © 2016 Gil Dekel. All rights reserved.
//

#ifndef _UNDIRECTED_GRAPH_H_
#define _UNDIRECTED_GRAPH_H_

#include <iostream>
#include <unordered_set>
//#include <map>
//#include <set>
#include <unordered_map>

/*
 * This is a simple undirected and unweighted graph implementation.
 *
 * --Assumptions--
 * 1) All vertices are unique (i.e. no duplicates).
 * 2) Objects of type Comparable define operator<
 *    (i.e. it is possible to compare between two objects of type Comparable)
 */

template <typename Comparable>
class UndirectedGraph {
private:
    // A vertex holds its value and an adjacency list to
    // represent edges to its neighbors.
    struct Vertex {
        Comparable val;
        std::unordered_set<Comparable> adj_l;
        
        Vertex(const Comparable &nuVal) : val(nuVal) {}
    };
    
    // The set of vertices searchable by their values.
    std::unordered_map<Comparable, Vertex> vertices_;
    
    // The number of edges in the graph
    // An edge is counted if v1 is connected to v2
    // and v2 is connected to v1.
    size_t numOfEdges_;
    
public:
    // Using default ctors, assignment operators and destructor.
    UndirectedGraph() : numOfEdges_(0) {}
    UndirectedGraph(const UndirectedGraph &rhs) = default;
    UndirectedGraph& operator=(const UndirectedGraph &rhs) = default;
    UndirectedGraph(UndirectedGraph &&rhs) = default;
    UndirectedGraph& operator=(UndirectedGraph &&rhs) = default;
    ~UndirectedGraph() = default;
    
    // Check if a a certain value is in the graph.
    // param val: The Comparable object as a value to search.
    // return: True if the value is already in the graph. False otherwise.
    bool ContainsVertex(const Comparable &val) const;
    
    // Add a new vertex to the graph.
    // param val: the Comparable object as a value to the new vertex.
    // return: True if the vertex was added to the graph. False otherwise.
    bool AddVertex(const Comparable &val);
    
    // Check if an edge exists between two vertices in the graph.
    // param lhs: the 'from' vertex value.
    // param rhs: the 'to' vertex value.
    // return: True if the edge exists between the two vertices. False otherwise.
    bool ContainsEdge(const Comparable &lhs, const Comparable &rhs) const;
    
    // Add a new edge between two vertices in the graph.
    // If successful, lhs-->rhs, and lhs<--rhs after execution.
    // Will increase the number of edges by ONE if the edge was added successfully.
    // Will work only if both vertices are already in the graph.
    // param lhs: the 'from' vertex value.
    // param rhs: the 'to' vertex value.
    // return: True if the edge was added between the two vertices. False otherwise.
    bool AddEdge(const Comparable &lhs, const Comparable &rhs);
    
    // return the size of the graph (i.e. num of vertices)
    size_t Size() const { return vertices_.size(); }
    
    // prints the following stats:
    //    a) The number of edges that your final graph contains.
    //    b) The smallest out-degree for a vertex.
    //    c) The largest out-degree for a vertex.
    //    d) The average out-degree for a vertex.
    void PrintGraphStats() const;
    
    // prints the graph for testing.
    // assumes Comparable implements operator<<
    void printGraph() const;
    
};

#include "UndirectedGraph.cpp"
#endif /* _UNDIRECTED_GRAPH_H_ */
