// 42 header
#include "minitalk.h"

void	ft_print_pid(int pid)
{
	write(1, "Client PID: ", 12);
	ft_putnbr(pid);
	write(1, "\n", 1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	long long	num;

	i = 0;
	num = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] >= 9 && str[i] <= 13)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = 10 * num + (str[i++] - '0');
		if ((minus * num) > 0 && minus < 0)
			return (0);
		if ((minus * num) < 0 && minus > 0)
			return (-1);
	}
	return (minus * num);
}

int	ft_send_byte(int pid, char c)
{
	int	mask;
	int	result;

	mask = 1 << 6;
	while (mask > 0)
	{
		if ((c & mask) == 0) // 0
		{
			result = kill(pid, SIGUSR1);
//			write(1, "send 0\n", 7);
		}
		else
		{
			result = kill(pid, SIGUSR2);
//			write(1, "send 1\n", 7);
		}
		mask = mask >> 1;
		if (result == -1)
			return (-1);
		usleep(100);
	}
	return (0);
}

void	ft_send_message(int pid, char *msg)
{
	int	i;
	int	result;

	i = 0;
	while (msg[i])
	{
		result = ft_send_byte(pid, msg[i++]);
		if (result == -1)
		{
			write(1, "ERROR - Please check server PID.\n", 33);
			return ;
		}
	}
}

int main(int argc, char **argv)
{
	int	server_pid;

	if (argc != 3)
	{
		write(1, "<usage> ./client [PID] [message]\n", 33);
		return (0);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
		write(1, "Please enter server PID correctly.\n", 35);
	ft_print_pid(getpid());
	ft_send_message(server_pid, argv[2]);
	return (0);
}
