#include "struct.h"

int sym_main(char *fname)
{
reg_tab *rhead;
	 	symtab *shead;
rhead = reg_head;
	FILE *input_file_pointer;
	input_file_pointer = fopen (fname, "r");
	int no_of_bytes=100;
	char *line;
	char *part1,*part2,*part3,*part4;
	sym_head = NULL;
	line=(char *)malloc(sizeof(char)*no_of_bytes);
	while(!feof(input_file_pointer)){
		getline(&line,&no_of_bytes,input_file_pointer);
		part1 = (char *)malloc(sizeof(line));
		part1 = strtok(line," ");
		if (strcmp(part1,"section") == 0 )
		{
			part2 = (char *)malloc(sizeof(line));
			part2 = strtok(NULL," ");
			if(strcmp(part2,".data\n") == 0 || strcmp(part2,".data") == 0)
				input_file_pointer = fill_symtab_data(input_file_pointer,"data");
			else if(strcmp(part2,".bss\n") == 0 || strcmp(part2,".bss") == 0)
				input_file_pointer = fill_symtab_bss(input_file_pointer,"bss");
			else if (strcmp(part2,".text\n") == 0 || strcmp(part2,".text") == 0)
				input_file_pointer = fill_symtab_text(input_file_pointer,"text");
			else
				printf("\nINVALID SECTION\n");
		}
	}
	shead = sym_head;
//	display(shead);
//printf("\n%d\n",validate_symbol(shead,"dword[eax]",rhead));
//printf("\n%d\n",is_symbol(shead,"loop"));
//printf("\n%d\n",return_S_value(shead,"dword[loop]",rhead));
return 0;
}

