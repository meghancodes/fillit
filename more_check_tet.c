#include <stdio.h>
#include <string.h>

//tet = ..##\n..##\n....\n....\n

int main(void)
{
	char *tet = "..##\n..##\n....\n....\n";

	if (!(check_tet(tet)))
		printf("error\n");
	if (!(check_tet3(tet)))
		printf("error2\n");
	if (!(check_tet4(tet)))
		printf("error3\n");
	return (0);
}

/*
**  Ensures that every character is a '.' '#' or '\n'
*/

int check_tet(char *tet)
{
	int index;
	int count;

	index = 0;
	count = 0;
	while (index < strlen(tet))
	{
		if (tet[index] == '.')
			count++;
		else if (tet[index] == '#')
			count++;
		else if (tet[index] == '\n')
			count++;
		else
			return (0);
		index++;
	}
	return (1);
}

/*
**  Ensures that there are 4 '\n' in the tet and they appear at every 5th char
*/

int check_tet3(char *tet)
{
	int index;
	int count;

	index = 0;
	count = 0;
	while (tet[index] != '\0')
	{
		if (tet[index] == '\n')
		{
			count++;
		}
		index++;
	}
	if (count != 4)
		return (0);
	return (1);
}

/*
**  Ensures that the '\n' appear at every 5th character
*/

int check_tet4(char *tet)
{
	int index;

	index = 0;
	while (tet[index] != '\0')
	{
		if (tet[4] != '\n' || tet[9] != '\n' || tet[14] != '\n' || tet[19] != '\n')
			return (0);
		index++;
	}
	return (1);
}

/*
**  Ensures that there are 4 "#" and that every one touches every other one
*/
