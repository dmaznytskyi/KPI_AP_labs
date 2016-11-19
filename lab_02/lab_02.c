/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   lab_02.c                                            (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/11/01 03:41:30 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2016/11/01 19:21:29 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

float	g_a;
float	g_b;
float	g_c;

char	g_forbiden[] = "abcdefghijklmnopqrstuvwxyzйцукенгшщзхъфывапролджэячсмитьбю!@#$%%^&*()_+-=\\|'\"/,{}[]";
char	input_buffer[100];

int		main(void)
{
	input_provider();
	input_checker(g_a, g_b, g_c);
	printf("Площа дорівнює %.3f квадратних одиниць.\n", area(g_a, g_b, g_c));
	printf("\nПериметр дорівнює %.3f одиниць.\n", per(g_a, g_b, g_c));
	heights(g_a, g_b, g_c, area(g_a, g_b, g_c), 0);
	bisektrisi(g_a, g_b, g_c, pper(per(g_a, g_b, g_c)), 0);
	mediani(g_a, g_b, g_c, 0);
	return (0);
}

//площа
float	area(float a, float b, float c)
{
	float pp;

	pp = pper(per(a, b, c));
	return sqrt(pp * (pp - a) * (pp - b) * (pp - c));
}	
//периметр
float	per(float a, float b, float c)
{
	return (a + b + c);
}
//воспомогательный полупериметр
float	pper(float per)
{
	return (per / 2);
}
//ввод и его проверка
void	input_provider(void)
{
	int	flag;

	flag = 0;
	while (true)
	{
		printf("Введіть сторони трикутника(вони повинні бути більше нуля!)\n");	
		for (int i = 0; i < 3; i++)
		{
			printf("Введіть %d сторону й натисніть enter: ", (i + 1));
			scanf("%s", input_buffer);
			if (strpbrk(input_buffer, g_forbiden) != NULL)
			{
				errorer(3);
				break;
			}
			else
			{
				if (i==0) g_a = atof(input_buffer);
				if (i==1) g_b = atof(input_buffer);
				if (i==2) g_c = atof(input_buffer);
			}
		}
		flag = input_checker(g_a, g_b, g_c);
		if (flag != -1)
			if (flag != 1)
				break;
			else
			{
				errorer(1);
				errorer(4);
			}
		else
		{
			errorer(2);
			errorer(4);
		}
	}
	printf("\nВведені сторони вірні. Виконую розрахунки...\n");
}
