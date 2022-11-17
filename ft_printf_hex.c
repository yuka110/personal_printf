/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_hex.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 11:50:56 by yitoh         #+#    #+#                 */
/*   Updated: 2022/11/17 11:03:54 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// static int	ft_printchar_fd(char c, int fd)
// {
// 	int	len;

// 	len = 1;
// 	write(fd, &c, 1);
// 	return (len);
// }

// //strlen
// int	ft_strlen(const char *s)
// {
// 	int		i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		++i;
// 	return (i);
// }

// //putstr and increment counter
// static int	ft_printstr_fd(char *s, int fd)
// {
// 	int	len;

// 	len = ft_strlen(s);
// 	write(fd, &s, len);
// 	return (len);
// }

//print address and increment counter
static int	ft_printvoid_fd(void *p, int fd)
{
	int	len;

	len = ft_printstr_fd("0x", fd);
	len = ft_printstr_fd(&(*p), fd);
	return (len);
}

//putchar and increment counter
static int	ft_printhexup_fd(int num, int fd)
{
	long int	nbr;
	int			len;

	nbr = (long int)num;
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
	if (nbr == (long int) num)
		return (len);
}


// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdarg.h>

// int main(void)
// {
//     int num = 2545;
//     void    *p = &num;
//     ft_printhexup_fd(num, 1);
// 	printf("\n");
// 	printf("%X\n", num);
// 	ft_printvoid_fd(p, 1);
// 	printf("\n");
// 	printf("%p\n", p);
// }
