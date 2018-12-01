#include "struct.h"

int return_S_value(symtab *head,char *name,reg_tab *rhead){
char *sym_name;
	sym_name = (char *)malloc(sizeof(name));
	int i,k,j=0;
	for(i=0;name[i]!='[';i++);
	for(k=i+1;name[k]!=']';k++){
		sym_name[j] = name[k];
		j++;
	}
	if(is_register(rhead,sym_name) == 0)
		return ret_register_number(rhead,sym_name);
	else{
		while(head!=NULL)
		{
			if(strcmp(sym_name,head->symbol_name)==0)
				return (head->line_number);
			else
				head=head->next;
		}	
		return -1;
	}
}

