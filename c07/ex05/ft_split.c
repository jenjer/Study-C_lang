/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <youngski@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:45:02 by youngski          #+#    #+#             */
/*   Updated: 2022/09/07 13:45:29 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
char	**ft_split(char *str, char *charset);
int		count(char *str, char *charset);
int		check(char *str, char c);
char	*pick_word(char *str, char *charset, int *i);

char	*pick_word(char *str, char *charset, int *i)
{
	char *ret;
	int k;
	
	k = *i;
	while (!check(charset, str[k]))
	{
		k++;
	}
	ret = malloc(sizeof(char) * (k - *i) + 1);
	k = *i;
	while (!check(charset, str[k]))
	{
		ret[k] = str[k];
		k++;
		*i++;
	}
		
}

int		check(char *str, char c)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return 1;
		i++;
	}
	return 0;
}

int	count(char *str, char *charset)
{
	int	i;
	int	count;
	
	i = 0;
	count =0;
	while (str[i])
	{
		while (str[i] != '\0' && check(str, str[i]))
			i++;	
		if (check(charset, str[i]))
			count++;
		while (str[i] != '\0' && !check(str, str[i]))
			i++;
	}
	return count;
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		i;
	int		k;
	
	i = 0;
	k = 0;
	ret = (char **)malloc(sizeof(char*)*count(str, charset) + 1);
	while (str[i])
	{
		while(str[i] != '\0' || check(charset, str[i]))
			i++;
		if (str[i] != '\0' && !check(charset, str[i]))
		{
			ret[k] = pick_word(str, charset, &i);
			k++;
		}
		
	}
	ret[k] = '\0';
	return ret;
}
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
		/* ex05 */
	char** ret;
	ret = ft_split(" abc,d.abcdef^", " ,.^");
	assert(strcmp(ret[0], "abc") == 0);
	printf("asdf");
	assert(strcmp(ret[1], "d") == 0);
	assert(strcmp(ret[2], "abcdef") == 0);
	assert(ret[3] == NULL);

	ret = ft_split(" ^^^^,", " ,.^");
	assert(ret[0] == NULL);

}
