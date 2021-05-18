#include "assert.h"
#include "../treeBlock/treeBlockApi.h"

/* En este test, primero insertamos 194M de aristas. luego borramos el arbol completo, pero medimos cada 5M de aristas
 * Es decir, calculamos cuanto se demora en borrar los primeros 5M, los primeros 10M,... el arbol completo*/

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

int main()
{

    blockGlobalVars *bgv=(blockGlobalVars*) malloc(sizeof(blockGlobalVars));
    bgv->init(4,S3,0.99);

    //we init the trieNode that will contain all the edges
    trieNode *t = (trieNode *) malloc(sizeof(trieNode));
    t->init(bgv);



    //scan int code
    int scanCode;

    /*int this part we insert the nodes in the trie
    n=rows, n1=cols, nEdges=number of edges*/
    uint64_t n, n1, nEdges;
    //this variable will contain the string in the morton code of a edge (max of the string is 50, that means 2^50 nodes)
    uint8_t str[50];
    //init a clock
    clock_t start,start2, diff=0,diff2=0;
    //we read the first line of the input (wich contains the number of: rows,cols,edges)
    scanCode=scanf("%lu %lu %lu\n", &n, &n1, &nEdges);
    uint64_t i = 0;
    while(i<1000000){
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

        //for each edge, we sum the time it cost to insert


        insertTrie(t, str, 23, 22);

        i++;

        if(i==1000000){
            int * node;
            node = ab(str,23);
            printf("%i %i\n",node[0],node[1]);
            printf("neighbours\n");
            int pathLength=23;
            int left=0;
            int right=pow(2,pathLength)-1;
            linkedList* answer=getNeighboursTrie(t,node[0],23,0,22,left,right,left,right);
            printLinkedList(answer);
        }

    }

    printf("congratulation all test passed\n");
    return 0;
}
