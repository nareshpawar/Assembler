#include "struct.h"

int check_sym_label(symtab *head,char *name){
	while(head!=NULL)
	{
		if(strcmp(name,head->symbol_name) == 0 && strcmp(head->type,"label") == 0)
			return 0;
		else
			head=head->next;
	}
	return 1;
}
