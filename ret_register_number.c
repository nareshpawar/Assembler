#include "struct.h"

int ret_register_number(reg_tab *head,char *name){
	while(head!=NULL)
		if(strcmp(name,head->reg_name)==0)
			return head->reg_number;
		else
			head=head->next;
	return 1;
}
