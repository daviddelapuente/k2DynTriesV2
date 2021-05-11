#ifndef K2DYNTRIESV2_BLOCKGLOBALVARS_H
#define K2DYNTRIESV2_BLOCKGLOBALVARS_H

struct blockGlobalVars{
    uint16_t N1;
    uint16_t Nt;
    double alpha;
    // Global table that stores the sizes of the blocks, used for growing them
    uint16_t *sizeArray; // array of sizes

    void init(uint16_t N1v,uint16_t Ntv, double alphav){
        N1=N1v;
        Nt=Ntv;
        alpha=alphav;

        sizeArray = (uint16_t *) malloc(sizeof(uint16_t)*(Ntv+1));
        for (int i = 0; i <= Ntv; ++i) {
            if (i > N1v) N1v = 4*(((uint16_t)ceil((double)N1v/alphav)+3)/4);
            sizeArray[i] = N1v;
        }
    }
};


#endif //K2DYNTRIESV2_BLOCKGLOBALVARS_H
