#include "struct.h"
int is_literal(char *operand){
	int i,flag;
	if(operand[0] == '\'' && operand[strlen(operand)-1] == '\'')
		return 0;
	else{
		for(i=0;operand[i]!='\0';i++){
			if(operand[i] == '0' || operand[i] == '1' || operand[i] == '2' || operand[i] == '3' || operand[i] == '4' || operand[i] == '5' || operand[i] == '6' ||operand[i] == '7' || operand[i] == '8'|| operand[i] == '9')
				flag = 1;
			else
				return 1;		
		}
		return 0;		
	}
}

