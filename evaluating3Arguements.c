#include "struct.h"

int evaluating3Arguments(char *mnemonic,char *operand1,char *operand2){
	reg_tab *rhead;
	symtab *shead;
	rr *rrhead;
	mn_tab *mhead;
	mhead = mn_head;	
	rrhead = rr_head;
	shead = sym_head; 
	rhead = reg_head;

//	fprintf(stdout,"%s\t%s\t%s\n",mnemonic,operand1,operand2);
	char *reg1;
	reg1 = (char*)malloc(sizeof(char)*strlen(operand1));
	if(is_mnemonic(mhead,mnemonic) == 0){
		if(is_register(rhead,operand1) == 0){
			strcpy(reg1,r_bit(operand1));
			if(is_register(rhead,operand2) == 0){
				if(strcmp(reg1,r_bit(operand2)) == 0){
					fprintf(outFp,"%s%s\n",return_mn_value(mhead,mnemonic,"RR",reg1),return_RR_value(rrhead,operand1,operand2));
					return 0;					
				}
				else{
					error_flag =1;
					fprintf(errorFp,"LINE NUMBER : %d:error\tInvalid Combination of registers\n",lineNumber);
					return 0;
				}				
			}
			else if(is_memory(shead,operand2,rhead) == 0){
				printf("%s\t%s\n",reg1,m_bit(operand2));
				if(strcmp(reg1,m_bit(operand2)) == 0){
					fprintf(outFp,"%s[%c%d]\n",return_mn_value(mhead,mnemonic,"RM",reg1),type(shead,operand2,rhead),return_S_value(shead,operand2,rhead));
					return 0;					
				}
				else{
					error_flag =1;
					fprintf(errorFp,"LINE NUMBER : %d:error\tInvalid Combination of Register and Memmory\n",lineNumber);
					return 0;
				}	
			}
			else if(is_literal(operand2) == 0){
				fprintf(outFp,"%s(%s)\n",return_mn_value(mhead,mnemonic,"RD",reg1),return_L_value(operand2));
				return 0;					
			}
			else{
				error_flag =1;
				fprintf(errorFp,"LINE NUMBER : %d:error\tInvalid Operand 2\n",lineNumber);
				return 0;
			}
		}
		else if (is_memory(shead,operand1,rhead) == 0){
			if(validate_symbol(shead,operand1,rhead) == 0){
				if(is_register(rhead,operand2) == 0){
					strcpy(reg1,r_bit(operand2));
					if(strcmp(r_bit(operand2),m_bit(operand1))==0){
								fprintf(outFp,"%s[%c%d]\n",return_mn_value(mhead,mnemonic,"MR",reg1),type(shead,operand1,rhead),return_S_value(shead,operand1,rhead));
							return 0;					
						}
						else{
							error_flag =1;					
							fprintf(errorFp,"LINE NUMBER : %d:error\tInvalid Combination of registers\n",lineNumber);
							return;
						}				
				}
				else if(is_literal(operand2) == 0){
					fprintf(outFp,"%s(%s)\n",return_mn_value(mhead,mnemonic,"MD",reg1),return_L_value(operand2));
					return 0;					
				}
				else{
					error_flag =1;
					fprintf(errorFp,"LINE NUMBER : %d:error\tInvalid Operand 2\n",lineNumber);
					return 0;
				}

			}
			else{
				error_flag =1;
				fprintf(errorFp,"LINE NUMBER : %d:error\tInvalid Symbol used\n",lineNumber);
				return 0;
			}
		}
		else{
			error_flag =1;
			fprintf(errorFp,"LINE NUMBER : %d:error\tError in operand1 of %s. Should be register or symbol\n",lineNumber,mnemonic);
			return 0;			
		}	
	}	
	else{
		error_flag =1;
		fprintf(errorFp,"LINE NUMBER : %d:error\tError in mnenomic %s\n",lineNumber,mnemonic);
		return 0;
	}
}


