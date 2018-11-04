#include "HForest.hh"
#include <vector>

using tree_ptr_t = std::shared_ptr<const HTree>;
using std::cout;

//recursively creates arbitrary trees from a list
tree_ptr_t makeTree(std::vector<int> listT){
	if(listT.size()<1){
		return nullptr;
	}
	int f = listT.front();

	std::vector<int> left;
	std::vector<int> right;
	for (uint64_t i = 1; i < listT.size();i++){
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
		966,2,3,4,5,8});
	tree_ptr_t testTree2 = makeTree(std::vector<int>{
		967,556,6,7,6});
	tree_ptr_t testTree3 = makeTree(std::vector<int>{
		963,723,623});

	HForest billyJoel;
	//verify addTree works
	billyJoel.addTree(testTree1);
	billyJoel.addTree(testTree2);
	billyJoel.addTree(testTree3);

	cout<<"tree 1 is " << (*testTree1).GetDebugString()<<"\n";
	cout<<"tree 2 is " << (*testTree2).GetDebugString()<<"\n";

	//verify that popTree works
	cout<<"pop "<<(billyJoel.popTree())->get_key()<<"\n";
	cout<<"pop again "<<(billyJoel.popTree())->get_key()<<"\n";
	cout<<"pop again "<<(billyJoel.popTree())->get_key()<<"\n";
	cout<<"diddlydone\n";

}
/*
std::ostream& operator<<(std::ostream& thingey, const HTree &tree) {
  std::cout<< tree.get_key();
  return thingey;
}*/

