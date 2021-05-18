#include "../treeBlock/treeBlockApi.h"
#include "assert.h"

void testNeighTrie1() {


    blockGlobalVars *bgv = (blockGlobalVars *) malloc(sizeof(blockGlobalVars));
    bgv->init(4, S3, 0.99);

    trieNode *t = (trieNode *) malloc(sizeof(trieNode));
    t->init(bgv);

    uint8_t path0[30] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    insertTrie(t, path0, 23, 22);
    assert(isEdgeTrie(t,path0,23,22));

    uint8_t path1[30] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    insertTrie(t, path1, 23, 22);
    assert(isEdgeTrie(t,path1,23,22));

    int pathLength=23;
    int left=0;
    int right=pow(2,pathLength)-1;
    linkedList* answer=getNeighboursTrie(t,0,23,0,22,left,right,left,right);

    assert(answer->data==0);
    assert(answer->next->data==4194304);


}

void testNeighTrie2() {


    blockGlobalVars *bgv = (blockGlobalVars *) malloc(sizeof(blockGlobalVars));
    bgv->init(4, S3, 0.99);

    trieNode *t = (trieNode *) malloc(sizeof(trieNode));
    t->init(bgv);

    uint8_t path0[30] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    insertTrie(t, path0, 23, 22);
    assert(isEdgeTrie(t,path0,23,22));

    uint8_t path1[30] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    insertTrie(t, path1, 23, 22);
    assert(isEdgeTrie(t,path1,23,22));

    int pathLength=23;
    int left=0;
    int right=pow(2,pathLength)-1;
    linkedList* answer=getNeighboursTrie(t,0,23,0,22,left,right,left,right);

    assert(answer->data==0);
    assert(answer->next->data==1);
}

void testNeighTrie3() {


    blockGlobalVars *bgv = (blockGlobalVars *) malloc(sizeof(blockGlobalVars));
    bgv->init(4, S3, 0.99);

    trieNode *t = (trieNode *) malloc(sizeof(trieNode));
    t->init(bgv);

    uint8_t path0[30] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    insertTrie(t, path0, 23, 22);

    uint8_t path1[30] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    insertTrie(t, path1, 23, 22);

    uint8_t path2[30] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0};
    insertTrie(t, path2, 23, 22);

    uint8_t path3[30] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1};
    insertTrie(t, path3, 23, 22);

    int pathLength=23;
    int left=0;
    int right=pow(2,pathLength)-1;
    linkedList* answer=getNeighboursTrie(t,0,23,0,22,left,right,left,right);

    int i=0;

    while(answer!=NULL){
        assert(answer->data==i);
        answer=answer->next;
        i++;
    }



}

void testNeighTrie4() {


    blockGlobalVars *bgv = (blockGlobalVars *) malloc(sizeof(blockGlobalVars));
    bgv->init(4, S3, 0.99);

    trieNode *t = (trieNode *) malloc(sizeof(trieNode));
    t->init(bgv);

    uint8_t path0[30] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    insertTrie(t, path0, 23, 22);

    uint8_t path1[30] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    insertTrie(t, path1, 23, 22);

    uint8_t path2[30] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0};
    insertTrie(t, path2, 23, 22);

    uint8_t path3[30] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1};
    insertTrie(t, path3, 23, 22);

    int pathLength=23;
    int left=0;
    int right=pow(2,pathLength)-1;
    linkedList* answer=getNeighboursTrie(t,1,23,0,22,left,right,left,right);

    assert(answer==NULL);

}

void testNeighTrie5() {


    blockGlobalVars *bgv = (blockGlobalVars *) malloc(sizeof(blockGlobalVars));
    bgv->init(4, S3, 0.99);

    trieNode *t = (trieNode *) malloc(sizeof(trieNode));
    t->init(bgv);

    uint8_t path0[30] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2};
    insertTrie(t, path0, 23, 22);

    uint8_t path1[30] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3};
    insertTrie(t, path1, 23, 22);

    uint8_t path2[30] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2};
    insertTrie(t, path2, 23, 22);

    uint8_t path3[30] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3};
    insertTrie(t, path3, 23, 22);

    int pathLength=23;
    int left=0;
    int right=pow(2,pathLength)-1;
    linkedList* answer=getNeighboursTrie(t,1,23,0,22,left,right,left,right);

    int i=0;

    while(answer!=NULL){
        assert(answer->data==i);
        answer=answer->next;
        i++;
    }

}


int main(){

    testNeighTrie1();
    testNeighTrie2();
    testNeighTrie3();
    testNeighTrie4();
    testNeighTrie5();
    return 0;
}

