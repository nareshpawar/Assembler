#include"struct.h"

int is_mnemonic2(mn2_tab *head,char *name)
{
	while(head!=NULL)
		if(strcmp(name,head->mnemonic_name)==0)
			return 0;
		else
			head=head->next;
	return 1;
}


