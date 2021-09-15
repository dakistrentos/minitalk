#include "minitalk.h"

static char	*g_str_pointer = NULL;

void	usage_print(void)
{
	write(1, "usage: ./client [valid server's pid] [text message]\n", 52);
	exit(0);
}

void	invalid_server(void)
{
	write(1, "Invalid Server's pid!\n", 22);
	exit(0);
}

void	send_bin_str(int pid, char *str_pointer, int memory_slot)
{	
	int	bin;

	bin = 0;
	bin = (*str_pointer >> memory_slot) & 1;
	if (bin == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}

static void	main_handler(int bin, siginfo_t *info, void *context)
{
	static int	memory_slot;
	size_t		len;

	usleep(100);
	(void)context;
	len = ft_strlen(&g_str_pointer[0]);
	if (g_str_pointer && bin == 31 && len != 0)
	{
		if (memory_slot < 7)
		{
			send_bin_str(info->si_pid, g_str_pointer, memory_slot);
			memory_slot++;
			if (memory_slot == 7)
			{
				g_str_pointer++;
				memory_slot = 0;
			}
		}
	}
	else
		exit(0);
}

int	main(int argc, char *argv[])
{	
	int					pid;
	size_t				len;
	struct sigaction	action;

	sigemptyset(&action.sa_mask);
	action.sa_sigaction = main_handler;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &action, NULL);
	if (argc == 3)
	{
		len = ft_strlen(&argv[2][0]);
		pid = ft_atoi(argv[1]);
		if (kill(pid, 0) != 0)
			invalid_server();
		g_str_pointer = &argv[2][0];
		kill(pid, SIGUSR2);
		pause();
	}
	else
		usage_print();
	while (1)
		pause();
	return (0);
}
