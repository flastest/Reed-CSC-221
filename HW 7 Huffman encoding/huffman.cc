
#include "huffman.hh"
#include "hforest.cc"
#include <vector>


using bits_t = std::vector<bool>;
using tree_t = HTree::tree_ptr_t;
//enum class Direction { LEFT, RIGHT };
using Direction = HTree::Direction;
using path_t = HTree::path_t;
//using path_t = std::list<Direction>;


/*
void Huffman::addToFrqTable(int symbol){ 
	//makes a tree for a new letter just in case
	HTree newLetter = HTree(symbol, 1, nullptr,nullptr);
	//if the forest doesn't already have this symbol in it, it will add the 
	// tree to the forest. If it already has the symbol as a key to a node,
	// it will increment the frq counter in value.
	if (!jimmy.findKeyAndIncrementValue()) {
		jimmy.add_tree(newLetter);
	}
	// isn't that so much nicer than creating an unecessarily long array
	// of values that might not even be in the file? and you don't need
	// to loop through that table 257 times to create a new tree!
}

void encodeBetterImplementInFuture(int symbol){
	addToFrqTable(symbol);
	createTree();
	path_t path = huffTree->path_to(symbol);
	return parsePath(path);
}
*/
Huffman::Huffman(){
	frqTable = std::vector<int>(257,0);
	//jimmy = HForest();
	huffTree = nullptr;
}

void Huffman::addEOF(){ 
	int EOFi = 256; 
	HTree* letter = new HTree(256, 966, nullptr,nullptr);
	tree_t newLetter = std::make_shared<HTree>(letter);
	jimmy->add_tree(newLetter);
}
                      
//                           
tree_t Huffman::createTree(){
	//first add EOF character!! 
	addEOF();
	tree_t newTree;
	//takes lowest 2 trees and adds them to a very small, unreal tree.
	for (int i= 0; i <jimmy->size(); i++){
		tree_t tree1 = jimmy->pop_top(); 
		tree_t tree2 = jimmy->pop_top();
		HTree* treeguy = new HTree(-1,tree1->get_value() + tree2->get_value(),tree2,tree1);
		newTree = std::make_shared<HTree>(treeguy);
		jimmy->add_tree(newTree);
	}
	huffTree = newTree;
	currentSpot = newTree;
	return newTree;

}



void Huffman::updateRealFrqTable(int symbol) {
	frqTable[symbol] ++;
}

void Huffman::createForest(){
	for (int i = 0; i < 256; i++){
		HTree* newGuy= new HTree(i,frqTable[i],nullptr,nullptr);
		tree_t newBro = std::make_shared<HTree>(newGuy);
		jimmy->add_tree(newBro);  
	}
}

bits_t Huffman::encode(int symbol) {
	updateRealFrqTable(symbol);
	createForest();
	createTree();
	path_t path = huffTree->path_to(symbol);
	return parsePath(path);
}

bits_t parsePath(path_t path) {
	bits_t bitString = bits_t();
	for(Direction d:path){
		if(d==Direction::LEFT) {
			bitString.push_back(false);
			break;
		}
		if(d==Direction::RIGHT) {
			bitString.push_back(true);
		}
	}
	return bitString;
}



//needs to loop through rights until it gets a left
//then needs to decrement the tree in jimmy and replace 
//the huffTree
int Huffman::decode(bool bit) {
	if(bit) {
		currentSpot = currentSpot -> get_child(Direction::RIGHT);
	} else {
		currentSpot = currentSpot -> get_child(Direction::LEFT);
	}
	int curKey =currentSpot ->  get_key();
	//needs to update tree if we actually got to a character
	if (curKey >= 0) {
		frqTable[curKey]--;
		//recreate tree with updated value..
		createForest();
		currentSpot = createTree();
	}
	return	curKey;
}



