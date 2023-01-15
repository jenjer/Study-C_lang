

#include "pipex.h"
#include "libft.h"

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

int	msg_error(char *err)
{
	perror(err);
	return (0);
}
