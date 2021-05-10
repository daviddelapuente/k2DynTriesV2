#include "../../materializeSuite.c"
#include "assert.h"

// !! important !! dont forget to clean the materializaion field. and create empty directories for each trie (A1 and A2)
//if you dont do that, this test will probably fail or get a segmentation fault
//if you do it right, you can check the materialization field to see results.


//this function will test the materialization of a Trie
void testDeletion2(){
    //first we instanciate the trie

    trieNode *t2 = (trieNode *) malloc(sizeof(trieNode));
    t2->children[0] = t2->children[1] = t2->children[2] = t2->children[3] = NULL;
    t2->block = NULL;



    double alpha = 0.99;
    N1 = 4;
    Nt = S3;
    sizeArray = (uint16_t *) malloc(sizeof(uint16_t)*(Nt+1));
    for (int i = 0; i <= Nt; ++i) {
        if (i > N1) N1 = 4*(((uint16_t)ceil((double)N1/alpha)+3)/4);
        sizeArray[i] = N1;
    }
    //now we inert the first 65536 points (in fourth base)
    long long c=1;



    c=0;
    while(c<=305){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        //uint8_t path[30]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        insertTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=305){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        //uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1,2,3};
        deleteTrie(t2, path, 23, 22);
        c++;
    }


    //treeBlock *actualBlock= (treeBlock*)t2->children[0]->children[0]->children[0]->children[0]->children[0]->children[0]->children[0]->children[0]->block;

    //printDfuds2(actualBlock->dfuds,actualBlock->maxNodes/4);


    char srcFolder2[] = "../materializeField/A2/";
    materializeTrie(t2,srcFolder2);

}

void dummyTest(){
    uint16_t A[3]={0xf0f0,0x00f0,0x00f0};
    deleteZeros2(A,3);
    for(int i=0;i<3;i++){
        babToBin(A[i]);
    }
}

void testDeletion(){
    //first we instanciate the trie
    trieNode *t = (trieNode *) malloc(sizeof(trieNode));
    t->children[0] = t->children[1] = t->children[2] = t->children[3] = NULL;
    t->block = NULL;


    double alpha = 0.99;
    N1 = 4;
    Nt = S3;
    sizeArray = (uint16_t *) malloc(sizeof(uint16_t)*(Nt+1));
    for (int i = 0; i <= Nt; ++i) {
        if (i > N1) N1 = 4*(((uint16_t)ceil((double)N1/alpha)+3)/4);
        sizeArray[i] = N1;
    }
    //now we inert the first 65536 points (in fourth base)
    long long c=1;



    c=191;
    while(c<=296){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        //uint8_t path[30]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        insertTrie(t, path, 23, 22);
        c++;
    }





    char srcFolder2[] = "../materializeField/A1/";
    materializeTrie(t,srcFolder2);

}


//test deletion in a block in a deep level
void testDeletion3(){

    trieNode *t = (trieNode *) malloc(sizeof(trieNode));
    t->children[0] = t->children[1] = t->children[2] = t->children[3] = NULL;
    t->block = NULL;

    double alpha = 0.99;
    N1 = 4;
    Nt = S3;
    sizeArray = (uint16_t *) malloc(sizeof(uint16_t)*(Nt+1));
    for (int i = 0; i <= Nt; ++i) {
        if (i > N1) N1 = 4*(((uint16_t)ceil((double)N1/alpha)+3)/4);
        sizeArray[i] = N1;
    }
    //now we inert the first 65536 points (in fourth base)
    long long c=0;
    while(c<=500){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        //uint8_t path[30]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        insertTrie(t, path, 23, 22);
        c++;
    }

    c=5;
    while(c<=5){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        //uint8_t path[30]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        deleteTrie(t, path, 23, 22);
        c++;
    }


    c=0;
    while(c<=500){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        //uint8_t path[30]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        if(c!=5){
            assert(isEdgeTrie(t,path,23,22));
        }else{
            assert(!isEdgeTrie(t,path,23,22));
        }
        c++;
    }


    //now we materialize the trie in ../materializeFie/A1
    char srcFolder[] = "../materializeField/A2/";
    materializeTrie(t,srcFolder);
}

void testDeletion4(){
    trieNode *t = (trieNode *) malloc(sizeof(trieNode));
    t->children[0] = t->children[1] = t->children[2] = t->children[3] = NULL;
    t->block = NULL;

    double alpha = 0.99;
    N1 = 4;
    Nt = S3;
    sizeArray = (uint16_t *) malloc(sizeof(uint16_t)*(Nt+1));
    for (int i = 0; i <= Nt; ++i) {
        if (i > N1) N1 = 4*(((uint16_t)ceil((double)N1/alpha)+3)/4);
        sizeArray[i] = N1;
    }
    //now we inert the first 65536 points (in fourth base)
    long long c=0;
    while(c<=2000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        //uint8_t path[30]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        insertTrie(t, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=2000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        //uint8_t path[30]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        deleteTrie(t, path, 23, 22);
        c++;
    }





    //now we materialize the trie in ../materializeFie/A1
    char srcFolder[] = "../materializeField/A2/";
    materializeTrie(t,srcFolder);
}

void testDeletion5(){
    trieNode *t = (trieNode *) malloc(sizeof(trieNode));
    t->children[0] = t->children[1] = t->children[2] = t->children[3] = NULL;
    t->block = NULL;

    double alpha = 0.99;
    N1 = 4;
    Nt = S3;
    sizeArray = (uint16_t *) malloc(sizeof(uint16_t)*(Nt+1));
    for (int i = 0; i <= Nt; ++i) {
        if (i > N1) N1 = 4*(((uint16_t)ceil((double)N1/alpha)+3)/4);
        sizeArray[i] = N1;
    }
    //now we inert the first 65536 points (in fourth base)
    long long c=0;
    while(c<=2000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        //uint8_t path[30]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        insertTrie(t, path, 23, 22);
        c++;
    }


    //now we materialize the trie in ../materializeFie/A1
    char srcFolder[] = "../materializeField/A2/";
    materializeTrie(t,srcFolder);
}
int main(){
    testDeletion4();

    //dummyTest();
    printf("congratulations, all test passed\n");
    return 0;
}