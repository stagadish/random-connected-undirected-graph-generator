//
//  DisjointSet.cpp
//  union-find-graph-generator-xcode
//
//  Created by Gil Dekel on 4/28/16.
//  Last updated by Gil Dekel on 4/28/16.
//  Copyright © 2016 Gil Dekel. All rights reserved.
//

#include "DisjointSet.hpp"

#include <cstdlib>
#include <ctime>

template <typename Comparable>
bool DisjointSet<Comparable>::AddNewNode(const Comparable &val) {
    if (nodes_.find(val) != nodes_.end())
        return false;
    
    nodes_.insert(std::pair<Comparable, Node>(val, Node(val)));
    nodes_.find(val)->second.parent = &nodes_.find(val)->second;
    ++numOfSets_;
    return true;
}

template <typename Comparable>
Comparable* DisjointSet<Comparable>::Find(const Comparable &val) {
    auto fetchNode = nodes_.find(val);
    if (fetchNode == nodes_.end()) {
        return nullptr;
    }
    
    if (fetchNode->second.parent == &fetchNode->second) {        // if this node points to itself
        return &fetchNode->second.val;
    } else {
        auto fetchParentNode = nodes_.find(fetchNode->second.parent->val);
        Comparable next = fetchParentNode->second.val;
        fetchNode->second.parent = &nodes_.find(*Find(next))->second;
        return &fetchNode->second.parent->val;
    }
}

template <typename Comparable>
bool DisjointSet<Comparable>::Union(const Comparable &lhs, const Comparable &rhs) {
    Comparable* l = Find(lhs);
    Comparable* r = Find(rhs);
    
    if (r == l) return false;     // if the two values share the same root, terminate.
    
    auto fetchL = nodes_.find(*l);
    auto fetchR = nodes_.find(*r);
    
    // Here, we are going to insert the lhs under the rhs.
    // However, we choose lhs to be of lower rank.
    
    // if they have the same rank, pick one randomly
    // to avoid unintentional bias
    if (fetchL->second.rank == fetchR->second.rank) {
        srand(time(0));
        if (rand() % 2 == 0) {
            std::swap(fetchL, fetchR);
        } // else do nothing.
        
    } else if (fetchL->second.rank > fetchR->second.rank)
        std::swap(fetchL, fetchR);
    // else lhs ranks lower than rhs and we do nothing.
    
    
    // And finally, we make the union.
    fetchL->second.parent = &fetchR->second;
    ++fetchR->second.rank;
    --numOfSets_; // we just made a union. The number of sets decreases by one.
    return true;
    
}



