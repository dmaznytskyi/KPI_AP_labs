/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:58:07 by dmaznyts          #+#    #+#             */
/*   Updated: 2016/12/05 18:53:53 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t	ft_strlen(const char *str)
{
	size_t n;

	n = -1;
	while (str[++n])\
		;
	return (n);
}
