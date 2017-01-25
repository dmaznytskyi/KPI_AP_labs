/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   lab_08.c                                            (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/11/03 02:30:17 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2017/01/14 09:33:05 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main()
{
	draw_circuits();
	int tmp;
	tmp = ret_int_inp("Виберіть контур [1-4] або 0 для виходу: ");
	switch (tmp)
	{
		case 1: cir1(); break;
		case 2: cir2(); break;
		case 3: cir3(); break;
		case 4: cir4(); break;
		default: return (0); break;
	}
	return (0);
}
