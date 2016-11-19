/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   zadanie2.c                                          (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/11/14 20:22:51 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2016/11/17 23:07:50 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	fb2[] = "abcdefghijklmnopqrstuvwxyzйцукенгшщзхъфывапролджэячсмитьбю!@#$%%^&*()_+=\\|'\"/,{}[]";
char	input_buffer[100];

void	zadanie2(void)
{
	int	n = 0;
	int	day;
	int	day_max;
	int	month;
	int	year;
	int	is_leap = 0; // 0 - если не високосный год, 1 - если високосный
	int	day_of_week;

	printf("\nВведіть рік, місяць та число");
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			printf("\nВведіть рік : ");
			scanf("%s", input_buffer);
			if (strpbrk(input_buffer, fb2) != NULL)
			{
				error(1);
				error(2);
				break ;
			}
			else
			{
				year = ft_atoi(input_buffer);
				if (year == 0)
				{
					error(3);
					error(2);
					break ;
				}
				else
					i++;
				if ((((year % 100) != 0) && ((year % 4) == 0)) || 
					(((year % 100) == 0) && ((year % 400) == 0)))
					{is_leap = 1;}
			}
		}
		if (i == 1)
		{
			printf("Введіть місяць : ");
			scanf("%s", input_buffer);
			if (strpbrk(input_buffer, fb2) != NULL)
			{
				error(1);
				error(2);
				break ;
			}
			else
			{
				month = ft_atoi(input_buffer);
				if ((month > 0) && (month < 13))
					i++;
				else
				{
					error(20);
					error(2);
					break ;
				}
				if (month == 2)
					day_max = (is_leap) ? 29 : 28;
				if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
					day_max = 30;
				else
					day_max = 31;
			}
		}
		if (i == 2)
		{
			printf("Введіть число : ");
			scanf("%s", input_buffer);
			if (strpbrk(input_buffer, fb2) != NULL)
			{
				error(1);
				error(2);
				break ;
			}
			else
			{
				day = ft_atoi(input_buffer);
				if ((day > 0) && (day < day_max))
					if ((year == 1918) && (month == 2) && ((day > 16) && (day < 29)))
					{
						error(22);
						error(2);
						break ;
					}
					else
						i++;
				else
				{
					error(21);
					error(2);
					break ;
				}
			}
		}
	}
	//корректировка дней по юлианскому календарю
	if ((year < 1918) || ((year == 1918) && (month <= 2)))
	{
		if (((day + 13) > day_max) != 0)
		{
			day = (day + 13) - day_max;
			month++;
		}
		else
			day = day + 13;
	}
	//поправка n
	if (month > 2)
		n = 0;
	else
		if ((is_leap) && (month <= 2))
			n = 1;
		else
			if ((!is_leap) && (month <= 2))
				n = 2;
	//вычисления дня недели
	day_of_week = ((int)((365.25 * year) + (30.56 * month) + day + n) % 7);
	//вывод дня недели
	switch (day_of_week)
	{
		case 0:
			printf("Введена дата припадає на понеділок.\n");
			break ;
		case 1:
			printf("Введена дата припадає на вівторок.\n");
			break ;
		case 2:
			printf("Введена дата припадає на середу.\n");
			break ;
		case 3:
			printf("Введена дата припадає на четвер.\n");
			break ;
		case 4:
			printf("Введена дата припадає на п'ятницю.\n");
			break ;
		case 5:
			printf("Введена дата припадає на суботу.\n");
			break ;
		case 6:
			printf("Введена дата припадає на неділю.\n");
			break ;
	}
	printf("\n\e[32m\e[1m>>> УСПІШНО <<<\e[0m Підпрограма виконана!\n\n");
}
