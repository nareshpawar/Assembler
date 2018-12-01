#include "struct.h"

int evaluating2Arguments(char *mnemonic,char *operand1){
	reg_tab *rhead;
	symtab *shead;
	rr *rrhead;
	mn_tab *mhead;
        mn2_tab *m2head;
	m2head = mn2_head; 
	mhead = mn_head;	
	rrhead = rr_head;
	shead = sym_head; 
	rhead = reg_head;

	char *reg1;
	if(is_mnemonic2(m2head,mnemonic) == 0){
		if(strcmp(mnemonic,"jmp") == 0){
			if(check_sym_label(shead,operand1) == 0)
				fprintf(outFp,"%s[%d]\t\n",ret_mn2_value(m2head,mnemonic),ret_line_number(shead,operand1));
			else{
				error_flag =1;
				fprintf(errorFp,"LINE NUMBER : %d:error\tInvalid operand for %s\n",lineNumber,mnemonic);
			}
		}
		if(strcmp(mnemonic,"inc") == 0 || strcmp(mnemonic,"dec") == 0 ){
			if(is_register(rhead,operand1) == 0)
				fprintf(outFp,"%s(%d)\t\n",ret_mn2_value(m2head,mnemonic),ret_register_number(rhead,operand1));
			else if(is_memory(shead,operand1,rhead) == 0)
				fprintf(outFp,"%s[%d]\t\n",ret_mn2_value(m2head,mnemonic),return_S_value(shead,operand1,rhead));
			else{
				error_flag =1;
				fprintf(errorFp,"LINE NUMBER : %d:error\tInvalid operand for %s\n",lineNumber,mnemonic);
			}
		}
		if(strcmp(mnemonic,"push") == 0 ){
			if(is_register(rhead,operand1) == 0)
				fprintf(outFp,"%s(%d)\t\n",ret_mn2_value(m2head,mnemonic),ret_register_number(rhead,operand1));
			else if(is_memory(shead,operand1,rhead) == 0)
				fprintf(outFp,"%s[%c%d]\t\n",ret_mn2_value(m2head,mnemonic),type(shead,operand1,rhead),return_S_value(shead,operand1,rhead));
			else if(is_data_symbol(shead,operand1) == 0)
				fprintf(outFp,"%s[%d]\t\n",ret_mn2_value(m2head,mnemonic),ret_line_number(shead,operand1));	
			else{
				error_flag =1;
				fprintf(errorFp,"LINE NUMBER : %d:error\tInvalid operand for %s\n",lineNumber,mnemonic);
			}
		}
		if(strcmp(mnemonic,"pop") == 0 ){
			if(is_register(rhead,operand1) == 0)
				fprintf(outFp,"%s(%d)\t\n",ret_mn2_value(m2head,mnemonic),ret_register_number(rhead,operand1));
			else if(is_memory(shead,operand1,rhead) == 0)
				fprintf(outFp,"%s[%c%d]\t\n",ret_mn2_value(m2head,mnemonic),type(shead,operand1,rhead),return_S_value(shead,operand1,rhead));
			else{
				error_flag =1;
				fprintf(errorFp,"LINE NUMBER : %d:error\tInvalid operand for %s\n",lineNumber,mnemonic);
			}
		}
/*		if(strcmp(mnemonic,"call") == 0 ){
			if(is_inExtern(exhead,operand1) == 0)
				fprintf(outFp,"%s()\t\n",ret_mn2_value(m2head,mnemonic));	
			else
				fprintf(errorFp,"LINE NUMBER : %d:error\tInvalid operand for %s\n",mnemonic);
		}
*/	}
	else{
		error_flag =1;
		fprintf(errorFp,"LINE NUMBER : %d:error\tError in mnenomic %s\n",lineNumber,mnemonic);
	}
		return 0;
}


