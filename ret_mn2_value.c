#include "struct.h"

char *ret_mn2_value(mn2_tab *head,char *name)
{
	while(head!=NULL)
	{
		if(strcmp(name,head->mnemonic_name)==0)
			return head->value;
		else
			head=head->next;
	}
	return NULL;
}

