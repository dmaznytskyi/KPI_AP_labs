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
int		ft_atoi(char *str);

int		returnEps(void);
float	returnPrecision(int eps);

float	function1(float x, float y);
float	function2(float x, float y);
float	derivative1(float x, float y);
float	derivative2(float x, float y);
float	half(float a, float b, float y, int fun, float precision);
float	newton(float b, float y, int fun, float precision);


#endif
