/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   header.h                                            (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/11/01 03:49:51 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2016/11/17 05:14:18 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>

void	zadanie1(void);
void	zadanie2(void);
void	zadanie3(void);

float	powerof(float number, int powerto);
void	exponent(int k, float y, float *yk);
void	root(int k, float *y, float *x, float *yk, float *d);
void	error(int code);
int		ft_atoi(char *str);

#endif
