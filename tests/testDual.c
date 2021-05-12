#include "../treeBlock/treeBlockApi.h"
#include "assert.h"

void test100Deterministic1(){


    blockGlobalVars *bgv=(blockGlobalVars*) malloc(sizeof(blockGlobalVars));
    bgv->init(4,S3,0.99);

    trieNode *t = (trieNode *) malloc(sizeof(trieNode));
    t->init(bgv);

    blockGlobalVars *bgv2=(blockGlobalVars*) malloc(sizeof(blockGlobalVars));
    bgv2->init(4,S3,0.99);

    trieNode *t2 = (trieNode *) malloc(sizeof(trieNode));
    t2->init(bgv2);

    long long c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        insertTrie(t, path, 23, 22);
        insertTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=50){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        deleteTrie(t, path, 23, 22);
        deleteTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        if(c<=50){
            assert(!isEdgeTrie(t,path,23,22));
            assert(!isEdgeTrie(t2,path,23,22));
        }else{
            assert(isEdgeTrie(t,path,23,22));
            assert(isEdgeTrie(t2,path,23,22));
        }
        c++;
    }

    c=0;
    while(c<=50){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        insertTrie(t, path, 23, 22);
        insertTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        assert(isEdgeTrie(t,path,23,22));
        assert(isEdgeTrie(t2,path,23,22));
        c++;
    }

    c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        deleteTrie(t, path, 23, 22);
        deleteTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        assert(!isEdgeTrie(t,path,23,22));
        assert(!isEdgeTrie(t2,path,23,22));
        c++;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        insertTrie(t, path, 23, 22);
        insertTrie(t2, path, 23, 22);
        c++;
    }

    c=78;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        deleteTrie(t, path, 23, 22);
        deleteTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        if(c>=78){
            assert(!isEdgeTrie(t,path,23,22));
            assert(!isEdgeTrie(t2,path,23,22));
        }else{
            assert(isEdgeTrie(t,path,23,22));
            assert(isEdgeTrie(t2,path,23,22));
        }
        c++;
    }

    c=78;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        insertTrie(t, path, 23, 22);
        insertTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        assert(isEdgeTrie(t,path,23,22));
        assert(isEdgeTrie(t2,path,23,22));
        c++;
    }

    c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        deleteTrie(t, path, 23, 22);
        deleteTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        assert(!isEdgeTrie(t,path,23,22));
        assert(!isEdgeTrie(t2,path,23,22));
        c++;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        insertTrie(t, path, 23, 22);
        insertTrie(t2, path, 23, 22);
        c++;
    }

    c=31;
    while(c<=63){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        deleteTrie(t, path, 23, 22);
        deleteTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        if(31<=c && c<=63){
            assert(!isEdgeTrie(t,path,23,22));
            assert(!isEdgeTrie(t2,path,23,22));
        }else{
            assert(isEdgeTrie(t,path,23,22));
            assert(isEdgeTrie(t2,path,23,22));
        }
        c++;
    }

    c=31;
    while(c<=63){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        insertTrie(t, path, 23, 22);
        insertTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        assert(isEdgeTrie(t,path,23,22));
        assert(isEdgeTrie(t2,path,23,22));
        c++;
    }

    c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        deleteTrie(t, path, 23, 22);
        deleteTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=100){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        assert(!isEdgeTrie(t,path,23,22));
        assert(!isEdgeTrie(t2,path,23,22));
        c++;
    }

}


void test1000000Deterministic1(){

    blockGlobalVars *bgv=(blockGlobalVars*) malloc(sizeof(blockGlobalVars));
    bgv->init(4,S3,0.99);

    trieNode *t = (trieNode *) malloc(sizeof(trieNode));
    t->init(bgv);

    blockGlobalVars *bgv2=(blockGlobalVars*) malloc(sizeof(blockGlobalVars));
    bgv2->init(4,S3,0.99);

    trieNode *t2 = (trieNode *) malloc(sizeof(trieNode));
    t2->init(bgv2);


    long long c=0;
    while(c<=1000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        insertTrie(t, path, 23, 22);
        insertTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=327888){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        deleteTrie(t, path, 23, 22);
        deleteTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=1000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        if(c<=327888){
            assert(!isEdgeTrie(t,path,23,22));
            assert(!isEdgeTrie(t2,path,23,22));
        }else{
            assert(isEdgeTrie(t,path,23,22));
            assert(isEdgeTrie(t2,path,23,22));
        }
        c++;
    }

    c=0;
    while(c<=327888){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        insertTrie(t, path, 23, 22);
        insertTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=1000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        assert(isEdgeTrie(t,path,23,22));
        assert(isEdgeTrie(t2,path,23,22));
        c++;
    }

    c=0;
    while(c<=1000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        deleteTrie(t, path, 23, 22);
        deleteTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=1000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        assert(!isEdgeTrie(t,path,23,22));
        assert(!isEdgeTrie(t2,path,23,22));
        c++;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    c=0;
    while(c<=1000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        insertTrie(t, path, 23, 22);
        insertTrie(t2, path, 23, 22);
        c++;
    }

    c=388999;
    while(c<=1000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        deleteTrie(t, path, 23, 22);
        deleteTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=1000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        if(c>=388999){
            assert(!isEdgeTrie(t,path,23,22));
            assert(!isEdgeTrie(t2,path,23,22));
        }else{
            assert(isEdgeTrie(t,path,23,22));
            assert(isEdgeTrie(t2,path,23,22));
        }
        c++;
    }

    c=388999;
    while(c<=1000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        insertTrie(t, path, 23, 22);
        insertTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=1000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        assert(isEdgeTrie(t,path,23,22));
        assert(isEdgeTrie(t2,path,23,22));
        c++;
    }

    c=0;
    while(c<=1000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        deleteTrie(t, path, 23, 22);
        deleteTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=1000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        assert(!isEdgeTrie(t,path,23,22));
        assert(!isEdgeTrie(t2,path,23,22));
        c++;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    c=0;
    while(c<=1000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        insertTrie(t, path, 23, 22);
        insertTrie(t2, path, 23, 22);
        c++;
    }

    c=177356;
    while(c<=555777){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        deleteTrie(t, path, 23, 22);
        deleteTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=1000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        if(177356<=c && c<=555777){
            assert(!isEdgeTrie(t,path,23,22));
            assert(!isEdgeTrie(t2,path,23,22));
        }else{
            assert(isEdgeTrie(t,path,23,22));
            assert(isEdgeTrie(t2,path,23,22));
        }
        c++;
    }

    c=177356;
    while(c<=555777){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        insertTrie(t, path, 23, 22);
        insertTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=1000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        assert(isEdgeTrie(t,path,23,22));
        assert(isEdgeTrie(t2,path,23,22));
        c++;
    }

    c=0;
    while(c<=1000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        deleteTrie(t, path, 23, 22);
        deleteTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=1000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        assert(!isEdgeTrie(t,path,23,22));
        assert(!isEdgeTrie(t2,path,23,22));
        c++;
    }



}



void test5MDeterministic1(){



    blockGlobalVars *bgv=(blockGlobalVars*) malloc(sizeof(blockGlobalVars));
    bgv->init(4,S3,0.99);

    trieNode *t = (trieNode *) malloc(sizeof(trieNode));
    t->init(bgv);

    blockGlobalVars *bgv2=(blockGlobalVars*) malloc(sizeof(blockGlobalVars));
    bgv2->init(4,S3,0.99);

    trieNode *t2 = (trieNode *) malloc(sizeof(trieNode));
    t2->init(bgv2);


    long long c=0;
    while(c<=5000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/4194304)%4),(uint8_t) ((c/1048576)%4),(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        insertTrie(t, path, 23, 22);
        insertTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=3485955){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/4194304)%4),(uint8_t) ((c/1048576)%4),(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        deleteTrie(t, path, 23, 22);
        deleteTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=5000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/4194304)%4),(uint8_t) ((c/1048576)%4),(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        if(c<=3485955){
            assert(!isEdgeTrie(t,path,23,22));
            assert(!isEdgeTrie(t2,path,23,22));
        }else{
            assert(isEdgeTrie(t,path,23,22));
            assert(isEdgeTrie(t2,path,23,22));
        }
        c++;
    }

    c=0;
    while(c<=3485955){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/4194304)%4),(uint8_t) ((c/1048576)%4),(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        insertTrie(t, path, 23, 22);
        insertTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=5000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/4194304)%4),(uint8_t) ((c/1048576)%4),(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        assert(isEdgeTrie(t,path,23,22));
        assert(isEdgeTrie(t2,path,23,22));
        c++;
    }

    c=0;
    while(c<=5000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/4194304)%4),(uint8_t) ((c/1048576)%4),(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        deleteTrie(t, path, 23, 22);
        deleteTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=5000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/4194304)%4),(uint8_t) ((c/1048576)%4),(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        assert(!isEdgeTrie(t,path,23,22));
        assert(!isEdgeTrie(t,path,23,22));
        c++;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    c=0;
    while(c<=5000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/4194304)%4),(uint8_t) ((c/1048576)%4),(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        insertTrie(t, path, 23, 22);
        insertTrie(t2, path, 23, 22);
        c++;
    }

    c=1000000;
    while(c<=5000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/4194304)%4),(uint8_t) ((c/1048576)%4),(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        deleteTrie(t, path, 23, 22);
        deleteTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=5000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/4194304)%4),(uint8_t) ((c/1048576)%4),(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        if(c>=1000000){
            assert(!isEdgeTrie(t,path,23,22));
            assert(!isEdgeTrie(t,path,23,22));
        }else{
            assert(isEdgeTrie(t,path,23,22));
            assert(isEdgeTrie(t2,path,23,22));
        }
        c++;
    }

    c=1000000;
    while(c<=5000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/4194304)%4),(uint8_t) ((c/1048576)%4),(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        insertTrie(t, path, 23, 22);
        insertTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=5000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/4194304)%4),(uint8_t) ((c/1048576)%4),(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        assert(isEdgeTrie(t,path,23,22));
        assert(isEdgeTrie(t2,path,23,22));
        c++;
    }

    c=0;
    while(c<=5000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/4194304)%4),(uint8_t) ((c/1048576)%4),(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        deleteTrie(t, path, 23, 22);
        deleteTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=5000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/4194304)%4),(uint8_t) ((c/1048576)%4),(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        assert(!isEdgeTrie(t,path,23,22));
        assert(!isEdgeTrie(t,path,23,22));
        c++;
    }



    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    c=0;
    while(c<=5000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/4194304)%4),(uint8_t) ((c/1048576)%4),(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        insertTrie(t, path, 23, 22);
        insertTrie(t2, path, 23, 22);
        c++;
    }

    c=200000;
    while(c<=4800000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/4194304)%4),(uint8_t) ((c/1048576)%4),(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        deleteTrie(t, path, 23, 22);
        deleteTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=5000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/4194304)%4),(uint8_t) ((c/1048576)%4),(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        if(200000<=c && c<=4800000){
            assert(!isEdgeTrie(t,path,23,22));
            assert(!isEdgeTrie(t,path,23,22));
        }else{
            assert(isEdgeTrie(t,path,23,22));
            assert(isEdgeTrie(t2,path,23,22));
        }
        c++;
    }

    c=200000;
    while(c<=4800000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/4194304)%4),(uint8_t) ((c/1048576)%4),(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        insertTrie(t, path, 23, 22);
        insertTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=5000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/4194304)%4),(uint8_t) ((c/1048576)%4),(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        assert(isEdgeTrie(t,path,23,22));
        assert(isEdgeTrie(t2,path,23,22));
        c++;
    }

    c=0;
    while(c<=5000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/4194304)%4),(uint8_t) ((c/1048576)%4),(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        deleteTrie(t, path, 23, 22);
        deleteTrie(t2, path, 23, 22);
        c++;
    }

    c=0;
    while(c<=5000000){
        uint8_t path[30]={0,0,0,0,0,0,0,0,0,0,0,(uint8_t) ((c/4194304)%4),(uint8_t) ((c/1048576)%4),(uint8_t) ((c/262144)%4),(uint8_t) ((c/65536)%4),(uint8_t) ((c/16384)%4),(uint8_t) ((c/4096)%4),(uint8_t) ((c/1024)%4),(uint8_t) ((c/256)%4),(uint8_t) ((c/64)%4),(uint8_t) ((c/16)%4),(uint8_t) ((c/4)%4),(uint8_t) (c%4)};
        assert(!isEdgeTrie(t,path,23,22));
        assert(!isEdgeTrie(t,path,23,22));
        c++;
    }
}


int main(){
    test100Deterministic1();
    test1000000Deterministic1();
    test5MDeterministic1();
    printf("congratulations, all test passed in\n");
    return 0;
}