/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   lab_07.c                                            (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/12/14 16:05:19 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2016/12/14 16:05:25 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	forbiden[] = "abcdefghijklmnopqrstuvwxyzйцукенгшщзхъфывапролджэячсмитьбю!@#$%%^&*()_+=\\|'\"/,{}[]";
char	input_buffer[100];

float g_y = 0.0;
int g_fun = 0;
int g_meth = 0;

int main()
{
	float a, b;

	printf("        y       1   1             \n");
	printf("[1]  cos- - 2sin- - - = 0, x [a,b]\n");
	printf("        x       x                 \n\n");

	printf("[2]  sin(ln x) - cos(ln x) + yln x = 0, x [a,b]\n\n");

	printf("Виберіть рівняння [1/2] або 0 для виходу: ");
	scanf("%s", input_buffer);
	if (strpbrk(input_buffer, forbiden) != NULL)
	{
		error(1);
		error(2);
		return (0);
	}
	else
	{
		switch (ft_atoi(input_buffer))
		{
			case 1: g_fun = 1; break;
			case 2: g_fun = 2; break;
			default: return(0); break;
		}
	}
	printf("Введіть a : ");
	scanf("%s", input_buffer);
	if (strpbrk(input_buffer, forbiden) != NULL)
	{
		error(1);
		error(2);
		return (0);
	}
	else
	{
		a = atof(input_buffer);
	}
	printf("Введіть b : ");
	scanf("%s", input_buffer);
	if (strpbrk(input_buffer, forbiden) != NULL)
	{
		error(1);
		error(2);
		return (0);
	}
	else
	{
		b = atof(input_buffer);
	}
	printf("Введіть y : ");
	scanf("%s", input_buffer);
	if (strpbrk(input_buffer, forbiden) != NULL)
	{
		error(1);
		error(2);
		return (0);
	}
	else
	{
		g_y = atof(input_buffer);
	}
	if(g_y == 0)
	{
		error(11);
		return 0;
	}
	int eps = returnEps();
	float precision = returnPrecision(eps);

	printf("[1] Метод половинного ділення\n");
	printf("[2] Метод Ньютона\n");
	printf("Виберіть метод [1/2] або 0 для виходу: ");
	scanf("%s", input_buffer);
	if (strpbrk(input_buffer, forbiden) != NULL)
	{
		error(1);
		error(2);
		return (0);
	}
	else
	{
		switch (ft_atoi(input_buffer))
		{
			case 1: g_meth = 1; break;
			case 2: g_meth = 2; break;
			default: return(0); break;
		}
	}
	if(g_meth == 1)
	{
		printf("Відповідь: %f\n", half(a, b, g_y, g_fun, precision));
	}
	else if(g_meth == 2)
	{
		printf("Відповідь: %f\n", newton(b, g_y, g_fun, precision));
	}

	printf("\n");
	printf("Розрахувати іншим методом? [1 - так, 0 - ні]: ");
	scanf("%s", input_buffer);
	if (strpbrk(input_buffer, forbiden) != NULL)
	{
		error(1);
		error(2);
		return (0);
	}
	else
	{
		switch (ft_atoi(input_buffer))
		{
			case 1: if (g_meth == 1)
				{
					g_meth = 2;
					printf("Відповідь: %f\n", newton(b, g_y, g_fun, precision));
				} 
				else 
				{
					g_meth = 1; 
					printf("Відповідь: %f\n", half(a, b, g_y, g_fun, precision));
				} break;
			default: return(0); break;
		}
	}
	return 0;
}
