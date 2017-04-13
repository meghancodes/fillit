#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"
#define TET_SIZE 21
#define TET_VARS int i; char *tet
#define READ_VARS char *buf; char order
#define T(tet, i) (tet[i - 5] == '#' || tet[i- 1] == '#' || tet[i + 1] == '#' || tet[i + 5] == '#')

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
	int					h;
	int					w;
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
	char		**arr;
}				t_map;

typedef struct	s_types
{
	int			size;
	t_type		*head;
	t_type		*current;
}				t_types;

t_tet			*new_tet(t_type *type, char order, int x, int y);
t_tet			*set_tet(t_tet *tet, char fill, t_map *map, int x, int y);
void			unset_tet(t_map *map, t_tet *tet);
int				valid_set(t_tet *node, t_map *map, int x, int y);
int				is_empty_map(t_map *map);
t_lst			*read_in(int fd);
int				check_tet(char *tet);
int				check_tet2(char *tet);
int				check_tet3(char *tet);
char			*remove_newlines(char *type_string);
void			to_struct(t_lst *list, t_type *type, char order);
t_type			*tet_types(char *final_string);
char			*tet_string(char *buf);
void			create_typelist(void);
int				ceil_sqrt(int tet_num);
t_map			*new_map(int size);
void			free_map(t_map *map);
void			set_map_val(t_map *map, int x, int y);
void			solver(t_lst *list);
int				solve(t_tet *tet, t_map *map);
void			print_map(t_map *map);
void			print_tets(t_lst *tets);
int				is_big_enough(t_map *map, t_tet *tet, int lines);
int				check_shape(t_type *type);
void			tet_size(t_tet *tet);
void			zero_map(t_map *map);
int				fill_in(t_tet *tet, t_map *map, int lines, int x, int y, int count);
int				process_string(int fd, void *buf, t_lst *list, char order);
int				check_tet4(char *final_string);

#endif
