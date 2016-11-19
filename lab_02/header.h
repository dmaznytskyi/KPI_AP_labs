/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   header.h                                            (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/11/01 03:49:51 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2016/11/01 17:00:36 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <curses.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>

float	area(float a, float b, float c);
float	per(float a, float b, float c);
float	pper(float per);
void	heights(float a, float b, float c, float area, int i);
void	bisektrisi(float a, float b, float c, float pper, int i);
void	mediani(float a, float b, float c, int i);
void	errorer(int code);
int		input_checker(float a, float b, float c);
void	input_provider(void);

#endif
