#include "ft_printf.h"



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
	// else if (format == 'u')
	// 	length += ft_put_unsigned(va_arg(args, unsigned int));
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
			length += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (length);
}

int main() 
{
	char *p;


    ft_printf( "Begin %% End\n", p );

    ft_printf( "Begin %d End\n", 123 );
}    

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

