// 42header
#include "minitalk.h"

void	ft_print_pid(int pid, int flag)
{
	write(1, "Server PID: ", 12);
	ft_putnbr(pid);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc != 1)
	{
		write(1, "<usage> ./server\n", 17);
		return (0);
	}
	// sigaction 구초제 선언 및 초기화

	// server pid 출력
	// getpid()
	ft_print_pid(getpid(), 0);

	// sigaction()
	// SIGUSR1 => 1
	// SIGUSR2 => 0

	// while (1)
	//	pause();
	return (0);
}
