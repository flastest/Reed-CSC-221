#pragma once

#include "htree.hh"
#include <algorithm>
#include <queue>          // std::priority_queue

using tree_ptr_t = std::shared_ptr<const HTree>;


class compareTrees
    {
        public:
            bool operator() (const tree_ptr_t &t1, const tree_ptr_t &t2) const
            {
                return t1->get_key() < t2->get_key();
            }
    };
    


class HForest { 
public:
	//constructor
	HForest();

	//returns the size of the forest
	int size() const;

	//adds a tree to forest
	void addTree(tree_ptr_t tree);
	
	//returns a pointer to a tree and removes it from the forest.
	tree_ptr_t popTree();
private:

	//made a priority queue because that's easier
	std::priority_queue<tree_ptr_t, std::vector<tree_ptr_t>, compareTrees> listOfTrees;
};

