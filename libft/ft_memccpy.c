/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 12:14:11 by Vtrentos      #+#    #+#                 */
/*   Updated: 2021/09/01 20:02:23 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	while (n > 0)
	{
		if (*s2 == (unsigned char)c)
		{
			*s1 = *s2;
			s1++;
			return (s1);
		}
		*s1 = *s2;
		s1++;
		s2++;
		n--;
	}
	return (NULL);
}
