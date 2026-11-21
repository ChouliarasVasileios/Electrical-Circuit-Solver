#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct{

    // Here we need to have the following
    //leftAttachedPinToNode
    int left; // Left pin attached to node id
    int right; // Right pin attached to node id

    char* Name;

    float R; // Resistant
    float V; // Voltage
    float I; // Current

    bool hasR;
    bool hasV;
    bool hasI;

} Ohms_Law_Componet;

typedef struct{
    int id;
    Ohms_Law_Componet * Componets;
} Node;

void printSepLine(void){
    for(size_t i = 0; i < 35;++i){
        printf("=");
    }
    printf("\n");
}

void printComponetMetadata(Ohms_Law_Componet Componet){
    
    printSepLine();
    printf("Componet: %s\n",Componet.Name);
    printf("Componet Resistant: %f\n",Componet.R);
    printf("Componet Voltage: %f\n",Componet.V);
    printf("Componet Current: %f\n",Componet.I);

    printf("Left  : NodeId_%d\n",Componet.left);
    printf("Right : NodeId_%d\n",Componet.right);
    printSepLine();

}

int main()
{
    // NODE 1 - Upper NODE
    Node * node1 = malloc(sizeof(Node));
    assert(node1 != NULL);
    node1->id = 1;

    node1->Componets = malloc(sizeof(Ohms_Law_Componet)*2);
    assert(node1->Componets != NULL);

    // NODE 2 - Lower NODE
    Node * node2 = malloc(sizeof(Node));
    assert(node2 != NULL);
    node2->id = 2;


    node2->Componets = malloc(sizeof(Ohms_Law_Componet)*2);
    assert(node2->Componets != NULL);

    // Resistan - Load
    Ohms_Law_Componet resistant = {node1->id,node2->id,"R1",1.0,-1,-1,true,false,false};

    // DC Source - Source
    Ohms_Law_Componet DC_Source = {node1->id,node2->id,"DC",0.05,5.0,0.2,true,true,true};

    printComponetMetadata(resistant);
    printComponetMetadata(DC_Source);

    printf("Hello World\n");
    return 0;
}