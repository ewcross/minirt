/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:14:09 by ecross            #+#    #+#             */
/*   Updated: 2020/05/22 13:26:53 by ecross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_parse_func_arr(int (*func_arr[])(char *, t_scene_struct *))
{
	func_arr[0] = r_func;
	func_arr[1] = a_func;
	func_arr[2] = c_func;
	func_arr[3] = l_func;
	func_arr[4] = s_func;
	func_arr[5] = p_func;
	func_arr[6] = t_func;
}

void	fill_buff_str(char *src, char *dst, int len)
{
	int	i;

	i = 0;
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = src[i];
}

void	init_error_messages(char err_msgs[][ERR_BUFF_SIZE])
{
	fill_buff_str(BAD_IDENTIFIER, err_msgs[0], ERR_BUFF_SIZE);
	fill_buff_str(WRONG_ARG_NO, err_msgs[1], ERR_BUFF_SIZE);
	fill_buff_str(POS_ERROR, err_msgs[2], ERR_BUFF_SIZE);
	fill_buff_str(NORMAL_ERROR, err_msgs[3], ERR_BUFF_SIZE);
	fill_buff_str(DIMENSION_ERROR, err_msgs[4], ERR_BUFF_SIZE);
	fill_buff_str(COLOUR_ERROR, err_msgs[5], ERR_BUFF_SIZE);
	fill_buff_str(LINKED_LIST_ERROR, err_msgs[6], ERR_BUFF_SIZE);
	fill_buff_str(MULTIPLE_R_A, err_msgs[7], ERR_BUFF_SIZE);
}

int		parse_line(char *line, t_scene_struct *s)
{
	int		i;
	int		pos;
	int		(*func_arr[7])(char *, t_scene_struct *);

	init_parse_func_arr(func_arr);
	i = 0;
	if (line[i] == '#')
		return (0);
	while (line[i] == ' ')
		i++;
	if (!line[i])
		return (0);
	if ((pos = pos_in_set(line[i], CHARSET)) > -1)
		return (func_arr[pos](line, s));
	else
		return (-1);
}

int		process_line(t_scene_struct *s, char *line)
{
	int		err_code;
	char	err_msgs[8][ERR_BUFF_SIZE];

	init_error_messages(err_msgs);
	if ((err_code = parse_line(line, s)))
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd(err_msgs[(err_code * -1) - 1], 1);
		ft_putstr_fd("\nCheck line: ", 1);
		ft_putstr_fd(line, 1);
		ft_putstr_fd("\n", 1);
		return (0);
	}
	return (1);
}

int		parser(t_scene_struct *s, char *file)
{
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		ft_putstr_fd("Error opening file.\n", 1);
		return (0);
	}
	while (get_next_line(fd, &line))
	{
		if (!process_line(s, line))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	if (!process_line(s, line))
	{
		free(line);
		return (0);
	}
	free(line);
	return (1);
}
