#include "fillit.h"

/*
**  Compares the inputted string to each tetrimino type
*/

char *ot_tet_types(char *type_string)
{
	char *O1 = "##..##";
	char *T1 = "###..#"; 
	char *T2 = "#...##..#";
	char *T3 = "#..##...#";
	char *T4 = "#..###";

	if (ft_strcmp(type_string, O1) == 0)
		return ("O1");
	else if (ft_strcmp(type_string, T1) == 0)
		return ("T1");
	else if (ft_strcmp(type_string, T2) == 0)
		return ("T2");
	else if (ft_strcmp(type_string, T3) == 0)
		return ("T3");
	else if (ft_strcmp(type_string, T4) == 0)
		return ("T4");
	else
		return (NULL);
}

char *ij_tet_types(char *type_string)
{
	char *I1 = "#...#...#...#";
	char *I2 = "####";
	char *J1 = "#...#..##"; //need at least two dots in front to form the shape --> ..#...#..##
	char *J2 = "##..#...#";
	char *J3 = "#...###";
	char *J4 = "###...#";

	if (ft_strcmp(type_string, I1) == 0)
		return ("I1");
	else if (ft_strcmp(type_string, I2) == 0)
		return ("I2");
	else if (ft_strcmp(type_string, J1) == 0)
		return ("J1");
	else if (ft_strcmp(type_string, J2) == 0)
		return ("J2");
	else if (ft_strcmp(type_string, J3) == 0)
		return ("J3");
	else if (ft_strcmp(type_string, J4) == 0)
		return ("J4");
	else
		return (NULL);
}

char *l_tet_types(char *type_string)
{
	char *L1 = "#...#...##";
	char *L2 = "###.#";
	char *L3 = "##...#...#";
	char *L4 = "#.###"; //need at least two dots in front to form the shape --> ..#.###

	if (ft_strcmp(type_string, L1) == 0)
		return ("L1");
	else if (ft_strcmp(type_string, L2) == 0)
		return ("L2");
	else if (ft_strcmp(type_string, L3) == 0)
		return ("L3");
	else if (ft_strcmp(type_string, L4) == 0)
		return ("L4");
	else
		return (NULL);
}

char *zs_tet_types(char *type_string)
{
	char *Z1 = "##...##";
	char *Z2 = "#..##..#";
	char *S1 = "##.##";
	char *S2 = "#...##...#";
	

	if (ft_strcmp(type_string, Z1) == 0)
		return ("Z1");
	else if (ft_strcmp(type_string, Z2) == 0)
		return ("Z2");
	else if (ft_strcmp(type_string, S1) == 0)
		return ("S1");
	else if (ft_strcmp(type_string, S2) == 0)
		return ("S2");
	else
		return (NULL);
}
