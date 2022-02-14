/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:21:02 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/10 23:21:06 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	ft_check_number_of_items(t_utils *ptr)
{
	if ((*ptr).nb_of_collectibles == 0)
	{
		ft_free_struct_tab((*ptr).tab_map);
		free(ptr);
		ptr = NULL;
		ft_error_and_exit("Error\nyou need collectibles\n");
	}
	if ((*ptr).nb_of_exits == 0)
	{
		ft_free_struct_tab((*ptr).tab_map);
		free(ptr);
		ptr = NULL;
		ft_error_and_exit("Error\nnb_of_exits is wrong\n");
	}
	if ((*ptr).nb_of_players != 1)
	{
		ft_free_struct_tab((*ptr).tab_map);
		free(ptr);
		ptr = NULL;
		ft_error_and_exit("Error\none player is required\n");
	}
}

void	ft_get_items_number(char *tab_line, t_utils *ptr)
{
	while (*tab_line)
	{
		if ((ft_strchr(ITEM_CODE, *tab_line) == NULL))
		{
			ft_free_struct_tab((*ptr).tab_map);
			free(ptr);
			ptr = NULL;
			ft_error_and_exit("Error\nwrong item in the map, check rules\n");
		}
		if (*tab_line == 'C')
			(*ptr).nb_of_collectibles++;
		else if (*tab_line == 'E')
			(*ptr).nb_of_exits++;
		else if (*tab_line == 'P')
			(*ptr).nb_of_players++;
		tab_line++;
	}
}

int	ft_isrectangle(char **tab_map, t_utils *ptr)
{
	int	i;

	i = 1;
	if (tab_map[i] == NULL || ft_strlen(tab_map[i]) == 0)
	{
		ft_free_struct_tab((*ptr).tab_map);
		free(ptr);
		ptr = NULL;
		ft_error_and_exit("Error\nthe map is not a rectangle\n");
	}
	while (tab_map[i])
	{
		if ((ft_strlen(tab_map[0]) != ft_strlen(tab_map[i])))
		{
			ft_free_struct_tab((*ptr).tab_map);
			free(ptr);
			ptr = NULL;
			ft_error_and_exit("Error\nthe map is not a rectangle\n");
		}
		i++;
	}
	return (1);
}

int	ft_check_map_border(t_utils *ptr)
{
	int	i;
	int	j;

	i = 0;
	while ((*ptr).tab_map[i])
	{
		if (*(*ptr).tab_map[i] != '1' || \
				(*ptr).tab_map[i][ft_strlen((*ptr).tab_map[i]) - 1] != '1')
		{
			ft_free_struct_tab((*ptr).tab_map);
			free(ptr);
			ptr = NULL;
			ft_error_and_exit("Error\nborder must be only walls\n");
		}
		j = 0;
		while ((*ptr).tab_map[i][j])
		{
			if ((i == 0) || (i == (ft_get_size_of_tabmap((*ptr).tab_map) - 1)))
			{
				if (((*ptr).tab_map[i][j]) != '1')
				{
					ft_free_struct_tab((*ptr).tab_map);
					free(ptr);
					ptr = NULL;
					ft_error_and_exit("Error\nborder must be only walls\n");
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_map_validity(t_utils *ptr)
{
	int	i;

	i = 0;
	ft_isrectangle((*ptr).tab_map, ptr);
	while ((*ptr).tab_map[i])
	{
		ft_get_items_number((*ptr).tab_map[i], ptr);
		i++;
	}
	ft_check_number_of_items(ptr);
	ft_check_map_border(ptr);
	return (1);
}
