/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   zadanie1.c                                          (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/11/03 02:37:35 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2016/11/15 00:07:40 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	fb1[] = "abcdefghijklmnopqrstuvwxyzйцукенгшщзхъфывапролджэячсмитьбю!@#$%%^&*()_+=\\|'\"/,{}[]";
char	input_buffer[100];

void	zadanie1()
{
	//блок ввода данных и их проверка
	float	y = 1;
	float	x;
	float	d = 1.0;
	float	to = 0;
	float	yk;
	int		to_tmp;
	int		k;
	int		k_state_zero; //0 если меньше нуля, 1 если больше
	int		k_state_mod2; //0 если парное, 1 если не парное

	printf("Введiть аргумент, степiнь i точнiсть обчислень.\n");
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			printf("Введiть степiнь кореня 'k' (Це повинно бути цiле число i не може дорiвнювати нулю!): ");
			scanf("%s", input_buffer);
			if (strpbrk(input_buffer, fb1) != NULL)
			{
				error(1);
				error(2);			
				break;
			}
			else
			{
				k = atof(input_buffer);
				if (k == 0)
				{
					error(3);
					break;
				}
				if (k > 0) k_state_zero = 1; else k_state_zero = 0;
				if ((k % 2) == 0) k_state_mod2 = 0; else k_state_mod2 = 1;
				i++;
			}
		}
		if (i == 1)
		{
			printf("Виходячи з введеної степенi, \n");
			//ввод если k парное и меньше нуля
			if (k_state_zero == 0 && k_state_mod2 == 0)
			{
				printf("введіть аргумент 'х' (Це повинно бути число строго більше нуля!): ");
				scanf("%s", input_buffer);
				if (strpbrk(input_buffer, fb1) != NULL)
				{
					error(1);
					error(2);
					break ;
				}
				else
				{
					if (x <= 0)
					{
						error(10);
						break ;
					}
					x = atof(input_buffer);
				}
				i++;
			}
			//ввод если k парное и больше нуля
			if (k_state_zero == 1 && k_state_mod2 == 0)
			{
				printf("введіть аргумент 'х' (Це повинно бути число більше або рівне нулю!): ");
				scanf("%s", input_buffer);
				if (strpbrk(input_buffer, fb1) != NULL)
				{
					error(1);
					error(2);
					break ;
				}
				else
				{
					if (x < 0)
					{
						error(11);
						break ;
					}
					x = atof(input_buffer);
				}
				i++;
			}
			//ввод если k непарное и меньше нуля
			if (k_state_zero == 0 && k_state_mod2 == 1)
			{
				printf("введіть аргумент 'х' (Це повинно бути ненульове число!): ");
				scanf("%s", input_buffer);
				if (strpbrk(input_buffer, fb1) != NULL)
				{
					error(1);
					error(2);
					break ;
				}
				else
				{
					if (x == 0)
					{
						error(12);
						break ;
					}
					x = atof(input_buffer);
				}
				i++;
			}
			//ввод если k непарное и больше нуля
			if (k_state_zero == 1 && k_state_mod2 == 1)
			{
				printf("введіть аргумент 'х' (Це повинно бути будь-яке число!): ");
				scanf("%s", input_buffer);
				if (strpbrk(input_buffer, fb1) != NULL)
				{
					error(1);
					error(2);
					break ;
				}
				else
					x = atof(input_buffer);
				i++;
			}	
		}
		if (i == 2)
		{
			printf("Введiть точність обчислень (Це повинно бути цiле число від 0 до 6 (знаків після коми)!): ");
			scanf("%s", input_buffer);
			if (strpbrk(input_buffer, fb1) != NULL)
			{
				error(1);
				error(2);
				break;
			}
			else
			{
				to_tmp = atof(input_buffer);
				if ((to_tmp >= 0) && (to_tmp <= 6))
				{
					switch (to_tmp)
					{
						case 0: to = 1; break ;
						case 1: to = 0.1; break ;
						case 2: to = 0.01; break ;
						case 3: to = 0.001; break ;
						case 4: to = 0.0001; break ;
						case 5: to = 0.00001; break ;
						case 6: to = 0.000001; break ;
					}
				}
				i++;
			}

		}
	}
	//Блок вычислений
	while (fabs(d) >= to)
	{
		exponent(k, y, &yk);
		root(k, &y, &x, &yk, &d);
	}
	printf("\nКорінь %d степені з %f дорівнює %.*f\n\n", k, x, to_tmp, y);
	printf("\e[32m\e[1m>>> УСПІШНО <<<\e[0m Підпрограма виконана!\n\n");
}
