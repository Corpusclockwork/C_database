#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 4 // Maximum degree of the B-tree

//this is for SELECT

struct BTree{
	int num_keys; // Number of keys currently in the node
    int keys[M-1]; // Array of keys
    struct BTreeNode *children[M]; // Array of child pointers
    bool is_leaf; // True if node is a leaf
}
