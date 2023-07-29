#include "shell.h"

/**
* _eputs - prints a string to the stderr.
* @str: the string to be printed.
* Return: 0.
*/
void _eputs(char *str)
{
	int i = 0;

	if (!str)
	return;
	while (str[i] != '\0')
	{
	_eputchar(str[i]);
	i++;
	}
}

/**
* _eputchar - writes a character to the stderr.
* @c: the character to print.
* Return: On success, 1.
* On error, return -1, and errno is set appropriately.
*/
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
	write(2, buf, i);
	i = 0;
	}
	if (c != BUF_FLUSH)
	buf[i++] = c;
	return (1);
}

/**
* _putfd - writes a character to the given file descriptor.
* @c: the character to print.
* @fd: the filedescriptor to write to.
* Return: On success 1.
* On error, return -1, and errno is set appropriately.
*/
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
	write(fd, buf, i);
	i = 0;
	}
	if (c != BUF_FLUSH)
	buf[i++] = c;
	return (1);
}

/**
* _putsfd - prints a string to the given file descriptor.
* @str: string to be printed.
* @fd: filedescriptor to write to.
* Return: number of characters written.
*/
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
	return (0);
	while (*str)
	{
	i += _putfd(*str++, fd);
	}
	return (i);
}
