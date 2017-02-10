#include <unistd.h>
#include <string.h>

int check_tet(char *tet);
void	ft_putstr(char const *s);
void	ft_putchar(char c);
void	ft_putnbr(int n);
int	ft_strcmp(const char *s1, const char *s2);

int main(void)
{
	char *tet = "??###?????#????????";
;

	if (!(check_tet(tet)))			
		{																	
			ft_putstr("error here?\n"); 
			return (1);
		}
	return (0);
}

int check_tet(char *tet)
{
	int index;

	index = 0;
	while (index < strlen(tet))
	{
		if (i == 4 || i == 9 || i == 14 || i == 19)
		{
 			if (tet[i] != '\n')
 		}
		if (tet[index] == '?')
			break;
		else if (tet[index] == '#')
			break;
		else
			return (0);
		index++;
	}
	return (1);
}

void	ft_putstr(char const *s)
{
	char const	*str;
	int			index;

	index = 0;
	str = s;
	if (str)
	{
		while (str[index])
		{
			ft_putchar(str[index]);
			index++;
		}
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	index;

	index = 0;
	while (s1[index] && s2[index] && (s1[index] == s2[index]))
	{
		index++;
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}

//"?#??\n?#??\n##??\n????";

// int i;	

// 	i = 0;
// 	while (i < strlen(tet))
// 	{
// 		// if (i == 4 || i == 9 || i == 14 || i == 19)
// 		// {
// 		// 	if (tet[i] != '\n')
// 		// 	{
// 		// 		ft_putstr("maybe here?\n");
// 		// 		ft_putchar(tet[i]);
// 		// 		ft_putchar('\n');
// 		// 		return (0);
// 		// 	}
// 		// }
// 		if ((tet[i] != 'a') || (tet[i] != 'b'))
// 		{
// 			ft_putchar(tet[i]);
// 			ft_putchar('\n');
// 			ft_putstr("or HERE??\n");
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (1);
