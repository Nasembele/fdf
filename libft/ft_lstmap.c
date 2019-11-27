/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 17:37:24 by soyster           #+#    #+#             */
/*   Updated: 2019/05/01 17:56:55 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *ct, size_t s)
{
	s = 0;
	free(ct);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*help;

	if (lst)
	{
		if (!(res = f(lst)))
			return (0);
		help = res;
		lst = lst->next;
		while (lst)
		{
			if (!(res->next = f(lst)))
			{
				ft_lstdel(&help, del);
				return (0);
			}
			lst = lst->next;
			res = res->next;
		}
		return (help);
	}
	return (0);
}
