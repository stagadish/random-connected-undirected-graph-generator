//
//  DisjointSet.hpp
//  union-find-graph-generator-xcode
//
//  Created by Gil Dekel on 4/28/16.
//  Last updated by Gil Dekel on 4/29/16.
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
        
        // New nodes are initialized to rank = 0 with no parents.
        // They are later set to point to themselves in AddNewNode().
        Node() : parent(nullptr), rank(0) {}
        Node(const Comparable &nuVal, Node* nuParent = nullptr, size_t nuRank = 0)
            : val(nuVal), parent(nuParent), rank(nuRank) {}
    };
    
    // The set of Nodes searchable by their value
    std::unordered_map<Comparable, Node> nodes_;
    
    // The number of sets
    // currently in the data structure.
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
    // nullpte is returned if the element is NOT in the set.
    Comparable* Find(const Comparable &val);
    
    // Union by rank.
    // Fetch each element's root and decide whether or not
    // the two should be unioned.
    // Then consider each nodes rank. The lower ranked will be
    // joined under the higher rank. If both have equal ranks,
    // choose one randomly to be inserted under the other.
    // param lhs: 'From' element.
    // param rhs: 'To' element.
    // return: true if the union was made successfully. false otherwise.
    bool Union(const Comparable &lhs, const Comparable &rhs);
    
    // return the number of sets currently in the disjoint set.
    size_t Size() const { return numOfSets_; }
    
    // a path print test function to print a node's
    // path to its root. written to test path
    // compression.
    void printPath(const Comparable &val) const;
    
};

#include "DisjointSet.cpp"
#endif /* _DISJOINTSET_H_ */
