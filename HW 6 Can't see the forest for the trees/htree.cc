#include "htree.hh"

using tree_ptr_t = std::shared_ptr<const HTree>;
using path_t = std::list<Direction>;
enum class Direction { LEFT, RIGHT };

HTree::HTree(int key, uint64_t value) : MrKey(key), MrValue(value) {}

HTree::HTree(int key, uint64_t value,tree_ptr_t left = nullptr, tree_ptr_t right = nullptr) 
    : MrKey(key), MrValue(value), MrLeft(left), MrRight(right) {}

  
//HTree::~HTree(){}

int HTree::get_key() {return MrKey;};  // Return key in current node
uint64_t HTree::get_value() {return MrValue};      // Return value in current node

HTree::tree_ptr_t HTree::get_child(Direction dir) const {
  return dir == LEFT ? MrLeft : dir == RIGHT ? MrRight : nullptr;
}

  // Return a list of directions from root to a node of a given key.
  // Crashes (with an assert) if key not contained in this tree
HTree::path_t HTree::path_to(int key) const {
  HTree::path_t path = new HTree::path_t;
  if (MrKey == key) {
    return path;
  }
  if (isValueHere(MrLeft, key)) {
    return LEFT + path_to(MrLeft, key);
    //path = path + LEFT + path_to(MrLeft, key);
  }
  else if (isValueHere(MrRight, key)) {
    return RIGHT + path_to(MrRight, key);
    //path = path + RIGHT + path_to(MrRight, key); 
  }
  else {
    assert(false);
  }
  return path;
}


//tree_ptr_t getShrPtr() const {
//  return 
//}

void addChild (Direction dir, HTree child) {
  if (dir == LEFT) {
    MrLeft = child;
  }
  if (dir == RIGHT) {
    MrRight = child;
  }
}




bool HTree::isValueHere(HTree::tree_ptr_t tree, int key) const{
 // if (tree == nullptr) {
  //  return false;
  //}
  if (MrKey == key) {
    return true;
  }
  if (MrLeft && MrLeft -> find(key)) {
    return true;
  }
  if (MrRight && MrRight -> find(key)) {
    return true;
  }
  return false;
 // return (isValueHere(MrLeft,key) || isValueHere(MrRight,key));

}