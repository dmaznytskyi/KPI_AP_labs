/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   func.c                                              (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/11/03 02:52:15 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2016/11/14 19:15:38 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

float	powerof(float number, int powerto){
	int number_o = 1;
	for (int i = 0; i < powerto; i++){
		number_o = number_o * number;
		//printf("number_o %f\n", number_o);
	}
	return number_o;
}

void exponent (int k, float y, float *yk)
{
	int		ke;

	ke = abs(k);
	*yk = y;
	while (ke > 2)
	{
		*yk = *yk * y;
		ke = ke - 1;
	}
}

void root (int k, float *y, float *x, float *yk, float *d)
{
	int kr;
	kr = abs(k);
	*d = (1.0 / kr) * ((*x / *yk) - *y);
	*y = *y + *d;
}
