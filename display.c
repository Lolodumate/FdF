#include "fdf.h"

void	display_fdf_file(t_map *map)
{
	if (map == NULL)
		return ;
	map->y = 0;
	map->x = 0;
	while (map->y++ < map->size_y)
	{
		while (map->x++ < map->size_x)
		{
			printf("[%d] ", map->tab_map[map->y][map->x]);
		}
		map->x = 0;
		printf("\n");
	}
}

void	display_int_array(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < map->size_y)
	{
		while (i < map->size_x)
		{
			ft_putnbr_fd(map->tab_map[j][i], 1);
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		i = 0;
		j++;
	}
}
