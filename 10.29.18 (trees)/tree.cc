#include <string>

using tree_ptr_t = Tree*;
                                // why use & instead of asterisk?
tree_ptr_t create_tree(const key_t& key, const value_t& value, tree_ptr_t left = nullptr,
                       tree_ptr_t right = nullptr) {
	auto tmp = new Tree;
	tmp -> key_ = key;
	tmp -> value_ = value;
	tmp -> left_ = left;
	temp -> right_ = right;
	return tmp*;
}


void destroy_tree(tree_ptr_t tree) {
	if (tree = nullptr) {
		return;
	}
	destroy_tree(*tree -> right_);
	destroy_tree(*tree -> left_);
	delete *tree;
}

bool isValueHere(tree_ptr_t tree, key_t key){
	if (tree == nullptr) {
		return false;
	}
	if (tree* -> key_ == key) {
		return true;
	}
	return (isValueHere(tree*->left_) || isValueHere(tree*->right_));

}

std::string path_to(tree_ptr_t tree, key_t key) {
	std::string path = "";
	if (tree* -> key_ = key) {
		return path;
	}
	if (isValueHere(tree* -> left_, key)) {
		path = path + "L" + path_to(tree* -> left_, key);
	}
	else if (isValueHere(tree* -> right_, key)) {
		path = path + "R" + path_to(tree* -> left_, key);	
	}
	else {
		assert false;
	}
	return path;
}


