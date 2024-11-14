/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:16:27 by jboustan          #+#    #+#             */
/*   Updated: 2024/06/22 17:35:03 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static int	ft_count_substring(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str || !*str)
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && str[i] != c)
			i++;
	}
	return (count);
}

static char	*ft_extract_create(char const *str, char c)
{
	char	*s;
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	**ft_split(char const *str, char c)
{
	char	**string_array;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	string_array = malloc(sizeof(char *) * (ft_count_substring(str, c) + 1));
	if (!string_array)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
		{
			string_array[j++] = ft_extract_create((str + i), c);
			if (!(string_array[j - 1]))
				return (ft_free(string_array, j - 1), NULL);
		}
		while (str[i] != '\0' && str[i] != c)
			i++;
	}
	return (string_array[j] = NULL, string_array);
}
