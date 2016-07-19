/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 11:15:53 by alegent           #+#    #+#             */
/*   Updated: 2016/07/12 11:19:48 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				get_precision(t_pf *pf, t_nd *nd)
{
	if (*(pf->format) == '.')
	{
		pf->format++;
		if (*(pf->format) == '*')
		{
			nd->precision = va_arg(pf->ap, int);
			pf->format++;
			return ;
		}
		nd->precision = ft_atoi(pf->format);
		if (ft_isdigit(*(pf->format)))
			pf->format += ft_digitlen(nd->precision);
	}
}
