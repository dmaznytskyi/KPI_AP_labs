# **************************************************************************** #
#                                                                              #
#                                                         _____    ______      #
#    Makefile                                            (____ \  |  ___ \     #
#                                                         _   \ \ | | _ | |    #
#    By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |    #
#                                                        | |__/ / | || || |    #
#    Created: 2016/11/01 01:24:39 by dmaznytskyi         |_____/  |_||_||_|    #
#    Updated: 2016/11/01 03:56:54 by dmaznytskyi                               #
#                                                                              #
# **************************************************************************** #

NAME = lab_01

FLAGS = -Wall -Wextra -Werror -O3

SRCS = lab_01.c ft_atoi.c

BINS = $(SRCS:.c=.o)

HEADER = -I header.h

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
