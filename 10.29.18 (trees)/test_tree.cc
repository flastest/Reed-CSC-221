//This will test the tree class
////
#include "tree.hh"
#include <stdint.h>
#include <iostream>

using std::cout;
//using key_t = int;
//using value_t = uint64_t;
//using tree_ptr_t = Tree*;

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
	my_key_t num = 9;
	value_t val = 9;
	tree_ptr_t tree9 = create_tree(num,val);

	//tree 6
	num = 6;
	val = 6;
	tree_ptr_t left = tree9;
	tree_ptr_t tree6 = create_tree(num,val, left);

	//tree 12L-most
	num =  12;
	val = 12; 
	tree_ptr_t tree12L = create_tree(num,val);

	//tree -5
	num =  -5;
	val = 5; 
	left = tree12L;
	tree_ptr_t right = tree6;
	tree_ptr_t treeNeg5 = create_tree(num,val,left,right);

	//tree 3
	num =  3;
	val = 3; 
	tree_ptr_t tree3 = create_tree(num,val); 

	//tree 12R
	num =  12;
	val = 12; 
	left = tree3;
	tree_ptr_t tree12R = create_tree(num,val,left); 

	//tree 126 (head)
	num =  126;
	val = 126; 
	left = treeNeg5;
	right = tree12R;
	tree_ptr_t tree126 = create_tree(num,val,left,right); 
	
	int search = 9;
	cout<<"path to " << search << " is " +path_to(tree126,search) + "\n";
	
	cout <<"and the thing at that node is " <<  node_at(tree126,path_to(tree126,search))->key_ << " \n";

	destroy_tree(tree9);
	/*for (int i = 0; i < 5; i++){
		my_key_t key = i;
		value_t value = 0;
		if(i%2==0){
			Tree* left = i+1;
			Tree* right = nullptr;
		} else {
			Tree* left = nullptr;
			Tree* right = i+1;
		}
		Tree* = create_tree(key, value, left, right);	
	}*/
}

int main()	{
	test1();

}
