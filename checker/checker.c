/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:20:28 by antmarti          #+#    #+#             */
/*   Updated: 2021/03/25 15:26:35 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	joiner(t_check *check, char *line)
{
	char	*join;

	join = ft_strjoin(check->vals, "\n");
	free (check->vals);
	check->vals = join;
	join = ft_strjoin(check->vals, line);
	free (check->vals);
	check->vals = join;
	return ;
}

void	checker(t_check *check)
{
	char	*line;
	int		i;

	i = 0;
	line = 0;
	check->vals = 0;
	while (get_next_line(0, &line))
	{
		if (!check_opts(line))
			exit(printf("Error\n"));
		if (!check->vals)
			check->vals = ft_strdup(line);
		else
			joiner(check, line);
		i++;
	}
	if (!i)
		return ;
	joiner(check, line);
	check->opts = ft_split(check->vals, '\n');
	exec(check);
}

void	stack_creater(t_check *check, int i, char **argv)
{
	int	j;
	int	k;

	j = 1;
	check->nums = malloc(sizeof(int *) * 2);
	check->nums[0] = malloc(sizeof(int) * i - 1);
	check->nums[1] = malloc(sizeof(int) * i - 1);
	check->tot_elem = i - 1;
	check->a_elem = i - 1;
	check->b_elem = 0;
	while (argv[j])
	{
		check->nums[0][j - 1] = ft_atoi(argv[j]);
		k = 1;
		while (j - (++k) >= 0)
		{
			if (check->nums[0][j - 1] == check->nums[0][j - k])
			{
				ft_free_int(check->nums);
				free(check);
				exit(printf("Error\n"));
			}
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	t_check	*check;

	check = malloc(sizeof(t_check *));
	i = 1;
	if (argc < 2)
		return (0);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!((argv[i][j] <= '9' && argv[i][j] >= '0')
					|| (argv[i][j] == '-' && j == 0)))
				return (printf("Error\n"));
			j++;
		}
		i++;
	}
	stack_creater(check, i, argv);
	checker(check);
	compare(check);
	free(check);
	return (0);
}