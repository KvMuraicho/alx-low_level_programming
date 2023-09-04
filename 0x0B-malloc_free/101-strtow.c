#include "main.h"
#include <stdlib.h>

/**
 * word_count - Count the number of words in a string.
 * @str: string.
 * Return: number of words.
 */
int word_count(char *str)
{
	int i = 0, count = 0, isWord = 0;

	while (str[i])
	{
		if (str[i] != ' ' && !isWord)
		{
			isWord = 1;
			count++;
		}
		else if (str[i] == ' ')
		{
			isWord = 0;
		}
		i++;
	}
	return (count);
}

/**
 * strtow - Splits a string into words.
 * @str: the string to split.
 * Return: a pointer to an array of strings (words).
 */
char **strtow(char *str)
{
	int i = 0, j, k, l, words = word_count(str);
	char **result;

	if (!str || !*str || words == 0)
		return (NULL);

	result = (char **)malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);

	for (j = 0; j < words; j++)
	{
		while (str[i] == ' ' && str[i])
			i++;
		k = i;
		while (str[k] != ' ' && str[k])
			k++;
		result[j] = (char *)malloc((k - i + 1) * sizeof(char));
		if (!result[j])
		{
			while (j)
				free(result[--j]);
			free(result);
			return (NULL);
		}
		for (l = 0; i < k; i++, l++)
			result[j][l] = str[i];
		result[j][l] = '\0';
	}
	result[words] = NULL;
	return (result);
}

