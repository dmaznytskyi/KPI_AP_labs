/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   lab_03.c                                            (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/11/06 16:09:21 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2016/11/19 01:45:46 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	forbiden[] = "abcdefghijklmnopqrstuvwxyzйцукенгшщзхъфывапролджэячсмитьбю!@#$%%^&*()_+=\\|'\"/,{}[]";
char	input_buffer[100];

int		main(void)
{
	while (1)
	{
		printf("Oберiть пiдпрограму для виконання.\n");
		printf("Введiть номер пiдпрограми i натиснiть enter.\n");
		printf("Для виходу введiть '0' i натиснiть enter.\n");
		printf("Отже ваш вибiр (0-3) : ");
		scanf("%s", input_buffer);
		if (strpbrk(input_buffer, forbiden) != NULL)
			error(1);
		else
		{
			if (atof(input_buffer) == 0)
				return 0;
			else if (atof(input_buffer) == 1) 
			{
				printf("\nВибрана пiдпрограма № %d.\n\n", 1);
				zadanie1();
			}
			else if (atof(input_buffer) == 2)
			{
				printf("\nВибрана пiдпрограма № %d.\n\n", 2);
				zadanie2();
			}
			else if (atof(input_buffer) == 3)
			{
				printf("\nВибрана пiдпрограма № %d.\n\n", 3);
				zadanie3();
			}
			else 
				error(4);
		}
	}
}
