#include "struct.h"

int check_multiple_declaration(symtab *head){
	printf("IN mutliple function");
	symtab *temp,*temp1;
	int flag=0;
	temp  = head;
	while(temp!=NULL){
		temp1 = temp->next;
		while(temp1!=NULL){
			if(strcmp(temp->symbol_name,temp1->symbol_name)==0){
			printf("temp = %s \t temp1 = %s\n",temp->symbol_name,temp1->symbol_name);
				fprintf(errorFp,"Multiple declaration of %s \n\t\tFirst Declared on %d line\n",temp->symbol_name,temp->line_number);	
				flag =1;
			}
			temp1 = temp1->next;
		}
		temp = temp->next;
	}
	return flag;
}

			

