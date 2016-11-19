/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   hbm_func.c                                          (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/11/01 15:03:47 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2016/11/01 19:18:57 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	heights(float a, float b, float c, float area, int i)
{
	float side[3] = {a, b, c};
	float hei[3];

	hei[0] = 2 * area / a;
	hei[1] = 2 * area / b;
	hei[2] = 2 * area / c;
	while (i < 3)
	{
		printf("Висота, проведена до сторони довжиною ");
		printf("%.3f дорівнює %.3f одиниць\n", side[i], hei[i]);
		i++;
	}
}

void	bisektrisi(float a, float b, float c, float pper, int i)
{
	float side[3] = {a, b, c};
	float bis[3];

	bis[0] = (2 / (b + c)) * sqrt(b * c * pper * (pper - a)); 
	bis[1] = (2 / (a + c)) * sqrt(a * c * pper * (pper - b));
	bis[2] = (2 / (a + b)) * sqrt(a * b * pper * (pper - c));
	while (i < 3)
	{
		printf("Бісектриса, проведена до сторони довжиною ");
		printf("%.3f дорівнює %.3f одиниць\n", side[i], bis[i]);
		i++;
	}
}

void	mediani(float a, float b, float c, int i)
{
	float side[3] = {a, b, c};
	float med[3];

	med[0] = sqrt(2 * b * b + 2 * c * c - a * a) / 2;
	med[1] = sqrt(2 * a * a + 2 * c * c - b * b) / 2;
	med[2] = sqrt(2 * a * a + 2 * b * b - c * c) / 2;
	while (i < 3)
	{
		printf("Медіана, проведена до сторони довжиною ");
		printf("%.3f дорівнює %.3f одиниць\n", side[i], med[i]);
		i++;
	}
}
