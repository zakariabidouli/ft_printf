/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:02:00 by zbidouli          #+#    #+#             */
/*   Updated: 2021/12/14 21:02:02 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unsigned_len(unsigned int num)
{
	unsigned int	len;

	len = 0;
	if (num == 0)
		len++;
	while (num != 0 && ++len)
	{
		num = num / 10;
	}
	return (len);
}

int	ft_put_unsigned(unsigned int nb)
{
	unsigned int	len;

	len = ft_unsigned_len(nb);
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (nb > 9)
	{
		ft_put_unsigned(nb / 10);
		ft_put_unsigned(nb % 10);
	}
	else
		ft_putchar(nb + '0');
	return (len);
}
