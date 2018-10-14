#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
    char* A;
    char* B;
    char* C;
} quadConstants;



quadConstants* readFromConsole()
{
    quadConstants * line = (quadConstants*)malloc(sizeof(quadConstants));
    printf("Ax^2 + Bx + C\nA = 0\nPlease enter a, b, and c seperated by one space");
    char lineBuff[1024];
    fgets(lineBuff,1024,stdin);
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
                break;
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
            start = end+1;
        }
        if(i == 1){
            if(lineBuff[end] == '\n'){
                fprintf(stderr,"Missing c");
                break;
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
            start = end+1;
        }
        if(i == 2){
            if(lineBuff[end] != '\n'){
                fprintf(stderr,"Too Many Arguments");
                break;
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
            start = end+1;
        }
        i ++;
    }
    return line;
}