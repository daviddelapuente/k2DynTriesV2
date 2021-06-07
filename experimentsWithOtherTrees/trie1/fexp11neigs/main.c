#include "assert.h"
#include "../../../treeBlock/treeBlockApi.h"


int a(uint8_t path[],int pathLength){
    int ri=0;
    int rf=pow(2,pathLength)-1;

    int i=0;
    int medio;
    while(ri<rf){
        if(i>=pathLength){
            printf("ups error in a\n");
            assert(1==0);
        }
        medio=(ri+rf)/2;
        if(path[i]<=1){
            rf=medio;
        }else{
            ri=medio +1;
        }
        i++;
    }

    return ri;
}

int b(uint8_t path[],int pathLength){

    int ri=0;
    int rf=pow(2,pathLength)-1;;

    int i=0;
    int medio;
    while(ri<rf){
        if(i>=pathLength){
            printf("ups error in b\n");
            assert(1==0);
        }
        medio=(ri+rf)/2;
        if(path[i]%2==0){
            rf=medio;
        }else{
            ri=medio +1;
        }
        i++;
    }
    return ri;
}

int * ab(uint8_t path[],int pathLength){
    static int node[2];
    node[0]=a(path,pathLength);
    node[1]=b(path,pathLength);
    return node;
}

int main(){

    //scan int code
    int scanCode;



    blockGlobalVars *bgv=(blockGlobalVars*) malloc(sizeof(blockGlobalVars));
    bgv->init(4,S3,0.99);

    //we init the trieNode that will contain all the edges
    trieNode *t = (trieNode *) malloc(sizeof(trieNode));
    t->init(bgv);


    FILE *fpnEdges;
    FILE *fpinsert;

    fpnEdges=fopen("./results/nEdges.txt", "w");
    fpinsert=fopen("./results/insert.txt", "w");

    if (fpnEdges == NULL ||fpinsert==NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    /*int this part we insert the nodes in the trie
    n=rows, n1=cols, nEdges=number of edges*/
    uint64_t n, n1, nEdges;
    //this variable will contain the string in the morton code of a edge (max of the string is 50, that means 2^50 nodes)
    uint8_t str[50];
    //init a clock
    clock_t start, diff=0;
    //we read the first line of the input (wich contains the number of: rows,cols,edges)
    scanCode=scanf("%lu %lu %lu\n", &n, &n1, &nEdges);

    int * node;
    int neigNode;
    bool neigNodeDesigned=false;

    for (uint64_t i = 0; i < 190000001; ++i) {
        //we read the line containing the edge
        scanCode=scanf("%s\n", str);
        //todo: podemos cambiar el 23 por length thel string en el futuro.
        //for each char of the string, we need to convert it to int.
        //todo: podemos usar atoi y ahorrarnos el switch
        for (uint8_t j = 0; j < 23; ++j)
            switch(str[j]) {
                case '0': str[j] = 0;
                    break;
                case '1': str[j] = 1;
                    break;
                case '2': str[j] = 2;
                    break;
                case '3': str[j] = 3;
                    break;
            }

        insertTrie(t, str, 23, 22);


        if (i%5000000 == 0 && i!=0) {

            diff=0;
            printf(" nEdges=%lu\n",i);
            fprintf(fpnEdges,"%lu,\n",i);

            if(!neigNodeDesigned){
                node=ab(str,23);
                neigNodeDesigned=true;
                neigNode=node[0];
            }

            printf("%lu\n",i);
            printf("%i\n",neigNode);

            for(int i2=0;i2<1;i2++){
                int pathLength=23;
                int left=0;
                int right=pow(2,pathLength)-1;
                start = clock();
                linkedList* answer=getNeighboursTrie(t,neigNode,23,0,22,left,right,left,right);
                diff += clock() - start;
                //printLinkedList(answer);

                freeLinkedList(answer);


            }

            uint64_t msec = diff * 1000 ;
            printf("     insertTime=%f\n",(float)msec);
            fprintf(fpinsert,"%f,\n",(float)msec);
        }
    }



    fclose(fpnEdges);
    fclose(fpinsert);

    printf("congratulation all test passed\n");
    return 0;
}
