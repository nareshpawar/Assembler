#include "struct.h"

int is_data_symbol(symtab *head,char *name){
	while(head!=NULL)
	{
		if(strcmp(name,head->symbol_name) == 0 && strcmp(head->section,"data") == 0)
			return 0;
		else
			head=head->next;
	}
	return 1;
}

