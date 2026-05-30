#include "libft.h"

// String is empty if it only contains spaces or newlines
int	ft_str_is_empty(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n')
		i++;
	return (!s[i]);
}
