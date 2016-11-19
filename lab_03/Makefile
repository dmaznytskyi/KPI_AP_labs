# **************************************************************************** #
#                                                                              #
#                                                         _____    ______      #
#    Makefile                                            (____ \  |  ___ \     #
#                                                         _   \ \ | | _ | |    #
#    By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |    #
#                                                        | |__/ / | || || |    #
#    Created: 2016/11/01 01:24:39 by dmaznytskyi         |_____/  |_||_||_|    #
#    Updated: 2016/11/19 01:44:25 by dmaznytskyi                               #
#                                                                              #
# **************************************************************************** #

NAME = lab_03

FLAGS = -Wall -Wextra -Werror -O3

SRCS =	lab_03.c	error.c		func.c		ft_atoi.c\
		zadanie1.c	zadanie2.c	zadanie3.c		

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
