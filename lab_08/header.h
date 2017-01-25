/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   header.h                                            (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/11/01 03:49:51 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2017/01/13 13:57:09 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>

#define BLACK "\033[0;30m" 
#define RED "\033[0;31m" 
#define GREEN "\033[0;32m" 
#define ORANGE "\033[0;33m" 
#define BLUE "\033[0;34m" 
#define PURPLE "\033[0;35m" 
#define CYAN "\033[0;36m" 
#define LGREY "\033[0;37m" 

#define DGRAY "\033[1;30m" 
#define LRED "\033[1;31m" 
#define LGREEN "\033[1;32m" 
#define YELLOW "\033[1;33m" 
#define LBLUE "\033[1;34m" 
#define LPURPLE "\033[1;35m" 
#define LCYAN "\033[1;36m" 
#define WHITE "\033[1;37m" 

#define NC "\033[0m"

typedef struct 	s_complex
{
	float	real;
	float	imaginary;
}		complex;

void	error(int code);
int	ft_atoi(char *str);

int	ret_int_inp(char *str);
double	ret_fl_inp(char *str);
void	draw_circuits(void);
void	cir1(void);
void	cir2(void);
void	cir3(void);
void	cir4(void);

#endif
