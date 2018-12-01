#include "struct.h"

int is_memory(symtab *shead,char *name,reg_tab *rhead){
	char *sym_name;
	sym_name = (char *)malloc(sizeof(name));
	int i,k,j=0;
	for(i=0;name[i]!='[';i++)
		if(name[i] == '\0')
			return 1;
	for(k=i+1;name[k]!=']';k++){
		sym_name[j] = name[k];
		j++;
	}
	if(is_symbol(shead,sym_name) == 0)
		return 0;
	else if(is_register(rhead,sym_name) == 0)
		return 0;
	else
		return 1;
}


