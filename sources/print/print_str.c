/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 11:16:49 by alegent           #+#    #+#             */
/*   Updated: 2016/07/12 11:16:49 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					print_str(t_pf *pf, char *str)
{
	ft_putstr_fd(str, pf->fd);
	pf->value += ft_strlen(str);
}