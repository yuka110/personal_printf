/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_hex.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 11:50:56 by yitoh         #+#    #+#                 */
/*   Updated: 2022/11/21 16:08:16 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

//print hexadecimal upper and increment counter
int	ft_printhexup_fd(unsigned int X, int fd, int len)
{
	unsigned long	nbr;

	nbr = (unsigned long)X;
	if ((nbr / 16) != 0)
		len = ft_printhexup_fd((nbr / 16), fd, len);
	if ((nbr % 16) < 10)
	{
		len += ft_printchar_fd((nbr % 16) + 48, fd);
	}
	else
	{
		len += ft_printchar_fd((nbr % 16) + 55, fd);
	}
	if (nbr == (unsigned long) X)
		return (len);
	return (0);
}

//print hexadecimal lower and increment counter
int	ft_printhexlow_fd(unsigned int x, int fd, int len)
{
	unsigned long	nbr;

	nbr = (unsigned long)x;
	if ((nbr / 16) != 0)
		len = ft_printhexlow_fd((nbr / 16), fd, len);
	if ((nbr % 16) < 10)
	{
		len += ft_printchar_fd((nbr % 16) + 48, fd);
	}
	else
	{
		len += ft_printchar_fd((nbr % 16) + 87, fd);
	}
	if (nbr == (unsigned long) x)
		return (len);
	return (0);
}

//print address and increment counter
int	ft_printvoid_fd(void *p, int fd, int len)
{
	len = ft_printstr_fd("0x", fd);
	len = ft_printhexlow_fd((int)p, fd, len);
	return (len);
}
