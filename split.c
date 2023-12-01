#include "fdf.h"

int	split_map_contain_colors(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
			return (true);
		i++;
	}
	return (false);
}

char	**split_get_value(char *line, int size)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	**value;

	i = 0;
	j = 0;
	k = 0;
	len = 0;
//	printf("ft_strlen(line) = %ld\n", ft_strlen(line));
	value = malloc(sizeof(char *) * size);
	if (line == NULL || value == NULL)
		return (NULL);
	while (j < size)
	{
		while (line[i] && !ft_isdigit(line[i]))
			i++;
//		printf("Valeur de i = %d\n", i);
		len = values_len_value(line, i);
		value[j] = ft_calloc(sizeof(char), len + 1) ;
		if (value[j] == NULL)
		{
			free(value);
			return (NULL);
		}
		while (line[i] && ft_isdigit(line[i]))
		{
			value[j][k] = line[i];
//			printf("Valeur de i = %d\n", i);
			i++;
			k++;
		}
		if (line[i] == ',')
		{
			i++;
			while (ft_isalnum(line[i]))
				i++;
		}
		k = 0;
		j++;
	}
	return (value);
}

char	**split_get_color(char *line, int size)
{
	int		i;
	int		j;
	int		k;
	char	**color;

	i = 0;
	j = 0;
	k = 0;
	color = malloc(sizeof(char *) * size);
	if (line == NULL || color == NULL)
		return (NULL);
	while (j < size)
	{
		color[j] = ft_calloc(sizeof(char), 8 + 1);
		if (color[j] == NULL)
		{
			free(color);
			return (NULL);
		}
		while (line[i] && line[i] != ',')
			i++;
		if (line[i] && line[i] == ',')
		{
			i++;
			while (line[i] && ft_isalnum(line[i]))
			{
				color[j][k] = line[i];
				i++;
				k++;
			}
			k = 0;
		}
		color[j][8] = '\0';
		j++;
	}
	return (color);
}
