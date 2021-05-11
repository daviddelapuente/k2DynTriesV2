#ifndef K2DYNTRIESV2_TRIENODE_H
#define K2DYNTRIESV2_TRIENODE_H

//this is a recursive data structure. the trieNode has 4 childrens that are accesed using the morton code
//from the level [0,L1) the block is a null pointer (cuz the data structure is not compressed)
//for leves in [L1,maxint), block is a pointer to a treeBlock (the block data structure)
struct trieNode{
    void *block;
    trieNode *children[4];
};

#endif //K2DYNTRIESV2_TRIENODE_H
