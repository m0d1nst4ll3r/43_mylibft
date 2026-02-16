#include <stdio.h>
#include "libft.h"

int	main(int ac, char **av)
{
	int		ret;
	int		val;

	(void)ac;
	val = 0;
	ret = ft_atox(av[1], 0, &val, 3 | ATOX_LAX);
	if (ret < 0)
		ft_printf("Error: %s\n", av[1]);
}
