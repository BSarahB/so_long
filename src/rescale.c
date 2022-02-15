/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rescale.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 01:12:37 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/15 01:12:46 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

float	ft_minimum(float x, float y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

void	ft_rescale(t_utils *ptr)
{
	float	ratio_x;
	float	ratio_y;
	float	smallest_ratio;
	char	*xpm_size_string;

	mlx_get_screen_size((*ptr).mlx, &ptr->screen_x, &ptr->screen_y);
	ratio_x = (float)((*ptr).screen_x - SCREEN_OFFSET_X) / (*ptr).x;
	ratio_y = (float)((*ptr).screen_y - SCREEN_OFFSET_Y) / (*ptr).y;
	smallest_ratio = ft_minimum(ratio_x, ratio_y);
	if (smallest_ratio < 1)
	{
		(*ptr).xpm_size = (int)(smallest_ratio * DEFAULT_XPM_SIZE);
		if ((*ptr).xpm_size < MIN_XPM_SIZE)
		{
			(*ptr).xpm_size = MIN_XPM_SIZE;
		}
		(*ptr).y = ft_get_size_of_tabmap((*ptr).tab_map) * (*ptr).xpm_size;
		(*ptr).x = ft_strlen((*ptr).tab_map[0]) * (*ptr).xpm_size;
	}
	xpm_size_string = ft_itoa((*ptr).xpm_size);
	(*ptr).xpm_path = ft_strjoin2("assets/images/xpm/", xpm_size_string);
	free(xpm_size_string);
}
