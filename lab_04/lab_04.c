/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   lab_04.c                                            (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznyts <dmaznytskyi@gmail.com>                | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/11/29 21:41:30 by dmaznyts            |_____/  |_||_||_|   */
/*   Updated: 2016/12/05 11:56:04 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	forbiden[] = "abcdefghijklmnopqrstuvwxyzйцукенгшщзхъфывапролджэячсмитьбю!@#$%%^&*()_+=\\|'\"/,{}[]";
char	input_buffer[100];

int	main(void)
{
	while (1)
	{
		printf("Oберiть пiдпрограму для виконання.\n");
		printf("Введiть номер пiдпрограми i натиснiть enter.\n");
		printf("Для виходу введiть '0' i натиснiть enter.\n");
		printf("Отже ваш вибiр (0-2) : ");
		scanf("%s", input_buffer);
		if (strpbrk(input_buffer, forbiden) != NULL)
			error(1);
		else
		{
			if (ft_atoi(input_buffer) == 0)
				return 0;
			else if (ft_atoi(input_buffer) == 1)
			{
				printf("\nВибрана пiдпрограма № %d.\n\n", 1);
				zadanie1();
			}
			else if (ft_atoi(input_buffer) == 2)
			{
				printf("\nВибрана пiдпрограма № %d.\n\n", 2);
				zadanie2();
			}
			else
				error(4);
		}
	}
	return (0);
}
