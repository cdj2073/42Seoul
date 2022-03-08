// 42header
#include "minitalk.h"

void	ft_print_pid(int pid)
{
	write(1, "Server PID: ", 12);
	ft_putnbr(pid);
	write(1, "\n", 1);
}

void	ft_message_handler(int signum, siginfo_t *siginfo, void *context)
{
	static unsigned char	c;
	static int				bit;

//	write(1, "[Client PID: ", 13);
//	ft_putnbr(siginfo->si_pid);
//	write(1, "]\n", 2);
	if (signum == SIGUSR1)	// 0
	{
//		write(1, "0", 1);
		bit++;
	}
	else if (signum == SIGUSR2)	// 1
	{
//		write(1, "1", 1);
		c |= 1 << (6 - bit);
		bit++;
	}
	if (bit == 7)
	{
		write(1, &c, 1);
		c = 0;
		bit = 0;
	}
}

/*
void	ft_init_sigaction(struct sigaction *sa)
{
	sa->sa_sigaction = ft_message_handler;
	sa->sa_flags = SA_SIGINFO;
	sigemptyset(sa->sa_mask);
}
*/

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	// sigaction 구초제 선언 및 초기화

	// server pid 출력
	// getpid()
	ft_print_pid(getpid());
//	ft_init_sigaction(&sa);
	sa.sa_sigaction = ft_message_handler;
	sa.sa_flags = SA_SIGINFO;
//	sigemptyset(&sa.sa_mask);

	// sigaction()
	// SIGUSR1 => 1
	// SIGUSR2 => 0
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
