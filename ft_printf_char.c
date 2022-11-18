/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_char.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 09:52:25 by yitoh         #+#    #+#                 */
/*   Updated: 2022/11/18 18:15:50 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "printf.h"
# include "./libft/libft.h"

//putchar and increment counter
int	ft_printchar_fd(char c, int fd)
{
	int	len;

	len = 1;
	write(fd, &c, 1);
	return (len);
}

//putstr and increment counter
int	ft_printstr_fd(char *s, int fd)
{
	int	len;

	len = (int) ft_strlen(s);
	write(fd, s, len);
	return (len);
}

//putnbr and increment counter
int	ft_printnbr_fd(int n, int fd)
{
	long int	nbr;
	int			len;

	nbr = (long int) n;
	len = 0;
	if (nbr < 0)
	{
		ft_printchar_fd('-', fd);
		len++;
		nbr = nbr * -1;
	}
	if (nbr > 10)
	{
		ft_printnbr_fd((nbr / 10), fd);
	}
	ft_printchar_fd((nbr % 10) + '0', 1);
	len++;
	return (len);
}

int	ft_printunsigned_fd(unsigned int u, int fd)
{
	int			len;

	len = 0;
	if (u > 10)
	{
		ft_printnbr_fd((u / 10), fd);
	}
	ft_printchar_fd((u % 10) + '0', 1);
	len++;
	return (len);
}
