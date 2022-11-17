/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_char.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 09:52:25 by yitoh         #+#    #+#                 */
/*   Updated: 2022/11/17 11:00:26 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//putchar and increment counter
static int	ft_printchar_fd(char c, int fd)
{
	int	len;

	len = 1;
	write(fd, &c, 1);
	return (len);
}

//strlen
static int	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

//putstr and increment counter
static int	ft_printstr_fd(char *s, int fd)
{
	int	len;

	len = ft_strlen(s);
	write(fd, &s, len);
	return (len);
}

//putnbr and increment counter
static int	ft_printnbr_fd(int n, int fd)
{
	long int	nbr;
	int	len;

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


// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdarg.h>

// int main(void)
// {
//     int num = 2545;
//     //void    *p = &num;
//     ft_printnbr_fd(num, 1);
// 	printf("\n");
// 	printf("%i\n", num);
// }