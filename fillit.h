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
	s_tet		*next;
}				t_tet;

typedef struct	s_map
{
	int			size;
	int			**arr;
}				t_map;

typedef struct	s_types
{
	int		**o;
	int		**t;
	int		**i;
	int		**l;
	int		**j;
	int		**z;
}						t_types;

// Need to define xy positions to start rotation static const t_types types = {}; 
t_tet			*new_tet(char *type, char order, int x, int y);
void			set_tet(t_tet *node, t_map *map, int x, int y);
#endif
