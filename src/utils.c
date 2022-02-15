/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:46:59 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/10 20:47:05 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	ft_get_size_of_tabmap(char **tab_map)
{
	int	tab_size;

	tab_size = 0;
	while (tab_map[tab_size])
		tab_size++;
	return (tab_size);
}

char	*ft_strjoin2(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;
	char	*str;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (str == 0)
		return (str);
	i = 0;
	while (i < len_s1)
	{
		str[i] = s1[i];
		++i;
	}
	i = 0;
	while (i < len_s2)
	{
		str[len_s1 + i] = s2[i];
		++i;
	}
	str[len_s1 + i] = 0;
	return (str);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_strlen(const char *str)
{
	int	size_str;

	size_str = 0;
	while (str[size_str])
		size_str++;
	return (size_str);
}

char	*ft_strrchr(const char *s, int c)
{
	int	j;

	j = (int)ft_strlen((char *)s);
	while (j >= 0)
	{
		if (s[j] == c)
			return ((char *)&s[j]);
		j--;
	}
	return (NULL);
}
