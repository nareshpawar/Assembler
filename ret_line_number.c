#include "struct.h"

int ret_line_number(symtab *head,char *name){
	while(head!=NULL)
	{
		if(strcmp(name,head->symbol_name) == 0)
			return head->line_number;
		else
			head=head->next;
	}
	return -1;
}

