#include <printf.h>

// // int print(const char *form, int count)
// // {

// // }

// int	ft_printf(const char *format, ...)
// {
// 	va_list	args;
// 	int i;

// 	i = 0; 
// 	va_start(args, format);
//     while (format[i])
//     {
// 		if( (65 <= format[i] && 90 >= format[i]) || (97 <= format[i] && 122 >= format[i]) || format[i] == '%' )   
// 		{          
//         	ft_putchar_fd('format[i]');
//         	break;
// 		}	
//         else if (*format == 's')             
//         { 
// 		    ft_putstr_fd(va_arg(args, int), 1);
//             break;
// 		}	
//         else if (*format  == 'd')          
//         { 
// 		    ft_putnbr_fd(va_arg(args, int), 1);
//             break;
// 		}	
//         else if (*format  == 'c')          
//         {
// 		    ft_putchar_fd((char) va_arg(args, int), 1);
// 		    break;
// 		}
// 		// else if (*format  == 'X')          
//         // {
// 		// 	ft_puthex(va_arg(args, int));
//         // 	break;
// 		// }
// 		format++;	
//         }
// 	va_end(args);
// 	return (0);
// } 	
// int main( int argc, char * argv[] ) {

//     ft_printf( "Begin %s End\n", "Middle" );

//     ft_printf( "Begin %d End\n", 123 );
    

//     ft_printf( "Begin %% End\n", 123.456 );
    

// 	ft_printf( "Begin %s %d %c End\n", "toto", 421, 'c');
    

//     return 0;

// }

// int		do_shit(va_list list, t_list *arg)
// {
// 	if ((arg->dott) && arg->kind != 8 && arg->prec >= 0)
// 		arg->flags = 0;
// 	if (arg->kind == 8)
// 		arg->cont = ft_chardup('%', arg);
// 	else if (arg->kind == 0)
// 		arg->cont = ft_chardup(va_arg(list, int), arg);
// 	else if (arg->kind == 5 || arg->kind == 3)
// 		arg->cont = ft_itoa(va_arg(list, int), arg, 0);
// 	else if (arg->kind == 4)
// 		arg->cont = ft_itoa(va_arg(list, unsigned int), arg, 1);
// 	else if (arg->kind == 1)
// 		arg->cont = va_arg(list, char *);
// 	else if (arg->kind == 2)
// 		arg->cont = ft_xtoa(va_arg(list, size_t), arg, 1);
// 	else if (arg->kind == 7 || arg->kind == 6)
// 		arg->cont = ft_xtoa(va_arg(list, unsigned int), arg, 0);
// 	else
// 		return (0);
// 	return (wtreat(arg));
// }

// int		ft_printf(const char *format, ...)
// {
// 	va_list		list;
// 	int			i;
// 	int			j;
// 	t_list		arg;

// 	i = 0;
// 	j = 0;
// 	va_start(list, format);
// 	while (format[i])
// 	{
// 		linit(&arg);
// 		if (format[i] != '%')
// 			j += write(1, &format[i++], 1);
// 		else if ((j += whatisit((char *)&format[++i], list, &arg)) && arg.er)
// 			return (-1);
// 		i += arg.skip;
// 	}
// 	va_end(list);
// 	return (j);
// }


int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_putchar(va_arg(args, int));
	else if (format == 's')
		length += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		length += ft_put_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		length += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		length += ft_put_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		length += ft_put_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		length += ft_putpercent();
	return (length);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		length;

	i = 0;
	length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			length += ft_formats(args, format[i + 1]);
			i++;
		}
		else
			length += ft_prutchar(format[i]);
		i++;
	}
	va_end(args);
	return (length);
}