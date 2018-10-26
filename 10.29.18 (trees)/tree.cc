#include <string>
#include "tree.hh"
#include <iostream>
#include <assert.h>

using std::cout; 
using std::string;
                                // why use & instead of asterisk?
tree_ptr_t create_tree(const my_key_t& key, const value_t& value, tree_ptr_t left, tree_ptr_t right) {
	Tree* tmp = new Tree;
	tmp -> key_ = key;
	tmp -> value_ = value;
	tmp -> left_ = left;
	tmp -> right_ = right;
	return tmp;
}


void destroy_tree(tree_ptr_t tree) {
	if (tree == nullptr) {
		return;
	}
	destroy_tree(tree -> right_);
	destroy_tree(tree -> left_);
	delete tree;
	cout << "tree been desroyed\n";
}

bool isValueHere(tree_ptr_t tree, my_key_t key){
	if (tree == nullptr) {
		return false;
	}
	if (tree -> key_ == key) {
		return true;
	}
	return (isValueHere(tree->left_,key) || isValueHere(tree->right_,key));

}

std::string path_to(tree_ptr_t tree, my_key_t key) {
	std::string path = "";
	if (tree -> key_ == key) {
		return path;
	}
	if (isValueHere(tree -> left_, key)) {
		path = path + "L" + path_to(tree -> left_, key);
	}
	else if (isValueHere(tree -> right_, key)) {
		path = path + "R" + path_to(tree -> right_, key);	
	}
	else {
		assert(false);
	}
	return path;
}



char subString(string input) {
	if (input==""){
		return ' ';
	}
	char R = 'R';
	char L = 'L';
	return (input.at(0)==R)? R: (input.at(0)==L)? L: ' ';
}

string suffix(string input) {
	if(input.size()>1) {
		return (input.substr(1));
	}
	return "";
}

/*bool checkIfValid(string input){
	if (!input){
		return false;
	}
	if (input != "R")
}*/

tree_ptr_t node_at(tree_ptr_t tree, string path) {
	if (path==""||tree==nullptr){
		return tree;
	}
	char curChar = subString(path);
	string restOfStuff = suffix(path); 
	if (curChar == 'R') {
		return node_at(tree->right_, restOfStuff);	
	}
	if (curChar == 'L') {
		return node_at(tree->left_, restOfStuff);	
	}
	return nullptr;
}
