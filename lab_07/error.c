/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   error.c                                             (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/11/03 02:30:17 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2016/12/14 15:06:37 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// \e[32m\e[1m - green	color output
// \e[31m\e[1m - red	color output
// \e[0m       - reset	color output

// 1 - 9 : input/output errors
// 10 - 19 : errors for the first task
// 20 - 29 : errors for the second task
// 30 - 39 : errors for the third task

void	error(int code)
{
	switch (code)
	{
		case 1:
			printf("\n\e[31m\e[1m>>> ПОМИЛКА <<<\e[0m Ви ввели текст! Потрiбно ввести число!\n");
			break ;
		case 2:
			printf("\n\e[31m\e[1m>>> ПОМИЛКА <<<\e[0m Програма перервана з причини некоректного вводу.\n");
			break ;
		case 3:
			printf("\n\e[31m\e[1m>>> ПОМИЛКА <<<\e[0m Ви ввели 0! Потрiбно ввести ненульве число!\n");
			break ;
		case 4:
			printf("\n\e[31m\e[1m>>> ПОМИЛКА <<<\e[0m Введено невiрний номер пiдпрограми! Спробуйте ще раз!\n\n");
			break ;
		case 5:
			printf("\n\e[31m\e[1m>>> ПОМИЛКА <<<\e[0m Допустима точність обчислень від 0 до 6!");
			break ;
		case 6:
			printf("\n\e[31m\e[1m>>> ПОМИЛКА <<<\e[0m Сталася помилка під час виділення пам'яті!");
			break ;
		case 11:
			printf("\n\e[31m\e[1m>>> ПОМИЛКА <<<\e[0m y не може дорівнювати нулю!\n");
			break ;
	}
}
