#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "inputReader.h"


/**
 * Returns a quadConstants pointer
 * On error returns NULL
 **/
quadConstants* readFromConsole()
{
    quadConstants * line = (quadConstants*)malloc(sizeof(quadConstants));
    printf("Ax^2 + Bx + C = 0\nPlease enter a, b, and c seperated by one space");
    char lineBuff[1024];
    fgets(lineBuff,1023,stdin);
    /**
     *If LineBuff doesn't end in \n we know that the buffer overflowed 
     **/
    if(lineBuff[strlen(lineBuff)-1] != '\n'){
        fprintf(stderr,"%s\n","buffer overflow");
        free(line);
        return NULL;
    }
    int start = 0;
    int end = 0;
    int i = 0;
    /**
     * splits the buffer into the a, b, and c
     * it handles some input error
     **/
    while(lineBuff[end] != '\n')
    {
        while(lineBuff[end]!=' ' && lineBuff[end]!='\n')
        {
            end ++;
        }
        if(i == 0){
            if(lineBuff[end] == '\n'){
                fprintf(stderr,"Missing b, and c");
                free(line);
                return NULL;
            }
            char *A = (char*)malloc(end-start+1);
            A[end-start] = '\0';
            int index = 0;
            while(index + start != end){
                A[index] = lineBuff[index+start];
                index ++;
            }
            line->A = A;
            end++;
            start = end;
        }
        if(i == 1){
            if(lineBuff[end] == '\n'){
                fprintf(stderr,"Missing c");
                free(line->A);
                free(line);
                return NULL;
            }
            char *B = (char*)malloc(end-start+1);
            B[end-start] = '\0';
            int index = 0;
            while(index + start != end){
                B[index] = lineBuff[index+start];
                index ++;
            }
            line->B = B;
            end++;
            start = end;
        }
        if(i == 2){
            if(lineBuff[end] != '\n'){
                fprintf(stderr,"Too Many Arguments");
                free(line->A);
                free(line->B);
                free(line);
                return NULL;
            }
            char *C = (char*)malloc(end-start+1);
            C[end-start] = '\0';
            int index = 0;
            while(index + start != end){
                C[index] = lineBuff[index+start];
                index ++;
            }
            line->C = C;
            end++;
            start = end;
        }
        i ++;
    }
    return line;
}