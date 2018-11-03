#include "htree.hh"
#include <assert.h>

//for bugtesting
#include <iostream>
using std::cout;

enum class Direction { LEFT, RIGHT };
using tree_ptr_t = std::shared_ptr<const HTree>;
using path_t = std::list<Direction>;

//constructors
HTree::HTree(int key, uint64_t value) : MrKey(key), MrValue(value) {}

HTree::HTree(int key, uint64_t value, tree_ptr_t left, tree_ptr_t right) 
    : MrKey(key), MrValue(value),  MrRight(right),MrLeft(left) {}

  
int HTree::get_key() const {return MrKey;}  // Return key in current node
uint64_t HTree::get_value() const {return MrValue;}      // Return value in current node

HTree::tree_ptr_t HTree::get_child(Direction dir) const {
  // ternary operator is my anime waifu.
  // this checks to see if the input "dir" is LEFT, then returns left pointer
  // if so. Else, it does the same thing with RIGHT. If neither of these
  // work, it returns the nullpointer.
  return dir == Direction::LEFT ? MrLeft : dir == Direction::RIGHT ? MrRight : nullptr;
}

  // Return a list of directions from root to a node of a given key.
  // Crashes (with an assert) if key not contained in this tree
HTree::path_t HTree::path_to(int key) const {
  HTree::path_t path;
  //if we already at the key, the path is good to go and be returned.
  if (MrKey == key) {
    return path;
  }

  //checks if the key is in the left tree using a recursive helper function
  if (MrLeft->isValueHere( key)) {
    path_t tmp = MrLeft->path_to(key);
    tmp.push_front(Direction::LEFT);
    return tmp;
  }
  // does same thing as above but with right tree
  else if (MrRight->isValueHere( key)) {
    path_t tmp = MrRight->path_to(key);
    tmp.push_front(Direction::RIGHT);
    return tmp; 
  }

  //if number isn't in tree, asserts false
  else {
    assert(false);
  }
  return path;
}




bool HTree::isValueHere( int key) const{
  // end condition
  if (MrKey == key) {
    return true;
  }
  // lazy something? fast failure? short circuiting? has lots of names
  // checks left tree for value if it isn't a nullptr
  if (MrLeft && MrLeft -> isValueHere(key)) {
    return true;
  }
  //same thing here with right tree
  if (MrRight && MrRight -> isValueHere(key)) {
    return true;
  }
  return false;

}