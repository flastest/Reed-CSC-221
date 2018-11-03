#pragma once

#include "htree.hh"
#include <algorithm>
#include <queue>          // std::priority_queue


class HForest { 
public:
	HForest(){}
	int size() const;
	void addTree(HTree* tree);
	HTree* popTree();
private:

	//std::list<HTree*> listOfTrees;
	std::priority_queue<HTree*> listOfTrees;
};