/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   header.h                                            (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/11/01 03:49:51 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2016/12/14 14:21:05 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>

void	error(int code);
int	ft_atoi(char *str);
float	randFloat(void);
void	printSLAR(float **ar, float *cons, int n);
int	returnEps(void);
float	returnPrecision(int eps);
float	**allocFArr(int a);
void	rand_inp(float **fa, int n);
void	kb_inp(float **fa, int n);
void	const_rand_inp(float *cons, int n);
void	const_kb_inp(float *cons, int n);

#endif
