#include "htree.hh"
#include "HForest.hh"
#include <algorithm>

using tree_ptr_t = std::shared_ptr<const HTree>;

int HForest::size() const {
	return HForest::listOfTrees.size();
}

//is HTree* a pointer or a thingy?
bool compareTrees(tree_ptr_t t1, tree_ptr_t  t2) {
    return t1->get_value() < t2->get_value();
}

void HForest::addTree(tree_ptr_t tree) {
	//HForest::listOfTrees.push_back(tree);
	//std::push_heap<std::list<HTree*>::iterator>(listOfTrees.begin(),listOfTrees.end()
	//,compareTrees);
	listOfTrees.push(tree);
}

tree_ptr_t HForest::popTree() {
	//HTree* thing = (*listOfTrees.begin());
	//HForest::listOfTrees.pop_back();
	//std::pop_heap(HForest::listOfTrees.begin(),HForest::listOfTrees.end(),compareTrees);	
	tree_ptr_t thing = listOfTrees.top();
	listOfTrees.pop();
	return thing;
}


