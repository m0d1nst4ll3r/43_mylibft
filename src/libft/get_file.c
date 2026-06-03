#include "libft.h"

// Public helper
void	free_file_contents(t_file_contents *contents)
{
	t_file_contents	*last;

	while (contents)
	{
		last = contents;
		contents = contents->next;
		free(last->line);
		free(last);
	}
}

static t_file_contents	*new_node(char *line)
{
	t_file_contents	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->line = line;
	new->next = NULL;
	return (new);
}

// This function resets errno to 0 before working
t_file_contents	*get_file(int fd)
{
	char			*line;
	t_file_contents	*contents;
	t_file_contents	*cur;
	t_file_contents	*last;

	errno = 0;
	contents = NULL;
	last = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (errno)
			return (free_file_contents(contents), NULL);
		if (!line)
			return (contents);
		cur = new_node(line);
		if (!cur)
			return (free_file_contents(contents), NULL);
		if (contents)
			last->next = cur;
		else
			contents = cur;
		last = cur;
	}
}
