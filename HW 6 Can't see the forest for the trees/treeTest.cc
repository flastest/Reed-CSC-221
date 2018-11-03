#include "htree.hh"
#include <stdint.h>
#include <iostream>

using std::cout;
using tree_ptr_t = std::shared_ptr<const HTree>;

static void test1(){
	//gonna make this guy:
	/*
            126
           /   \
          /     \
        -5       12
        / \     /
      12   6    3
          /
         9
	*/

	//tree 9
	int num = 9;
	uint64_t val = 9;
	HTree* tree9 = new HTree(num,val);

	//tree 6
	num = 6;
	val = 6;
	tree_ptr_t left = tree_ptr_t(tree9);
	HTree* tree6 = new HTree(num,val, left);

	//tree 12L-most
	num =  12;
	val = 12; 
	HTree* tree12L = new HTree(num,val);

	//tree -5
	num =  -5;
	val = 5; 
	left = tree_ptr_t(tree12L);
	tree_ptr_t right = tree_ptr_t(tree6);
	HTree* treeNeg5 = new HTree(num,val,left,right);

	//tree 3
	num =  3;
	val = 3; 
	HTree* tree3 = new HTree(num,val); 

	//tree 12R
	num =  12;
	val = 12; 
	left = tree_ptr_t(tree3);
	HTree* tree12R = new HTree(num,val,left); 

	//tree 126 (head)
	num =  126;
	val = 126; 
	left = tree_ptr_t(treeNeg5);
	right = tree_ptr_t(tree12R);
	HTree* tree126 = new HTree(num,val,left,right); 
	
	int search = 3;
	cout<<"path to " << search << " is " ;
	for(HTree::Direction thing:tree126->path_to(search)){  
		cout<< (thing==HTree::Direction::LEFT?"Left":"Right") <<"\n";
	}
	
	//cout <<"and the thing at that node is " <<  node_at(tree126,path_to(tree126,search))->key_ << " \n";

	//cout << "RL brings us to node " << node_at(tree126,"RL")->key_<<"\n";

	//cout << "the path to 126 is '" << tree126->path_to(126) << "' \n";

	//cout << "blank string leads us to node " << node_at(tree126,"")->key_<<"\n";  

	delete tree126;
}


int main() {
	test1();
}