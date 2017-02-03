#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#define TET_SIZE 21
#define TET_VARS int row; int column; int check; char **tet
#define READ_VARS char **buf; char *type; char *type_string; char order

typedef struct	s_tet
{
	char				*type;
	char				order;
	int					x;
	int					y;
	struct s_tet		*next;
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
int				read_in(int fd);
int				check_tet(char **v_tet);
int				check_tet2(char **v_tet);
char			*ot_tet_types(char *type_string);
char			*ij_tet_types(char *type_string);
char			*l_tet_types(char *type_string);
char			*zs_tet_types(char *type_string);
char			*tet_string(char **buf, char *type_string);
char			*find_tet_type(*type_string)
#endif
