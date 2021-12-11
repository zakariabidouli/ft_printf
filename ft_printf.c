#include <printf.h>

// int print(const char *form, int count)
// {

// }

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int i;

	i = 0; 
	va_start(args, format);
    while (format[i])
    {
		if( (65 <= format[i] && 90 >= format[i]) || (97 <= format[i] && 122 >= format[i]) || format[i] == '%' )   
		{          
        	ft_putchar_fd('format[i]');
        	break;
		}	
        else if (*format == 's')             
        { 
		    ft_putstr_fd(va_arg(args, int), 1);
            break;
		}	
        else if (*format  == 'd')          
        { 
		    ft_putnbr_fd(va_arg(args, int), 1);
            break;
		}	
        else if (*format  == 'c')          
        {
		    ft_putchar_fd((char) va_arg(args, int), 1);
		    break;
		}
		// else if (*format  == 'X')          
        // {
		// 	ft_puthex(va_arg(args, int));
        // 	break;
		// }
		format++;	
        }
	va_end(args);
	return (0);
} 	
int main( int argc, char * argv[] ) {

    ft_printf( "Begin %s End\n", "Middle" );

    ft_printf( "Begin %d End\n", 123 );
    

    ft_printf( "Begin %% End\n", 123.456 );
    

	ft_printf( "Begin %s %d %c End\n", "toto", 421, 'c');
    

    return 0;

}