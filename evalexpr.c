/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalexpr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobax <nerdz78@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:15:08 by noobax            #+#    #+#             */
/*   Updated: 2016/04/01 20:58:22 by noobax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_atoi(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	if (str[0] == '-')
		i = 1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	if (str[0] == '-')
		res *= -1;
	return(res);
}

int	result(char *str, int i, int j)
{
	int	res;
	
	res = 0;
	if (str[j - 2] == '*')
		res = ft_atoi(str + i) * ft_atoi(str + j);
	if (str[j - 2] == '/')
		res = ft_atoi(str + i) / ft_atoi(str + j);
	if (str[j - 2] == '%')
		res = ft_atoi(str + i) % ft_atoi(str + j);
	if (str[j - 2] == '+')
		res = ft_atoi(str + i) + ft_atoi(str + j);
	if (str[j - 2] == '-')
		res = ft_atoi(str + i) - ft_atoi(str + j);
	return(res);
}

int	search(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != ')')
	{
		if (str[i] == '(')
			j = i;
		i++;
	}
	i = j;
	while (str[i] != '%' && str[i] != '*' && 
		str[i] != '/' && str[i] && str[i] != ')')
		i++;
	if (str[i] == '\0' || str[i] == ')')
	{	
		i = j;
		while (str[i] != '+' && str[i] && str[i] != ')' && 
			(str [i] != '-' || str[i + 1] != ' '))
			i++;
	}
	return(i);
}

int	eval_expr(char *str)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '(')
		{
			i = search(str);
			j = i + 2;
			i -= 2;
			while (str[i - 1] != ' ' && i > 0 && str[i - 1] != '(')
				i--;
			x = result(str, i, j);
			while (str[j + 1] >= '0' && str[j + 1] <= '9' && str[j])
				j++;
			str = clean_up(str, i, j, x);
			i = 0;
		}
		i++;
	}
	return(ft_atoi(str));	
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{	
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return(0);
}
