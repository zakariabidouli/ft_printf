#include "ft_printf.h"

static int	ft_unsigned_len(unsigned int num)
{
	unsigned int	len;

	len = 0;
	if(num < 0)
		len++;
	while (num != 0 && ++len)
	{
		num = num / 10;
	}
	return (len);
}

int	ft_put_unsigned(unsigned int nb)
{
	unsigned int	nbr;
	unsigned int	len;

	len = ft_unsigned_len(nb);
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
		ft_put_unsigned(nbr / 10);
		ft_put_unsigned(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
	
	return (len);
}