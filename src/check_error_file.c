/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:10:32 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/10 23:10:36 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	ft_check_invalid_format(char **argv, t_utils *ptr)
{
	char	*format;
	int		c;

	c = '.';
	format = ft_strrchr(argv[1], c);
	if (format == NULL || ft_strcmp(".ber", format))
	{
		ft_error("Error\nmap format is invalid, usage : file map.ber\n");
		free(ptr);
		ptr = NULL;
		exit(0);
	}
	return (0);
}

int	ft_check_error_file(char **argv, t_utils *ptr)
{
	int		fd;

	ft_check_invalid_format(argv, ptr);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_error("Error\nNo such file or directory\n");
		free(ptr);
		ptr = NULL;
		exit (0);
	}
	return (fd);
}
