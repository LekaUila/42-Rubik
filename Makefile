# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 14:52:06 by lflandri          #+#    #+#              #
#    Updated: 2024/04/09 18:07:42 by lflandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= Rubik

MAKEFLAGS	= --no-print-directory

SRC 		=	main.cpp \
				class/Face.cpp \
				class/Rubik.cpp \

				
				





#couleur
BLACK		=\\e[0;30m
GREY		=\\e[1;30m
BLACKRED	=\\e[0;31m
PINK		=\\e[1;31m
BLACKGREEN	=\\e[0;32m
WHITEGREEN	=\\e[1;32m
ORANGE		=\\e[0;33m
YELLOW		=\\e[1;33m
BLACKBLUE	=\\e[0;34m
WHITEBLUE	=\\e[1;34m
BLACKPURPLE	=\\e[0;35m
WHITEPURPLE	=\\e[;1;35m
BLACKCYAN	=\\e[0;36m
WHITECYAN	=\\e[1;36m
WHITEGREY	=\\e[0;37m
WHITE		=\\e[1;37m

NEUTRE		= \\e[0;m

#effect
BLINK		=\\e[5m

RESET		=\\e[25m

all :	${NAME}
			@echo "${WHITEGREEN}PROGRAMME \"${BLINK}${NAME}${RESET}\" PRET POUR EXECUTION !${NEUTRE}"

${NAME}: ${SRC}
			@echo "${BLACKPURPLE}==================== CRÉATION ==================${WHITE}" 
			c++  -Wall -Wextra -Werror -std=c++98 -o ${NAME} ${SRC}
			@echo "${BLACKPURPLE}================== FIN CRÉATION ================${NEUTRE}" 

clean :
			@echo -n "${BLACKRED}"
			@echo "Nothing to supress"
			@echo -n "${NEUTRE}"

fclean :	#clean
			@echo -n "${BLACKRED}"
			rm -f ${NAME}
			@echo -n "${NEUTRE}"

re :		fclean all

rebonus : fclean bonus

.PHONY : all clean fclean re bonus