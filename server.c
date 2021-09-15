#include "minitalk.h"

char	print_bin_str(int bin, int pid)
{
	static int	counter;
	static char	c;
	static int	l_pid;

	if (l_pid != pid && l_pid != 0)
	{	
		c = 0;
		counter = 0;
	}
	l_pid = pid;
	c += (bin & 1) << counter;
	counter++;
	if (counter == 7)
	{
		write(1, &c, 1);
		counter = 0;
		c = 0;
		l_pid = pid;
	}
	kill(pid, SIGUSR2);
	return ('0');
}

static void	main_handler(int bin, siginfo_t *info, void *context)
{
	static char	status = '1';
	static int	pid;

	(void)context;
	if (pid != info->si_pid)
		status = '1';
	usleep(100);
	if (status != '1')
	{	
		status = print_bin_str(bin, info->si_pid);
	}
	else
	{
		status = '0';
		kill(info->si_pid, SIGUSR2);
	}
	pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	action;

	ft_putstr_fd("PID is: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigemptyset(&action.sa_mask);
	action.sa_sigaction = main_handler;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
