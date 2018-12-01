#include "struct.h"

char *return_L_value(char *operand){
	char *name;
	int i;
	name = (char*)malloc(sizeof(operand));
	if(operand[0] == '\'' && operand[strlen(operand)-1] == '\''){
			for(i=1;i<strlen(operand)-1;i++)
				name[i-1] = operand[i];
			return name;
	}
	else	
		return operand;		
}
