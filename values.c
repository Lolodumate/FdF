/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:13:24 by laroges           #+#    #+#             */
/*   Updated: 2023/10/26 18:44:46 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	values_len_value(char *line, int i)
{
	int		len;

	len = 0;
	if (line[i] == '-')
	{
		len++;
		i++;
	}
	while (ft_isdigit(line[i]))
	{
		len++;
		i++;
	}
	return (len);
}

char	*values_create_str(int len)
{
	char	*str;

	if (len == 0)
		return (NULL);
	str = ft_calloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	return (str);
}

char	**values_create_value(char **argv, t_map *map)
{
	int		i;
	int		j;
	int		k;
	char	*line;

	i = 0;
	j = 0;
	k = 0;
	map.char_value = malloc(sizeof(char *) * map.x + 1);
	if (char_value == NULL)
		return (NULL);
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		map.char_value[j] = value_create_str(values_len_value(line, i));
		while (map.char_value[j])
		{
			char_value[j][k] = line[i];
			i++;
			k++;
		}
	}
	return (char_value);
}
