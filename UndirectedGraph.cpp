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
        auto findNeighbor = fetchVertex->adj_l.find(rhs);    // find the second vertx in the first vertex's adjacency list.
        if (findNeighbor == fetchVertex->adj_l.end())
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
            fetchLeftVertex->adj_l.insert(rhs);             // connect lhs-->rhs
            fetchRightVertex->adj_l.insert(lhs);            // connect lhs<--rhs
            ++numOfEdges;                           //update the number of undirected edges in the graph.
            return true;
        } else
            return false;
    }
}

template <typename Comparable>
void UndirectedGraph<Comparable>::printGraph() const {
    for (auto verx : vertices_) {
        std::cout << "Vertex " << verx.second.val << " is connected to:\n";
        for (auto neighbor : verx.second.adj_l)
            std::cout << "\t" << neighbor << std::endl;
    }
}



