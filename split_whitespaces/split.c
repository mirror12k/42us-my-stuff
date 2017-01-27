
#include <stdio.h>
#include <stdlib.h>

int is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char *strdup_p(char *start, char *end)
{
	char *res;
	char *iter;

	res = malloc(end - start + 1);
	iter = res;
	while (start < end)
		*iter++ = *start++;
	*iter = '\0';
	return (res);
}

char *forward_to_whitespace(char *str)
{
	while (*str != '\0' && !is_whitespace(*str))
		str++;
	return (str);
}

char *forward_to_non_whitespace(char *str)
{
	while (*str != '\0' && is_whitespace(*str))
		str++;
	return (str);
}

char **ft_split_whitespaces(char *str)
{
	char **res;
	int	i;
	char *iter;

	i = 0;
	iter = forward_to_non_whitespace(str);
	while (*iter != '\0')
	{
		iter = forward_to_whitespace(iter);
		iter = forward_to_non_whitespace(iter);
		i++;
	}
	res = malloc(sizeof(char*) * i + 1);
	i = 0;
	iter = forward_to_non_whitespace(str);
	while (*iter != '\0')
	{
		res[i++] = strdup_p(iter, forward_to_whitespace(iter));
		iter = forward_to_whitespace(iter);
		iter = forward_to_non_whitespace(iter);
	}
	res[i] = NULL;
	return (res);
}

int main(int argc, char **argv)
{
	char **res = ft_split_whitespaces(argv[1]);
	for (; *res != 0; res++)
		printf("%s\n", *res);
}
