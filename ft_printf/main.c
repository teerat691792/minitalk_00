/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:24:13 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/03 23:46:49 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
void	print_int(int num, ...)
{
	va_list	args;
	int		i;
	int		result;

	va_start(args, num);
	for (i = 0; i < num; i++)
	{
		result = va_arg(args, int);
		printf("index	=%d	result	=%d\n",i ,result);		

	}
	va_end(args);
}
*/

/*
void print_test(char *str, ...)
{
	size_t	i;
	int check;
	va_list abr;

	i = 0;
	va_start(abr,str);
	while (i < strlen(str))
	{
		if (str[i] == '.')
		{
			check = va_arg(abr, int);
			printf("%d", check);
		}
		else
			printf("%c", str[i]);
		i++;
	}
	va_end(abr);
}

void print_str(char *str, ...)
{
	va_list args;
	int		i;
	char	*result;

	printf("%s\n",str);	
	va_start(args, str);
	i = 0;
	while (i < 3)
	{
		result = va_arg(args, char*);
		printf("%s\n",result);
			i++;
	}

	va_end(args);
}
*/

/*
int		main(int argc, char** argv)
{
	int		len;
//	int		lenf;

	if (argc >= 2)
	{
		len = ft_printf(argv[1],'q');
		printf("\n");
		printf("len	=%d\n",len);

	}
	else
		printf("enter input\n");
	//print_int(10, 2, 3, "xcvb", 5);
	//print_str("aaaaa","bbbbbb","ccccccc`");

	//print_test("one two tree . five .", 4, 5);
	//int a = printf("123456\t789\n");
	//printf("%d\n",a);
	printf("**********************************************\n");
	return (0);
}
*/
int	main(void)
{
	char	c;

	c = 'a';
	printf("default	= %%\n");
	ft_printf("ft_printf	= %%\n");
	return (0);
}

/*
int	main(void)
{
	unsigned int	dec;
	char	c;
	int 	i;
	long double lu;
	char	*str;
	
	dec =  (unsigned int)3735929054;
	c = 'a';

	ft_printf("ft_printf	c= %c\n",c);
	printf("default		c= %c\n",c);
	printf("***************\n");
	ft_printf("ft_printf	c= %p\n",&c);
	printf("default		c= %p\n",&c);
	ft_printf("ft_printf	i= %p\n",&i);
	printf("default		i= %p\n",&i);
	ft_printf("ft_printf	lu= %p\n",&lu);
	printf("default		lu= %p\n",&lu);
	ft_printf("ft_printf	str= %p\n",&str);
	printf("default		str= %p\n",&str);
	return (0);
}
*/
