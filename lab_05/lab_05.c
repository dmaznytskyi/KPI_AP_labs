/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   lab_05.c                                            (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznyts <dmaznytskyi@gmail.com>                | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/11/29 21:41:30 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2016/12/05 22:10:37 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	forbiden[] = "abcdefghijklmnopqrstuvwxyzйцукенгшщзхъфывапролджэячсмитьбю!@#$%%^&*()_+=\\|'\"/,{}[]";
char	input_buffer[100];

void	a_sort(char **ar, int n)
{
	int	i;
	int	j;
	char	t[4096];

	i = 0;
	j = 1;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (ft_strcmp(ar[i], ar[j]) > 0)
			{
				*t = *ar[i];
				*ar[i] = *ar[j];
				*ar[j] = *t;
			}
			j++;
		}
		i++;
	}
}

void	d_sort(char **ar, int n)
{
	int	i;
	int	j;
	char	t[4096];

	i = 0;
	j = 1;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (ft_strcmp(ar[i], ar[j]) < 0)
			{
				*t = *ar[i];
				*ar[i] = *ar[j];
				*ar[j] = *t;
			}
			j++;
		}
		i++;
	}
}

int	main(void)
{
	char	**array;
	char	*tmp;
	int	n;
	int	len;
	int	i;

	printf("Введіть кількість рядків : ");
	scanf("%s", input_buffer);
	if (strpbrk(input_buffer, forbiden) != NULL)
	{
		error(1);
		error(2);
		return (0);
	}
	else
	{
		if (ft_atoi(input_buffer) <= 0)
			return (0);
		n = ft_atoi(input_buffer);
		array = (char **)malloc(n);
		i = 0;
		while (i < n)
		{
			tmp = (char *)malloc(sizeof(char) * 4096);
			printf("Введіть %d рядок : ", i);
			scanf(" %[^\n]", tmp);
			len = ft_strlen(tmp);
			array[i] = (char *)malloc(len + 1);
			array[i] = tmp;
			i++;
		}
		printf("Несортований масив : \n");
		i = 0;
		while (i < n)
		{
			printf("%s\n", array[i]);
			i++;
		}
		printf("Сортований за зростанням масив : \n");
		a_sort(array, n);
		i = 0;
		while (i < n)
		{
			printf("%s\n", array[i]);
			i++;
		}
		printf("Сортований за спаданням масив : \n");
		d_sort(array, n);
		i = 0;
		while (i < n)
		{
			printf("%s\n", array[i]);
			i++;
		}
	}		
	return (0);
}
