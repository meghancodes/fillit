# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# define TET_SIZE 21
# define TET_VARS int i; char *tet
# define READ_VARS char *buf; int **type; char *type_string; char *final_string; char order
#define T(tet, index) (tet[index - 5] == '#' || tet[index - 1] == '#' || tet[index + 1] == '#' || tet[index +5] == '#')
typedef struct	s_tet
{
	char				*type;
	char				order;
	int					x;
	int					y;
	struct s_tet		*next;
}				t_tet;

typedef struct	s_lst
{
	int			size;
	t_tet		*head;
	t_tet		*current;
}				t_lst;

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
void to_struct(t_lst *list, char *type, char order);
int		valid_set(t_tet *node, t_map *map, int x, int y);
int		is_empty_map(t_map *map);
void	set_tet(t_tet *node, t_map *map, int x, int y);
void	solve(t_lst *tets);
t_tet		*new_tet(char *type, char order, int x, int y);

int main (int argc, char *argv[])
{
	int	result;

	if (argc != 2)
	{
		ft_putstr("usage: fillit_file\n");
		return (-1);
	}

	if ((result = (read_in(open(argv[1], O_RDONLY)))) == 0)
	{
		ft_putstr("error\n");
		return (-1);
	}
	return (0);
}

void	solve(t_lst *tets)
{
	t_map	*map;
	int		x;
	int		y;

	map = new_map(ceil_sqrt(tets->size));
	print_map(map);
	x = 0;
	y = 0;
	if(valid_set(tets->head, map, x, y))
		set_tet(tets->head, map, x, y);
	print_map(map);
}

int		valid_set(t_tet *node, t_map *map, int x, int y)
{
	int i;
	int count;

	node->x = x;
	node->y = y;
	i = 0;
	count = 0;
	if (is_empty_map(map))
		return (1);
	if (!is_empty_map(map))
	{
		ft_putstr("The error isn't here\n");
		while (i++ < 4)
		{
			if (map->arr[x + node->type[i][1]][y + node->type[i][0]] == 0)
			{
				if (map->arr[x + node->type[i][1]][(y + node->type[i][0])-1] != 1 || map->arr[(x + node->type[i][1])+1][y + node->type[i][0]] != 1
					|| map->arr[x + node->type[i][1]][(y + node->type[i][0])+1] != 1 || map->arr[(x + node->type[i][1])-1][y + node->type[i][0]] != 1)
					count++;
			}
		}
	}
	ft_putstr("Valid set works \n");
	if (count >= 1)
		return (1);
	return (0);
}

int		is_empty_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i++ < map->size)
	{
		j = 0;
		while (j++ < map->size)
		{
			if (map->arr[i][j] != 0)
				return (0);
		}
	}
	return (1);
}

void	set_tet(t_tet *node, t_map *map, int x, int y)
{
	int i;

	node->x = x;
	node->y = y;
	i = 0;
	while (i < 4)
	{
		ft_putstr("inside loop\n");
		ft_putnbr(node->type[i][1]);
		ft_putnbr(node->type[i][0]);
		i++;
	}
	map->size = map->size;
}


int read_in(int fd)
{
	READ_VARS;
	t_lst	*list;

	order = 65;
	if (!(list = (t_lst *)malloc(sizeof(t_lst))))
		return (0);
	if (!(buf = (char *)malloc(sizeof(char))))
		return (0);
	while (read(fd, (void *)buf, TET_SIZE) > 0)
	{	
		ft_putstr("this is the buffer fresh from read:\n");
		ft_putstr(buf);
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
		to_struct(list, type, order);
	 	order++;
	// 	}
	// 	ft_bzero(buf, TET_SIZE);
	// 	ft_bzero(type_string, TET_SIZE);
	}
	return (1);
}

/*
**  Puts type and order into a struct
*/

void to_struct(t_lst *list, int **type, char order)
{
	if (order == 65)
	{
		list->size = 1;
		list->head = new_tet(type, order, 0, 0);
		list->current = list->head;
	}
	else
	{
		list->size = list->size + 1;
		list->current->next = new_tet(type, order, 0, 0);
		list->current = list->current->next;
	}
	printf("%d\n", list->size);
	printf("%c\n", order);
}

t_tet		*new_tet(int **type, char order, int x, int y)
{
	t_tet	*new;

	new = (t_tet*)malloc(sizeof(t_tet));
	if (new)
	{
		new->type = type;
		new->order = order;
		new->x = x;
		new->y = y;
		new->next = NULL;
		return (new);
	}
	return (NULL);
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
	while ((size_t)index < ft_strlen(tet))
	{
		if (tet[index] == '.')
			count++;
		else if (tet[index] == '#')
			count++;
		else if (tet[index] == '\n')
			count++;
		else
			return (0);
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

	index = 0;
	count = 0;
	while (tet[index] != '\0')
	{
		if(tet[index] == '#')
		{
			if (T(tet, index))
				count++;
			else
				return (0);
		}
		index++;
	}
	if (count != 4)
		return (0);
	return (1);
}

/*
**  Ensures that '\n's appear at the right places and that there are exactly 5
*/

int check_tet3(char *tet)
{
	int index;
	int	count;

	index = 0;
	count = 0;
	while (tet[index] != '\0')
	{
		if (tet[index] == '\n')
			count++;
		if (tet[4] != '\n' || tet[9] != '\n' || tet[14] != '\n' || tet[19] != '\n' 
			|| tet[20] != '\n')
			return (0);
		index++;
	}
	if (count != 5)
		return (0);
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
	int **type;

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

char *ot_tet_types(char *type_string)
{
	char *O1 = "##..##";
	char *T1 = "###..#"; 
	char *T2 = "#...##..#";
	char *T3 = "#..##...#";
	char *T4 = "#..###";

	if (ft_strcmp(type_string, O1) == 0)
		return ({{0,0}, {0,1}, {1,0}, {1,1}});
	else if (ft_strcmp(type_string, T1) == 0)
		return ({{0,0}, {0,1}, {0,2}, {1,1}});
	else if (ft_strcmp(type_string, T2) == 0)
		return ({{0,0}, {1,-1}, {1,0}, {2,0}});
	else if (ft_strcmp(type_string, T3) == 0)
		return ({{0,0}, {1,-1}, {1,0}, {1,1}});
	else if (ft_strcmp(type_string, T4) == 0)
		return ({{0,0}, {0,1}, {1,1}, {2,0}});
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
		return ({{0,0}, {1,0}, {2,0}, {3,0}});
	else if (ft_strcmp(type_string, I2) == 0)
		return ({{0,0}, {0,1}, {0,2}, {0,3}});
	else if (ft_strcmp(type_string, J1) == 0)
		return ({{0,0}, {1,0}, {2,-1}, {2,0}});
	else if (ft_strcmp(type_string, J2) == 0)
		return ({{0,0}, {1,0}, {1,1}, {1,2}});
	else if (ft_strcmp(type_string, J3) == 0)
		return ({{0,0}, {0,1}, {1,0}, {2,0}});
	else if (ft_strcmp(type_string, J4) == 0)
		return ({{0,0}, {0,1}, {0,2}, {1,2}});
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
		return ({{0,0}, {1,0}, {2,0}, {2,1}});
	else if (ft_strcmp(type_string, L2) == 0)
		return ({{0,0}, {0,1}, {0,2}, {1,0}});
	else if (ft_strcmp(type_string, L3) == 0)
		return ({{0,0}, {0,1}, {1,1}, {2,1}});
	else if (ft_strcmp(type_string, L4) == 0)
		return ({{0,0}, {1,-2}, {1,-1}, {1,0}});
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
		return ({{0,0}, {0,1}, {1,1}, {1,2}});
	else if (ft_strcmp(type_string, Z2) == 0)
		return ({{0,0}, {1,-1}, {1,0}, {2,-1}});
	else if (ft_strcmp(type_string, S1) == 0)
		return ({{0,0}, {0,1}, {1,-1}, {1,0}});
	else if (ft_strcmp(type_string, S2) == 0)
		return ({{0,0}, {1,0}, {1,1}, {2,1}});
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
