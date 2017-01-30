#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_tet
{
	char		*type;
	char		order;
	int			x;
	int			y;
}				t_tet;

typedef struct	s_map
{
	int			size;
	t_tet		**tets;
	int			**arr;
}				t_map;

t_tet			*new_tet(char *type, char order, int x, int y);
void			set_tet(t_tet *node, t_map *map, int x, int y);
#endif
