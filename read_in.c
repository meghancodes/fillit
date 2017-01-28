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

int read_in(int fd)
{
	void **buf;

	if (!(*buf = (char *)malloc(sizeof(char) * sizeoftetromino)))
		return (-1);
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