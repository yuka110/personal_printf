// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        ::::::::            */
// /*   main.c                                             :+:    :+:            */
// /*                                                     +:+                    */
// /*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
// /*                                                   +#+                      */
// /*   Created: 2022/11/16 10:35:51 by yitoh         #+#    #+#                 */
// /*   Updated: 2022/11/21 11:17:00 by yitoh         ########   odam.nl         */
// /*                                                                            */
// /* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"

int main(void)
{
	char	try[50] = "12345abcde";
	int	num = 785785;
	int	num2 = 2367;
	void	*p = "";
	int	original;
	int mine;
	
	printf("s = %s\n", try);
	mine = ft_printstr_fd((char *)NULL, 1);
	printf(", %d\n", mine);
	printf("i = %i\n", num);
	mine = ft_printnbr_fd(num, 1, 0);
	printf(", %d\n", mine);
	printf("u = %u\n", num);
	mine = ft_printunsigned_fd(num, 1, 0);
	printf(", %d\n", mine);
	printf("X = %X\n", num);
	mine = ft_printhexup_fd(num, 1, 0);
	printf(", %d\n", mine);
	printf("x = %x\n", num);
	mine = ft_printhexlow_fd(num, 1, 0);
	printf(", %d\n", mine);
	printf("p = %p\n", p);
	mine = ft_printvoid_fd((void *)p, 1, 0);
	printf(", %d\n", mine);

	//without any variable argument
	mine = ft_printf("print this\n");
	original = printf("print this\n");
	printf("%d, %d\n", mine, original);
	//print %
	mine = ft_printf("abc%%as\n");
	original = printf("abc%%as\n");
	printf("%d, %d\n", mine, original);
	//print string
	mine = ft_printf("abc%s\n", try);
	original = printf("abc%s\n", try);
	printf("%d, %d\n", mine, original);
	//print number
	mine = ft_printf("mine = %d\n", num);
	original = printf("orig = %d\n", num);
	printf("%d, %d\n", mine, original);
	//print unsigned int
	mine = ft_printf("mine = %u\n", num);
	original = printf("orig = %u\n", num);
	printf("%d, %d\n", mine, original);
	//print hex upper
	mine = ft_printf("mine = %X\n", num2);
	original = printf("orig = %X\n", num2);
	printf("%d, %d\n", mine, original);
	//print hex lower
	mine = ft_printf("mine = %x\n", num2);
	original = printf("orig = %x\n", num2);
	printf("%d, %d\n", mine, original);
	//print address
	mine = ft_printf("mine = %p\n", (void *)p);
	original = printf("orig = %p\n", (void *)p);
	printf("%d, %d\n", mine, original);

}
