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
	int		(*O1)[2];
	int		(*T1)[2];
	int		(*T2)[2];
	int		(*T3)[2];
	int		(*T4)[2];
	int		(*I1)[2];
	int		(*I2)[2];
	int		(*L1)[2];
	int		(*L2)[2];
	int		(*L3)[2];
	int		(*L4)[2];
	int		(*J1)[2];
	int		(*J2)[2];
	int		(*J3)[2];
	int		(*J4)[2];
	int		(*Z1)[2];
	int		(*Z2)[2];
	int		(*S1)[2];
	int		(*S2)[2];
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


static const t_types types = {o1, t1, t2, t3, t4, i1, i2, l1, l2, l3, l4, j1, j2, j3, j4, z1, z2, s1, s2};
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
