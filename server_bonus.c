/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:50:29 by abelayad          #+#    #+#             */
/*   Updated: 2023/02/06 16:14:42 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

pid_t	g_pid;

void	free_char(void *c)
{
	free(c);
}

int	ft_chain_up(t_list **strptr, char c)
{
	char	*mc;
	t_list	*new_node;

	mc = malloc(sizeof(char));
	if (!mc)
		return (0);
	*mc = c;
	new_node = ft_lstnew(mc);
	if (!new_node)
		return (free(mc), 0);
	ft_lstadd_back(strptr, new_node);
	return (1);
}

void	ft_char_handler(char c, t_list **strptr)
{
	t_list	*head;

	if (c)
	{
		if (!ft_chain_up(strptr, c))
			ft_lstclear(strptr, free_char);
	}
	else
	{
		kill(g_pid, SIGUSR2);
		head = *strptr;
		while (*strptr && *(char *)(*strptr)->content)
		{
			ft_putchar_fd(*(char *)(*strptr)->content, 1);
			(*strptr) = (*strptr)->next;
		}
		ft_lstclear(&head, free_char);
	}
}

void	ft_handler(int sig, siginfo_t *info, void *ucontext)
{
	static t_char_struct	cs;
	static t_list			*str = NULL;

	(void)ucontext;
	if (info->si_pid != g_pid)
	{
		g_pid = info->si_pid;
		if (str)
		{
			ft_lstclear(&str, free_char);
			cs = (t_char_struct){0, 0};
		}
	}
	if (sig == SIGUSR1 && ++cs.i)
		cs.c = cs.c << 1 | 0;
	else if (sig == SIGUSR2 && ++cs.i)
		cs.c = cs.c << 1 | 1;
	if (cs.i == 8)
	{
		ft_char_handler(cs.c, &str);
		cs = (t_char_struct){0, 0};
	}
}

int	main(void)
{
	struct sigaction	sa;

	g_pid = getpid();
	ft_memset(&sa, 0, sizeof(struct sigaction));
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr_fd(YELLOW, 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putendl_fd(COLOR_RESET, 1);
	while (1)
		pause();
}
