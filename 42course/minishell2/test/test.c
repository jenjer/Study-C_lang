#include <stdio.h>
#include <stdlib.h>

char ***myfunc(char ***t)
{
	int	i =0;
	char **ret;

	ret = *t;
	i = 0;
	while (ret[i])
	{
		printf("%s\n",ret[i]);
		i++;
	}
	return 0;
}

int main(int argc, char *argv[], char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		printf("%s\n",envp[i]);
		i++;
	}
	printf("end_first\n\n");
	char ***t = myfunc(&envp);

}
