# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angassin <angassin@student.19.be>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 17:16:32 by angassin          #+#    #+#              #
#    Updated: 2023/04/03 10:48:54 by angassin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-------------------------------COLORS------------------------------------------

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
BLUE='\033[1;94m'
RED='\033[1;91m'

#-------------------------------VARIABLES---------------------------------------

NAME		= push_swap

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g

DEBUG		=  -g -fsanitize=address


#--------------------------------SOURCES----------------------------------------

SRC		= $(PUSH_SWAP_SRC) $(UTILS_SRC)

LIBFT_A 	= libft.a
LIBFT_DIR 	= libft/	
LIBFT		= $(addprefix libft/, $(LIBFT_A))

PUSH_SWAP		= main.c sort.c operations.c
PUSH_SWAP_SRC	= $(addprefix src/, $(PUSH_SWAP))

UTILS		= utils.c 
UTILS_SRC	= $(addprefix utils/, $(UTILS)) 

OBJ			= $(SRC:.c=.o)

#---------------------------------RULES-----------------------------------------

%o: %c 
	@$(CC) $(CFLAGS) -Iincludes -c $< -o  $(<:.c=.o)
			
all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Making libft..." $(NONE)
	@make -C $(LIBFT_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)	
	@echo $(GREEN)"- Compiled -"$(NONE)

exe: all
	@make -C ./ clean
	@echo "     - Executing $(NAME)... \n"
	@./$(NAME) 1 5 3 2 6 55
	@echo "\n     - Done -"

debug: $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Making libft..." $(NONE)
	@make -C $(LIBFT_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@$(CC) $(CFLAGS) $(DEBUG) $(OBJ) $(LIBFT) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE) 

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean
	
re: fclean all

.PHONY:	all debug exe clean fclean re 
