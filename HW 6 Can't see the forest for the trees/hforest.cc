#include "htree.hh"
#include "HForest.hh"
#include <algorithm>



int HForest::size() const {
	return HForest::listOfTrees.size();
}

bool compareTrees(HTree* t1, HTree*  t2) {
    return t1->get_value() < t2->get_value();
}

void HForest::addTree(HTree* tree) {
	//HForest::listOfTrees.push_back(tree);
	//std::push_heap<std::list<HTree*>::iterator>(listOfTrees.begin(),listOfTrees.end()
	//,compareTrees);
	listOfTrees.push(tree);
}

HTree* HForest::popTree() {
	//HTree* thing = (*listOfTrees.begin());
	//HForest::listOfTrees.pop_back();
	//std::pop_heap(HForest::listOfTrees.begin(),HForest::listOfTrees.end(),compareTrees);	
	HTree* thing = listOfTrees.top();
	listOfTrees.pop();
	return thing;
}


