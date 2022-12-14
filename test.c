#include "main.h"

/*ssize_t
_getline(char **restrict lineptr, size_t *restrict n, FILE *restrict stream)
{
	char buf[128];

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		perror("Error: Invalid arguments");
		return (-1);
	}

	if (*lineptr == NULL)
	{
		*n = sizeof(buf);
		if ((*lineptr = malloc(*n)) == NULL)
		{
			perror("Unable to allocate memory for line buffer.");
			return (-1);
		}
	}
	*lineptr[0] = '\0';

	while (fgets(buf, sizeof(buf), stream) != NULL)
	{
		if (*n - strlen(*lineptr) < sizeof(buf))
		{
			*n *= 2;
			if ((*lineptr = realloc(*lineptr, *n)) == NULL)
			{
				perror("Error: Unable to reallocate buffer memory");
				free(*lineptr);
				return (-1);
			}
		}
		strcat(*lineptr, buf);
		if (*lineptr[strlen(*lineptr) - 1] == '\n');
			return (strlen(*lineptr));
	}
	return (-1);
} */

int main(void)
{
	char *str;
	size_t len;

	while (true)
	{
		printf("$ ");
		len = _getline(&str, &len, stdin);
		if (strcmp(str, "exit\n") == 0)
			break;
		printf("%s", str);
	}

	free(str);
	return (0);
}
