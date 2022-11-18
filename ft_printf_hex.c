/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_hex.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 11:50:56 by yitoh         #+#    #+#                 */
/*   Updated: 2022/11/18 18:07:50 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "printf.h"

//print hexadecimal upper and increment counter
int	ft_printhexup_fd(unsigned int X, int fd)
{
	unsigned long	nbr;
	int			len;

	nbr = (unsigned long)X;
	len = 0;
	if ((nbr / 16) != 0)
		ft_printhexup_fd((nbr / 16), fd);
	if ((nbr % 16) < 10)
	{
		ft_printchar_fd((nbr % 16) + 48, fd);
	}
	else
	{
		ft_printchar_fd((nbr % 16) + 55, fd);
	}
	len++;
	if (nbr == (unsigned long) X)
		return (len);
	return (0);
}

//print hexadecimal lower and increment counter
int	ft_printhexlow_fd(unsigned int x, int fd)
{
	unsigned long	nbr;
	int				len;

	nbr = (unsigned long)x;
	len = 0;
	if ((nbr / 16) != 0)
		ft_printhexlow_fd((nbr / 16), fd);
	if ((nbr % 16) < 10)
	{
		ft_printchar_fd((nbr % 16) + 48, fd);
	}
	else
	{
		ft_printchar_fd((nbr % 16) + 87, fd);
	}
	len++;
	if (nbr == (unsigned long) x)
		return (len);
	return (0);
}

//print address and increment counter
int	ft_printvoid_fd(void *p, int fd)
{
	int	len;

	len = ft_printstr_fd("0x", fd);
	len += ft_printhexlow_fd((unsigned int) p, fd);
	return (len);
}
