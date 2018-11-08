
#include "huffman.hh"
#include "hforest.cc"


using bits_t = std::vector<bool>;
using tree_t = HTree::tree_ptr_t;
enum class Direction { LEFT, RIGHT };
using path_t = std::list<Direction>;

void Huffman::addToFrqTable(int symbol){ 
	HTree newLetter = HTree(symbol, 1, nullptr,nullptr);
	if (!jimmy.findKeyAndIncrementValue()) {
		jimmy.add_tree(newLetter);
	}
}

void Huffman::addEOF(){ 
	int EOF = 26; //EOF is 26 in ASCII
	HTree newLetter = HTree(26, 966, nullptr,nullptr);
	jimmy.add_tree(newLetter);
}
                      
//                           
tree_t Huffman::createTree(){
	//first add EOF character!! that's 26 in ASCII
	addEOF();

	//takes lowest 2 trees and adds them to a very small, unreal tree.
	for (int i:jimmy.size()){
		tree_t tree1 = jimmy.pop_top(); 
		tree_t tree2 = jimmy.pop_top();
		tree_t newTree = new HTree(-1,tree1->get_value() + tree2->get_value(),tree2.tree1);
	}
	huffTree = newTree;
	return newTree;

}


bits_t Huffman::encode(int symbol) {
	addToFrqTable(symbol);
	createTree();
	path_t path = huffTree->path_to(symbol);

}

bits_t parsePath(path_t path) {
	bits_t bitString = bits_t();
	for(Direction d:path){
		if(d==LEFT) {
			bitString.push_back(false);
			break;
		}
		if(d==RIGHT) {
			bitString.push_back(true);
		}
	}
	return bitString;
}
