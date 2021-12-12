#include <printf.h>

// void	ft_putnbr_fd(int nb, int fd)
// {
// 	unsigned int	nbr;

// 	if (nb == 0)
// 	{
// 		ft_putchar_fd ('0', fd);
// 		return ;
// 	}
// 	if (nb < 0)
// 	{
// 		ft_putchar_fd ('-', fd);
// 		nbr = nb * -1;
// 	}
// 	else
// 		nbr = nb;
// 	if (nbr > 9)
// 	{
// 		ft_putnbr_fd (nbr / 10, fd);
// 		ft_putnbr_fd (nbr % 10, fd);
// 	}
// 	else
// 		ft_putchar_fd (nbr + '0', fd);
// }

int	ft_ptr_len(unsigned long long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_ptr(unsigned long long num)
{
	if (num >= 16)
	{
		ft_ptr(num / 16);
		ft_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_put_ptr(unsigned long long ptr)
{
	int	length;

	length = 0;
	length += write(1, "0x", 2);
	if (ptr == 0)
		length += write(1, "0", 1);
	else
	{
		ft_ptr(ptr);
		length += ft_ptr_len(ptr);
	}
	return (length);
}