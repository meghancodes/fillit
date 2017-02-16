#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"
#define TET_SIZE 21
#define TET_VARS int i; char *tet

typedef struct	s_tet
{
	int					**type;
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

typedef struct	s_map
{
	int			size;
	int			**arr;
}				t_map;

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

/*
** Coordinates relative to 0,0 as the top left to make up a tetrimino
*/

static int				o1[4][2] = {{0,0}, {0,1}, {1,0}, {1,1}};
static int				t1[4][2] = {{0,0}, {0,1}, {0,2}, {1,1}};
static int				t2[4][2] = {{0,0}, {1,-1}, {1,0}, {2,0}};
static int				t3[4][2] = {{0,0}, {1,-1}, {1,0}, {1,1}};
static int				t4[4][2] = {{0,0}, {0,1}, {1,1}, {2,0}};
static int				i1[4][2] = {{0,0}, {1,0}, {2,0}, {3,0}};
static int				i2[4][2] = {{0,0}, {0,1}, {0,2}, {0,3}};
static int				l1[4][2] = {{0,0}, {1,0}, {2,0}, {2,1}};
static int				l2[4][2] = {{0,0}, {0,1}, {0,2}, {1,0}};
static int				l3[4][2] = {{0,0}, {0,1}, {1,1}, {2,1}};
static int				l4[4][2] = {{0,0}, {1,-2}, {1,-1}, {1,0}};
static int				j1[4][2] = {{0,0}, {1,0}, {2,-1}, {2,0}};
static int				j2[4][2] = {{0,0}, {1,0}, {1,1}, {1,2}};
static int				j3[4][2] = {{0,0}, {0,1}, {1,0}, {2,0}};
static int				j4[4][2] = {{0,0}, {0,1}, {0,2}, {1,2}};
static int				z1[4][2] = {{0,0}, {0,1}, {1,1}, {1,2}};
static int	 			z2[4][2] = {{0,0}, {1,-1}, {1,0}, {2,-1}};
static int				s1[4][2] = {{0,0}, {0,1}, {1,-1}, {1,0}};
static int				s2[4][2] = {{0,0}, {1,0}, {1,1}, {2,1}};


static const t_types types = {(int **)o1, (int **)t1, (int **)t2, (int **)t3, (int **)t4, (int **)i1, (int **)i2, (int **)l1, (int **)l2, (int **)l3, (int **)l4, (int **)j1, (int **)j2, (int **)j3, (int **)j4, (int **)z1, (int **)z2, (int **)s1, (int **)s2};
t_tet			*new_tet(int **type, char order, int x, int y);
void			set_tet(t_tet *node, t_map *map, int x, int y);
int				valid_set(t_tet *node, t_map *map, int x, int y);
int				is_empty_map(t_map *map);
int				read_in(int fd);
int				check_tet(char *tet);
int				check_tet2(char *tet);
int				check_tet3(char *tet);
int				check_tet4(char *tet);
char			*remove_newlines(char *type_string);
void			to_struct(t_lst *list, int **type, char order);
int				**ot_tet_types(char *type_string);
int				**ij_tet_types(char *type_string);
int				**l_tet_types(char *type_string);
int				**zs_tet_types(char *type_string);
char			*tet_string(char *buf);
int				**find_tet_type(char *type_string);
int				ceil_sqrt(int tet_num);
t_map			*new_map(int size);
void			free_map(t_map *map);
void			solve(t_lst *tets);
void			print_map(t_map *map);
void			print_tets(t_lst *tets);

#endif
