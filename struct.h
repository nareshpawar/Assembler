#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Register_Table{
int reg_number;
char *reg_name;
struct Register_Table *next;
}reg_tab;

typedef struct Mnemonic2_Table{
	char *mnemonic_name;
	char *value;	
	struct Mnemonic2_Table *next;
}mn2_tab;

typedef struct Mnemonic_Value{
	char *RM;  // reg-reg reg-data reg-mem mem-reg
	char *Register;
	char *value;
	struct Mnemonic_Value *next;
}mn_val;

typedef struct Mnemonic_Table{
	char *mnemonic_name;
	struct Mnemonic_Value *head;
	struct Mnemonic_Table *next;
}mn_tab;

typedef struct Reg_Combn_Value{
char *reg_name_1;
char *reg_name_2;
char *value;
struct Reg_Combn_Value *next;
}rr;

typedef struct symTab{
	int sym_number;
	char *symbol_name;
	char *type;
	char *section;
	char *value;
	int line_number;
	struct symTab *next;
}symtab;

symtab *sym_head;
rr *rr_head;
mn_tab *mn_head;
reg_tab *reg_head;
mn2_tab *mn2_head;
int error_flag,lineNumber;
FILE *errorFp,*outFp;


int sym_main(char *fname);
FILE *fill_symtab_data(FILE *input_file_pointer,char *sec);
FILE *fill_symtab_bss(FILE *input_file_pointer,char *sec);
FILE *fill_symtab_text(FILE *input_file_pointer,char *sec);
void display(symtab *head);
int return_S_value(symtab *head,char *name,reg_tab *rhead);
char type(symtab *head,char *name,reg_tab *rhead);
symtab *create_symbol_table(symtab *head,char *name,char *typ,char *sec,char *val,int line);
int validate_symbol(symtab *head,char *name,reg_tab *rhead);
int is_symbol(symtab *head,char *name);
mn_val *insert_mn_val(mn_val *head,char *rm,char *reg,char *data);
mn_val *create_mn_val(mn_val *head,char *val);
mn_tab *insert_Mnemonic(mn_tab *mhead,char *val);
mn_tab *create_mn(mn_tab *head);
void disp_mn(mn_val *head);
void display_mn(mn_tab *head);
int is_mnemonic(mn_tab *head,char *name);
char *ret_mn_value(mn_val *head,char *rm,char *reg);
char *return_mn_value(mn_tab *head,char *name,char *rm,char *reg);
reg_tab *insert_Register(reg_tab *rhead,char *val);
reg_tab *create_reg_table(reg_tab *head);
void display_reg(reg_tab *head);
int is_register(reg_tab *head,char *name);
rr *create_RR_combination(rr *head);
rr *insert_RegCombn(rr *head,char *op1,char *op2,char *val);
char *return_RR_value(rr *head,char *reg1,char *reg2);
void display_rr(rr *head);
char *r_bit(char *operand);
mn2_tab *insert_Mnemonic2(mn2_tab *mhead,char *name,char *value);
mn2_tab *create_mn2(mn2_tab *head);
void displaymn2(mn2_tab *head);
int evaluating3Arguments(char *mnemonic,char *operand1,char *operand2);
void parse_three_args(char *line1);
void print_label(char *line1);
void parse_two_args(char *line1);
FILE *in_main(FILE *input_file_pointer);
char *m_bit(char *name);
int evaluating3Arguments(char *mnemonic,char *operand1,char *operand2);
int ret_line_number(symtab *head,char *name);
int is_mnemonic2(mn2_tab *head,char *name);
char *ret_mn2_value(mn2_tab *head,char *name);
int ret_register_number(reg_tab *head,char *name);
int check_sym_label(symtab *head,char *name);
int is_data_symbol(symtab *head,char *name);
int evaluating2Arguments(char *mnemonic,char *operand1);
int check_multiple_declaration(symtab *head);
