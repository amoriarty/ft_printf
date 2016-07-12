/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minus_weight.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 11:16:35 by alegent           #+#    #+#             */
/*   Updated: 2016/07/12 12:07:53 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					print_minus_weight(t_pf *pf, int len)
{
	int					i;

	i = -1;
	while (++i < len)
		print_char(pf, ' ');
}
