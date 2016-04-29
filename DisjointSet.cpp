//
//  DisjointSet.cpp
//  union-find-graph-generator-xcode
//
//  Created by Gil Dekel on 4/28/16.
//  Last updated by Gil Dekel on 4/29/16.
//  Copyright © 2016 Gil Dekel. All rights reserved.
//

#include "DisjointSet.hpp"

#include <cstdlib>
#include <ctime>

template <typename Comparable>
bool DisjointSet<Comparable>::AddNewNode(const Comparable &val) {
    // Check if the value is already in the set.
    if (nodes_.find(val) != nodes_.end())
        return false;
    
    // Add a new node to the set, and then set its parent as itself.
    nodes_.insert(std::pair<Comparable, Node>(val, Node(val)));
    nodes_.find(val)->second.parent = &nodes_.find(val)->second;
    ++numOfSets_;       // A new disjoint component was added to the set.
    return true;
}

template <typename Comparable>
Comparable* DisjointSet<Comparable>::Find(const Comparable &val) {
    // Check if the element is in the set.
    auto fetchNode = nodes_.find(val);
    if (fetchNode == nodes_.end()) {
        return nullptr;
    }
    
    if (fetchNode->second.parent == &fetchNode->second)         // BASECASE: if this node points to itself
        return &fetchNode->second.val;                          // return its value as the root.
    
    else {
        // Get the parent node.
        auto fetchParentNode = nodes_.find(fetchNode->second.parent->val);
        // Get the parent node's value.
        Comparable next = fetchParentNode->second.val;
        // Path compression. Set the current node's parent to the root of its parent.
        fetchNode->second.parent = &nodes_.find(*Find(next))->second;
        // return the new parent of this node after path compression.
        return &fetchNode->second.parent->val;
    }
}

template <typename Comparable>
bool DisjointSet<Comparable>::Union(const Comparable &lhs, const Comparable &rhs) {
    
    // Find the roots of lhs and rhs.
    Comparable* l = Find(lhs);
    Comparable* r = Find(rhs);
    
    if (r == l) return false;     // if the two values share the same root, terminate.
    
    // Retrive the actual nodes.
    auto fetchL = nodes_.find(*l);
    auto fetchR = nodes_.find(*r);
    
    // Here, we are going to insert the lhs under the rhs.
    // However, we choose lhs to be of lower rank.
    
    // if they have the same rank, pick one randomly
    // to avoid unintentional bias.
    if (fetchL->second.rank == fetchR->second.rank) {
        srand(time(0));
        if (rand() % 2 == 0) {
            std::swap(fetchL, fetchR);
        } // else do nothing.
        
    } else if (fetchL->second.rank > fetchR->second.rank)
        std::swap(fetchL, fetchR);
    // else lhs ranks lower than rhs and we do nothing.
    
    
    // Finally, we make the union.
    fetchL->second.parent = &fetchR->second;
    ++fetchR->second.rank;
    --numOfSets_; // we just made a union. The number of sets decreases by one.
    return true;
    
}


template <typename Comparable>
void DisjointSet<Comparable>::printPath(const Comparable &val) const {
    auto fetchNode = nodes_.find(val);
    if (fetchNode == nodes_.end()) return;
    
    if (fetchNode->second.parent == &fetchNode->second) {
        std::cout << fetchNode->second.val << ", ";
        }
        else {
            std::cout << fetchNode->second.val << ", ";
            printPath(fetchNode->second.parent->val);
        }
        
}

