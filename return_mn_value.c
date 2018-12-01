#include "struct.h"

char *return_mn_value(mn_tab *head,char *name,char *rm,char *reg)
{
	while(head!=NULL)
	{
		if(strcmp(name,head->mnemonic_name)==0)
			return ret_mn_value(head->head,rm,reg);
		else
			head = head->next;
	}
	return NULL;
}


char *ret_mn_value(mn_val *head,char *rm,char *reg)
{
	while(head!=NULL)
	{
		if(strcmp(rm,head->RM)==0 && strcmp(reg,head->Register)==0)
			return head->value;
		else
			head=head->next;
	}
	return NULL;
}

