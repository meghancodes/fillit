#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_tet
{
	char		type;
	int			order;
	int			x;
	int			y;
}				t_tet;

t_tet			*newtet(char type, int order, int x, int y);
#endif
