/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:39:04 by mhorn             #+#    #+#             */
/*   Updated: 2016/11/30 16:11:58 by mhorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** ft_strsplit2 doesn't trim off the separating characters
** word_count returns the number of splitting chars
** next_word separates strings by the split char and can have strings with
** just the split char as the value
*/

static int	word_count(char const *s, char c)
{
	int	i;
	int count;
	
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c || s[i + 1] == '\0')
			count++;
		i++;
	}
	return (count);
}

/*
** j is the start position of the sub-string
** i - j + 1 is the end position of the sub-string, it includes the split char
*/

static char	*next_word(int *i, char const *s, char c)
{
	int		j;
	
	if (!s)
		return (NULL);
	j = (*i != 0) ? ++*i : *i;
	while (s[*i] != c && s[*i] != '\0')
		++*i;
	return (ft_strsub(s, (unsigned int)j, (size_t)(*i - j + 1)));
}

char		**ft_strsplit2(char const *s, char c)
{
	char	**arr;
	int		*i;
	int		j;
	int		word_ct;
	
	if (!s)
		return (NULL);
	i = malloc(sizeof(int) * 1);
	word_ct = word_count(s, c);
	if (!i)
		return (NULL);
	*i = 0;
	j = 0;
	arr = (char **)malloc(sizeof(char *) * (word_ct + 1));
	if (arr != NULL)
	{
		while (s[*i] != '\0' && j < word_ct)
		{
			arr[j] = next_word(i, s, c);
			j++;
		}
		arr[j] = NULL;
	}
	return (arr);
}
