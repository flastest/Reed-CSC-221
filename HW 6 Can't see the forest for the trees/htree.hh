/*
 * HTree: a class to represent a tree node with two values: a key
 * and a value.
 */

#pragma once

#include <memory>
#include <list>
#include <iostream>
#include <ostream>

class HTree {
 public:
  using tree_ptr_t = std::shared_ptr<const HTree>;
  enum class Direction { LEFT, RIGHT };
  using path_t = std::list<Direction>;

  // Initialize with a key and a value:
  HTree(int key, uint64_t value);
  HTree(int key, uint64_t value, tree_ptr_t left, tree_ptr_t right = nullptr);
  ~HTree() = default;

  int get_key() const;  // Return key in current node
  uint64_t get_value() const;      // Return value in current node

  // Return the child of this node indicated by dir.
  // If the child is nullptr (current node is a leaf), returns nullptr.
  tree_ptr_t get_child(Direction dir) const;

  // Return a list of directions from root to a node of a given key.
  // Crashes (with an assert) if key not contained in this tree
  path_t path_to(int key) const;
 
  std::string GetDebugString() const;


private:
  int MrKey;
  uint64_t MrValue;
  tree_ptr_t MrRight;
  tree_ptr_t MrLeft;

  // helper function for path_to
  bool isValueHere( int key) const;
};



