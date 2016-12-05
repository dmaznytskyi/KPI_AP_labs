/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   zadanie2.c                                          (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/12/05 11:12:11 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2016/12/05 13:59:50 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	fb2[] = "abcdefghijklmnopqrstuvwxyzйцукенгшщзхъфывапролджэячсмитьбю!@#$%%^&*()_+=\\|'\"/,{}[]";
char	input_buffer[100];
int	size;

void	sort_up(float *ar, int num)
{
	float t;
	for (int a = 0; a < num - 1; a++)
		for (int b = a + 1; b <= num; b++)
		{
			if(ar[a] > ar[b])
			{
				t = ar[a];
				ar[a] = ar[b];
				ar[b] = t;
			}
		}
}

void	sort_down(float *ar, int num)
{
	float t;
	for (int a = 0; a < num - 1; a++)
		for (int b = a + 1; b <= num; b++)
		{
			if(ar[a] < ar[b])
			{
				t = ar[a];
				ar[a] = ar[b];
				ar[b] = t;
			}
		}
}

float	*kb_input(void)
{
	int	i;
	float	*ar;

	printf("Введіть розмір масиву. Він повинен бути більше нуля!\n");
	printf("(У випадку вводу від'ємного числа, воно буде перетворене у додатнє)\n");
	scanf("%s", input_buffer);
	if (strpbrk(input_buffer, fb2) != NULL)
	{
		error(1);
		error(2);
		return (NULL);
	}
	else
		if (ft_atoi(input_buffer) == 0)
		{
			error(3);
			return (NULL);
		}
		size = abs(ft_atoi(input_buffer));
	ar = (float *)malloc(sizeof(float) * size);
	i = 0;
	while (i < size)
	{
		printf("Введіть [%d] елемент масиву : ", i);
		scanf("%s", input_buffer);
		if (strpbrk(input_buffer, fb2) != NULL)
		{
			error(1);
			continue;
		}
		else
		{
			ar[i] = atof(input_buffer);
			printf("%d, %f\n", i, ar[i]);
			i++;
		}
	}
	return (ar);
}

float	*rand_gen(void)
{
	int	i;
	float	*ar;

	i = -1;
	printf("Буде застосовано генератор випадкових чисел.\n");
	size = randInt();
	printf("Випадково сгенерований розмір масиву : %d.\n", size);
	ar = (float *)malloc(sizeof(float) * size);
	while (++i < size)
	{
		ar[i] = randFloat();
		printf("Елемент масиву [%d] = %f\n", i, ar[i]);
	}
	return (ar);
}

void	zadanie2(void)
{
	float	*ar;
	int	i;

	printf("Виберіть метод наповнення масиву\n");
	printf("(1 - з клавіатури, 2 - використовуючи генератор випадкових чисел) : ");
	scanf("%s", input_buffer);
	if (strpbrk(input_buffer, fb2) != NULL)
	{
		error(1);
		error(2);
		return;
	}
	else
		switch (ft_atoi(input_buffer))
		{
			case 1: ar = kb_input(); break ;
			case 2: ar = rand_gen(); break ;
			default: error(20); error(2); return ;
		}
	printf("Виберіть метод сортування масиву\n");
	printf("(1 - за зростанням, 2 - за спаданням) : ");
	scanf("%s", input_buffer);
	if (strpbrk(input_buffer, fb2) != NULL)
	{
		error(1);
		error(2);
		return;
	}
	else
		switch (ft_atoi(input_buffer))
		{
			case 1: sort_up(ar, size); break ;
			case 2: sort_down(ar, size); break ;
			default: error(21); error(2); return ;
		}
	printf("Відсортований масив: \n");
	i = -1;
	while (++i < size)
	{
		printf("Елемент [%d] = %f\n", i, ar[i]);
	}
	return ;
}
