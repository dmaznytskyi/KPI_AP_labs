/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   func.c                                              (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/11/03 02:52:15 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2016/12/14 14:44:29 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	f[] = "abcdefghijklmnopqrstuvwxyzйцукенгшщзхъфывапролджэячсмитьбю!@#$%%^&*()_+=\\|'\"/,{}[]";
char	input_buffer[100];

float	randFloat()
{
	float num = ((float)rand() / (float)(RAND_MAX)) * 100;
	int sign = rand() % 2;
	if (sign)
		num *= -1;
	return num;
}

int	returnEps()
{
	int inpcheck = 0;
	char term;
	int eps;

	do
	{
		printf("Введіть точність обчислення : ");
		scanf("%d%c", &eps, &term);
		if ( term != '\n' || eps < 0 || eps > 6 ) {
			printf("Помилка вводу, число повинно бути 0 < e <= 6\n");
			printf("Спробуйте ще раз або натисніть Ctrl+C для виходу\n");
			inpcheck = 0;
			fflush(stdin);
		}
		else inpcheck = 1;
	} while (!inpcheck);

	return eps;
}

float	returnPrecision(int eps)
{
	float precision = 1;

	for (int i = 0; i < eps; i++)
	{
		precision *= 0.1;
	}

	return precision;
}

float	**allocFArr(int a)
{
	int i = 0;

	float	**ret = calloc(a, sizeof(float *));
	if (ret)
	{
		while (i < a)
		{
			ret[i] = (float *)calloc(a, sizeof(float *));
			i++;
		}
		return (ret);
	}
	else
		return (NULL);
}

void	rand_inp(float **fa, int n)
{
	int	i = 0;
	int	j = 0;

	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			fa[i][j] = randFloat();
			j++;
		}
		i++;
	}
}

void	kb_inp(float **fa, int n)
{
	int	i = 0;
	int	j = 0;

	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			printf("Введіть %d аргумент рівняння %d рівняння системи: ", j + 1, i + 1);
			scanf("%s", input_buffer);
			if (strpbrk(input_buffer, f) != NULL)
			{
				error(1);
				error(2);
				return ;
			}
			else
			{
				fa[i][j] = atof(input_buffer);
				j++;
			}
		}
		i++;
	}
}

void	const_rand_inp(float *fa, int n)
{
	int	i = 0;

	while (i < n)
	{
		fa[i] = randFloat();
		i++;
	}
}

void	const_kb_inp(float *fa, int n)
{
	int	i = 0;

	while (i < n)
	{
		printf("Введіть константу %d рівняння системи: ", i + 1);
		scanf("%s", input_buffer);
		if (strpbrk(input_buffer, f) != NULL)
		{
			error(1);
			error(2);
			return ;
		}
		else
		{
			fa[i] = atof(input_buffer);
			i++;
		}
	}
}

void	printSLAR(float **ar, float *cons, int n)
{
	for (int a = 0; a < n; a++)
	{
		printf("| ");
		for (int b = 0; b < n; b++)
		{
			if ((b != 0) && (ar[a][b] >= 0))
				printf(" +");
			else
				printf(" ");
			printf("%g*x%d", ar[a][b], b + 1);
			if (b == (n - 1))
				printf(" = %g\n", cons[a]);
		}
	}
}
