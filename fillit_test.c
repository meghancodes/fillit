# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# define TET_SIZE 21
# define TET_VARS int i; char *tet
# define READ_VARS char *buf; char *type; char *type_string; char *final_string  //; char order
int read_in(int fd);
char *tet_string(char *buf);
char *remove_newlines(char *type_string);
char *find_tet_type(char *type_string);
int	check_tet(char *tet);
int check_tet2(char *tet);
int	check_tet3(char *tet);
int	check_tet4(char *tet);
char *ot_tet_types(char *type_string);
char *ij_tet_types(char *type_string);
char *l_tet_types(char *type_string);
char *zs_tet_types(char *type_string);
void	ft_putstr(char const *s);
void	ft_putchar(char c);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
int	ft_strcmp(const char *s1, const char *s2);
void	ft_putnbr(int n);

int main (int argc, char **argv)
{
	read_in(open(argv[1], O_RDONLY));
	return (0);
}

// int main (int argc, char *argv[])
// {
// 	int	result;

// 	if (argc != 2)
// 	{
// 		ft_putstr("usage: fillit_file\n");
// 		return (-1);
// 	}

// 	if ((result = (read_in(open(argv[1], O_RDONLY)))) == 0)
// 	{
// 		ft_putstr("error\n");
// 		return (-1);
// 	}

// 	return (0);
// }

int read_in(int fd)
{
	READ_VARS;
//	t_list	*list;

//	order = 65;
//	if (!(list = (t_list *)malloc(sizeof(t_list))))
//		return (0);
	if (!(buf = (char *)malloc(sizeof(char))))
		return (0);
	while (read(fd, (void *)buf, TET_SIZE) > 0)
	{	
		if (!(check_tet(buf)) || !(check_tet2(buf)) || !(check_tet3(buf)) || !(check_tet4(buf)))			
		{																	
			ft_putstr("error here?\n");
			exit (fd); 
			return (0);
		}
		type_string = tet_string(buf);
		ft_putstr(type_string);
		ft_putchar('\n');
		final_string = remove_newlines(type_string);
		ft_putstr(final_string);
		ft_putchar('\n');
		type = find_tet_type(final_string);
		ft_putstr(type);
		ft_putchar('\n');
	// //		to_struct(list, type, order);
	// 		order++;
	// 	}
	// 	ft_bzero(buf, TET_SIZE);
	// 	ft_bzero(type_string, TET_SIZE);
	}
	// ft_putstr(type);
	return (1);
}

/*
**  Ensures that every character is a '.' '#' or '\n'
*/

int check_tet(char *tet)
{
	int index;
	int count;

	index = 0;
	count = 0;
	while (index < strlen(tet))
	{
		if (tet[index] == '.')
			count++;
		else if (tet[index] == '#')
			count++;
		else if (tet[index] == '\n')
			count++;
		else
		{
			ft_putstr("invalid character\n");
			return (0);
		}
		index++;
	}
	return (1);
}

/*
**  Ensures that there are 4 '#' and every '#' touches at least one other one
*/

int check_tet2(char *tet)
{
	int index;
	int count;
	int hash_touch;

	index = 0;
	count = 0;
	hash_touch = 0;
	while (tet[index] != '\0')
	{
		if(tet[index] == '#')
		{
			count++;
			if ((tet[index - 5]) == '#' || (tet[index - 1]) == '#' || (tet[index + 1]) == '#' || (tet[index + 5]) == '#')
				hash_touch++;
			else
			{
				ft_putstr("hashes aren't touching\n");
				return (0);
			}
		}
		index++;
	}
	if (count != 4)
	{
		ft_putstr("wrong number of hashes\n");
		return (0);
	}
	return (1);
}

/*
**  Ensures that there are 4 '\n' in the tet
*/

int check_tet3(char *tet)
{
	int index;
	int count;

	index = 0;
	count = 0;
	while (tet[index] != '\0')
	{
		if (tet[index] == '\n')
			count++;
		index++;
	}
	if (count != 4)
	{
		ft_putstr("newline number error\n");
		return (0);
	}
	return (1);
}

/*
**  Ensures that the '\n' appear at every 5th character
*/

int check_tet4(char *tet)
{
	int index;

	index = 0;
	while (tet[index] != '\0')
	{
		if (tet[4] != '\n' || tet[9] != '\n' || tet[14] != '\n' || tet[19] != '\n')
		{
			ft_putstr("newline placement error\n");
			return (0);
		}
		index++;
	}
	return (1);
}

char *tet_string(char *buf)
{
	char *type_string;
	int hash_count;
	int index;
	int index2;

	index = 0;
	index2 = 0;
	if (!(type_string = (char *)malloc(sizeof(char) * strlen(buf))))
		return (NULL);
	hash_count = 4;
	while (buf[index] != '\0')
	{
		if (buf[index] == '#')
		{	
			while (hash_count >= 1)									
			{
				if (buf[index] == '#')
					hash_count--;
				type_string[index2++] = buf[index++];
			}
			type_string[index2] = '\0';
		}
		index++;
	}
	return (type_string);
}

char *remove_newlines(char *type_string)
{
	char *final_string;
	int index;
	int index2;

	index = 0;
	index2 = 0;
	if (!(final_string = (char *)malloc(sizeof(char) * strlen(type_string))))
		return (NULL);
	while (type_string[index] != '\0')
	{
		if (type_string[index] == '\n')
			index++;
		final_string[index2] = type_string[index];
		index++;
		index2++;
	}
	final_string[index2] = '\0';
	return (final_string);
}

char *find_tet_type(char *type_string)
{
	char *type;

	type = NULL;
	if (ot_tet_types(type_string) != 0)								
		type = ot_tet_types(type_string);
	else if (ij_tet_types(type_string) != 0)
		type = ij_tet_types(type_string);
	else if (l_tet_types(type_string) != 0)
		type = l_tet_types(type_string);
	else if (zs_tet_types(type_string) != 0)
		type = zs_tet_types(type_string);
	return (type);
}

// int	check_tet(char *v_tet)
// {
// 	TET_VARS;

// 	i = 0;
// 	tet = v_tet;
// 	while (i < 19)
// 	{
// 		if (i == 4 || i == 9 || i == 14 || i == 19)
// 		{
// 			if (tet[i] != '\n')
// 			{
// 				ft_putstr("maybe here?\n");
// 				ft_putchar(tet[i]);
// 				ft_putchar('\n');
// 				return (0);
// 			}
// 		}
// 		else if (ft_strcmp(&tet[i], "?") || ft_strcmp(&tet[i], "#"))
// 		{
// 			ft_putstr("or HERE??\n");
// 			ft_putchar(tet[i]);
// 			ft_putchar('\n');
// 			ft_putnbr(ft_strcmp(&tet[i], "?"));
// 			ft_putchar('\n');
// 			ft_putnbr(ft_strcmp(&tet[i], "#"));
// 			ft_putchar('\n');
// 			ft_putnbr(i);
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (1);
// }

char *ot_tet_types(char *type_string)
{
	char *O1 = "##..##";
	char *T1 = "###..#"; 
	char *T2 = "#...##..#";
	char *T3 = "#..##...#";
	char *T4 = "#..###";

	if (ft_strcmp(type_string, O1) == 0)
		return ("O1");
	else if (ft_strcmp(type_string, T1) == 0)
		return ("T1");
	else if (ft_strcmp(type_string, T2) == 0)
		return ("T2");
	else if (ft_strcmp(type_string, T3) == 0)
		return ("T3");
	else if (ft_strcmp(type_string, T4) == 0)
		return ("T4");
	else
		return (NULL);
}

char *ij_tet_types(char *type_string)
{
	char *I1 = "#...#...#...#";
	char *I2 = "####";
	char *J1 = "#...#..##"; //need one dot in front to form the shape --> .#...#..##
	char *J2 = "##..#...#";
	char *J3 = "#...###";
	char *J4 = "###...#";

	if (ft_strcmp(type_string, I1) == 0)
		return ("I1");
	else if (ft_strcmp(type_string, I2) == 0)
		return ("I2");
	else if (ft_strcmp(type_string, J1) == 0)
		return ("J1");
	else if (ft_strcmp(type_string, J2) == 0)
		return ("J2");
	else if (ft_strcmp(type_string, J3) == 0)
		return ("J3");
	else if (ft_strcmp(type_string, J4) == 0)
		return ("J4");
	else
		return (NULL);
}

char *l_tet_types(char *type_string)
{
	char *L1 = "#...#...##";
	char *L2 = "###.#";
	char *L3 = "##...#...#";
	char *L4 = "#.###"; //need at least two dots in front to form the shape --> ..#.###

	if (ft_strcmp(type_string, L1) == 0)
		return ("L1");
	else if (ft_strcmp(type_string, L2) == 0)
		return ("L2");
	else if (ft_strcmp(type_string, L3) == 0)
		return ("L3");
	else if (ft_strcmp(type_string, L4) == 0)
		return ("L4");
	else
		return (NULL);
}

char *zs_tet_types(char *type_string)
{
	char *Z1 = "##...##";
	char *Z2 = "#..##..#";
	char *S1 = "##.##";
	char *S2 = "#...##...#";
	

	if (ft_strcmp(type_string, Z1) == 0)
		return ("Z1");
	else if (ft_strcmp(type_string, Z2) == 0)
		return ("Z2");
	else if (ft_strcmp(type_string, S1) == 0)
		return ("S1");
	else if (ft_strcmp(type_string, S2) == 0)
		return ("S2");
	else
		return (NULL);
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

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			index;
	unsigned char	*b2;
	unsigned char	c2;

	b2 = b;
	c2 = c;
	index = 0;
	while (index < len)
	{
		b2[index] = c2;
		index++;
	}
	return (b);
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
