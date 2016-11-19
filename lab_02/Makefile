# **************************************************************************** #
#                                                                              #
#                                                         _____    ______      #
#    Makefile                                            (____ \  |  ___ \     #
#                                                         _   \ \ | | _ | |    #
#    By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |    #
#                                                        | |__/ / | || || |    #
#    Created: 2016/11/01 01:24:39 by dmaznytskyi         |_____/  |_||_||_|    #
#    Updated: 2016/11/01 19:29:55 by dmaznytskyi                               #
#                                                                              #
# **************************************************************************** #

NAME = lab_02

FLAGS = -Wall -Wextra -Werror -O3

SRCS = lab_02.c input_checker.c errorer.c hbm_func.c

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
