#include "main.h"

/**
  * _strtok- This is our custom implementation of the built in strtok()
  * function
  *
  * @BUFFER_STR: A pointer to the input string from stdin.
  * @delims: A pointer to the array of delimiters.
  *
  * Return: a pointer to the token identified.
  */
char *_strtok(char *BUFFER_STR, const char *delims)
{
	char *start;
	/*
	 * we initialise a static variable to store the current position in the
	 * string being tokenised, so subsequent calls to the function can
	 * continue tokenising the same string
	*/
	char *tmp_str = NULL;

	if (BUFFER_STR != NULL)
		tmp_str = BUFFER_STR;
	else if (tmp_str == NULL)
		return (NULL);

	/* store the current position in the string being tokenised */
	start = tmp_str;

	/*
	 * we use the strpbrk() to find the first occurence of any of
	 * the delimiters in str
	*/
	tmp_str = strpbrk(start, delims);

	if (tmp_str != NULL)
	{
		*tmp_str = '\0';
		tmp_str++;
	}

	return (start);
}
