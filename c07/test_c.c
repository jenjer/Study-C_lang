#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "ex00/ft_strdup.c"
#include "ex01/ft_range.c"
#include "ex02/ft_ultimate_range.c"
#include "ex03/ft_strjoin.c"
#include "ex04/ft_convert_base.c"
#include "ex04/ft_convert_base2.c"
#include "ex05/ft_split.c"

int main()
{
	/* ex00 */
	char *ex00;
	ex00 = ft_strdup("HELLO WORLD");
	assert(strcmp(ex00, "HELLO WORLD") == 0);

	ex00 = ft_strdup("");
	assert(strcmp(ex00, "") == 0);

	/* ex01 */
	int *ex01;
	ex01 = ft_range(30, 15);
	assert(ex01 == NULL);

	ex01 = ft_range(-10, -5);
	for (int i = 0; i < 5; i++)
	{
		assert(ex01[i] == -10 + i);
	}

	/* ex02 */
	int *ex02;
	int ex02_ret;
	ex02_ret = ft_ultimate_range(&ex02, -10, -5);
	assert(ex02_ret == 5);
	for (int i = 0; i < 5; i++)
	{
		assert(ex02[i] == -10 + i);
	}

	ex02_ret = ft_ultimate_range(&ex02, 10, -5);
	assert(ex02_ret == 0);
	assert(ex02 == NULL);

	/* ex03 */
	char* ex03;
	char** ex03_strs;
	ex03_strs = (char**)malloc(3 * sizeof(char*));
	ex03_strs[0] = (char*)malloc(4 * sizeof(char));
	ex03_strs[1] = (char*)malloc(4 * sizeof(char));
	ex03_strs[2] = (char*)malloc(4 * sizeof(char));
	strcpy(ex03_strs[0], "AB ");
	strcpy(ex03_strs[1], "CD^");
	strcpy(ex03_strs[2], "EF~");
	ex03 = ft_strjoin(3, ex03_strs, "WOW");
	assert(strcmp(ex03, "AB WOWCD^WOWEF~") == 0);
	
	assert(*ft_strjoin(0,NULL,NULL) == '\0');

	/* ex04 */
	char* ex04;
	ex04 = ft_convert_base("  \t---10", "0123456789", "01");
	assert(strcmp(ex04, "-1010") == 0);

	ex04 = ft_convert_base("  \t---10", "0123456789", "-01");
	assert(ex04 == NULL);
	
	ex04 = ft_convert_base(NULL, "aba", NULL);
	assert(ex04 == NULL);

	/* ex05 */
	char** ret;
	ret = ft_split(" abc,d.abcdef^", " ,.^");
	assert(strcmp(ret[0], "abc") == 0);
	assert(strcmp(ret[1], "d") == 0);
	assert(strcmp(ret[2], "abcdef") == 0);
	assert(ret[3] == NULL);

	ret = ft_split(" ^^^^,", " ,.^");
	assert(ret[0] == NULL);
}
