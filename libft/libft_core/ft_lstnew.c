/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:12:40 by rbalazs           #+#    #+#             */
/*   Updated: 2023/12/13 11:12:46 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*liste;

	liste = (void *)malloc(sizeof(t_list));
	if (liste != NULL)
	{
		(*liste).content = content;
		(*liste).next = NULL;
	}
	return (liste);
}
