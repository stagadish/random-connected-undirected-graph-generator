//
//  UndirectedGraph.cpp
//  union-find-graph-generator-xcode
//
//  Created by Gil Dekel on 4/27/16.
//  Last updated by Gil Dekel on 4/27/16.
//  Copyright © 2016 Gil Dekel. All rights reserved.
//

#include "UndirectedGraph.hpp"


template <typename Comparable>
bool UndirectedGraph<Comparable>::ContainsVertex(const Comparable &val) const {
    auto fetchVertex = vertices_.find(val);
    if (fetchVertex == vertices_.end())
        return false;
    else
        return true;
}

template <typename Comparable>
bool UndirectedGraph<Comparable>::AddVertex(const Comparable &val) {
    if (ContainsVertex(val))
        return false;
    else {
        Vertex newVertex(val);
        vertices_.insert(std::pair<Comparable, Vertex>(newVertex.val, std::move(newVertex)));
        return true;
    }
}

template <typename Comparable>
bool UndirectedGraph<Comparable>::ContainsEdge(const Comparable &lhs, const Comparable &rhs) const {
    // Check if both values are in the graph
    if (ContainsVertex(lhs) && ContainsVertex(rhs)) {
        auto fetchVertex = vertices_.find(lhs);              // get the first vertex.
        auto findNeighbor = fetchVertex->second.adj_l.find(rhs);    // find the second vertx in the first vertex's adjacency list.
        if (findNeighbor == fetchVertex->second.adj_l.end())
            return false;
        else
            return true;
    } else
        return false;
}

template <typename Comparable>
bool UndirectedGraph<Comparable>::AddEdge(const Comparable &lhs, const Comparable &rhs) {
    if (ContainsEdge(lhs, rhs))
        return false;
    else {
        if (ContainsVertex(lhs) && ContainsVertex(rhs)) {
            auto fetchLeftVertex = vertices_.find(lhs);
            auto fetchRightVertex = vertices_.find(rhs);
            fetchLeftVertex->second.adj_l.insert(rhs);             // connect lhs-->rhs
            fetchRightVertex->second.adj_l.insert(lhs);            // connect lhs<--rhs
            ++numOfEdges_;                           //update the number of undirected edges in the graph.
            return true;
        } else
            return false;
    }
}

template <typename Comparable>
void UndirectedGraph<Comparable>::PrintGraphStats() const {
    size_t min = numOfEdges_, max = 0;
    // num of edges divide by the number of vertices = average out degree of a vertex.
    double avg = static_cast<double>(numOfEdges_) / vertices_.size();
    
    for (auto v : vertices_) {
        // The out degree of a vertex is the size of its adjacency list.
        size_t currentOutDeg = v.second.adj_l.size();
        
        if (min > currentOutDeg) min = currentOutDeg;
        if (max < currentOutDeg) max = currentOutDeg;
    }
    
    std::cout << "Current Graph Statistics:\n";
    std::cout << "Number of vertices: " << vertices_.size() << std::endl;
    std::cout << "Number of edges: " << numOfEdges_ << std::endl;
    std::cout << "Smallest out-degree for a vertex: " << min << std::endl;
    std::cout << "Largest out-degree for a vertex: " << max << std::endl;
    std::cout << "Average out-degree for a vertex: " << avg << std::endl << std::endl;
    
}

template <typename Comparable>
void UndirectedGraph<Comparable>::printGraph() const {
    for (auto verx : vertices_) {
        std::cout << verx.second.val << "\t---> ";
        for (auto neighbor : verx.second.adj_l)
            std::cout << neighbor << ", ";
        std::cout << std::endl;
    }
}



