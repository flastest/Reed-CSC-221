#include "HForest.hh"
#include <vector>

using tree_ptr_t = std::shared_ptr<const HTree>;


tree_ptr_t makeTree(std::vector<int> listT){
	if(listT.empty()){
		return nullptr;
	}
	int f = listT.front();

	std::vector<int> left;
	std::vector<int> right;
	for (uint64_t i = 0; i < listT.size();i++){
		if (i % 2 == 0) {
			left.push_back(listT[i]);
		} else {
			right.push_back(listT[i]);
		}
	}
	tree_ptr_t leftChild = makeTree(left);
	tree_ptr_t rightChild = makeTree(right);
	tree_ptr_t root = tree_ptr_t(new HTree(f,(uint64_t) 0, leftChild, rightChild));
	return root;
}


int main (){
	tree_ptr_t testTree1 = makeTree(std::vector<int>{
		1,2,3,4,5});

}
/*
std::ostream& operator<<(std::ostream& thingey, const HTree &tree) {
  std::cout<< tree.get_key();
  return thingey;
}*/

