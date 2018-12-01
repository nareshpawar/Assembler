CC=gcc
SOURCE= main.c create_mnemonic_table.c create_reg_table.c create_rr_value.c sym_main.c create_symbol_table.c m_bit.c r_bit.c is_literal.c return_L_value.c create_mnemonic2_table.c is_memory.c passtwomain.c is_mnemonic.c return_mn_value.c is_register.c return_S_value.c is_symbol.c validate_symbol.c evaluating3Arguements.c ret_line_number.c is_mnemonic2.c ret_mn2_value.c ret_register_number.c check_sym_label.c is_data_symbol.c evaluating2Arguements.c type.c check_multiple_declaration.c
OBJECTS=$(SOURCE: .c=.o)
TARGET=table

all: $(SOURCE) $(TARGET)

$(TARGET):$(OBJECTS)
	$(CC) $(OBJECTS) -o $@ 
clean:
	rm ./$(TARGET) *~
