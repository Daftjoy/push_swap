/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agianico <agianico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:27:02 by agianico          #+#    #+#             */
/*   Updated: 2021/03/18 12:27:16 by agianico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned int	ft_wcount(char const *s, char c)
{
	unsigned int n;
	unsigned int w;

	n = 0;
	w = 0;
	while (*(s + n))
	{
		if (*(s + n) == c)
		{
			n++;
			continue ;
		}
		w++;
		while ((*(s + n) != c) && *(s + n))
			n++;
	}
	return (w);
}

static unsigned int	ft_lcount(char const *s, char c, unsigned int n)
{
	unsigned int k;

	k = 0;
	while (*(s + n) != c && *(s + n))
	{
		k++;
		n++;
	}
	return (k);
}

static unsigned int	ft_loop(char const *s, char c, char **str)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	n;

	i = 0;
	n = 0;
	while (i < (ft_wcount(s, c)))
	{
		while (s[n] == c)
			n++;
		if (!(str[i] = (char *)malloc((ft_lcount(s, c, n) + 1) * sizeof(char))))
			return (0);
		j = 0;
		while (j < ft_lcount(s, c, n))
		{
			str[i][j] = s[n + j];
			j++;
		}
		str[i][j] = '\0';
		i++;
		n += j;
	}
	return (i);
}

char				**ft_split(char const *s, char c)
{
	char			**str;
	unsigned int	i;

	if (!s)
		return (0);
	if (!(str = (char **)malloc((ft_wcount(s, c) + 1) * sizeof(char *))))
		return (0);
	str[ft_wcount(s, c)] = NULL;
	i = ft_loop(s, c, str);
	return (str);
}
