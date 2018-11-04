#include "htree.hh"
#include "HForest.hh"
#include <algorithm>

using tree_ptr_t = std::shared_ptr<const HTree>;



int HForest::size() const {
	return HForest::listOfTrees.size();
}


HForest::HForest() 
	: listOfTrees(compareTrees())
{
}

void HForest::addTree(tree_ptr_t tree) {
	//adds a tree to the priority queue
	listOfTrees.push(tree);
}

tree_ptr_t HForest::popTree() {
	//pops a tree from the priority queue
	tree_ptr_t thing = listOfTrees.top();
	listOfTrees.pop();
	return thing;
}


