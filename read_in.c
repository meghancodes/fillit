void write_error(void)
{
	char *error_string;
	int index;

	error_string = "error\n";
	index = 0;
	while (error_string != '\0');
	{
		ft_putchar(error_string[index])++;
		index++
	}
}

void tet_shapes(void)
{
	char *o = "##..##";
	char *t = "###..#";
	char *t2 = "#...##..#";
	char *t3 = "#..##...#";
	char *t4 = "#..###";
	char *i = "#...#...#...#";
	char *i2 = "####";
	char *l = "#...#...##";
	char *l2 = "##..#...#";
	char *l3 = "###.#";
	char *l4 = "#...###";
	char *l5 = "#...#..##";
	char *l6 = "##...#...#";
	char *l7 = "#.###";
	char *l8 = "###...#";
	char *z = "##...##";
	char *z2 = "#..##..#";
	char *z3 = "#...##...#";
	char *z4 = "##.##";
}

int read_in(int fd)
{
	void **buf;

	if (!(*buf = (char *)malloc(sizeof(char) * sizeoftetromino)))
		return (0);
	while (read(fd, *buf, sizeoftetromino) > 0)
	{
		if (((check_table(*buf)) != 1) && ((check_table2(*buf)) != 1))
		{
			write_error();
			exit (fd)
			return (0);
		}
		else
		{
			
		}
		ft_bzero(buf, sizeoftetromino);
	}
}