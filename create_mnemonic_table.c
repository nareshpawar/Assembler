#include "struct.h"
mn_val *insert_mn_val(mn_val *head,char *rm,char *reg,char *data)
{
	mn_val *newnode,*temp ;
	newnode = (mn_val *) malloc(sizeof(mn_val));

	newnode->RM = (char *)malloc(sizeof(rm));
	newnode->Register = (char *)malloc(sizeof(reg));
	newnode->value = (char *)malloc(sizeof(data));

	strcpy(newnode->RM,rm);
	strcpy(newnode->Register,reg);
	strcpy(newnode->value,data);
	newnode->next = NULL;

	if(head == NULL)
		head = newnode;
	else
	{	
		temp =head;
		while(temp->next != NULL)
			temp=temp->next;
		temp->next = newnode;
	}
	return head;
}

mn_val *create_mn_val(mn_val *head,char *val)
{
	FILE *fp;
	char *rm,*reg,*value;
	fp = fopen (val, "r");

	rm=(char *)malloc(sizeof(char)*2);
	reg=(char *)malloc(sizeof(char)*3);
	value=(char *)malloc(sizeof(char)*8);
	while(1)
	{
		if(fscanf(fp, "%s %s %s",rm,reg,value) == 3 )
			head = insert_mn_val(head,rm,reg,value);
		else 
			break;
	}
//	free(rm);
//	free(reg);
//	free(value);
	return head;
}


mn_tab *insert_Mnemonic(mn_tab *mhead,char *val)
{
	mn_tab *newnode,*temp;
	newnode = (mn_tab *)malloc(sizeof(mn_tab));
	newnode->mnemonic_name = (char *)malloc(sizeof(val));
	strcpy(newnode->mnemonic_name,val);
	newnode->head = NULL;
	newnode->next=NULL;
	newnode->head = create_mn_val(newnode->head,val);
	if(mhead == NULL)
		mhead = newnode;
	else
	{
		temp = mhead;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newnode;
	}
//	free(temp);
	return mhead;
}


mn_tab *create_mn(mn_tab *head)
{
	FILE *fp;
	char *val;
	val=(char *)malloc(sizeof(char)*5);
	fp = fopen ("mnemonic3.txt", "r");
	while(1)
	{
		if(fscanf(fp, "%s",val) == 1 )
		{
			head = insert_Mnemonic(head,val);
		}
		else 
			break;
	}
//	free(val);
	return head;
}


void disp_mn(mn_val *head)
{
	while(head!=NULL)
	{
		printf("%s\t%s\t%s\n",head->RM,head->Register,head->value);
		head=head->next;
	}
}

void display_mn(mn_tab *head){
	printf("\nIN display\n");
	while(head != NULL)
	{
		printf("\n%s",head->mnemonic_name);
		disp_mn(head->head);
		head=head->next;
	}
}


