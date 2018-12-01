#include "struct.h"

mn2_tab *insert_Mnemonic2(mn2_tab *mhead,char *name,char *value)
{
	mn2_tab *newnode,*temp;
	newnode = (mn2_tab *)malloc(sizeof(mn2_tab));
	newnode->mnemonic_name = (char *)malloc(sizeof(name));
	strcpy(newnode->mnemonic_name,name);
	newnode->value = (char *)malloc(sizeof(value));
	strcpy(newnode->value,value);
	newnode->next=NULL;
	if(mhead == NULL)
		mhead = newnode;
	else
	{
		temp = mhead;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newnode;
	}
	return mhead;
}


mn2_tab *create_mn2(mn2_tab *head)
{
	FILE *fp;
	char *name,*val;
	name=(char *)malloc(sizeof(char)*5);
	val=(char *)malloc(sizeof(char)*5);
	fp = fopen ("mnemonic2.txt", "r");
	while(1)
	{
		if(fscanf(fp, "%s %s",name,val) == 2 )
		{
			head = insert_Mnemonic2(head,name,val);
		}
		else 
			break;
	}
//	free(name);
//	free(val);
	fclose(fp);
	return head;
}

void displaymn2(mn2_tab *head){
	while(head != NULL)
	{
		printf("\n%s\t%s",head->mnemonic_name,head->value);
		head=head->next;
	}
}

