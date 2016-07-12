/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_weight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 11:16:07 by alegent           #+#    #+#             */
/*   Updated: 2016/07/12 11:16:08 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				get_weight(t_pf *pf, t_nd *nd)
{
	if (*(pf->format) == '*')
	{
		nd->weight = va_arg(pf->ap, int);
		pf->format++;
		return ;
	}
	if ((nd->weight = ft_atoi(pf->format)))
		pf->format += ft_digitlen(nd->weight);
}
