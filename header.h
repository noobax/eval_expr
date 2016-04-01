#ifndef	HEADER_H

# define	HEADER_H

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c);
void	ft_putnbr(int nb);
int	eval_expr(char *str);
void	ft_putstr(char *str);
char	*clean_up(char *src, int i, int j, int cpy);
char	*ft_tabint(int nb);

#endif
