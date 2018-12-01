#include "struct.h"
void display_rr(rr *head)
{
	while(head!=NULL)
	{
		printf("%s\t%s\t%s\n",head->reg_name_1,head->reg_name_2,head->value);
		head=head->next;
	}
}

char *return_RR_value(rr *head,char *reg1,char *reg2)
{
	while(head!=NULL)
	{
		if(strcmp(reg1,head->reg_name_1)==0 && strcmp(reg2,head->reg_name_2)==0)
			return (head->value);
		else
			head = head->next;
	}
	return NULL;
}

rr *insert_RegCombn(rr *head,char *op1,char *op2,char *val)
{
	rr *newnode,*temp;
	newnode = (rr *)malloc(sizeof(rr));
	newnode->reg_name_1 = (char*)malloc(sizeof(char)*strlen(op1));
	newnode->reg_name_2 = (char*)malloc(sizeof(char)*strlen(op2));
	newnode->value = (char*)malloc(sizeof(char)*strlen(val));
	strcpy(newnode->reg_name_1,op1);
	strcpy(newnode->reg_name_2,op2);
	strcpy(newnode->value,val);
	newnode->next=NULL;

	if(head == NULL)
		return newnode;
	else{
		temp = head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newnode;
	}
	return head;
}

rr *create_RR_combination(rr *head)
{
	FILE *fp;
	char *val,*op1,*op2;
val = (char*)malloc(sizeof(char)*2);
op1 = (char*)malloc(sizeof(char)*3);
op2 = (char*)malloc(sizeof(char)*3);
	fp = fopen ("reg_reg.txt", "r");
	while(1){
		if(fscanf(fp,"%s %s %s",val,op1,op2) == 3)
			head = insert_RegCombn(head,op1,op2,val);
		else 
			break;
	}
//free(val);
//free(op1);
//free(op2);
return head;
}


