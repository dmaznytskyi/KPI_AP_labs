/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   lab_01.c                                            (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/10/31 13:35:05 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2017/01/20 19:58:24 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(void)
{
	char	*str;
	int		a;

	a = 0;
	str = malloc(sizeof(int));
	write(1, "Введіть число\n", 26);
	read(0, str, 4096);
	a = ft_atoi(str);
	a = roman(a, 1000, 'M');
	a = roman(a, 500, 'D');
	a = roman(a, 100, 'C');
	a = roman(a, 50, 'L');
	a = roman(a, 10, 'X');
	a = roman(a, 5, 'V');
	a = roman(a, 1, 'I');
	return (0);
}

int	roman(int a, int b, char c)
{
	while (a >= b)
	{
		write(1, &c, 1);
		a = a - b;
	}
	return a;
}
