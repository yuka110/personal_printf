/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 10:35:51 by yitoh         #+#    #+#                 */
/*   Updated: 2022/11/17 10:59:39 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int main(void)
{
    int num = 12897;
    void    *p = &num;
    ft_printvoid_fd(p, 1);

    int num = 2545;
    void    *p = &num;
    
    ft_printnbr_fd(num, 1);
	printf("\n");
	printf("%i\n", num);

    ft_printhexup_fd(num, 1);
	printf("\n");
	printf("%X\n", num);
    
	ft_printvoid_fd(p, 1);
	printf("\n");
	printf("%p\n", p);
}
