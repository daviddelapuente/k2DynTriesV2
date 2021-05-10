#ifndef TREEBLOCK
#define TREEBLOCK

//some libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <utility>
#include <stdint.h>
#include <time.h>

//the name space
using namespace std;

// Global table that stores the sizes of the blocks, used for growing them
uint16_t *sizeArray; // array of sizes

// Minimum and maximum block sizes
uint16_t N1;
uint16_t Nt;

//L1 and L2 are leves from where the tree change it forms.
//the nodes in the leves [0,L1) are trieNodes.
//nodes in [L1,l2] are TreeBlocks of a medium size
//nodes in (L2.maxint) are TreeBlocks of a larger size
//we make this, because we need to hava some equilibrium, the first nodes are not compress because
//the are accesed very often. And for the treeBlocks we have two diferent max sizes because the medium
//node are accessed more frequently and rank the child isnt cheap.
#define L1 8
#define L2 16

//these are the sizes for the diferent type of blocks
//S1 = for nodes in [0,L1)
//S2 = for nodes in [L1,L2]
//S3 = for nodes in (L2,maxint]
#define S1 64
#define S2 128
#define S3 1024


//this is a recursive data structure. the trieNode has 4 childrens that are accesed using the morton code
//from the level [0,L1) the block is a null pointer (cuz the data structure is not compressed)
//for leves in [L1,maxint), block is a pointer to a treeBlock (the block data structure)
struct trieNode{
    void *block;
    trieNode *children[4];
};


// position in the dfuds
#define NODE_TYPE uint16_t
// any postition in the dfuds, contains an uint16_t, that represent 4 nodes of 4 bits. the OFFSET_TYPE, represent wich of the 4 bits represent the node
#define OFFSET_TYPE uint8_t
//max unsigned int of 16 bits, is used to limit the dfuds
#define MAX_UINT_16 65535

//A node within a block represented as a pair <index of the short int that contains the node, offset of the node within the short int>. The offset is 0, 1, 2, or 3
typedef std::pair <NODE_TYPE,OFFSET_TYPE> treeNode;

//function that returns the the absolute position of a node in the block.
//this absolute position is calculated first geting the NODE_TYPE, and then we have 4 consecutives posibilities
//and we use the OFFSET_TYPE to choose one.
uint16_t absolutePosition(treeNode &node);




//this is the main structure. the more important attributes are:
//dfuds: is the bit array containing the topology
//ptr: is the array of pointers to the child blocks (the frontier)
struct treeBlock
 {
    //attributes
    uint8_t rootDepth;  // depth of the root of the block
    uint16_t nNodes;  // number of nodes in the tree block
    uint16_t maxNodes; // maximum number of nodes in the block. Also, it is the size of the next array.
    uint16_t *dfuds;  // DFUDS of the tree block
    void /*blockPTR*/ *ptr;    // Pointers to child blocks (this is a pointer to a data structure containing the pointer to the block (please read  blockPtr below))
    uint16_t nPtrs;   // number of pointers to child blocks

    //methods
    //inserts in a block
    void insert(treeNode, uint8_t[], uint64_t, uint16_t, uint64_t, uint16_t);
    //takes me to the position in dfuds, where is the child of the node with symbol
    treeNode skipChildrenSubtree(treeNode &, uint8_t, uint16_t &, uint16_t, uint16_t &);
    //return the next child in function of the symbol (this function is a wrapper of skipChildrenSubtree but identificate when a child is in the block or in a child block)
    treeNode child(treeBlock *&, treeNode &, uint8_t, uint16_t &, uint16_t, uint16_t &);
    // grow the dfuds and update maxNodes
    void grow(uint16_t extraNodes);
    // shrink dfuds and update maxNodes
    void shrink(uint16_t deletedNodes);
    void shrink2();
    //return a treeNode where the subtree begin (the end is in subTreeSize)
    treeNode selectSubtree2(uint16_t maxDepth, uint16_t & subTreeSize, uint16_t & depthSelectN);
    //return the pointer to a treeBlock pointer, in function of the current flag (fronteir node)
    struct treeBlock *getPointer(uint16_t);
    //this function calculate the size of the whole tree
    uint64_t size();

    //free the data structure
    void freeTreeBlock();
    void freeTreeBlock2();
    ~treeBlock(){;};
 };
 
//this is a wrapper that contain the treeBlock pointer, but also contain a flag.
//this flag is the pre order of the node in the block.
typedef struct
 {
    uint16_t flag;   // node that owns the pointer to child block
    treeBlock *P;
 } blockPtr;





//todo: estas estructuras podrian estar cada una en su propio archivo
//struct to retrieve some data of the nodes
struct nodeInfo{
    //preorder: give the preorder of the node in the topology
    uint16_t preorder;
    //give the number of children the node have from 1 to 4
    uint16_t nChildren;
    //constructors
    nodeInfo() {};
    nodeInfo(uint16_t _preorder, uint16_t _nChildren){
        preorder = _preorder;
        nChildren = _nChildren;
    };
};


//struct to retrieve some data of the subtrees of a node
struct subtreeInfo{
    //the preorder of a subtree
    uint16_t preorder;
    //the size of the subtree
    uint16_t subtreeSize;
    //constructors
    subtreeInfo() {};
    subtreeInfo(uint16_t _preorder, uint16_t _subtreeSize){
        preorder = _preorder;
        subtreeSize = _subtreeSize;
    };
};








/* Auxiliary tables */

/* this table is used to right Shitf >> bits for the OFFSET_TYPE
for example if you have this node with its 4 childs
0000 1111 0000 0000
you want to shift 8 times to the left (shiftT[1]) to recover the node
0000 0000 0000 1111 */
const uint16_t shiftT[4] = {12,8,4,0};

/*initial mask to obtain the binary code of a node according to its offset within a short int
 for example if you have a node 11001010100001101 and you want the fourth children, you want
 maskInitT[3]=0000000000001111*/
const uint16_t maskInitT[4] = {0xf000,0x0f00,0x00f0,0x000f};

/* number of childrens of a node. for example 9=1001 has 2 childrens because it has two 1 */
const uint8_t nChildrenT[16] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};


/*given a node and a symbol, this table says how many subtrees of the given node must be skipped to obtain the corresponding child subtree
for example, for 1100, and 2 = childSkipT[12,2], you have to skip 2 nodes to insert in 2, because you have two 1 in the left side*/


const int8_t childSkipT[16][4] = {
/*0000*/ { 0,  0,  0,  0},
/*0001*/ { 0,  0,  0,  0},
/*0010*/ { 0,  0,  0,  1},
/*0011*/ { 0,  0,  0,  1},
/*0100*/ { 0,  0,  1,  1},
/*0101*/ { 0,  0,  1,  1},
/*0110*/ { 0,  0,  1,  2},
/*0111*/ { 0,  0,  1,  2},
/*1000*/ { 0,  1,  1,  1},
/*1001*/ { 0,  1,  1,  1},
/*1010*/ { 0,  1,  1,  2},
/*1011*/ { 0,  1,  1,  2},
/*1100*/ { 0,  1,  2,  2},
/*1101*/ { 0,  1,  2,  2},
/*1110*/ { 0,  1,  2,  3},
/*1111*/ { 0,  1,  2,  3}
};


/*Given a node and a symbol, gives the rank of the symbol within the children of the node.
If the children does not exist, returns -1*/

const int8_t childT[16][4] = {
/*0000*/ {-1, -1, -1, -1},
/*0001*/ {-1, -1, -1,  1},
/*0010*/ {-1, -1,  1, -1},
/*0011*/ {-1, -1,  1,  2},
/*0100*/ {-1,  1, -1, -1},
/*0101*/ {-1,  1, -1,  2},
/*0110*/ {-1,  1,  2, -1},
/*0111*/ {-1,  1,  2,  3},
/*1000*/ { 1, -1, -1, -1},
/*1001*/ { 1, -1, -1,  2},
/*1010*/ { 1, -1,  2, -1},
/*1011*/ { 1, -1,  2,  3},
/*1100*/ { 1,  2, -1, -1},
/*1101*/ { 1,  2, -1,  3},
/*1110*/ { 1,  2,  3, -1},
/*1111*/ { 1,  2,  3,  4}
};

/* given a node in bits (example 1010) and a number(0,1,2,3), give us how the node will be after inserting in that postion
for example insertT[1010][3]=insertT[10][3]=1011 and insertT[1010][0]=insertT[10][0]=1010 */
const int8_t insertT[16][4] = {
/*0000*/ {0x8, 0x4, 0x2, 0x1},
/*0001*/ {0x9, 0x5, 0x3, 0x1},
/*0010*/ {0xa, 0x6, 0x2, 0x3},
/*0011*/ {0xb, 0x7, 0x3, 0x3},
/*0100*/ {0xc, 0x4, 0x6, 0x5},
/*0101*/ {0xd, 0x5, 0x7, 0x5},
/*0110*/ {0xe, 0x6, 0x6, 0x7},
/*0111*/ {0xf, 0x7, 0x7, 0x7},
/*1000*/ {0x8, 0xc, 0xa, 0x9},
/*1001*/ {0x9, 0xd, 0xb, 0x9},
/*1010*/ {0xa, 0xe, 0xa, 0xb},
/*1011*/ {0xb, 0xf, 0xb, 0xb},
/*1100*/ {0xc, 0xc, 0xe, 0xd},
/*1101*/ {0xd, 0xd, 0xf, 0xd},
/*1110*/ {0xe, 0xe, 0xe, 0xf},
/*1111*/ {0xf, 0xf, 0xf, 0xf}
};


//todo: explicar que hace
const uint16_t delNodeInBlockT[4][4] = {
/*xfff*/ {0x7fff, 0xbfff, 0xdfff, 0xefff},
/*fxff*/ {0xf7ff, 0xfbff, 0xfdff, 0xfeff},
/*ffxf*/ {0xff7f, 0xffbf, 0xffdf, 0xffef},
/*fffx*/ {0xfff7, 0xfffb, 0xfffd, 0xfffe},
};


// given a symbol in {0, 1, 2, 3}, yields a unary node representing that symbol
const int8_t symbol2NodeT[4] = {0x8,0x4,0x2,0x1};


//todo: estas tablas creo qe no se usan


/* Table used for insertion. Represents the DFUDS patterns using nibbles
within a byte*/

const uint8_t nibblePattern[2][4] = {{0x80,0x40,0x20,0x10},
                               {0x08,0x04,0x02,0x01}};


const uint8_t firstChildT[16] = {(uint8_t)-1,1,2,1,3,1,2,1,4,1,2,1,3,1,2,1};

// Given the code of a node and a symbol to insert, gives the insertion rank of the symbol

const int8_t childRankT[16][4] = {
/*0000*/ { 1,  1,  1,  1}, 
/*0001*/ { 1,  1,  1, -1},
/*0010*/ { 1,  2, -1,  3},
/*0011*/ { 1,  2, -1, -1},
/*0100*/ { 1, -1,  2,  3},
/*0101*/ { 1, -1,  2, -1},
/*0110*/ { 1, -1, -1,  2},
/*0111*/ { 1, -1, -1, -1},
/*1000*/ {-1,  1,  2,  3}, 
/*1001*/ {-1,  1,  2, -1}, 
/*1010*/ {-1,  1, -1,  2},
/*1011*/ {-1,  1, -1, -1},
/*1100*/ {-1, -1,  1,  2},
/*1101*/ {-1, -1,  1, -1},
/*1110*/ {-1, -1, -1,  1},
/*1111*/ {-1, -1, -1, -1}
};


/*
1) e=0: [0fgh] ->m1=0000 and m2=0fgh; m2<<4=fgh0; m1|m2=fgh0
2) f=0: [e0gh] ->m1=e000 and m2=00gh; m2<<4=0gh0; m1|m2=egh0
3) g=0: [ef0h] ->m1=ef00 and m2=000h; m2<<4=00h0; m1|m2=efh0
4) h=0: [efg0] ->m1=efg0 and m2=0000; m2<<4=0000; m1|m2=efg0
 */

const uint16_t delete0Table1[4] = {0x0000,0xf000,0xff00,0xfff0};
const uint16_t delete0Table2[4] = {0x0fff,0x00ff,0x000f,0x0000};


#endif
