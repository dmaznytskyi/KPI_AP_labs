/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   zadanie1.c                                          (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznyts <dmaznytskyi@gmail.com>                | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/11/29 23:36:10 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2016/12/05 11:10:36 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	fb1[] = "abcdefghijklmnopqrstuvwxyzйцукенгшщзхъфывапролджэячсмитьбю!@#$%%^&*()_+=\\|'\"/,{}[]";
char	input_buffer[100];
float	precision;
int	e;

void	getPrecision(int e)
{
	switch (e)
	{
		case 1:		precision = 0.1;	break ;
		case 2:		precision = 0.01;	break ;
		case 3:		precision = 0.001;	break ;
		case 4:		precision = 0.0001;	break ;
		case 5:		precision = 0.00001;	break ;
		case 6:		precision = 0.000001;	break ;
		default:	precision = 1;		break ;
	}
}

float	sinTeylor(float rad)
{
	float delta = rad;
	float sinus = rad;
	float n = 1;

	while (fabs(delta) >= precision)
	{
		delta *= -1 * rad * rad / ((n + 1) * (n + 2));
		sinus += delta;
		n+=2;
	}
	sinus *= pow(10, 6 - e);
	sinus /= pow(10, 6 - e);
	return sinus;
}

float	cosTeylor(float rad)
{
	float delta = 1;
	float cosin = 1;
	float n = 1;

	while (fabs(delta) >= precision)
	{
		delta *= -1 * rad * rad / (2 * n * (2 * n - 1));
		cosin += delta;
		n += 1;
	}
	return cosin;
}

void	zadanie1(void)
{
	float x1 = 0;
	float x2 = 0;
	float dx = 0;

	printf("Введіть першу межу діапазону: ");
	scanf("%s", input_buffer);
	if (strpbrk(input_buffer, fb1) != NULL)
	{
		error(1);
		error(2);			
		return;
	}
	else
		x1 = atof(input_buffer);
	printf("Введіть останню межу діапазону: ");
	scanf("%s", input_buffer);
	if (strpbrk(input_buffer, fb1) != NULL)
	{
		error(1);
		error(2);			
		return;
	}
	else
		x2 = atof(input_buffer);
	printf("Введіть крок зміни аргументу(у градусах): ");
	scanf("%s", input_buffer);
	if (strpbrk(input_buffer, fb1) != NULL)
	{
		error(1);
		error(2);			
		return;
	}
	else if (atof(input_buffer) == 0)
	{
		error(10);
		error(2);
		return ;
	}
	else if (atof(input_buffer) > 0 && (x1 > x2))
	{
		error(11);
		error(2);
		return ;
	}
	dx = atof(input_buffer);
	printf("Введіть точніть обчислень: ");
	scanf("%s", input_buffer);
	if (strpbrk(input_buffer, fb1) != NULL)
	{
		error(1);
		error(2);			
		return;
	}
	else
	{
		e = ft_atoi(input_buffer);
		if (e >= 0 && e <= 6)
			getPrecision(e);
		else
		{
			error(5);
			error(2);
			return ;
		}
	}
	printf("\e[33m| x		");
	printf("| rad		");
	printf("| sin(x)	");
	printf("| ssin(x)	");
	printf("| diff		");
	printf("| cos(x)	");
	printf("| scos(x)	");
	printf("| diff		");
	printf("|\e[0m\n");
	while (x1 <= x2)
	{
		float rad = (x1 * M_PI) / 180;
		printf("\e[33m|\e[0m %f	", x1);
		printf("\e[33m|\e[0m %f	", rad);
		printf("\e[33m|\e[0m %f	", sinTeylor(rad));
		printf("\e[33m|\e[0m %f	", sin(rad));
		printf("\e[33m|\e[0m %f	", (sinTeylor(rad) - sin(rad)));
		printf("\e[33m|\e[0m %f	", cosTeylor(rad));
		printf("\e[33m|\e[0m %f	", cos(rad));
		printf("\e[33m|\e[0m %f	", (cosTeylor(rad) - cos(rad)));
		printf("\e[33m|\e[0m\n");
		x1 = x1 + dx;
	}
}
