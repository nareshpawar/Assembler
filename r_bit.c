#include "struct.h"

char *r_bit(char *operand){
	
	if(strlen(operand) == 3){
		if((strcmp(operand,"eax")==0) || (strcmp(operand,"ebx")==0) || (strcmp(operand,"ecx")==0) || (strcmp(operand,"edx")==0))
			return "eax";
		else
			return "error";
	}
	else {
		if((strcmp(operand,"ax")==0) || (strcmp(operand,"bx")==0) || (strcmp(operand,"cx")==0) || (strcmp(operand,"dx")==0))
			{
				return "ax";
			}
		else if((strcmp(operand,"al")==0) || (strcmp(operand,"ah")==0) || (strcmp(operand,"bl")==0) || (strcmp(operand,"bh")==0) || (strcmp(operand,"cl")==0) || (strcmp(operand,"ch")==0) || (strcmp(operand,"dl")==0) || (strcmp(operand,"dh")==0))
			return "al";
		else
			return "error";		
	}
	//else
	//	return "error";
}
