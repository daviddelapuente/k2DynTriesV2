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

// Global table that stores the sizes of the blocks, used for growing them
uint16_t *sizeArray; // array of sizes

// Minimum and maximum block sizes
uint16_t N1;
uint16_t Nt;

//our modules
#include "preComputedTables.h"
#include "globalConstants.h"
#include "subtreeInfo.h"
#include "nodeInfo.h"
#include "treeNode.h"
#include "blockGlobalVars.h"
#include "trieNode.h"
#include "treeBlock.h"
#include "blockPtr.h"



#endif
