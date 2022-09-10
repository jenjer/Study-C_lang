
#include <stdlib.h>
#include <unistd.h>
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	ft_atoi_base(char *str, char *base);
int	start_base(char *str, int *i);
int	putnbr_base(int for_return, char *base);
int	base_check(char *base, int i, int j);
int	start_flag(char *str, int *i);


int	start_flag(char *str, int *i)
{
	int	flag;

	flag = 1;
	while (str[*i] == '\t' || str[*i] == '\n' || str[*i] == '\v' || \
str[*i] == '\f' || str[*i] == '\r' || str[*i] == ' ')
		*i = *i + 1;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			flag *= -1;
		*i = *i + 1;
	}
	return (flag);
}

int	base_check(char *base, int i, int j)
{
	if (!base || !base[0])
		return (0);
	while (base[i] == '\t' || base[i] == '\n' || base[i] == '\v' || \
base[i] == '\f' || base[i] == '\r' || base[i] == ' ')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	i = 0;
	while (base[i + 1] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0' && base[j] != base[i])
			j++;
		if (base[i] == base[j])
			return (0);
		i++;
	}
	return (1);
}

int	is_in_base(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == str)
			return (i);
		i++;
	}
	return (-1);
}

int	run_base(char *str, char *base, int i)
{
	int	k;
	int	for_return;
	int	t;
	int	j;

	t = 0;
	j = 0;
	for_return = 0;
	k = 0;
	if (base_check(base, t, j) == 0)
		return (0);
	while (base[k])
		k++;
	while (str[i] && (is_in_base(str[i], base) >= 0))
	{
		for_return = for_return * k + is_in_base(str[i], base);
		i++;
	}
	return (for_return);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	for_return;
	int	flag;

	for_return = 0;
	i = 0;
	flag = start_flag(str, &i);
	for_return = run_base(str, base, i);
	return (flag * for_return);
}

int	ft_strlen_(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	double_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i + 1] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0' && base[j] != base[i])
		{
			j++;
		}
		if (base[i] == base[j])
			return (0);
		i++;
	}
	return (1);
}

void	print_things(long long nbr, char *base)
{
	int	i;

	i = 0;
	if (nbr < 0)
		print_things(-nbr, base);
	while (base[i] != '\0')
		i++;
	if (nbr >= i)
	{
		print_things(nbr / i, base);
		print_things(nbr % i, base);
	}
	else if (nbr > -1)
	{
		write (1, &base[nbr], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	i = 0;
	if (ft_strlen_(base) < 2)
		return ;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return ;
		i++;
	}
	if (double_check(base) == 0)
		return ;
	if (nbr < 0)
	{
		write (1, "-", 1);
	}
	print_things((long long)nbr, base);
}
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char *ret;
	int	befor_ret;
	int i;
	int j;
	j = 0;
	i = 0;
	
	if (base_check(base_from,i,j) == 0 || base_check(base_to, i ,j))
		return (NULL);
	befor_ret = ft_atoi_base(nbr, base_from);
	while (base_to[i])
		ret[i] = base_to[i++];
	
	ft_putnbr_base(befor_ret, ret);
	return ret;
}
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
		char* ex04;
	ex04 = ft_convert_base("  \t---10", "0123456789", "01");
	assert(strcmp(ex04, "-1010") == 0);

	ex04 = ft_convert_base("  \t---10", "0123456789", "-01");
	assert(ex04 == NULL);
	
	ex04 = ft_convert_base(NULL, "aba", NULL);
	assert(ex04 == NULL);


}