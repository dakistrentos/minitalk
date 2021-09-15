/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 11:19:14 by Vtrentos      #+#    #+#                 */
/*   Updated: 2021/09/01 19:59:43 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_array(char **arr, int words)
{
	if (words <= 0)
		free(arr);
	else
	{
		while (words > 0)
		{
			free(arr[words]);
			words--;
		}
	}
	free(arr);
}

static int	count_words_letters(char *str3, char c)
{
	int		i;
	int		j;
	size_t	f;
	size_t	len;

	j = 0;
	f = 0;
	len = ft_strlen(str3);
	while (f < len)
	{
		i = 0;
		while (str3[f] != c && str3[f] != '\0')
		{
			i++;
			f++;
		}
		if (i != 0)
			j++;
		if (f >= len)
			break ;
		f++;
	}
	return (j);
}

static char	*string_ptr(char *str2, char c)
{
	int		i;
	char	*str;
	char	*string;

	i = 0;
	str = str2;
	while (*str != c && *str != '\0')
	{
		i++;
		str++;
	}
	string = (char *)malloc(i + 1);
	if (!string)
		return (NULL);
	ft_strlcpy(string, str - i, i + 1);
	return (string);
}

static char	**malloc_array(int words, char c, char *str2)
{
	char	**ar;
	int		l;
	size_t	len;

	l = 0;
	ar = (char **)malloc(sizeof(char *) * (words + 1));
	if (!ar)
		return (NULL);
	while (l < words)
	{
		while (*str2 == c && *str2)
			str2++;
		ar[l] = string_ptr(str2, c);
		if (!ar[l])
		{
			free_array(ar, l - 1);
			return (NULL);
		}
		len = ft_strlen(ar[l]);
		str2 = str2 + len;
		l++;
	}
	ar[words] = NULL;
	return (ar);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**arr;

	if (!s)
		return (NULL);
	words = count_words_letters((char *)s, c);
	arr = malloc_array(words, c, (char *)s);
	if (!arr)
		return (NULL);
	return (arr);
}
