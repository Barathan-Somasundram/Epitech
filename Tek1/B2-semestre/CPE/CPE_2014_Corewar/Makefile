##
## Makefile for Corewar in /home/somasu_b/rendu/corewar/CPE_2014_Corewar
##
## Made by somasu_b
## Login   <somasu_b@epitech.net>
##
## Started on  Thu Apr 10 02:04:40 2014 somasu_b
## Last update Sun Apr 13 21:02:49 2014 somasu_b
##

CC			=	gcc

RM			=	rm -f

CFLAGS			=	-I./inc

SRCS_COMMUN		=	./src/src_com/op.c

ASM_NAME		=	./asm/asm

VM_NAME			=	./corewar/corewar

SRCS_ASM_MY		=	./src/src_asm/main.c			\
				./src/src_asm/my/get_next_line.c	\
				./src/src_asm/my/my_strncpy.c 		\
				./src/src_asm/my/my_strlen.c 		\
				./src/src_asm/my/my_strcmp.c 		\
				./src/src_asm/my/my_getnbr.c 		\
				./src/src_asm/my/my_get_token.c 	\
				./src/src_asm/my/my_putnbr.c 		\
				./src/src_asm/my/my_error.c 		\
				./src/src_asm/my/my_strcat.c 		\
				./src/src_asm/my/epur_str.c 		\
				./src/src_asm/my/my_exit.c 		\
				./src/src_asm/my/my_epurstr.c		\

SRCS_ASM_CHECK		=	./src/src_asm/check/verif_asm.c		\
				./src/src_asm/check/verif_asm2.c	\
				./src/src_asm/check/verif_value.c	\

SRCS_ASM_PARSER		=	./src/src_asm/parser/parse_code.c 	\
				./src/src_asm/parser/parser_command.c 	\
				./src/src_asm/parser/fct_parse_code.c	\


SRCS_ASM_OPCODE		=	./src/src_asm/op_code/ld.c 		\
				./src/src_asm/op_code/live.c 		\
				./src/src_asm/op_code/st.c 		\
				./src/src_asm/op_code/add.c 		\
				./src/src_asm/op_code/sub.c 		\
				./src/src_asm/op_code/and.c 		\
				./src/src_asm/op_code/or.c 		\
				./src/src_asm/op_code/xor.c 		\
				./src/src_asm/op_code/ldi.c 		\
				./src/src_asm/op_code/zjmp.c 		\
				./src/src_asm/op_code/fork.c 		\
				./src/src_asm/op_code/sti.c 		\
				./src/src_asm/op_code/lldi.c 		\
				./src/src_asm/op_code/lld.c 		\
				./src/src_asm/op_code/aff.c 		\
				./src/src_asm/op_code/lfork.c 		\

SRCS_ASM		=	./src/src_asm/asm_init.c		\
				./src/src_asm/compile_msg.c		\
				./src/src_asm/label_search.c		\
				./src/src_asm/put_byte_to_buff.c	\
				./src/src_asm/put_value_to_buff.c	\
				./src/src_asm/rmv_node.c		\
				./src/src_asm/write_cor_file.c		\
				./src/src_asm/swap_byte.c		\
				$(SRCS_ASM_MY)				\
				$(SRCS_ASM_CHECK)			\
				$(SRCS_ASM_PARSER)			\
				$(SRCS_ASM_OPCODE)			\
				$(SRCS_COMMUN)				\

OBJS_ASM		=	$(SRCS_ASM:.c=.o)

SRCS_VM_INITIAL		=	./src/src_vm/initial/my_strings_1.c	\
				./src/src_vm/initial/my_strings_2.c	\
				./src/src_vm/initial/error.c		\
				./src/src_vm/initial/champ.c		\
				./src/src_vm/initial/fill_champs.c	\
				./src/src_vm/initial/init.c		\
				./src/src_vm/initial/my_list.c		\
				./src/src_vm/initial/place_champs.c	\

SRCS_VM_RETCODE		=	./src/src_vm/retcode/functions_1.c	\
				./src/src_vm/retcode/functions_2.c	\
				./src/src_vm/retcode/functions_3.c	\
				./src/src_vm/retcode/functions_4.c

SRCS_VM_FIGHT		=	./src/src_vm/fight/lets_fight.c		\
				./src/src_vm/fight/my_gets_info.c	\
				./src/src_vm/fight/finish.c

SRCS_VM			=	$(SRCS_VM_INITIAL)		\
				$(SRCS_VM_RETCODE)		\
				$(SRCS_VM_FIGHT)		\
				$(SRCS_COMMUN)			\
				./src/src_vm/main.c

OBJS_VM			=	$(SRCS_VM:.c=.o)


all:	$(ASM_NAME) $(VM_NAME)

$(ASM_NAME):	$(OBJS_ASM)
	$(CC) -o $(ASM_NAME) $(OBJS_ASM) $(CFLAGS)

$(VM_NAME):	$(OBJS_VM)
	$(CC) -o $(VM_NAME) $(OBJS_VM) $(CFLAGS)

clean:
	$(RM) $(OBJS_ASM) $(OBJS_VM)

fclean:		clean
	$(RM) $(ASM_NAME) $(VM_NAME)

re:	fclean all

.PHONY: all fclean re
