/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/13 17:05:16 by Vtrentos      #+#    #+#                 */
/*   Updated: 2020/12/13 17:11:37 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*lst2;

	lst2 = lst;
	i = 0;
	if (!lst)
		return (0);
	while (lst2->next != NULL)
	{
		i++;
		lst2 = lst2->next;
	}
	i++;
	return (i);
}
