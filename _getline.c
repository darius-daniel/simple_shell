#include "main.h"

char *_malloc(size_t size);
char *_realloc(char *src, size_t size);

/**
 * _getline - reads an entire line of input from the user
 *
 * @lineptr: a pointer to the buffer to store the line of text
 * @n: size of the the lineptr
 * @stream: stream to get input from
 *
 * Return: On success: the number of characters read, including the
 * delimiter character, but not including the terminatin null byte.
 * On failure to read a line, this function returns -1;
*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char tmp_str[128];

	/* Check if parameters are of valid types */
	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		perror("Error: Invalid arguments.");
		return (-1);
	}

	/* Allocate memory for *lineptr if it NULL */
	if (*lineptr == NULL)
	{
		*n = sizeof(tmp_str);
		*lineptr = _malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	*lineptr[0] = '\0';

	while (fgets(tmp_str, sizeof(tmp_str), stream) != NULL)
	{
		/* Resize the buffer if necessary */
		if (*n - strlen(*lineptr) < sizeof(tmp_str))
		{
			*n *= 2;
			*lineptr = _realloc(*lineptr, *n);
			if (*lineptr == NULL)
				return (-1);
		}
		strcat(*lineptr, tmp_str);
		if ((*lineptr)[strlen(*lineptr) - 1] == '\n')
			return (strlen(*lineptr));
	}
	return (-1);
}

/**
 * _malloc - allocates memory on the heap for a char pointer
 *
 * @size: size of the allocated block
 * Return: pointer to the newly allocated block
*/
char *_malloc(size_t size)
{
	char *block = malloc(size);

	if (block == NULL)
	{
		perror("Error: Unable to allocate memory");
		exit(EXIT_FAILURE);
	}
	return (block);
}

/**
 * _realloc - reallocates memory on the heap for a pointer
 *
 * @src: the source pointer
 * @size: size of the new memory block
 * Return: pointer to the reallocated block of memory
*/
char *_realloc(char *src, size_t size)
{
	char *block = realloc(src, size);

	if (block == NULL)
	{
		perror("Unable to reallocate memory block");
		exit(EXIT_FAILURE);
	}
	return (block);
}
