/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   header.h                                            (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/11/01 03:49:51 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2016/12/21 15:13:28 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>

struct record
{
	char data[100]; 
	double a;
	double b;
};

void	print_menu(void);

void	create_file(void);
void	read_file(void);
void	remove_file(void);

void	new_note(void);
void	read_note(void);
void	edit_note(void);
void	sort_notes(void); //acsending/descending
void	insert_note(void);
void	delete_note(void);

void	error(int code);
int		ft_atoi(char *str);
char	*ft_strcpy(char *dst, const char *src);
void	ft_bzero(void *str, size_t n);

int	ret_int_inp(char *str);
double	ret_fl_inp(char *str);

#endif
