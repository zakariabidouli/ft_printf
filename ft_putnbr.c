#include <printf.h>

int	ft_nbr_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0 && ++len)
	{
		num = num / 10;
	}
	return (len);
}

void	ft_putnbr_fd(int nb)
{
	unsigned int	nbr;

	if (nb == 0)
	{
		ft_putchar ('0');
		return ;
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
}

int	ft_printpercent(void)
{
	write(1, '%', 1);
	return (1);
}