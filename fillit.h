#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"
#define TET_SIZE 21
#define TET_VARS int i; char *tet

typedef struct	s_type
{
	char				*shape;
	char				*name;
	struct s_type		*next;
}				t_type;

typedef struct	s_tet
{
	t_type				*type;
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
	int			size;
	t_type		*head;
	t_type		*current;
}				t_types;

t_tet			*new_tet(t_type *type, char order, int x, int y);
void			set_tet(t_tet *node, t_map *map, int x, int y);
int				valid_set(t_tet *node, t_map *map, int x, int y);
int				is_empty_map(t_map *map);
int				read_in(int fd);
int				check_tet(char *tet);
int				check_tet2(char *tet);
int				check_tet3(char *tet);
char			*remove_newlines(char *type_string);
void			to_struct(t_lst *list, t_type *type, char order);
t_type			*tet_types(char *final_string);
char			*tet_string(char *buf);
//int				**find_tet_type(char *type_string);
void			create_typelist(void);
int				ceil_sqrt(int tet_num);
t_map			*new_map(int size);
void			free_map(t_map *map);
void			set_map_val(t_map *map, int x, int y);
void			solve(t_lst *list);
void			print_map(t_map *map);
void			print_tets(t_lst *tets);
int				is_big_enough(t_map *map, t_tet *tet);
int			check_shape(t_type *type);

#endif
