/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   input_checker.c                                     (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/11/01 04:14:37 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2016/11/01 19:17:46 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	input_checker(float a, float b, float c)
{
	if ((a > 0) && (b > 0) && (c > 0))
	{
		if (((a + b) > c) && ((b + c) > a) && ((c + a) > b))
			return (0);
		else
			return (1);
	}
	else
		return (-1);
}
