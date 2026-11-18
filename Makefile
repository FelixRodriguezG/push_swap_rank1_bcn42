# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imelkonj <imelkonj@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/17 21:28:12 by imelkonj          #+#    #+#              #
#    Updated: 2026/11/17 21:28:15 by imelkonj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==============================================================================
# 1. NAME OF PROGRAM PUSH_SWAP AND NAME OF CHECKER
# ==============================================================================

NAME        = push_swap
#CHECKER 	= checker   <-- DESCOMENTAR SI HAY BONUS

# ==============================================================================
# 2. TOOLS, FLAGS AND VARIABLES 
# ==============================================================================

SHELL      := /bin/bash
CC          = cc
RM          = rm -f
LIBFT_DIR   = libft
INCLUDES    = includes
SRCS        = srcs
LIBFT       = $(LIBFT_DIR)/libft.a
HEADER      = $(INCLUDES)/push_swap.h

# Definimos CFLAGS asegurando que las rutas de inclusión sean correctas
CFLAGS      = -Wall -Wextra -Werror -I$(INCLUDES) -I$(LIBFT_DIR)

# ==============================================================================
# 3. ANSI COLORS - OUTPUT FORMAT
# ==============================================================================

DEF_COLOR   = \033[0m
GRAY        = \033[38;2;128;128;128m
RED         = \033[38;2;255;85;85m
GREEN       = \033[38;2;80;250;123m
YELLOW      = \033[38;2;255;215;0m
BLUE        = \033[38;2;97;175;239m
MAGENTA     = \033[38;2;189;147;249m
CYAN        = \033[38;2;139;233;253m
WHITE       = \033[38;2;255;255;255m

# ==============================================================================
# 4. ARCHIVOS FUENTE Y OBJETOS
# ==============================================================================
		
SRCS_MANDATORY = push_swap.c 
SRCS_BONUS     = checker.c

#  SRC_FILES = $(SRCS_BONUS) $(SRCS_MANDATORY)  <-- DESCOMPENTAR SI HAY BONUS
SRC_FILES = $(SRCS_MANDATORY)

OBJS = $(SRC_FILES:.c=.o)

# ============================================================================== 
# 5. REGLAS PRINCIPALES
# ==============================================================================
 
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@printf "    $(GREEN)─────────────────────────────────────────$(DEF_COLOR)\n"
	@printf "    $(GREEN) ✔ Binario $(CYAN)%-10s$(GREEN) creado con éxito!$(DEF_COLOR)\n" "$(NAME)"
	@printf "    $(GREEN)─────────────────────────────────────────$(DEF_COLOR)\n"
    
$(LIBFT):
	@make -C $(LIBFT_DIR)
	@printf "    $(GREEN)─────────────────────────────────────────$(DEF_COLOR)\n"
	@printf "    $(GREEN) ✔ Librería $(CYAN)%-10s$(GREEN) creada con éxito!$(DEF_COLOR)\n" "$(LIBFT)"
	@printf "    $(GREEN)─────────────────────────────────────────$(DEF_COLOR)\n"

%.o: %.c $(HEADER)
	@printf "$(CYAN)⚙  %-16s$(DEF_COLOR) %-20s $(CYAN)->$(DEF_COLOR) $(GREEN)%s$(DEF_COLOR)\n" "[ COMPILANDO ]" "$<" "$@"
	@$(CC) $(CFLAGS) -c $< -o $@	
# ==============================================================================
# 6. REGLAS DE LIMPIEZA ALINEADAS EN COLUMNAS
# ==============================================================================

clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@printf "$(RED)    %-20s$(DEF_COLOR) - Objetos temporales (.o) eliminados.\n" "[ LIMPIANDO ]"

fclean: clean 
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@printf "$(RED)    %-20s$(DEF_COLOR) - Librería $(CYAN)%s$(DEF_COLOR) eliminada.\n" "[ LIMPIANDO TODO ]" "$(NAME)"

re: fclean
	@printf "$(YELLOW)    %-20s$(DEF_COLOR) - Recompilando todo el proyecto...\n\n" "[ RECOMPILANDO ]"
	@make all

.PHONY: all clean fclean re
