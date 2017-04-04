//read tetrominoes from fd and check if valid

//exit, open, close, write, read, malloc, free

//in h file, put a struct that holds each tetromino

tetromino types: http://mathworld.wolfram.com/Tetromino.html

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

//per n: read the entire file into the buffer then move each tet into an array and process

int read_in(int fd)
{
	void **buf; //can it be char **buf? if not change check functions

	if (!(*buf = (char *)malloc(sizeof(char) * sizeoftetromino)))
		return (-1);
	while (read(fd, *buf, sizeoftetromino) > 0) //loop that reads each tetromino in 1 at a time, checks it for validity, and then assigns it a struct
	{
		//there's a new line between each tetromino
		if (((check_table(*buf)) != 1) && ((check_table2(*buf)) != 1)) //tetromino is bad
		{
			write_error();
			exit (fd)
			return (0);
		}
		else //tetromino is good
		{
			assign it a struct or linked list? need to hold type of tetromino, order letter, xy coordinates
		}
		ft_bzero(buf, sizeoftetromino); //make buf zero again for size of tetrominosize
	}
}

//1/29

else //make this a new function
		{
			while (*buf != '\0')
			{
				if (*buf == '#')
				{	
					while (hash_count >= 1)
					{
						if (*buf == '#')
							hash_count--;
						shape_string = *buf;
						buf++;
						shape_string++
					}
				}
				*buf++
			}
			if (ot_tet_shapes(shape_string) == 1)
				type = 
		}