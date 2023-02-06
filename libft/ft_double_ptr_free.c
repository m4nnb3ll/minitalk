/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_ptr_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:49:41 by abelayad          #+#    #+#             */
/*   Updated: 2023/02/01 22:53:39 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_double_ptr_free(void **tofree)
{
	size_t	i;

	i = 0;
	while (tofree[i])
		free(tofree[i++]);
	free(tofree);
}
