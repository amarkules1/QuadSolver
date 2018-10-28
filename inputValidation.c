#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "inputReader.h"
#include "inputValidation.h" 
/**This method could be implemented after Grant's initial input validation
 * things to check:
 * check if float
 * check precision
 * 
 * 
 * 
 * **/
float validateInput(char * input){

float number; 

if(sscanf(input, "%d", &number) == 1) {
  
} else {
  printf("Error: not a number.\n%s\n", buffer);
  return -1;
}
return number;
}