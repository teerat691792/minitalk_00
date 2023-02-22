
#include "libftminitalk.h"

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_printf("please enter input as followeding\n");
		ft_printf("./client.out [PID] [string]\n");
		return (1);
	}
	ft_printf("PID	=	%s\n",argv[1]);
	ft_printf("str	=	%s\n",argv[2]);
	return (0);
}
