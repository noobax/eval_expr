/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalexpr2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobax <nerdz78@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:15:35 by noobax            #+#    #+#             */
/*   Updated: 2016/04/01 20:58:19 by noobax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

char	*ft_tabint(int nb)
{
	int	count;
	int	stock;
	char	*tab;

	count = 1;
	stock = nb;
	if (nb < 0)
		count = 2;
	if (nb < 0)
		nb *= -1;
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	tab = (char*)malloc(sizeof(char) * count);
	if (stock < 0)
		tab[0] = '-';
	if (stock < 0)
		stock *= -1;
	while (count-- > 0 && tab[count] != '-')
	{
		tab[count] = (stock % 10) + 48;
		stock /= 10;
	}
	return(tab);
}

char	*clean_up(char *src, int i, int j, int cpy)
{
	char	*str;
	char	*res;
	int	index;

	index = 0;
	if (src[i - 1] == '(' && src[j + 1] == ')')
		i -= 1;
	if (src[i] == '(')
		j += 1;
	res = ft_tabint(cpy);
	str = (char*)malloc(sizeof(char) * (ft_strlen(src) + (ft_strlen(res) 
		- (j - i))));
	while (index < (ft_strlen(src) + (ft_strlen(res) - (j - i))))
	{
		if (index < i)
			str[index] = src[index];
		else if (index >= i && index < i + ft_strlen(res))
			str[index] = res[index - i];
		else
			str[index] = src[index + ((j - i) - ft_strlen(res) + 1)];
		index++;
	}
	return(str);
}
