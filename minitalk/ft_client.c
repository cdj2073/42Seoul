// 42 header
#include "minitalk.h"

void	ft_print_pid(int pid, int flag)
{
	write(1, "Client PID: ", 12);
	ft_putnbr(pid);
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "<usage> ./client [PID] [message]\n", 33);
		return (0);
	}

	ft_print_pid(getpid(), 1);

	return (0);
}
