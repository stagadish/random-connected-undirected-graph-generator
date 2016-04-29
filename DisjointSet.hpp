//
//  DisjointSet.hpp
//  union-find-graph-generator-xcode
//
//  Created by Gil Dekel on 4/28/16.
//  Last updated by Gil Dekel on 4/28/16.
//  Copyright © 2016 Gil Dekel. All rights reserved.
//

#ifndef _DISJOINTSET_H_
#define _DISJOINTSET_H_

#include <iostream>
#include <unordered_map>

/*
 *  This is an implementation of the union-find data structure
 *  using union by rank and path compression in find.
 *
 * --Assumptions--
 * 1) All vertices are unique (i.e. no duplicates).
 * 2) Objects of type Comparable define operator<, operator==, and operator*
 *    (i.e. it is possible to compare between two objects of type Comparable
 *     and dereference the object to its comparable value)
 */

template <typename Comparable>
class DisjointSet {
private:
    struct Node {
        Comparable val;
        Node* parent;
        size_t rank;
        
        // Initialize new Nodes to point to themselves with rank 0.
        // Or, Initialize new Nodes with a val, parent, and rank.
        Node() : parent(nullptr), rank(0) {}
        Node(const Comparable &nuVal, Node* nuParent = nullptr, size_t nuRank = 0)
            : val(nuVal), parent(nuParent), rank(nuRank) {}
    };
    
    // The set of Nodes searchable by their value
    std::unordered_map<Comparable, Node> nodes_;
    
    // The number of sets
    size_t numOfSets_;
    
public:
    // Using default ctors, assignment operators and destructor.
    DisjointSet() : numOfSets_(0) {}
    DisjointSet(const DisjointSet &rhs) = default;
    DisjointSet& operator=(const DisjointSet &rhs) = default;
    DisjointSet(DisjointSet &&rhs) = default;
    DisjointSet& operator=(DisjointSet &&rhs) = default;
    ~DisjointSet() = default;
    
    
    // Push a new element to the superset.
    // It also increases the number of sets by 1
    // with each new addition.
    // param val: the new param to push as a node.
    // return: true if the val was add. False if it is already
    // in the set.
    bool AddNewNode(const Comparable &val);
    
    // Find the root of a given value, compressing paths
    // along the way.
    // param val: The value to find.
    // return: A pointer to the root value.
    Comparable* Find(const Comparable &val);
    
    
    bool Union(const Comparable &lhs, const Comparable &rhs);
    
    // return the number of sets currently in the disjoint set.
    size_t Size() const { return numOfSets_; }
    
};

#include "DisjointSet.cpp"
#endif /* _DISJOINTSET_H_ */
