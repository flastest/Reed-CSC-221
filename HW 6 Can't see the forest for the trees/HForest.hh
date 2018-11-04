#pragma once

#include "htree.hh"
#include <algorithm>
#include <queue>          // std::priority_queue

using tree_ptr_t = std::shared_ptr<const HTree>;

class HForest { 
public:
	HForest(){}
	int size() const;
	void addTree(tree_ptr_t tree);
	tree_ptr_t popTree();
private:

	//std::list<HTree*> listOfTrees;
	std::priority_queue<tree_ptr_t> listOfTrees;
};