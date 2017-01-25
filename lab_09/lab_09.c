/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   lab_09.c                                            (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/11/03 02:30:17 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2016/12/21 14:50:30 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main()
{
	int choise;

	while (1)
	{
		print_menu();
		choise = ret_int_inp("");
		switch (choise)
		{
			case 1:
				create_file();
				break ;
			case 2:
				read_file();
				break ;
			case 3:
				remove_file();
				break ;
			case 4:
				new_note();
				break ;
			case 5:
				read_note();
				break ;
			case 6:
				edit_note();
				break ;
			case 7:
				sort_notes();
				break ;
			case 8:
				insert_note();
				break ;
			case 9:
				delete_note();
				break ;
			case 0:
				return (0);
				break ;
			default:
				return (0);
		}
	}
	return (0);
}
