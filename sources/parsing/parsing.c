/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 11:16:16 by alegent           #+#    #+#             */
/*   Updated: 2016/07/12 11:16:18 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				init_nd(t_nd *nd)
{
	nd->weight = 0;
	nd->precision = -1;
	nd->opt = 0;
}

t_nd					parsing(t_pf *pf)
{
	t_nd				nd;

	init_nd(&nd);
	pf->format++;
	get_opt(pf, &nd);
	get_weight(pf, &nd);
	get_precision(pf, &nd);
	get_modifier(pf, &nd);
	get_type(pf, &nd);
	return (nd);
}
