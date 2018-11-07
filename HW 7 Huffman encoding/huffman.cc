
#include "huffman.hh"
#include "hforest.cc"


using bits_t = std::vector<bool>;
using tree_t = HTree::tree_ptr_t;
const int ASCII_CONSTANT = 0;

bits_t Huffman::encode(int symbol){ 
	symbol -= ASCII_CONSTANT;
	HTree newLetter = HTree(symbol, 1, nullptr,nullptr);
	if (!jimmy.findKeyAndIncrementValue()) {
		jimmy.add_tree(newLetter);
	}
	return std::vector<bool>({1,2});
}

//               0            
//              /     amount of L in path() = amount of 1s before the 0        
//             10             
//            110               
//                           
//                           
//                           
//                           
//                           
//                           
//                           
//                           
tree_t Huffman::createTree(){
	tree_t tree1 = jimmy.pop_top(); 
	tree_t biggerThanLast = jimmy.pop_top();
	for (int i:jimmy.size()){
		biggerThanLast->addChildLeft(tree1);
		tree1 = biggerThanLast;
	}
	return biggerThanLast;

}
