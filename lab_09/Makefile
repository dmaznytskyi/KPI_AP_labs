# **************************************************************************** #
#                                                                              #
#                                                         _____    ______      #
#    Makefile                                            (____ \  |  ___ \     #
#                                                         _   \ \ | | _ | |    #
#    By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |    #
#                                                        | |__/ / | || || |    #
#    Created: 2016/11/01 01:24:39 by dmaznytskyi         |_____/  |_||_||_|    #
#    Updated: 2016/12/07 16:45:14 by dmaznytskyi                               #
#                                                                              #
# **************************************************************************** #

NAME = lab_09

FLAGS = -Wall -Wextra -Werror -O3

SRCS =	lab_09.c error.c ft_atoi.c func.c ft_strcpy.c

HEADER = -I header.h

BINS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
	gcc -o $(NAME) $(BINS) $(HEADER)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(BINS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
