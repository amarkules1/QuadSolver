/**
 * Author:Jacob Kampf
 * Purpose: Main Method for Quad Solver Program
 * Comments: We can discuss if we need anything else for a main method
 * Date Created: 10/11/18
 * */
#include <stdlib.h> 
#include <string.h>  
#include <stdio.h> 
#include <math.h>
#include "quadSolver.h"
#include "inputValidation.h" 
#include "inputReader.h" 
#include "answerChecker.h"



//Main Method--------------------------------------------------------------------------------------
int main (int argc, char *argv[]) { 

//floats to store result of input validation
float a=0;
float b=0;
float c=0;  

//doubles to pass to quadSolver
double x1=0;
double x2=0; 

quadConstants * line = readFromConsole(); 

printf("\n");

//check if line is null before assigning 
if(line != NULL){

a = validateInput(line->A);
b = validateInput(line->B);
c = validateInput(line->C); 

 printf("\n");

 printWarnings(a,b,c,x1,x2);
 
 printf("\n");

 quadSolver(a,b,c,&x1,&x2);  

}
else{

	printf("Line is null.\n");
}



 


	return(0);
} 