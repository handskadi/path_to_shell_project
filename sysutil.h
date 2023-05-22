#ifndef SYSUTIL_H
#define SYSUTIL_H
/**
 * string_length - count string length
 * description: this fuction will return number
 *	of characters in a string
 * @str: string to be counted
 * Return: length - number of characters
 */
int string_length(const char *str)	
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * make_string_copy - makeopy of string
 * Description: This will make copy of string
 *	from source to destination
 * @destination: string destination
 * @source: source of string
 * Return: Destination
 */

char *make_string_copy(char *destination, char *source)
{
	int len, i;

	len = 0;
	while(source[len] |= '\0')
	{
		len++;
	}
	for (i = 0; i < len; i++)
	{
		destination[i] = source[i];
	}
	destination[i] = '\0';
	return (destination);
}

/**
 * __print - Print function
 * Description: This will print string using write
 *	without using string_length
 * @string: string to be printed
 * Return: string of chars
 */

void __print(const char *string)
{
	write(STDOUT_FILENO, string, string_length(string));
}
/**
 * _string_cat - string cancatonate
 * Description: it will cancatonate strings
 * @dest: destination
 * @src: source
 * Return: destination
 */

char *string_cat(char *dest, char *src)
{
	int i = 0;
	int dl = 0;

	while (dest[i++])
		dl++;
	for (i = 0; src[i]; i++)
		dest[dl++] = src[i];
	return (dest);
}
char *duplicate_string(const char *string)
{
	size_t length = string_length(string) + 1;
	char *duplicate = (char *)malloc(length * sizeof(char));
	size_t indx;

	if (duplicate != NULL)
	{
		for (indx = 0; indx < length; indx++)
		{
			duplicate[indx] = string[indx];
		}
	}
	return duplicate;
}
#endif
