/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/13 17:16:23 by Vtrentos      #+#    #+#                 */
/*   Updated: 2021/09/01 20:05:24 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst2;

	if ((lst && *lst) && new)
	{
		lst2 = ft_lstlast(*lst);
		lst2->next = new;
	}
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
}
