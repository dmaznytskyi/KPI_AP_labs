/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   lab_06.c                                            (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/12/14 16:04:54 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2016/12/14 16:04:59 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	forbiden[] = "abcdefghijklmnopqrstuvwxyzйцукенгшщзхъфывапролджэячсмитьбю!@#$%%^&*()_+=\\|'\"/,{}[]";
char	input_buffer[100];

int	main(void)
{
	float **arr;
	int n;

	printf("Введіть кількість аргументів рівняння : ");
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
		arr = allocFArr(n);
	}
	if (arr)
	{
		printf("Чи бажаєте використовувати генератор випадкових чисел? (1 - так, 0 - ні) : ");
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
				case 1: rand_inp(arr, n); break;
				case 0: kb_inp(arr, n); break;
			}
		}
		int a, b;
		float prop;
		int eps = returnEps();
		float precision = returnPrecision(eps);
		float *constants = calloc(n, sizeof(float));
		float *x = calloc(n, sizeof(float));
		float *xp = calloc(n, sizeof(float));
		float *delta = calloc(n, sizeof(float));
		float *sum = calloc(n, sizeof(float));
		float *tsum = calloc(n, sizeof(float));

		printf("Чи бажаєте використовувати генератор випадкових чисел для констант? (1 - так, 0 - ні) : ");
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
				case 1: const_rand_inp(constants, n); break;
				case 0: const_kb_inp(constants, n); break;
			}
		}
		printSLAR(arr, constants, n);
		for (a = 0; a < n; a++)
		{
			tsum[a] = 0;
			for (b = 0; b < n; b++)
			{
				if (a != b)
				tsum[a] += arr[a][b];
			}
			if (fabs(arr[a][a]) < fabs(tsum[a]))
			{
				error(11);
				return 0;
			}
		}		
		for (a = 0; a < n; a++)
			xp[a] = constants[a] / arr[a][a];
		
		do {
			prop = 0;
			for (a = 0; a < n; a++) 
			{
				sum[a] = 0;
				for (b = 0; b < n; b++)
					if (a != b) 
						sum[a] += arr[a][b] * xp[b];
				x[a] = (constants[a] - sum[a]) / arr[a][a];
				delta[a] = fabs(x[a] - xp[a]);
				if (delta[a] > prop)
					prop = delta[a];
				xp[a] = x[a];
			}
		} while (prop >= precision);

		printf("Відповідь :\n");
		for (a = 0; a < n; a++)
			printf("x%d = %g\n", a + 1, xp[a]);
		for (a = 0; a < n; a++)
			free(arr[a]);
		free(arr);
		free(constants);
		free(x);
		free(xp);
		free(delta);
		free(sum);
		free(tsum);
	}
	else
	{
		error(6);
		return (0);
	}
	return (0);
}
