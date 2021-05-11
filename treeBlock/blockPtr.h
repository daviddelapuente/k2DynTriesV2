#ifndef K2DYNTRIESV2_BLOCKPTR_H
#define K2DYNTRIESV2_BLOCKPTR_H

//this is a wrapper that contain the treeBlock pointer, but also contain a flag.
//this flag is the pre order of the node in the block.
typedef struct
{
    uint16_t flag;   // node that owns the pointer to child block
    treeBlock *P;
} blockPtr;


#endif //K2DYNTRIESV2_BLOCKPTR_H
