/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 15:55:43 by soyster           #+#    #+#             */
/*   Updated: 2019/04/28 17:30:49 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*new;
	t_list	*tmp;

	if (!alst || !(*alst) || !del)
		return ;
	new = *alst;
	while (new)
	{
		tmp = new;
		del(new->content, new->content_size);
		free(new);
		new = tmp->next;
	}
	*alst = NULL;
}
