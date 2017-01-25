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

float function1(float x, float y)
{
	return (cos(y/x) - 2*sin(1/x) + 1/x);
}

float function2(float x, float y)
{
	return (sin(log(x)) - cos(log(x)) + y*log(x));
}

float derivative1(float x, float y)
{
	float e = 0.0001;
	return ((function1(x+e, y)-function1(x, y))/e);
}

float derivative2(float x, float y)
{
	float e = 0.0001;
	return ((function2(x+e, y)-function2(x, y))/e);
}

float half(float a, float b, float y, int fun, float precision)
{
	float x;
	do {
		x = (a + b) / 2;
		if(fun == 1)
		{
			if(function1(a, y)*function1(x, y) > 0)
				a = x;
			else
				b = x;
		}
		else
		{
			if(function2(a, y)*function2(x, y) > 0)
				a = x;
			else
				b = x;
		}
	} while(fabs(b-a) > precision);
	return x;
}

float newton(float b, float y, int fun, float precision)
{
	float x;
	float delta = 0.0;

	if(fun == 1)
	{
		x = function1(b, y);
		do {
			delta = function1(x, y) / derivative1(x, y);
			x -= delta;
		} while(fabs(delta) > precision);

	}
	else
	{
		x = function2(b, y);

		do {
			delta = function2(x, y) / derivative2(x, y);
			x -= delta;
		} while(fabs(delta) > precision);
	}
	return x;
}