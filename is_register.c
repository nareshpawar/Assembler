#include "struct.h" 

int is_register(reg_tab *head,char *name)
{
	while(head!=NULL){
		if(strcmp(name,head->reg_name)==0){
			return 0;}
		else
			head=head->next;
       }
	return 1;
}

