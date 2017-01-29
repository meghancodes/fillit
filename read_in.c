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
	char type;
	char *type_string;
	int count;
	int hash_count;

	count = 0;
	hash_count = 4;
	if (!(*buf = (char *)malloc(sizeof(char) * sizeoftetromino)))
		return (0);
	if (!(type_string = (char *)malloc(sizeof(char) * sizeoftetromino)))
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
			while (*buf != '\0')
			{
				if (*buf == '#')
				{	
					while (hash_count >= 1)
					{
						if (*buf == '#')
							hash_count--;
						type_string = *buf;
						buf++;
						type_string++
					}
				}
				*buf++
			}
			if (function != 0)
				type =  
		}
		ft_bzero(buf, sizeoftetromino);
	}
}