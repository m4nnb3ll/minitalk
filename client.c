/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:03:57 by abelayad          #+#    #+#             */
/*   Updated: 2023/02/06 16:09:46 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_char_sender(char c, int pid)
{
	size_t	i;

	i = 8;
	while (i--)
	{
		if (c >> i & 1)
		{
			kill(pid, SIGUSR2);
			usleep(WAIT_TIME);
		}
		else
		{
			kill(pid, SIGUSR1);
			usleep(WAIT_TIME);
		}
	}
}

void	ft_sender(char *str, int pid)
{
	size_t	i;

	i = 0;
	while (str[i])
		ft_char_sender(str[i++], pid);
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR1);
		usleep(WAIT_TIME);
	}
}

int	ft_valid_pid(char *pidstr)
{
	size_t	i;
	pid_t	pid;

	i = 0;
	while (pidstr[i])
		if (!ft_isdigit(pidstr[i++]))
			return (0);
	pid = ft_atoi(pidstr);
	if (pid < 2 || kill(pid, 0) == -1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	if (!ft_valid_pid(argv[1]))
		return (1);
	ft_sender(argv[2], ft_atoi(argv[1]));
	return (0);
}

/*"Test `~(*123!@#$%^&*(_+-=][}{';:.></|\\?)"*/
