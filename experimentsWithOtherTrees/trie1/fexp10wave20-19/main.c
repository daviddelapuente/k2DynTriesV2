#include "assert.h"
#include "../../../treeBlock.c"

/* En este test, primero insertamos 194M de aristas. luego borramos el arbol completo, pero medimos cada 5M de aristas
 * Es decir, calculamos cuanto se demora en borrar los primeros 5M, los primeros 10M,... el arbol completo*/
int main()
{
    //first we init the variables used int the tree
    //todo: creo qe estas variables estan de mas.
    treeBlock B;
    treeNode node;
    node.first = 0;
    node.second = 0;
    uint16_t curFlag = 0;
    uint16_t subTreeSize;
    uint16_t level = 0;

    //we init the trieNode that will contain all the edges
    trieNode *t = (trieNode *) malloc(sizeof(trieNode));
    t->children[0] = t->children[1] = t->children[2] = t->children[3] = NULL;
    t->block = NULL;

    bool found;

    //scan int code
    int scanCode;



    /*int this part we create the array that contains the sizes a block can have.
    a node always has %alpha of space ocupied
    N1,Nt,S3 and sizeArray are defined in treeBloch.h*/
    double alpha = 0.99;
    //min size of a block. (the min number of nodes a block can have is n1)
    N1 = 4;
    //max size a block can have (the max number of nodes a block can have is nt) we can test with: 96, 128, 256, 512, 1024
    Nt = S3;
    /*the array of sizes is of length Nt+1
    the idea is to acces sizeArray[i] where i is the actual number of nothes
    and the array will return the size the block should have
    so is probably that sizeArray[i]=sizeArray[i+1]*/
    sizeArray = (uint16_t *) malloc(sizeof(uint16_t)*(Nt+1));
    //for each espace in the array
    for (int i = 0; i <= Nt; ++i) {
        //todo: por que 4*(((uint16_t)ceil((double)N1/alpha)+3)/4)?;
        //we fill using this rule
        if (i > N1) N1 = 4*(((uint16_t)ceil((double)N1/alpha)+3)/4);
        sizeArray[i] = N1;
    }




    FILE *fpnEdgesInsert;
    FILE *fpinsert;
    
    FILE *fpnEdgesDelete;
    FILE *fpdelete;

    FILE *fptotalSize;
    FILE *fptotalSizeCount;

    fpnEdgesInsert=fopen("./results/fpnEdgesInsert.txt", "w");
    fpinsert=fopen("./results/insert.txt", "w");
    
    fpnEdgesDelete=fopen("./results/fpnEdgesDelete.txt", "w");
    fpdelete=fopen("./results/delete.txt", "w");
    
    fptotalSize=fopen("./results/totalSize.txt", "w");
    fptotalSizeCount=fopen("./results/totalSizeCount.txt", "w");

    if (fpnEdgesInsert == NULL ||fpinsert==NULL || fpnEdgesDelete == NULL || fpdelete==NULL || fptotalSize==NULL  || fptotalSizeCount==NULL){
        printf("Error opening file!\n");
       exit(1);
    }

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
    uint64_t c = 0;
    uint64_t totalSizeCount = 0;
    uint64_t nedgestotal=0;
    while(i<190000000){
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
	
	//assert(!isEdgeTrie(t, str, 23, 22));
	start = clock();
	insertTrie(t, str, 23, 22);
	diff += clock() - start;
	//assert(isEdgeTrie(t, str, 23, 22));


	c++;
	i++;
	totalSizeCount++;
	nedgestotal++;

 	if (i%5000000 == 0 && i!=0) {
	    printf("inserted i=%lu\n",nedgestotal);
	    fprintf(fpnEdgesInsert,"%lu,\n",nedgestotal);
		
	    uint64_t msec = diff * 1000 / CLOCKS_PER_SEC;
            fprintf(fpinsert,"%f,\n",(float)msec/nedgestotal);
	    
	    uint64_t treeSize2 = sizeTrie(t);
            fprintf(fptotalSize,"%lu,\n",treeSize2);
	    fprintf(fptotalSizeCount,"%lu,\n",totalSizeCount);

        }


        //we print each 1000000 edges
        if (c%20000000 == 0 && i!=0) {
		diff=0;
		diff2=0;
		c=0;
		printf("inserted nEdges=%lu\n",nedgestotal);
		uint64_t j=0;
		uint64_t nedgesstartdelete=i;	
		fseek(stdin,26+24*(i-15000000),SEEK_SET);        
		while(j<15000000){
                        
			scanCode=scanf("%s\n", str);


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

			//assert(isEdgeTrie(t, str, 23, 22));
			start2 = clock();
			deleteTrie(t, str, 23, 22);
			diff2 += clock() - start2;
 			//assert(!isEdgeTrie(t, str, 23, 22));

			j++;
			totalSizeCount++;
			nedgestotal--;

			if (j%5000000 == 0 && j!=0) {
			    fprintf(fpnEdgesDelete,"%lu,\n",nedgesstartdelete);

			    uint64_t msec2 = diff2 * 1000 / CLOCKS_PER_SEC;
            	 	    fprintf(fpdelete,"%f,\n",(float)msec2/j);

			    uint64_t treeSize2 = sizeTrie(t);
			    fprintf(fptotalSize,"%lu,\n",treeSize2);
			    fprintf(fptotalSizeCount,"%lu,\n",totalSizeCount);
			}
		}
		fseek(stdin,26+24*(i),SEEK_SET);
		printf("i=%lu \n",i);
		
        }

    }



    fclose(fpnEdgesInsert);
    fclose(fpinsert);
    fclose(fpnEdgesDelete);
    fclose(fpdelete);
    fclose(fptotalSize);
    fclose(fptotalSizeCount);

    printf("congratulation all test passed\n");
    return 0;
}
