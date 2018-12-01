#include "struct.h"

void parse_three_args(char *line1){
	char *line2;
	char *part1,*part2,*part3;
	int i,k,j=0;
	line2=(char *)malloc(sizeof(char)*strlen(line1));
	if(line1[0] == '\t'){
		for(k=1;line1[k]!='\0';k++){
			line2[j]=line1[k];
			j++;
		}
		line2[j]='\0';
	}
	else{
		for(i=0;line1[i]==' ';i++);
		for(k=i;line1[k]!='\0';k++){
			line2[j]=line1[k];
			j++;
		}
		line2[j]='\0';
	}
	part1=(char *)malloc(sizeof(char)*strlen(line2));
	part1 = strtok(line2," ");
	part1[strlen(part1)]='\0';
	part2=(char *)malloc(sizeof(char));
	part2 = strtok(NULL,",");
	part2[strlen(part2)]='\0';
	part3=(char *)malloc(sizeof(char));
	part3=strtok(NULL," ");
evaluating3Arguments(part1,part2,part3);
}

void print_label(char *line1){
	symtab *shead ;
	shead = sym_head; 
	line1 = strtok(line1,":");
	int i;
	for(i=0;i<strlen(line1);i++)
		if(line1[i] == ' ')
			line1[i] = '\0';
fprintf(outFp,"[%d]\n",ret_line_number(shead,line1));
			
}
//----------------------------------------------------------------------------------------------------------------

/*int is_inExtern(exhead *exhead,char *operand1){
return 0;
}*/

//-------------------------------------------------------------------------------------------------------------------------

void parse_two_args(char *line1){
	char *line2;
	char *part1,*part2,*part3;
	int i,k,j=0;
	line2=(char *)malloc(sizeof(char));
	if(line1[0] == '\t'){
		for(k=1;line1[k]!='\0';k++){
			line2[j]=line1[k];
			j++;
		}
		line2[j]='\0';
	}
	else{
		for(i=0;line1[i]==' ';i++);
		for(k=i;line1[k]!='\0';k++){
			line2[j]=line1[k];
			j++;
		}
		line2[j]='\0';
	}
	part1=(char *)malloc(sizeof(char));
	part1 = strtok(line2," ");
	part1[strlen(part1)]='\0';
	part2=(char *)malloc(sizeof(char));
	part2=strtok(NULL," ");
evaluating2Arguments(part1,part2);

}


FILE *in_main(FILE *input_file_pointer){
	int no_of_bytes=0,i,flag1,flag2,flag3,flag4;
	char *line1,*line2;
	line1=(char *)malloc(sizeof(char));
	line2=(char *)malloc(sizeof(char));
	while(!feof(input_file_pointer)){
		flag1 = 0;
		flag2 = 0;
		flag3 = 0;
		flag4 = 0;
		getline(&line1,&no_of_bytes,input_file_pointer);
		lineNumber = lineNumber +1;
		line2 = strtok(line1,"\n");
		if(line2 == NULL){
			flag4 = 1;
			flag3 = 0;	
			fprintf(outFp,"\n");
		}
		else{
			fprintf(outFp,"%-100s",line1 );
			line2[strlen(line2)]='\0';
			for(i=0;line2[i]!='\0';i++){
				if(line2[i] == ','){
					parse_three_args(line1);
					flag1 = 1;
					flag2 = flag3 = 2;
					break;
				}
				if(line2[i] == ':'){
					print_label(line1);
					flag2 = 1;
					flag1 = flag3 = 2;
					break;
				}
				if(line2[i]!=' '){
					flag3 = 1;
					flag4 = 1;
				}
			}
		if(flag3 == 0 )
			fprintf(stdout,"");
		if(flag1 == 0 && flag4 == 1)
				parse_two_args(line1);
		}
	}
	return input_file_pointer;
}

int passtwomain(char *fname)
{
	symtab *head;
	head = sym_head;
	FILE *input_file_pointer;
errorFp = fopen ("error.txt", "w");
outFp = fopen ("output.txt", "w");
	if(check_multiple_declaration(head)==1)
		error_flag =1;	
	input_file_pointer = fopen (fname, "r");
	int no_of_bytes=100;
	char *line1,*line2;
	char *part1;
	line1=(char *)malloc(sizeof(char)*no_of_bytes);
	part1=(char *)malloc(sizeof(char)*no_of_bytes);
	while(!feof(input_file_pointer))
	{
		getline(&line1,&no_of_bytes,input_file_pointer);
		part1 = strtok(line1," ");
		if(strcmp(part1,"main")== 0 || strcmp(part1,"main:")==0 || strcmp(part1,"main:\n")==0)
		{
			if(part1[strlen(part1)-1] == '\n')
				part1 = strtok(part1,"\n");
			lineNumber = lineNumber +1;
			fprintf(outFp,"%-100s",part1);
			print_label(line1);
			input_file_pointer = in_main(input_file_pointer);
		}
	}
if(error_flag == 1){
	fclose(outFp);	
	outFp = fopen ("output.txt", "w");
}

fclose(errorFp);
fclose(outFp);	
}
