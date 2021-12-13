#include "ft_printf.h"

static int	ft_hex_len(unsigned	int num)
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

int	ft_hex(unsigned int num, const char format)
{
	int	len;

	if (num >= 16)
	{
		ft_hex(num / 16, format);
		ft_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
		{
			if (format == 'x')
				ft_putchar(num - 10 + 'a');
			if (format == 'X')
				ft_putchar(num - 10 + 'A');
		}
	}
	len = ft_hex_len(num);
	return (len);

}

int	ft_put_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_hex(num, format);
	return (ft_hex_len(num));
}