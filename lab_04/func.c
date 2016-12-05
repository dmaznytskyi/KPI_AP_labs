/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   func.c                                              (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/11/03 02:52:15 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2016/12/05 12:53:31 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int randInt()
{
	float num = rand() % 100;
	return (int)num;
}

float randFloat()
{
	float num = ((float)rand() / (float)(RAND_MAX)) * 100;
	int sign = rand() % 2;
	if (sign)
		num *= -1;
	return num;
}
