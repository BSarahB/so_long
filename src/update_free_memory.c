/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_free_memory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:15:06 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/10 23:15:14 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	ft_free_struct_str(char **p)
{
	if (*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}

void	ft_free_struct_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

void	ft_free_struct_utils(t_utils *ptr)
{
	if (ptr != NULL)
	{
		ft_free_struct_tab((*ptr).tab_map);
		ft_free_struct_str(&(*ptr).xpm_path);
		free((*ptr).mlx);
		free(ptr);
		ptr = NULL;
	}
}

int	ft_free_and_exit(t_utils *ptr)
{
	mlx_destroy_image((*ptr).mlx, (*ptr).wall);
	mlx_destroy_image((*ptr).mlx, (*ptr).avatar);
	mlx_destroy_image((*ptr).mlx, (*ptr).collectible);
	mlx_destroy_image((*ptr).mlx, (*ptr).exit);
	mlx_destroy_image((*ptr).mlx, (*ptr).scene);
	mlx_destroy_window((*ptr).mlx, (*ptr).win);
	mlx_destroy_display((*ptr).mlx);
	mlx_loop_end((*ptr).mlx);
	ft_free_struct_utils(ptr);
	exit(0);
}

t_utils	*ft_struct_init_utils(t_utils **ptr)
{
	*ptr = (t_utils *)malloc(sizeof(t_utils));
	if (!(*ptr))
		return (0);
	(*ptr)->nb_of_players = 0;
	(*ptr)->nb_of_collectibles = 0;
	(*ptr)->nb_of_exits = 0;
	(*ptr)->move_count = 0;
	(*ptr)->finish = 0;
	(*ptr)->flag_empty_line = 0;
	(*ptr)->xpm_size = DEFAULT_XPM_SIZE;
	(*ptr)->xpm_path = NULL;
	return (*ptr);
}
