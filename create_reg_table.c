#include "struct.h"
reg_tab *insert_Register(reg_tab *rhead,char *val)
{
	reg_tab *newnode,*temp;
	newnode = (reg_tab *)malloc(sizeof(reg_tab));
	newnode->reg_name = (char *)malloc(sizeof(val));
	strcpy(newnode->reg_name,val);
	newnode->next=NULL;
	if(rhead == NULL){
		newnode->reg_number =1;
		rhead = newnode;
	}
	else
	{
		temp = rhead;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newnode;
		newnode->reg_number = temp->reg_number +1;
	}
	return rhead;
}


reg_tab *create_reg_table(reg_tab *head)
{
	FILE *fp;
	char *val;
	val=(char *)malloc(sizeof(char)*5);
	fp = fopen ("register.txt", "r");
	while(1)
	{
		if(fscanf(fp, "%s",val) == 1 )
		{
			head = insert_Register(head,val);
		}
		else 
			break;
	}
//	free(val);
	return head;
}

void display_reg(reg_tab *head){
	while(head != NULL)
	{
		printf("%d\t%s\n",head->reg_number,head->reg_name);
		head=head->next;
	}
}



