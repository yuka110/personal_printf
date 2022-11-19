/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 11:01:37 by yitoh         #+#    #+#                 */
/*   Updated: 2022/11/19 16:04:11 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(const char *format, ...);
int	whichtype(int i, va_list ap, const char *format);

int	ft_printchar_fd(char c, int fd);
int	ft_printstr_fd(char *s, int fd);
int	ft_printnbr_fd(int n, int fd, int len);
int	ft_printunsigned_fd(unsigned int u, int fd, int len);
int	ft_printvoid_fd(void *p, int fd, int len);
int	ft_printhexup_fd(unsigned int X, int fd, int len);
int	ft_printhexlow_fd(unsigned int x, int fd, int len);

#endif
