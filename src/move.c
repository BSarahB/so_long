/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:12:55 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/10 19:12:59 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	ft_set_abandonned_square_to_0(t_utils *ptr, int key)
{
	int	i;
	int	j;

	i = (*ptr).avatar_pos_y;
	j = (*ptr).avatar_pos_x;
	if (key == D || key == RIGHT)
		(*ptr).tab_map[i][j - 1] = '0';
	else if (key == A || key == LEFT)
		(*ptr).tab_map[i][j + 1] = '0';
	else if (key == W || key == UP)
		(*ptr).tab_map[i + 1][j] = '0';
	else if (key == S || key == DOWN)
		ptr->tab_map[i - 1][j] = '0';
}

void	ft_move_on(t_utils *ptr, int key)
{
	int	i;
	int	j;

	i = (*ptr).avatar_pos_y;
	j = (*ptr).avatar_pos_x;
	if ((*ptr).tab_map[i][j] == 'C')
		ptr->nb_of_collectibles -= 1;
	(*ptr).tab_map[i][j] = 'P';
	ft_set_abandonned_square_to_0(ptr, key);
	(*ptr).move_count++;
	ft_push_assets_to_window(ptr, (*ptr).tab_map);
}

void	ft_push_back(t_utils *ptr, int key)
{
	if (ptr->tab_map[(*ptr).avatar_pos_y][(*ptr).avatar_pos_x] == 'E')
		printf("grab all collectibles before you try to exit!\n");
	if (key == D || key == RIGHT)
		ptr->avatar_pos_x -= 1;
	else if (key == A || key == LEFT)
		ptr->avatar_pos_x += 1;
	else if (key == W || key == UP)
		ptr->avatar_pos_y += 1;
	else if (key == S || key == DOWN)
		ptr->avatar_pos_y -= 1;
}

void	ft_take_exit(t_utils *ptr, int key)
{
	ft_set_abandonned_square_to_0(ptr, key);
	(*ptr).move_count++;
	(*ptr).finish = 1;
}

void	ft_move(t_utils *ptr, int key)
{
	ft_destroy_and_update_image(ptr, key);
	if (ptr->tab_map[ptr->avatar_pos_y][ptr->avatar_pos_x] == 'E'
			&& (*ptr).nb_of_collectibles == 0)
		ft_take_exit(ptr, key);
	else if (ptr->tab_map[ptr->avatar_pos_y][ptr->avatar_pos_x] == '1'
			|| ptr->tab_map[(*ptr).avatar_pos_y][(*ptr).avatar_pos_x] == 'E')
		ft_push_back(ptr, key);
	else
		ft_move_on(ptr, key);
}
