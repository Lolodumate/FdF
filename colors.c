#include "fdf.h"

void	colors_create_tab_colors(t_mlx_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	data->tab_colors = ft_calloc(sizeof(char **), data->size_y + 1);
	if (data->tab_colors == NULL)
	{
		printf("Erreur allocation dynamique data->tab_colors\n");
		return ;
	}
	else
		printf("Allocation dynamique data->tab_colors OK\n");
	while (y <= data->size_y)
	{
		data->tab_colors[y] = ft_calloc(sizeof(char *), data->size_x + 1);
		if (data->tab_colors[y] == NULL)
		{
			printf("Erreur allocation dynamique tab_colors[%d]\n", y);
			return ;
		}
		else
			printf("Allocation dynamique tab_colors[%d] OK\n", y);
		while (x <= data->size_x)
		{
			data->tab_colors[y][x] = ft_calloc(sizeof(char), 8 + 1);
			if (data->tab_colors[y][x] == NULL)
			{
				printf("Erreur allocation dynamique data->tab_colors[%d][%d]\n", y, x);
				free(data->tab_colors[y]);
				free(data->tab_colors);
				return ;
			}
			else
				printf("Allocation dynamique data->tab_colors[%d][%d] OK\n", y, x);
			x++;
		}
		x = 0;
		y++;
	}
}

t_parsing	*colors_insert_colors(t_parsing *list, t_mlx_data *data)
{
	t_parsing	*ptr;

	ptr = list;

	if (list == NULL)
		return (NULL);
	data->y = data->size_y - 1;
	while (list && (data->y >= 0))
	{
		while (data->x < data->size_x)
		{
			ft_strlcpy(data->tab_colors[data->y][data->x], list->parsing_color[data->x], 8);
			printf("data->tab_colors[%d] = %s\n", data->y, data->tab_colors[data->y][data->x]);
			free(list->parsing_color[data->x]);
			data->x++;
		}
		list = list->next;
		data->y--;
		data->x = 0;
	}
	data->y = 0;
	return (ptr);
}
