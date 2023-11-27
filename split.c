#include "fdf.h"

char **split_line(char *line, int size)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	**split;

	i = 0;
	j = 0;
	k = 0;
	len = 0;
	if (line == NULL)
		return (NULL);
	split = malloc(sizeof(char *) * size);
	if (split == NULL)
		return (NULL);
	while (j < size)
	{
		while (!ft_isdigit(line[i]))
			i++;
		len = values_len_value(line, i);
		split[j] = ft_calloc(sizeof(char), len + 1) ;
		if (split[j] == NULL)
		{
			free(split);
			return (NULL);
		}
		while (line[i] && line[i] != ' ')
		{
			split[j][k] = line[i];
			i++;
			k++;
		}
		k = 0;
		j++;
	}
	return (split);
}
