/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   zadanie3.c                                          (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/11/17 23:31:34 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2016/11/19 04:31:38 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	fb3[] = "abcdefghijklmnopqrstuvwxyzйцукенгшщзхъфывапролджэячсмитьбю!@#$%%^&*()_+=\\|'\"/,{}[]";
char	input_buffer[100];

void	zadanie3(void)
{
	float	a;
	float	b;
	float	c;

	float	p;
	float	q;
	float	d;

	float	u;
	float	v;
	float 	r;
	float	fi;

	float	x1;
	float	x2;
	float	x3;

	printf("\nВведіть три коефіцієнти кубічного рівняння.");
	printf("\nРівняння має вигляд (xˆ3 + axˆ2 + bx + c = 0),\nде потрібно ввести a, b, c.");
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			printf("\nВведіть a : ");
			scanf("%s", input_buffer);
			if (strpbrk(input_buffer, fb3) != NULL)
			{
				error(1);
				error(2);
				break ;
			}
			else
			{
				a = atof(input_buffer);
			}
		}
		if (i == 1)
		{
			printf("Введіть b : ");
			scanf("%s", input_buffer);
			if (strpbrk(input_buffer, fb3) != NULL)
			{
				error(1);
				error(2);
				break ;
			}
			else
			{
				b = atof(input_buffer);
			}
		}
		if (i == 2)
		{
			printf("Введіть c : ");
			scanf("%s", input_buffer);
			if (strpbrk(input_buffer, fb3) != NULL)
			{
				error(1);
				error(2);
				break ;
			}
			else
			{
				c = atof(input_buffer);
			}
		}
	}
	p = b - ((a*a) / 3);
	q = (2 * (a * a * a) / 27) - ((a * b) / 3) + c;
	d = ((p * p * p) / 27) + ((q * q) / 4);
	if (d > 0)
	{
		u = cbrtf((-1 * (q / 2)) + sqrtf(d));
		v = -1 * (p / (3 * u));
		
		x1 = (u + v) - (a / 3);
		x2 = (-1 * (u + v)) - (a / 3);
		x3 = (sqrtf(3) * (u - v)) / 2;

		printf("\nКорені рівняння : \n");
		printf("x1: %f\n", x1);
		printf("x2: %f + i * %f\n", x2, x3);
		printf("x3: %f - i * %f\n", x2, x3);
	}
	else
		if (d == 0)
		{
			x1 = (3 * (q / p)) - (a / 3);
			x2 = -1 * ((3 * q) / (2 * p));
			x3 = x2;
	
			printf("\nКорені рівняння : \n");
			printf("x1: %f\n", x1);
			printf("x2: %f\n", x2);
			printf("x3: %f\n", x3);
		}
		else
			if (d < 0)
			{
				r = sqrtf(-1 * (p * p * p) / 27);
				fi = acos(-1 * (q / (2 * r)));

				x1 = 2 * fabs(cbrtf(r)) * cos(fi / 3) - a / 3;
				x2 = 2 * fabs(cbrtf(r)) * cos((fi + 2 * M_PI) / 3) - a / 3;
				x3 = 2 * fabs(cbrtf(r)) * cos((fi + 4 * M_PI) / 3) - a / 3;

				printf("\nКорені рівняння : \n");
				printf("x1: %f\n", x1);
				printf("x2: %f\n", x2);
				printf("x3: %f\n", x3);
			}
	printf("\n\e[32m\e[1m>>> УСПІШНО <<<\e[0m Підпрограма виконана!\n\n");
}
