#include "ft_printf.h"

static int	ft_nbr_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0 && ++len)
	{
		num = num / 10;
	}
	return (len);
}

int	ft_putnbr(int nb)
{
	unsigned int	nbr;
	unsigned int	len;

	if (nb == 0)
	{
		ft_putchar('0');
		return (0);
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
	len = ft_nbr_len(nb);
	return (len);
}

int	ft_putpercent(void)
{
	write(1, "%", 1);
	return (1);
}