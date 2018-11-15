/*
 * Huffman: a class to encode and decode symbols based on adaptive Huffman coding
 * https://en.wikipedia.org/wiki/Huffman_coding
 */

#pragma once

#include <climits>
#include <vector>
//#include <list>

#include "htree.hh"
#include "hforest.hh"


class Huffman {
 public:
  // Maximum number of symbols we need to encode (a symbol fits in a char) + EOF
  static const int ALPHABET_SIZE = (1 << CHAR_BIT) + 1;  // (2 ** 8) + 1
  static const int HEOF = ALPHABET_SIZE - 1;  // Special symbol to denote end of file

  using bits_t = std::vector<bool>;
  using tree_t = HTree::tree_ptr_t;
  //enum class Direction { LEFT, RIGHT };
  //using path_t = std::list<Direction>;
  using Direction = HTree::Direction;
  using path_t_t = HTree::path_t;


  Huffman();
  ~Huffman();
  Huffman(const Huffman&) = delete;
  Huffman(Huffman&&) = delete;
  Huffman& operator=(const Huffman&) = delete;
  Huffman& operator=(Huffman&&) = delete;

  // Encode a symbol into a sequence of bits, then update frequency table.
  bits_t encode(int symbol);




  // Decode a single bit into a symbol. If no symbol can be unmabiguously decoded
  // without additional bits, returns a negative value.
  // Subsequent calls with more bits should eventually resolve to either
  // a character symbol or HEOF.
  // Finally, updates the frequency table with this additional symbol.
  int decode(bool bit);

  

private:
  using forest_t = std::shared_ptr<HForest>;
  forest_t jimmy;
  // Like MapReduce, FrqTable also refers to something other than what
  // the name suggests. It adds a tree to forest Jimmy, or increments a tree.
  //void addToFrqTable(int symbol);
  tree_t huffTree;
  

  // if there's already a hufftree, it's stupid to remake it.
  // neither of these are implemented, maybe I'll get to it...
  /*void createOrAddToTree(tree_t newTree);
  void addToTree(tree_t newTree);
  void switchNodes(tree_t tree1, tree_t tree2); 
  */
  //adds EOF to the tree
  void addEOF();


  //creates huffman tree!
  tree_t createTree();

  //helper function, takes a list of directions and converts them to bits_t
  bits_t parsePath(path_t_t path); 
  // do I really need to put Direction enum and path_t in this file if I only mention it once?
  
  //for decode, we need a pointer to where we currently at
  tree_t currentSpot;

  //fine I'll do a frequency table !!
  std::vector<int> frqTable;


  // fine this will actually do what it says it will
  void updateRealFrqTable(int symbol);

  //takes the frq table and creates a forest
  // puts that forest into Jimmy
  void createForest();

};
