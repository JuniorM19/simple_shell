#include "shell.h"

/**
* interactive - Checks whether the shell is in the interactive mode.
* @info: Is the pointer to the info_t structure.
* Return: 1 if shell is in the interactive mode, if not return 0.
*/
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && (info->readfd <= 2));
}

/**
* is_delim - Checks whether a character is a delimiter.
* @c: The character to be checked.
* @delim: the delimiter string.
* Return: On success 1 if the character is a delimiter, otherwise return 0.
*/
int is_delim(char c, char *delim)
{
	while (*delim)
	{
	if (*delim == c)
	return (1);
	delim++;
	}
	return (0);
}

/**
* is_alpha - Checks whether a character is an alphabetic character.
* @c: The character to be checked.
* Return: On success 1 if character is an alphabetic character, otherwise 0.
*/
int is_alpha(int c)
{
return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
* convert_to_int - converts a string into an integer.
* @s: The string to be converted.
* Return: The converted integer value, return 0.
* if there are no numbers in the integer string.
*/
int convert_to_int(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
	if (s[i] == '-')
	sign *= -1;

	if (s[i] >= '0' && s[i] <= '9')
	{
	flag = 1;
	result *= 10;
	result += (s[i] - '0');
	}
	else if (flag == 1)
	flag = 2;
	}
	output = (sign == -1) ? -result : result;
	return (output);
}
