#include "RTE_Components.h"
#include CMSIS_device_header

#include "ARMCM4_FP.h" // Device header
#include <stdio.h>
static const char numbers[] = "36, 60, 48";
int main(void){
    int result = myGCD(numbers);
    char comb[100];

    printf("Resultado MCD: %d\n",result);

    // Pruebas para myCombinations

    // Pruebas validas
    myCombinations( 1, "A = {rojo, verde, azul}", comb);
    myCombinations( 2, "A = {rojo, verde, azul}", comb);
    myCombinations( 3, "A = {rojo, verde, azul, amarillo, negro}", comb);

    // Pruebas invalidas
    myCombinations( 4, "A = {rojo, verde, azul}", comb); // n mayor a 3
    myCombinations( 1, "A = {rojo, verde, azul, amarillo, negro, blanco}", comb); // Cardinalidad de set mayor a 5
    myCombinations( 10, "A = {rojo, verde, azul, amarillo, negro, blanco}", comb);
    while (1);
}
