#include "libft.h"

// Public helper
void	free_file(t_file *file)
{
	t_file	*last;

	while (file)
	{
		last = file;
		file = file->next;
		free(last->line);
		free(last);
	}
}

static t_file	*new_node(char *line)
{
	t_file	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->line = line;
	new->next = NULL;
	return (new);
}

// This function resets errno to 0 before working
t_file	*get_file(int fd)
{
	char	*line;
	t_file	*file;
	t_file	*cur;
	t_file	*last;

	errno = 0;
	file = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (errno)
			return (free_file(file), NULL);
		if (!line)
			return (file);
		cur = new_node(line);
		if (!cur)
			return (free_file(file), NULL);
		if (file)
			last->next = cur;
		else
			file = cur;
		last = cur;
	}
}
