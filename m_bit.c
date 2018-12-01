#include "struct.h"

char *mtype(symtab *head,char *name)
{
	while(head!=NULL)
	{
		if(strcmp(name,head->symbol_name)==0)
			return head->type;
		else
			head=head->next;
	}
	return "error";
}

char *m_bit(char *name){
		reg_tab *rhead;
	symtab *shead;
	shead = sym_head; 
	rhead = reg_head;
	char *type,*sym_name,*s_type;
	s_type = (char *)malloc(sizeof(char)*4);
	type = (char *)malloc(sizeof(name));
	sym_name = (char *)malloc(sizeof(name));
	int i,k=0,j=0;
	for(i=0;name[i]!='[';i++){
		type[k] = name[k];
		k++;
	}
	for(k=i+1;name[k]!=']';k++){
		sym_name[j] = name[k];
		j++;
	}	
	if(strcmp(sym_name,"eax") == 0 ||strcmp(sym_name,"ebx") == 0 || strcmp(sym_name,"ecx") == 0 || strcmp(sym_name,"edx") == 0 )
			return "eax";
	else  if(strcmp(sym_name,"ax") == 0 ||strcmp(sym_name,"bx") == 0 || strcmp(sym_name,"cx") == 0 || strcmp(sym_name,"dx") == 0 )
                        return "ax";
	else if(strcmp(sym_name,"al") == 0 ||strcmp(sym_name,"bl") == 0 || strcmp(sym_name,"cl") == 0 || strcmp(sym_name,"dl") == 0 )
                        return "al";
	else if(strcmp(sym_name,"ah") == 0 ||strcmp(sym_name,"bh") == 0 || strcmp(sym_name,"ch") == 0 || strcmp(sym_name,"dh") == 0 )
                        return "al";
	else{
	s_type = mtype(shead,sym_name);
	if((strcmp(type,"dword")==0) && (strcmp(s_type,"dd") == 0 || strcmp(s_type,"resd")==0))
		return "eax";
	else if((strcmp(type,"word")==0) && (strcmp(s_type,"dw") == 0 || strcmp(s_type,"resw")==0))
		return "ax";
	else if((strcmp(type,"byte")==0) && (strcmp(s_type,"db") == 0 || strcmp(s_type,"resb")==0))
		return "al";
	else
		return "invalid";
	}	
}


