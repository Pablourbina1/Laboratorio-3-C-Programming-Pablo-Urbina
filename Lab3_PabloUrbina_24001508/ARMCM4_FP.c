#include "ARMCM4_FP.h"
#include <stdio.h>
int myGCD(const char *set){
    // Variable auxiliar
    const char *ptr = set;
    int mcd = 0;

    
    while(*ptr != '\0'){
        // Ignorar espacios y ,
        while (*ptr == ' ' || *ptr == ','){
            ptr++;
        }
        // Detener la ejecucion si se llega al caracter nulo
        if (*ptr == '\0'){
            break;
        }

        // Parsear la cadena para extraer los números enteros
        int numero = 0;
        while(*ptr >= '0' && *ptr <= '9'){
            numero = (numero * 10) + (*ptr - '0');
            ptr++;
        }

        if (mcd != 0){
            while(numero != 0){
                int temp = mcd % numero;
                mcd = numero;
                numero = temp;
            }
        } else {
            mcd = numero;
        }
        
    }

    

    return mcd;
}

void myCombinations(int n, const char *set, char *comb){
    const char *ptr = set;
    char *out = comb;
    *out = '\0';
    if (n > 3){
        printf("%s\n", "n debe ser menor o igual a 3");
    } else {
        int cont = 0;
        // Buffer que guarda fisicamente los caracteres de cada palabra
        char buffer_caracteres[5][20];
        // Lista que almacena la dirección de inicio de cada palabra
        char *punteros[5];
        // Puntero doble que apunta a la lista "punteros"
        char **caracteres = punteros;

        const char *inicio = ptr;
        while(*inicio != '\0'){
            if(*inicio == '{'){
                ptr = inicio + 1;
                break;
            }
            inicio++;
        }


        while(*ptr != '\0'){
        // Ignorar espacios y , }
        while (*ptr == ' ' || *ptr == ',' || *ptr == '}'){
            ptr++;
        }
        // Detener la ejecucion si se llega al caracter nulo
        if (*ptr == '\0'){
            break;
        }


        if (cont >= 5){
            printf("%s\n", "La cardinalidad de set debe ser menor o igual a 5");
            *comb = '\0';
            return;
        }

        caracteres[cont] = buffer_caracteres[cont];
        

        int indice = 0;
        // Parsear palabras y almacenarlas
        while(*ptr >= '0' && *ptr <= '9'
            || *ptr >= 'a' && *ptr <= 'z'
            || *ptr >= 'A' && *ptr <= 'Z'){

            caracteres[cont][indice] = *ptr;
            indice++;
            ptr++;
        }
            caracteres[cont][indice] = '\0';
            cont++;
        }

        int flag = 1;

        // Caso n = 1
        if(n == 1){
            for(int i = 0; i < cont; i++){
                // Formatear la salida en la forma correcta
                if (!flag) {
                    *out = ',';
                    out++;
                    *out = ' ';
                    out++;
                }
                *out = '{';
                out++;

                const char *j = caracteres[i];
                while (*j != '\0'){
                    *out = *j;
                    out++;
                    j++;
                }
                *out = '}';
                out++;
                flag = 0;
            }
        }

        // Caso n = 2

        if(n == 2){
            for(int i = 0; i < cont - 1; i++){
                for(int p = i + 1; p < cont; p++){
                    // Formatear la salida en la forma correcta
                    if (!flag) {
                        *out = ',';
                        out++;
                        *out = ' ';
                        out++;
                    }
                    *out = '{';
                    out++;

                    const char *j = caracteres[i];
                    while (*j != '\0'){
                        *out = *j;
                        out++;
                        j++;
                    }

                    *out = ',';
                    out++;
                    *out = ' ';
                    out++;

                    const char *a = caracteres[p];
                    while (*a != '\0'){
                        *out = *a;
                        out++;
                        a++;
                    }

                    *out = '}';
                    out++;
                    flag = 0;
                }
            }
        }

        // Caso n = 3

        if(n == 3){
            for(int i = 0; i < cont - 2; i++){
                for(int p = i + 1; p < cont - 1; p++){
                    for(int k = p + 1; k < cont; k++){
                        // Formatear la salida en la forma correcta
                        if (!flag) {
                            *out = ',';
                            out++;
                            *out = ' ';
                            out++;
                        }
                        *out = '{';
                        out++;

                        const char *j = caracteres[i];
                        while (*j != '\0'){
                            *out = *j;
                            out++;
                            j++;
                        }

                        *out = ',';
                        out++;
                        *out = ' ';
                        out++;

                        const char *a = caracteres[p];
                        while (*a != '\0'){
                            *out = *a;
                            out++;
                            a++;
                        }

                        *out = ',';
                        out++;
                        *out = ' ';
                        out++;

                        const char *s = caracteres[k];
                        while (*s != '\0'){
                            *out = *s;
                            out++;
                            s++;
                        }
                        *out = '}';
                        out++;
                        flag = 0;
                        
                    }
                }
            }
        }

        *out = '\0';

        printf("Combinaciones: %s\n", comb);
    }
}
