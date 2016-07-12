/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 11:14:39 by alegent           #+#    #+#             */
/*   Updated: 2016/07/12 11:30:32 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_dprintf(int fd, const char *format, ...)
{
	t_pf				pf;

	if (!setlocale(LC_ALL, "en_US.UTF-8"))
		return (ERROR);
	pf.value = 0;
	pf.format = format;
	pf.fd = fd;
	va_start(pf.ap, format);
	while (*(pf.format))
	{
		if (*pf.format == FLAG)
			read_node(&pf, parsing(&pf));
		else
		{
			print_char(&pf, *(pf.format));
			pf.format++;
		}
	}
	va_end(pf.ap);
	return (pf.value);
}
