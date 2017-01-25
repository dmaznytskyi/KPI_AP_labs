/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   func.c                                              (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/11/03 02:52:15 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2017/01/20 17:23:29 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	f[] = "abcdefghijklmnopqrstuvwxyzйцукенгшщзхъфывапролджэячсмитьбю!@#$%%^&*()_+=\\|'\"/,{}[]";
char	input_buffer[100];

int ret_int_inp(char *str)
{
	printf("%s\n", str);
	scanf("%s", input_buffer);
	if (strpbrk(input_buffer, f) != NULL)
	{
		error(1);
		error(2);
		return (0);
	}
	else
	{
		return (ft_atoi(input_buffer));
	}
}

double ret_fl_inp(char *str)
{
	printf("%s\n", str);
	scanf("%s", input_buffer);
	if (strpbrk(input_buffer, f) != NULL)
	{
		error(1);
		error(2);
		return (0);
	}
	else
	{
		return (atof(input_buffer));
	}
}

void	draw_circuits(void)
{
	printf(" Схема №1:                     | Схема №4\n");
	printf("      _____      ^^^^^^        |        _____                  \n");
	printf("o-----|   |------|    |-----о  |  o-----|   |-----------------о\n");
	printf("   |  ‾‾‾‾‾        L     |     |     |  ‾‾‾‾‾              |   \n");
	printf("   |    R                |     |     |    R2               |   \n");
	printf("   |           C         |     |    |‾|                    |   \n");
	printf("   -----------| |---------     |    | | R1                 |   \n");
	printf(" Схема №2:                     |    |_|                    |   \n");
	printf("      _____                    |     |                     |   \n");
	printf("o-----|   |------| |--------о  |     ‾                     |   \n");
	printf("   |  ‾‾‾‾‾       C      |     |     _ C                   |   \n");
	printf("   |    R                |     |     |            L        |   \n");
	printf("   |           L         |     |     |          ^^^^^^     |   \n");
	printf("   |         ^^^^^       |     |     -----------|    |------   \n");
	printf("   ----------|   |--------     | \n");
	printf(" Схема №3:                     |\n");
	printf("      _____                    |\n");
	printf("o-----|   |------| |--------о  |\n");
	printf("   |  ‾‾‾‾‾       C      |     |\n");
	printf("   |    R2               |     |\n");
	printf("  |‾|                    |     |\n");
	printf("  | | R1                 |     |\n");
	printf("  |_|           L        |     |\n");
	printf("   |          ^^^^^^     |     |\n");
	printf("   -----------|    |------     |\n");
}

complex z;

void	cir1(void)
{
	float R = ret_fl_inp("Введіть опір R: ");
	float L = ret_fl_inp("Введіть індуктивність L: ");
	float C = ret_fl_inp("Введіть ємність C: ");
	float Fmin = ret_fl_inp("Введіть мінімальну частоту: ");
	float Fmax = ret_fl_inp("Введіть максимальну частоту: ");
	float df = ret_fl_inp("Введіть крок зміни частоти: ");
	if (Fmin == Fmax)
	{
		error(11);
		error(2);
		return ;
	}
	else if (Fmin < Fmax && df < 0)
	{
		error(12);
		error(2);
		return ;
	}
	else if (Fmin > Fmax && df > 0)
	{
		error(13);
		error(2);
		return ;
	}
	float f = 1 / (2 * M_PI * sqrt(L * C));
	printf("\nf0 = %14e\n\n", f);
	printf("%*s   |   ", 10, "F");
	printf("%*s   \n", 5, "Z");
	if (Fmin < Fmax)
	{
		while (Fmin <= Fmax)
		{
			float w = 2 * M_PI * Fmin;
			float a = L / C;
			float b = - R / (w * C);
			float c = R;
			float d = w * L - 1 / (w * C);

			z.real =    (a * c + b * d) / (c * c + d * d);
			z.imaginary = (b * c - a * d) / (c * c + d * d);
			printf("%*g   |   ", 10, Fmin);
			printf("%14e + i * (%14e)   \n", z.real, z.imaginary);
			Fmin += df;
		}
	}
	else
	{
		while (Fmin >= Fmax)
		{
			float w = 2 * M_PI * Fmin;
			float a = L / C;
			float b = - R / (w * C);
			float c = R;
			float d = w * L - 1 / (w * C);

			z.real =    (a * c + b * d) / (c * c + d * d);
			z.imaginary = (b * c - a * d) / (c * c + d * d);
			printf("%*g   |   ", 10, Fmin);
			printf("%14e + i * (%14e)   \n", z.real, z.imaginary);
			Fmin += df;
		}
	}
}

void	cir2(void)
{
	float R = ret_fl_inp("Введіть опір R: ");
	float L = ret_fl_inp("Введіть індуктивність L: ");
	float C = ret_fl_inp("Введіть ємніть C: ");
	float Fmin = ret_fl_inp("Введіть мінімальну частоту: ");
	float Fmax = ret_fl_inp("Введіть максимальну частоту: ");
	float df = ret_fl_inp("Введіть крок зміни частоти: ");
	
	if (Fmin == Fmax)
	{
		error(11);
		error(2);
		return ;
	}
	else if (Fmin < Fmax && df < 0)
	{
		error(12);
		error(2);
		return ;
	}
	else if (Fmin > Fmax && df > 0)
	{
		error(13);
		error(2);
		return ;
	}
	float f = 1 / (2 * M_PI * sqrt(L * C));
	printf("\nf0 = %14e\n\n", f);
	printf("%*s   |   ", 10, "F");
	printf("%*s   \n", 5, "Z");
	if (Fmin < Fmax)
	{
		while (Fmin <= Fmax)
		{
			float w = 2 * M_PI * Fmin;
			float a = L / C;
			float b = R / (w * C);
			float c = R;
			float d = w * L - 1 / (w * C);

			z.real = (a * c + b * d) / (c * c + d * d);
			z.imaginary = (b * c - a * d) / (c * c + d * d);
			printf("%*g   |   ", 10, Fmin);
			printf("%14e + i * (%14e)   \n", z.real, z.imaginary);
			Fmin += df;
		}
	}
	else
	{
		while (Fmin >= Fmax)
		{

			float w = 2 * M_PI * Fmin;
			float a = L / C;
			float b = R / (w * C);
			float c = R;
			float d = w * L - 1 / (w * C);

			z.real = (a * c + b * d) / (c * c + d * d);
			z.imaginary = (b * c - a * d) / (c * c + d * d);
			printf("%*g   |   ", 10, Fmin);
			printf("%14e + i * (%14e)   \n", z.real, z.imaginary);
			Fmin += df;
		}
	}

}

void	cir3(void)
{
	float R1 = ret_fl_inp("Введіть опір R1: ");
	float R2 = ret_fl_inp("Введіть опір R2: ");
	float L = ret_fl_inp("Введіть індуктивність L:  ");
	float C = ret_fl_inp("Введіть ємність С:  ");
	float Fmin = ret_fl_inp("Введіть мінімальну частоту: ");
	float Fmax = ret_fl_inp("Введіть максимальну частоту: ");
	float df = ret_fl_inp("Введіть крок зміни частоти: ");

	if (Fmin == Fmax)
	{
		error(11);
		error(2);
		return ;
	}
	else if (Fmin < Fmax && df < 0)
	{
		error(12);
		error(2);
		return ;
	}
	else if (Fmin > Fmax && df > 0)
	{
		error(13);
		error(2);
		return ;
	}
	float f = 1 / (2 * M_PI * sqrt(L * C));
	printf("\nf0 = %14e\n\n", f);
	printf("%*s   |   ", 10, "F");
	printf("%*s   \n", 5, "Z");
	if (Fmin < Fmax)
	{
		while (Fmin <= Fmax + df)
		{
			float w = 2 * M_PI * Fmin;
			float a = R1 * R2;
			float b = R1 * (w * L - 1 / (w * C));
			float c = R1 + R2;
			float d = w * L - 1 / (w * C);

			z.real = (a * c + b * d) / (c * c + d * d);
			z.imaginary = (b * c - a * d) / (c * c + d * d);
			printf("%*g   |   ", 10, Fmin);
			printf("%14e + i * (%14e)   \n", z.real, z.imaginary);
			Fmin += df;
		}
	}
	else 
	{
		while (Fmin >= Fmax)
		{
			float w = 2 * M_PI * Fmin;
			float a = R1 * R2;
			float b = R1 * (w * L - 1 / (w * C));
			float c = R1 + R2;
			float d = w * L - 1 / (w * C);

			z.real = (a * c + b * d) / (c * c + d * d);
			z.imaginary = (b * c - a * d) / (c * c + d * d);
			printf("%*g   |   ", 10, Fmin);
			printf("%14e + i * (%14e)   \n", z.real, z.imaginary);
			Fmin += df;
		}
	}

}

void	cir4(void)
{
	float R1 = ret_fl_inp("Введіть опір R1: ");
	float R2 = ret_fl_inp("Введіть опір R2: ");
	float L = ret_fl_inp("Введіть індуктивність L:  ");
	float C = ret_fl_inp("Введіть ємність C:  ");
	float Fmin = ret_fl_inp("Введіть мінімальну частоту: ");
	float Fmax = ret_fl_inp("Введіть максимальну частоту: ");
	float df = ret_fl_inp("Введіть крок зміни частоти: ");

	if (Fmin == Fmax)
	{
		error(11);
		error(2);
		return ;
	}
	else if (Fmin < Fmax && df < 0)
	{
		error(12);
		error(2);
		return ;
	}
	else if (Fmin > Fmax && df > 0)
	{
		error(13);
		error(2);
		return ;
	}
	float f = 1 / (2 * M_PI * sqrt(L * C));
	printf("\nf0 = %14e\n\n", f);
	printf("%*s   |   ", 10, "F");
	printf("%*s   \n", 5, "Z");
	if (Fmin < Fmax)
	{
		while (Fmin <= Fmax + df)
		{
			float w = 2 * M_PI * Fmin;
			float a = R1 * R2 + L / C;
			float b = w * L * R1 - R2 / (w * C);
			float c = R1 + R2;
			float d = w * L - 1 / (w * C);

			z.real = (a * c + b * d) / (c * c + d * d);
			z.imaginary = (b * c - a * d) / (c * c + d * d);
			printf("%*g   |   ", 10, Fmin);
			printf("%14e + i * (%14e)   \n", z.real, z.imaginary);
			Fmin += df;
		}
	}
	else
	{
		while (Fmin >= Fmax)
		{
			float w = 2 * M_PI * Fmin;
			float a = R1 * R2 + L / C;
			float b = w * L * R1 - R2 / (w * C);
			float c = R1 + R2;
			float d = w * L - 1 / (w * C);

			z.real = (a * c + b * d) / (c * c + d * d);
			z.imaginary = (b * c - a * d) / (c * c + d * d);
			printf("%*g   |   ", 10, Fmin);
			printf("%14e + i * (%14e)   \n", z.real, z.imaginary);
			Fmin += df;
		}
	}
}
