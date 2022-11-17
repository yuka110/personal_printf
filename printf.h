/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 11:01:37 by yitoh         #+#    #+#                 */
/*   Updated: 2022/11/17 11:02:15 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>

int	ft_printf(const char *format, ...);
static int	whichtype(va_list ap, const char *format, int i, int count);

static int	ft_printchar_fd(char c, int fd);
static int	ft_strlen(const char *s);
static int	ft_printstr_fd(char *s, int fd);
static int	ft_printnbr_fd(int n, int fd);
static int	ft_printvoid_fd(void *p, int fd);
static int	ft_printhexup_fd(int num, int fd);

#endif
