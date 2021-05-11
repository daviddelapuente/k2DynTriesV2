// Transform a node from it pair <NODE_TYPE,OFFSET_TYPE> to it absolute representation (position) in DFUDS
uint16_t absolutePosition(treeNode &node){
return 4*node.first + node.second;
}

/*give the next node in the dfuds.
for example, if your node is <1,1> it absolute position will be 5
then the next node will be <1,2> because it absolute position will be 6*/
inline void nextNode(treeNode &node){
//this is like (second+1)%4
node.second = (node.second+1) & 0x3;
//this sum 1 <=> node.second=0, and will sum 0 in an ohter case
node.first += !node.second;
}

/*give the previous node in the dfuds.
for example, if your node is <1,0> it absolute position will be 4
then the next node will be <0,3> because it absolute position will be 3*/
inline void prevNode(treeNode &node){
//only subtract 1 if node.second=0
node.first -= !node.second;
//this is like (second-1)%4
node.second = (node.second-1) & 0x3;
}


void babToBin(uint16_t a){
    uint16_t n=a;
    uint16_t mask=0x8000;
    uint16_t mask2=0x7fff;
    int c=16;
    while (c) {
        if (n & mask) {
            printf("1");
        }else {
            printf("0");
        }
        n = n&mask2;
        mask >>=1;
        mask2 >>=1;
        c--;
    }
    printf("\n");

}




/*this function consume the string that represent the morton code, until the path it represent finished
finally call a function that insert the new path in a block*/
//todo: consideraria cambiarle el nombre a esta funcion, y a las demas inserts
void insertar(treeBlock *root, uint8_t *str, uint64_t length, uint16_t level, uint16_t maxDepth){

    //curBlock is pointing to the root because we will start in that point. curBlockAux is a pointer we will use to decend the tree
    treeBlock *curBlock = root, *curBlockAux;
    //set a dummy treeNode, and an aux pointer to descend the tree
    treeNode curNode(0,0), curNodeAux;
    //dummy flag
    uint16_t curFlag = 0;

    //for every char of the string (the morton code) until we find the part were the path does not exist
    uint64_t i;
    for (i = 0; i < length; ++i) {

        //we get the child using the morton code char (str[i])
        curBlockAux = curBlock;
        curNodeAux = curBlock->child(curBlock, curNode, str[i], level, maxDepth, curFlag);

        //if the child function returned a treeNode with a -1, that means that the path does not exist. so we break here.
        if (curNodeAux.first == (NODE_TYPE)-1) {
            break;
        }
        else {
            //else, we update the curNode
            curNode = curNodeAux;
        }

        //if we are in a fronteir node
        if (curBlock->nPtrs > 0 && absolutePosition(curNode) == curFlag) {
            // we go to the block where the flag is pointing
            curBlock = curBlock->getPointer(curFlag);
            //and reset the treeNode (because we will start in a new block)
            curNode.first = 0;
            curNode.second = 0;
        }
    }

    /*
    the for cycle will stop at some i where the path does not exist
    so we have to inserts str[i..length-1] starting from the current node
    The new nodes inserted will descend from curNode*/
    curBlock->insert(curNode, &str[i], length-i, level, maxDepth, curFlag);
}


//this will create and insert the respective nodes in the trie and in the treeBlocks
void insertTrie(trieNode *t, uint8_t *str, uint64_t length, uint16_t maxDepth){
    blockGlobalVars * bgv=t->bgv;
    //this will consume the string until a children does not exist.
    //this will leave i as the position in str from where the path does not exist or if the path continue in a treeBlock
    uint64_t i = 0;
    while (t->children[str[i]]){
        t = t->children[str[i++]];
    }


    //if i<L1 we insert it uncompressed
    while (i < L1) {
        //create a new trieNode
        t->children[str[i]] = (trieNode *)malloc(sizeof(trieNode));
        t = t->children[str[i]];
        //go to next i
        i++;
        t->children[0] = t->children[1] = t->children[2] = t->children[3] = NULL;
        t->block = NULL;
        t->bgv=bgv;
    }


    //border case: we have that t (with i>L) is null (because that block was create recently)
    // this always pass when the previous while stop when i=L1
    treeBlock *p;
    p = (treeBlock *) t->block;
    if (t->block == NULL) {
        //we create the treeBlock
        t->block = malloc(sizeof(treeBlock));
        p = (treeBlock*)t->block;
        p->dfuds = (uint16_t *)calloc(2, sizeof(uint16_t));
        p->rootDepth = L1;
        p->nNodes = 1;
        p->ptr = NULL;
        p->nPtrs = 0;
        p->maxNodes = 4;
        p->bgv=bgv;
    }else{
        //if the block exist, we assign it to p
        p = (treeBlock *) t->block;
    }

    //we call insertar, that will insert the remaining string str[i...length(str)}
    //in treeBlocks
    insertar(p, &str[i], length-i, i, maxDepth);
}





//return true if the string str is a path in a block
bool isEdge(treeBlock *root, uint8_t *str, uint64_t length, uint16_t level, uint16_t maxDepth){

    //curBlock is pointing to the root because we will start in that point. curBlockAux is a pointer we will use to decend the tree
    treeBlock *curBlock = root, *curBlockAux;
    //set a dummy treeNode, and an aux pointer to descend the tree
    treeNode curNode(0,0), curNodeAux;
    //dummy flag
    uint16_t curFlag = 0;

    //for each char in the string
    uint64_t i;
    for (i = 0; i < length; ++i) {
        //we will get the child in function of the simbol str[i}
        curBlockAux = curBlock;
        curNodeAux = curBlock->child(curBlock, curNode, str[i], level, maxDepth, curFlag);

        //if the child is a -1, that means that the path does not exist, so we break
        if (curNodeAux.first == (NODE_TYPE)-1){
            break;
        }
        else {
            //if not, we continue
            curNode = curNodeAux;
        }

        //if we are in a frontier node, we need to go down to the corresponding block
        if (curBlock->nPtrs > 0 && absolutePosition(curNode) == curFlag) {
            // Goes down to a child block
            curBlock = curBlock->getPointer(curFlag);
            curNode.first = 0;
            curNode.second = 0;
        }
    }

    /*finally we return i==length that means: if we broke the previous cycle, the path does not exist*/
    return length == i;
}



//todo: consideraria cambiarle el nombre
//return true if the path represented with the str, is in the trie (and in the tree)
bool isEdgeTrie(trieNode *t, uint8_t *str, uint64_t length, uint16_t maxDepth) {

    //this will consume the string until a children does not exist.
    //this will leave i as the position in str from where the path does not exist or if the path continue in a treeBlock
    uint64_t i = 0;
    while (t->children[str[i]] && !t->block) {
        t = t->children[str[i++]];
    }

    /*instantiate p as the block of t (if it does not exist, then return false, but if exist, that means that exist in a treeBlock so we call
    isEdge to continue searching in the blocks)*/
    treeBlock *p= (treeBlock *) t->block;
    if (p) {
        return isEdge(p, &str[i], length - i, i, maxDepth);
    } else {
        return false;
    }
}


//return the size of the whole trie
uint64_t sizeTrie(trieNode *t){

    //base case: if the pointer is null return 0
    if (!t) {
        return 0;
    }

    //if we use up to 8 levels of pointers. the pointers can implemented with 16 bits
    //todo: me tinca que podemos cambiar esta parte para que la funcion size venga de la estructura, y que no este harcodeada
    //this is the size of the actual trie
    uint64_t totalSize = 4*sizeof(uint16_t);

    //if we are not a treeBlock
    if (!t->block) {
        //we sum the the size of the children tries
        totalSize += sizeTrie(t->children[0]);
        totalSize += sizeTrie(t->children[1]);
        totalSize += sizeTrie(t->children[2]);
        totalSize += sizeTrie(t->children[3]);
    }else{
        //if we are a treeBlock, we sum the size of the treeBlock
        totalSize += ((treeBlock *)t->block)->size();
    }
    //return the total sum
    return totalSize;
}


void printDfuds(uint16_t *A,int n){
    printf("dfuds");
    for(int i=0;i<n;i++){
        babToBin(A[i]);
    }
    printf("\n");
}

void f(uint16_t a){
    uint16_t n=a;
    uint16_t mask=0x8000;
    uint16_t mask2=0x7fff;
    int c=16;
    while (c) {
        if (n & mask) {
            printf("1");
        }else {
            printf("0");
        }
        n = n&mask2;
        mask >>=1;
        mask2 >>=1;
        c--;
    }

}


void printDfuds2(uint16_t *A,int n){
    printf("dfuds\n");
    for(int i=0;i<n;i++){
        printf(" ");
        f(A[i]);
    }
    printf("\n");
}


uint16_t table[4] = {0x0fff, 0xf0ff, 0xff0f, 0xfff0};

void deleteZeros(uint16_t * A,int n){
    int zeroIndex = 0;
    for (int actualIndex = 0; actualIndex < 4 * n; actualIndex++){
        uint16_t actualNumber = A[actualIndex / 4];
        actualNumber <<= (actualIndex % 4) * 4;
        actualNumber >>= 3 * 4;
        if (actualNumber != 0)
        {
            uint16_t aux = actualNumber;
            uint16_t zeroAux = A[zeroIndex / 4];
            zeroAux <<= (zeroIndex % 4) * 4;
            zeroAux >>= 3 * 4;

            A[actualIndex / 4] = A[actualIndex / 4] & table[actualIndex % 4] | (zeroAux << (4 * (3 - (actualIndex % 4))));
            A[zeroIndex / 4] = A[zeroIndex / 4] & table[zeroIndex % 4] | (aux << (4 * (3 - (zeroIndex % 4))));
            zeroIndex++;
        }
    }
}

void shift1(uint16_t *A, int n, int i, int j){
    int actualPos = 4 * i + j;
    for (int i2 = actualPos; i2 < (4 * n) - 1; i2++)
    {
        int newPos = i2 + 1;
        uint16_t newaux = A[newPos/4];
        newaux=newaux>>shiftT[newPos%4]&0x000f;
        newaux=newaux<<shiftT[i2%4];

        A[i2/4]=A[i2/4]&table[i2%4]|newaux;
    }
    A[n-1]= A[n-1]&0xfff0;
}

void deleteZeros2(uint16_t *A,int n){

    int c = 4 * n;
    int i = 0;
    while (c){
        uint16_t aux=A[i/4];
        aux=aux>>shiftT[i%4]&0x000f;
        if (aux == 0){
            shift1(A, n, i / 4, i % 4);
        }
        else{
            i++;
        }
        c--;
    }
}

void printTreePathStack(uint8_t *st,int index){
    printf("pathStackIndex = %u\n",index);
    printf("pathStack =\n");
    for(int i=0;i<index;i++){
        printf("%u ",st[i]);
    }
    printf("\n");
}

void printNodesInBlockStack(uint8_t *st,int index){
    printf("NodesInBlockStack index = %u\n",index);
    printf("printNodesInBlockStack =\n");
    for(int i=0;i<=index;i++){
        printf("%u ",st[i]);
    }
    printf("\n");
}

void blockInspectFrontiers(treeBlock *root){
    if(root==NULL){
        return;
    }
    if(root->nPtrs==0){
        return;
    }
    for(int k=0;k<root->nPtrs;k++){
        printf("%u ",((blockPtr *)root->ptr)[k].flag);
    }
    printf("\n");
    for(int k=0;k<root->nPtrs;k++){
        blockInspectFrontiers(((blockPtr *)root->ptr)[k].P);
    }



}

void trieInspectFrontiers(trieNode *t){
    if(t==NULL){
        return;
    }
    trieInspectFrontiers(t->children[0]);
    trieInspectFrontiers(t->children[1]);
    trieInspectFrontiers(t->children[2]);
    trieInspectFrontiers(t->children[3]);
    blockInspectFrontiers((treeBlock*)t->block);
}