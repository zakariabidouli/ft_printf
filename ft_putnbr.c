/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:02:27 by zbidouli          #+#    #+#             */
/*   Updated: 2021/12/14 21:02:29 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbr_len(int num)
{
	int	len;

	len = 0;
	if (num < 0)
		len++;
	while (num != 0 && ++len)
	{
		num = num / 10;
	}
	return (len);
}

int	ft_putnbr(int nb)
{
	unsigned int	nbr;
	int				len;

	len = ft_nbr_len(nb);
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
	return (len);
}

int	ft_putpercent(void)
{
	write(1, "%", 1);
	return (1);
}
