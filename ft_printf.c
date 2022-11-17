/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 11:30:32 by yitoh         #+#    #+#                 */
/*   Updated: 2022/11/17 11:02:00 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

//put counter inside each ft_put* function - so no need to include libft
static int	whichtype(va_list ap, const char *format, int i, int count)
{
	i += 1;
	if (format[i] == 'c')
		count += ft_printchar_fd(va_arg(ap, char), 1);
	if (format[i] == 's')
		count += ft_printstr_fd(va_arg(ap, char *), 1);
	if (format[i] == 'p')
		count += ft_printvoid_fd(va_arg(ap, unsigned long), 1);
	if (format[i] == 'd' || format[i] == 'i')
		count += ft_putnbr_fd(va_arg(ap, int), 1);
	if (format[i] == 'u')
		count += ft_put_fd(va_arg(ap, unsigned int), 1);
	if (format[i] == 'x')
		count += ft_put_fd(va_arg(ap, unsigned int), 1);
	if (format[i] == 'X')
		count += ft_put_fd(va_arg(ap, unsigned int), 1);
	if (format[i] == '%')
		count += ft_printchar_fd('%', 1);
	return (count);
}

/* The printf utility formats and prints its arguments, after the first, 
under control of the format.  return #of characters printed */
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(format);
	va_start(ap, format);
	while (i < len)
	{
		if (format[i] == '%')
			whichtype(ap, format, i, count);
		ft_putchar_fd(format[i], 1);
		count += 1;
		i++;
	}
	va_end (ap);
	return (count);
}
