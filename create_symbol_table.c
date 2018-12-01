#include "struct.h"
void display(symtab *head)
{
	fprintf(stdout,"\nNumber\tName\tType\tSection\tLine_Number\tValue\n");
	while(head!=NULL)
	{
		fprintf(stdout,"%d\t",head-> sym_number);
		fprintf(stdout,"%s\t",head-> symbol_name);
		fprintf(stdout,"%s\t",head -> type);
		fprintf(stdout,"%s\t",head -> section);
		fprintf(stdout,"%d\t",head-> line_number);
		fprintf(stdout,"%s\n",head -> value);
		head = head->next;
	}
}


symtab *create_symbol_table(symtab *head,char *name,char *typ,char *sec,char *val,int line)
{
	symtab *newnode,*temp;
	newnode = (symtab *)malloc(sizeof(symtab));
	newnode->symbol_name = (char *)malloc(sizeof(name));
	newnode->type = (char *)malloc(sizeof(typ));
	newnode->section = (char *)malloc(sizeof(sec));
	newnode->value = (char *)malloc(sizeof(val));
	newnode->line_number = line;
	strcpy(newnode->symbol_name,name);
	strcpy(newnode->type,typ);
	strcpy(newnode->section,sec);
	strcpy(newnode->value,val);
	newnode->next = NULL;
	if(head == NULL)
	{
		newnode->sym_number = 1;
		head = newnode;
	}
	else
	{
		temp = head;
		while(temp->next!=NULL)
			temp =temp->next;

		temp->next = newnode;
		newnode->sym_number = temp->sym_number + 1;
	}
	return head; 
}


FILE *fill_symtab_data(FILE *input_file_pointer,char *sec)
{
	int no_of_bytes=100,line_counter = 0;
	char *line;
	char *part1,*part2,*part3;
	while(!feof(input_file_pointer)){
		getline(&line,&no_of_bytes,input_file_pointer);
		if(strcmp(line,"\n") == 0)
			break;
		part1 = (char *)malloc(sizeof(line));
		part1 = strtok(line," ");
		if (strcmp(part1,"section") == 0 )
		{
			part2 = (char *)malloc(sizeof(line));
			part2 = strtok(NULL," ");
			if(strcmp(part2,".bss\n") == 0 || strcmp(part2,".bss") == 0)
				input_file_pointer = fill_symtab_bss(input_file_pointer,"bss");
			else if (strcmp(part2,".text\n") == 0 || strcmp(part2,".text") == 0)
				input_file_pointer = fill_symtab_text(input_file_pointer,"text");
			else
				printf("\nINVALID SECTION\n");
		}
		else
		{
			line_counter ++;
			part2 = (char *)malloc(sizeof(line));
			part2 = strtok(NULL," ");
			part3 = (char *)malloc(sizeof(line));
			part3 = strtok(NULL,"\n");
			part1=strtok(part1,"\t");
			sym_head = create_symbol_table(sym_head,part1,part2,sec,part3,line_counter);
		}
//	free(part1);
//	free(part2);
//	free(part3);	
	}
	return input_file_pointer;
}

FILE *fill_symtab_text(FILE *input_file_pointer,char *sec){
	int no_of_bytes=100,line_counter=0,len,i,flag1=0;
	char *line,*line1;
	char *part1;
		part1 = (char *)malloc(sizeof(char)*100);
		line1 = (char *)malloc(sizeof(char)*100);
	while(!feof(input_file_pointer)){
		getline(&line,&no_of_bytes,input_file_pointer);
		strcpy(line1,line);
		part1 = strtok(line," ");
		if (strcmp(part1,"section") == 0 )
		{
			printf("\nINVALID SECTION\n");
		}
		else
		{
			flag1 = 0;
			for(i=0;line1[i]!='\0';i++)
			{
				if(line1[i] == ':')
					{
					flag1 = 1;
					break;}
			}

			if(flag1== 1)
			{
				part1 = strtok(line1,":");
				if(strcmp(part1,"main")== 0 )
				{
					line_counter++;
					sym_head = create_symbol_table(sym_head,part1,"label",sec,"NULL",line_counter);
				}
				else if(strcmp(part1,"main ")==0)
				{
					part1=strtok(part1," ");
					sym_head = create_symbol_table(sym_head,part1,"label",sec,"NULL",line_counter);
				}
				else
				{
					len = strlen(part1);
					if(part1[len-1] ==' ')
					{	
						part1 = strtok(part1," ");
						sym_head = create_symbol_table(sym_head,part1,"label",sec,"NULL",line_counter);
					}
					else
					{	
						sym_head = create_symbol_table(sym_head,part1,"label",sec,"NULL",line_counter);
					}
				}
			}
			else
			{
				if(line_counter != 0)
					line_counter++;
			}
	}
//	free(line1);
//	free(part1);
	}
//	free(line);

	return input_file_pointer;
}

FILE *fill_symtab_bss(FILE *input_file_pointer,char *sec){
	int no_of_bytes=100,line_counter=0;
	char *line;
	char *part1,*part2,*part3;
	while(!feof(input_file_pointer)){
		getline(&line,&no_of_bytes,input_file_pointer);
		if(strcmp(line,"\n") == 0)
			break;
		part1 = (char *)malloc(sizeof(line));
		part1 = strtok(line," ");
		if (strcmp(part1,"section") == 0 )
		{
			part2 = (char *)malloc(sizeof(line));
			part2 = strtok(NULL," ");
			if (strcmp(part2,".text\n") == 0 || strcmp(part2,".text") == 0)
				input_file_pointer = fill_symtab_text(input_file_pointer,"text");
			else
				printf("\nINVALID SECTION\n");
		}
		else
		{
			line_counter++;
			part2 = (char *)malloc(sizeof(line));
			part2 = strtok(NULL," ");
			part3 = (char *)malloc(sizeof(line));
			part3 = strtok(NULL,"\n");
			part1=strtok(part1,"\t");
			sym_head = create_symbol_table(sym_head,part1,part2,sec,part3,line_counter);
		}	
//	free(part1);
//	free(part2);
//	free(part3);
	}
//	free(line);
	return input_file_pointer;
}
