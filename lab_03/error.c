/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   error.c                                             (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/11/03 02:30:17 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2016/11/17 21:17:47 by dmaznytskyi                              */
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
			printf("\n\e[31m\e[1m>>> ПОМИЛКА <<<\e[0m Пiдпрограма перервана з причини некоректного вводу.\n");
			break ;
		case 3:
			printf("\n\e[31m\e[1m>>> ПОМИЛКА <<<\e[0m Ви ввели 0! Потрiбно ввести ненульве число!\n");
			break ;
		case 4:
			printf("\n\e[31m\e[1m>>> ПОМИЛКА <<<\e[0m Введено невiрний номер пiдпрограми! Спробуйте ще раз!\n\n");
			break ;
		case 10:
			printf("\n\e[31m\e[1m>>> ПОМИЛКА <<<\e[0m Ви ввели невірне число! Потрібно ввести число більше за нуль!\n");
			break ;
		case 11:
			printf("\n\e[31m\e[1m>>> ПОМИЛКА <<<\e[0m Ви ввели від'ємне число. Потрібно ввести число більше або рівне нулю!");
			break ;
		case 12:
			printf("\n\e[31m\e[1m>>> ПОМИЛКА <<<\e[0m Ви ввели нуль. Введіть число відмінне від нуля!");
			break ;
		case 20:
			printf("\n\e[31m\e[1m>>> ПОМИЛКА <<<\e[0m Не вірно введений місяць! Номер місяця повинен відповідати його порядковому номеру. Наприклад №1 для січня, №12 для грудня.");
			break ;
		case 21:
			printf("\n\e[31m\e[1m>>> ПОМИЛКА <<<\e[0m Введене число виходить за межі введеного місяця!");
			break ;
		case 22:
			printf("\n\e[31m\e[1m>>> ПОМИЛКА <<<\e[0m Введеної дати не існує, у зв'язку з переходом на григоріанський календар.");
			break ;
	}
}