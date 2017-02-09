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

typedef struct	s_list
{
	int			size;
	t_tet		*head;
	t_tet		*current;
}				t_list;

typedef struct	s_map
{
	int			size;
	int			**arr;
}				t_map;

// Define all 19 different types for quicker reference rather than having to mathematically rotate them
typedef struct	s_types
{
	int		**O1;
	int		**T1;
	int		**T2;
	int		**T3;
	int		**T4;
	int		**I1;
	int		**I2;
	int		**L1;
	int		**L2;
	int		**L3;
	int		**L4;
	int		**J1;
	int		**J2;
	int		**J3;
	int		**J4;
	int		**Z1;
	int		**Z2;
	int		**S1;
	int		**S2;
}				t_types;

int				o1[4][2] = {{0,0}, {0,1}, {1,0}, {1,1}};
int				t1[4][2] = {{0,0}, {0,1}, {0,2}, {1,1}};
int				t2[4][2] = {{0,1}, {1,0}, {1,1}, {2,1}};
int				t3[4][2] = {{0,1}, {1,0}, {1,1}, {1,2}};
int				t4[4][2] = {{0,0}, {0,1}, {1,1}, {2,0}};
int				i1[4][2] = {{0,0}, {1,0}, {2,0}, {3,0}};
int				i2[4][2] = {{0,0}, {0,1}, {0,2}, {0,3}};
int				l1[4][2] = {{0,0}, {1,0}, {2,0}, {2,1}};
int				l2[4][2] = {{0,0}, {0,1}, {0,2}, {1,0}};
int				l3[4][2] = {{0,0}, {0,1}, {1,1}, {2,1}};
int				l4[4][2] = {{0,2}, {1,0}, {1,1}, {1,2}};
int				j1[4][2] = {{0,1}, {1,1}, {2,0}, {2,1}};
int				j2[4][2] = {{0,0}, {1,0}, {1,1}, {1,2}};
int				j3[4][2] = {{0,0}, {0,1}, {1,0}, {2,0}};
int				j4[4][2] = {{0,0}, {0,1}, {0,2}, {1,2}};
int				z1[4][2] = {{0,0}, {0,1}, {1,1}, {1,2}};
int				z2[4][2] = {{0,1}, {1,0}, {1,1}, {2,0}};
int				s1[4][2] = {{0,1}, {0,2}, {1,0}, {1,1}};
int				s2[4][2] = {{0,0}, {1,0}, {1,1}, {2,1}};


static const t_types types = {(int **)o1, (int **)t1, (int **)t2, (int **)t3, (int **)t4, (int **)i1, (int **)i2, (int **)l1, (int **)l2, (int **)l3, (int **)l4, (int **)j1, (int **)j2, (int **)j3, (int **)j4, (int **)z1, (int **)z2, (int **)s1, (int **)s2};
t_tet			*new_tet(char *type, char order, int x, int y);
void			set_tet(t_tet *node, t_map *map, int x, int y);
int				read_in(int fd);
int				check_tet(char **v_tet);
int				check_tet2(char **v_tet);
char			*ot_tet_types(char *type_string);
char			*ij_tet_types(char *type_string);
char			*l_tet_types(char *type_string);
char			*zs_tet_types(char *type_string);
char			*tet_string(char **buf);
char			*find_tet_type(char *type_string);
int				ceil_sqrt(int tet_num);
t_map			*new_map(int size);
void			free_map(t_map *map);
#endif
