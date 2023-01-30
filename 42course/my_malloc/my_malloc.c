#include "my_malloc.h"
#include <stdio.h>


void delete_temp(void ***buffer, void *temp)
{
	int	i;

	i = 0;
	while (buffer[i] != temp)
			i++;
	free (temp);
	buffer[i] = 0;
}

void delete_all(void ***buffer, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		free(buffer[i]);
		buffer[i++] = 0;
	}
}

//my_malloc call del_malloc
//del malloc mave all mallcked size
void *my_malloc(int size)
{
	void	*temp;
	
	temp = malloc(size);
	del_malloc(temp, 1);
	return (temp);
}

//flag 
//-1 = delete all
//0 = delete temp
//1 = add buffer
void del_malloc(void *temp, int flag)
{
	static void	**buffer;
	int			i;
	static int	size;

	i = 0;
	if (buffer == 0)
		buffer = make_buffer(&buffer);
	if (flag == -1)
	{
		delete_all(&buffer, size);
		return ;
	}
	if (flag == 0)
		return delete_temp(&buffer, temp);
	if (flag == 1)
		buffer[size++] = temp;
}

void ** make_buffer(void ***temp)
{
	void	**buffer;
	int	i;

	i = 0;
	buffer = (void **)malloc (sizeof (void *) * 5000);
	while (buffer[i])
	{
		buffer[i] = 0;
		i++;
	}
	return buffer;
}
