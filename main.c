/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 10:35:51 by yitoh         #+#    #+#                 */
/*   Updated: 2022/11/18 18:25:28 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "printf.h"

int main(void)
{
    char    try[50] = "12345abcde";
    int num = -128978;
    int num2 = 8969757;
    void    *p = &num;
    
    printf("s = %s\n", try);
    ft_printstr_fd(try, 1);
    printf("\n");
    printf("i = %i\n", num);
    ft_printnbr_fd(num, 1);
	printf("\n");
    printf("u = %u\n", num2);
    ft_printnbr_fd(num2, 1);
	printf("\n");
	printf("X = %X\n", num);
    ft_printhexup_fd(num, 1);
	printf("\n");
    printf("x = %x\n", num2);
    ft_printhexlow_fd(num2, 1);
	printf("\n");
	printf("p = %p\n", p);
	ft_printvoid_fd(p, 1);
	printf("\n");
}
