#include "fdf.h"

void	ev_up_and_down(t_map *map)
{
	int		v;
	int		i;
	int		j;

	v = 1;
	i = 0;
	j = 0;
	map = ev_update_map(map, v);
	ft_putnbr_fd(map->tab_map[j][i], 1);
}

t_map	*ev_update_map(t_map *map, int v)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < map->size_y)
	{
		while (i < map->size_x)
		{
			if (map->tab_map[j][i] != 0)
				map->tab_map[j][i] += v;
			ft_putnbr_fd(map->tab_map[j][i], 1);
			i++;
		}
		i = 0;
		j++;
	}
	return (map);
}
