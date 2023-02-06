/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:26:13 by abelayad          #+#    #+#             */
/*   Updated: 2023/02/06 16:10:15 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "libft/libft.h"
# include <signal.h>
# include <unistd.h>

# define WAIT_TIME 100

# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define WHITE "\033[1;37m"
# define COLOR_RESET "\033[0m"

typedef struct s_char_struct {
	char	c;
	int		i;
}	t_char_struct;

#endif
