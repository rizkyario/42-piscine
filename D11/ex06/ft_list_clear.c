/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 11:41:45 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/16 11:41:45 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list **begin_list)
{
	t_list	*list_ptr;
	t_list	*temp;

	list_ptr = *begin_list;
	while (list_ptr)
	{
		temp = list_ptr;
		list_ptr = list_ptr->next;
		free(temp);
	}
	*begin_list = NULL;
}
