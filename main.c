#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef enum {
    PIN1,
    PIN2
} PINS;

typedef struct{

    float R; // Resistant
    float V; // Voltage
    float I; // Current

    bool hasR;
    bool hasV;
    bool hasI;

} Ohms_Law_Componet;

typedef struct{

    PINS attachedPin;
    Ohms_Law_Componet Componet;

} ComponetMetadata;

typedef struct{

    ComponetMetadata * ComponetsMetadata;

} Node;

void printComponetMetadata(ComponetMetadata ComponetMetadata){
    printf("Attached PIN:%d\n",ComponetMetadata.attachedPin);
    printf("Componet Resistant: %f\n",ComponetMetadata.Componet.R);
    printf("Componet Voltage: %f\n",ComponetMetadata.Componet.V);
    printf("Componet Current: %f\n",ComponetMetadata.Componet.I);

}

int main()
{
    PINS left = PIN1;
    PINS right = PIN2;

    // NODE 1 - Upper NODE
    Node * node1 = malloc(sizeof(Node));
    assert(node1 != NULL);

    node1->ComponetsMetadata = malloc(sizeof(ComponetMetadata)*2);
    assert(node1->ComponetsMetadata != NULL);

    // NODE 2 - Lower NODE
    Node * node2 = malloc(sizeof(Node));
    assert(node2 != NULL);

    node2->ComponetsMetadata = malloc(sizeof(ComponetMetadata)*2);
    assert(node2->ComponetsMetadata != NULL);

    // Resistan - Load
    Ohms_Law_Componet resistant = {1.0,-1,-1,true,false,false};
    ComponetMetadata resistantMetadataNode1 = {left,resistant};
    ComponetMetadata resistantMetadataNode2 = {right,resistant};


    // DC Source - Source
    Ohms_Law_Componet DC_Source = {0.05,5.0,0.2,true,true,true};
    ComponetMetadata DC_SourceMetadataNode1 = {left,DC_Source};
    ComponetMetadata DC_SourceMetadataNode2 = {left,DC_Source};

    // Connect the left pin of source and resistant
    node1->ComponetsMetadata[0] = resistantMetadataNode1;
    node1->ComponetsMetadata[1] = DC_SourceMetadataNode1;

    // Connnect the right pin of source and resistant
    node2->ComponetsMetadata[0] = resistantMetadataNode2;
    node2->ComponetsMetadata[1] = DC_SourceMetadataNode2;

    for(size_t i = 0; i < 2; ++i){
       printComponetMetadata(node1->ComponetsMetadata[i]);
       printf("===\n\n");

    }

    printf("Hello World\n");
    return 0;
}