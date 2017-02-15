#include "fillit.h"

/*
**  Compares the inputted string to each tetrimino type
*/

int **ot_tet_types(char *type_string)
{
	char *O1 = "##..##";
	char *T1 = "###..#"; 
	char *T2 = "#...##..#";
	char *T3 = "#..##...#";
	char *T4 = "#..###";

	if (ft_strcmp(type_string, O1) == 0)
		return (types.O1);
	else if (ft_strcmp(type_string, T1) == 0)
		return (types.T1);
	else if (ft_strcmp(type_string, T2) == 0)
		return (types.T2);
	else if (ft_strcmp(type_string, T3) == 0)
		return (types.T3);
	else if (ft_strcmp(type_string, T4) == 0)
		return (types.T4);
	else
		return (NULL);
}

int **ij_tet_types(char *type_string)
{
	char *I1 = "#...#...#...#";
	char *I2 = "####";
	char *J1 = "#...#..##"; //need at least two dots in front to form the shape -. ..#...#..##
	char *J2 = "##..#...#";
	char *J3 = "#...###";
	char *J4 = "###...#";

	if (ft_strcmp(type_string, I1) == 0)
		return (types.I1);
	else if (ft_strcmp(type_string, I2) == 0)
		return (types.I2);
	else if (ft_strcmp(type_string, J1) == 0)
		return (types.J1);
	else if (ft_strcmp(type_string, J2) == 0)
		return (types.J2);
	else if (ft_strcmp(type_string, J3) == 0)
		return (types.J3);
	else if (ft_strcmp(type_string, J4) == 0)
		return (types.J4);
	else
		return (NULL);
}

int **l_tet_types(char *type_string)
{
	char *L1 = "#...#...##";
	char *L2 = "###.#";
	char *L3 = "##...#...#";
	char *L4 = "#.###"; //need at least two dots in front to form the shape -. ..#.###

	if (ft_strcmp(type_string, L1) == 0)
		return (types.L1);
	else if (ft_strcmp(type_string, L2) == 0)
		return (types.L2);
	else if (ft_strcmp(type_string, L3) == 0)
		return (types.L3);
	else if (ft_strcmp(type_string, L4) == 0)
		return (types.L4);
	else
		return (NULL);
}

int **zs_tet_types(char *type_string)
{
	char *Z1 = "##...##";
	char *Z2 = "#..##..#";
	char *S1 = "##.##";
	char *S2 = "#...##...#";
	

	if (ft_strcmp(type_string, Z1) == 0)
		return (types.Z1);
	else if (ft_strcmp(type_string, Z2) == 0)
		return (types.Z2);
	else if (ft_strcmp(type_string, S1) == 0)
		return (types.S1);
	else if (ft_strcmp(type_string, S2) == 0)
		return (types.S2);
	else
		return (NULL);
}
