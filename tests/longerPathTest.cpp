#include "../treeBlock/treeBlockApi.h"
#include "assert.h"

void testPath23(){

    blockGlobalVars *bgv=(blockGlobalVars*) malloc(sizeof(blockGlobalVars));
    bgv->init(4,S3,0.99);

    trieNode *t = (trieNode *) malloc(sizeof(trieNode));
    t->init(bgv);

    long long c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        insertTrie(t, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=50){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        deleteTrie(t, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        if(c<=50){
            assert(!isEdgeTrie(t,path,23,22));
        }else{
            assert(isEdgeTrie(t,path,23,22));
        }
        c++;
    }

    c=0;
    while(c<=50){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        insertTrie(t, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        assert(isEdgeTrie(t,path,23,22));
        c++;
    }

    c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        deleteTrie(t, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        assert(!isEdgeTrie(t,path,23,22));
        c++;
    }
    printf("testpath23 passed\n");
}

void testPath24(){
    blockGlobalVars *bgv=(blockGlobalVars*) malloc(sizeof(blockGlobalVars));
    bgv->init(4,S3,0.99);

    trieNode *t = (trieNode *) malloc(sizeof(trieNode));
    t->init(bgv);


    long long c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        insertTrie(t, path, 24, 23);
        c++;
    }

    c=0;
    while(c<=50){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        deleteTrie(t, path, 24, 23);
        c++;
    }

    c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        if(c<=50){
            assert(!isEdgeTrie(t,path,24,23));
        }else{
            assert(isEdgeTrie(t,path,24,23));
        }
        c++;
    }

    c=0;
    while(c<=50){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        insertTrie(t, path, 24, 23);
        c++;
    }

    c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        assert(isEdgeTrie(t,path,24,23));
        c++;
    }

    c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        deleteTrie(t, path, 24, 23);
        c++;
    }

    c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        assert(!isEdgeTrie(t,path,24,23));
        c++;
    }
    printf("testpath24 passed\n");

}

void testPath25(){
    blockGlobalVars *bgv=(blockGlobalVars*) malloc(sizeof(blockGlobalVars));
    bgv->init(4,S3,0.99);

    trieNode *t = (trieNode *) malloc(sizeof(trieNode));
    t->init(bgv);


    long long c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        insertTrie(t, path, 25, 24);
        c++;
    }

    c=0;
    while(c<=50){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        deleteTrie(t, path, 25, 24);
        c++;
    }

    c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        if(c<=50){
            assert(!isEdgeTrie(t,path,25,24));
        }else{
            assert(isEdgeTrie(t,path,25,24));
        }
        c++;
    }

    c=0;
    while(c<=50){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        insertTrie(t, path, 25, 24);
        c++;
    }

    c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        assert(isEdgeTrie(t,path,25,24));
        c++;
    }

    c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        deleteTrie(t, path, 25, 24);
        c++;
    }

    c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        assert(!isEdgeTrie(t,path,25,24));
        c++;
    }
    printf("testpath25 passed\n");

}


int main(){
    testPath23();
    testPath24();
    testPath25();
    printf("congratulations, all test passed in\n");
    return 0;
}