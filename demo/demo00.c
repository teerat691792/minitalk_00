
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>


//int	main(int argc, char *argv[])
int	main(void)
{
	int		pid;
	int 	i;
	int		n;
	char	*str;
	int		w;

	pid = fork();
	if (pid == 0)
	{
		n = 1;
		str = "child"; 	
	}
	else
	{
		n = 6;
		str = "parent"; 	
	}
	if (pid != 0)	
		w = wait(&pid);
	i = n;
	while (i < n + 5)
	{
		printf("%s %d\n",str, i);
		fflush(stdout);
		i++;
	}
//	pid = fork();
//	printf("Hello World form pid: %d\n",pid);
/*
	if (pid == 0)
	{
		printf("hello parent\n");
	}
	else
		printf("child is coming\n");
*/
	printf("\n");
	return (0);
}
 
