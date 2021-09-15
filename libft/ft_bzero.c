/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 12:13:43 by Vtrentos      #+#    #+#                 */
/*   Updated: 2021/09/01 20:07:21 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str1;

	str1 = s;
	while (n > 0)
	{
		*str1 = '\0';
		str1++;
		n--;
	}
}
