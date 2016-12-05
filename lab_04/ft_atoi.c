/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   ft_atoi.c                                           (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/10/31 16:51:57 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2016/10/31 16:59:25 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

int		g_is_neg;
int		g_is_plus;

void	check_symbol(char *str)
{
	if (*str == '-')
		g_is_neg = -1;
	if (*str == '+')
		g_is_plus = 1;
	str++;
}

int		fix_overflow(void)
{
	if (g_is_neg)
		return (-1);
	else
		return (0);
}

int		ft_atoi(char *str)
{
	int		res;
	int		case_fix;

	res = 0;
	case_fix = 0;
	g_is_neg = 1;
	g_is_plus = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32 || *str == '-' || *str == 43)
	{
		if (g_is_neg == -1 || g_is_plus == 1)
			return (0);
		check_symbol(str);
	}
	while (*str >= '0' && *str <= '9')
	{
		if (case_fix >= 19)
			return (fix_overflow());
		case_fix++;
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * g_is_neg);
}
