# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/03 15:22:31 by tdontos-          #+#    #+#              #
#    Updated: 2019/08/03 15:22:32 by tdontos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= asm

SRCDIR	= ./src
OBJDIR	= ./obj
ASM		= /asm/

SRC		= asm.c print.c pars.c op.c operation.c read_arg.c opers_list.c
OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
FTDIR	= libft
FT_LIB	= $(addprefix $(FTDIR)/,libft.a)
FT_INC	= -I $(FTDIR)
FT_LNK	= -L $(FTDIR) -l ft
all: obj $(FT_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:$(SRCDIR)$(ASM)%.c
	$(CC) $(CFLAGS) $(FT_INC) -o $@ -c $<

$(FT_LIB):
	@make -C $(FTDIR)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FT_LNK) -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	@make -C $(FTDIR) clean	

fclean: clean
	rm -f $(NAME)
	@make -C $(FTDIR) fclean	

re: fclean all