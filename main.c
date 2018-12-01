#include"struct.h"


int main(int argc,char *argv[])
{
//---------------------------------------------------- Declaring Heads-----------------------------------------------------------------------
	 mn_head=NULL;	
	 mn_tab *mhead;
         reg_tab *rhead;
	 reg_head=NULL;
         rr *rrhead;
	 rr_head = NULL;
         mn2_tab *mn2head;
	 mn2_head = NULL;
	
//--------------------------------------------------- CREATE TABLES -------------------------------------------------------------------------
//---------------------------------------------------2 arguments MNEMONIC TABLE--------------------------------------------------------------
	mn_head = create_mn(mn_head);
	mhead = mn_head;
	//display_mn(mhead);
	//printf("%d\n",is_mnemonic(mhead,"mov"));
	//printf("%s\n",return_mn_value(mhead,"mov","RR","ax"));

//-----------------------------------------------------REGISTER TABLE------------------------------------------------------------------------
	reg_head = create_reg_table(reg_head);
	rhead = reg_head;
	//display_reg(rhead);
	//	printf("%d",is_register(rhead,"eax"));
	//	printf("%d",is_register(rhead,"ax"));
	//	printf("%d",is_register(rhead,"ex"));

//-----------------------------------------------------------REGISTER_REGISTER TABLE---------------------------------------------------------
	rr_head = create_RR_combination(rr_head);	
	rrhead = rr_head;	
	//display_rr(rrhead);
	//	printf("%s",return_RR_value(rrhead,"eax","eax"));
	
//------------------------------------------------------------SYMBOL TABLE-------------------------------------------------------------------
	sym_main(argv[1]);
	//	printf("%s\n",m_bit("dword[eax]"));
	//	printf("%s\n",m_bit("dword[main]"));
	//		printf("%s\n",r_bit("edx"));
	//	if(strcmp(m_bit("dword[eax]"),r_bit("edx")) == 0)
	//		printf("1");

//---------------------------------------------------------- 1 argument1 Mnemonic Table------------------------------------------------------
	mn2_head = create_mn2(mn2_head);
	mn2head = mn2_head;
	//displaymn2(mn2head);	
	printf("\n");
	

//--------------------------------------------------------- PASS TWO-------------------------------------------------------------------------
	passtwomain(argv[1]);
}
