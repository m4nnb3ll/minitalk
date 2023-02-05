/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:03:57 by abelayad          #+#    #+#             */
/*   Updated: 2023/02/05 21:26:11 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
			usleep(100);
		}
		else
		{
			kill(pid, SIGUSR1);
			usleep(100);
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
		usleep(100);
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
	if (pid < 4 || kill(pid, 0) == -1)
		return (0);
	return (1);
}

void	ft_handler(int signo)
{
	if (signo == SIGUSR2)
	{
		ft_putstr_fd(WHITE, 1);
		ft_putstr_fd("Message from the server: ", 1);
		ft_putstr_fd(GREEN, 1);
		ft_putstr_fd("The string got fully received!\n", 1);
		ft_putstr_fd(COLOR_RESET, 1);
	}
	exit(0);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	if (!ft_valid_pid(argv[1]))
		return (1);
	signal(SIGUSR2, ft_handler);
	ft_sender(argv[2], ft_atoi(argv[1]));
	while (1)
		pause();
}

/*"Test `~(*123!@#$%^&*(_+-=][}{';:.></|\\?)"*/