#include "shell.h"

/**
 * interactive - true if shell is in interactive mode
 * @info: struct addresse
 *
 * Return: 1 when in interactive mode, 0 when false
 */
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * delim - checks if xter is a delimeter
 * @c: the character to check
 * @delim: delimeter string
 * Return: 1 when true, 0 when false
 */
int is_delim(char c, char *delim)
{
while (*delim)
        if (*delim++ == c)
                return (1);
return (0);
}

/**
 * _isalpha - alphabetic character
 * @c: The xter
 * Return: 1 if c is alphabetic, 0 if not
 */

int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
else
        return (0);
}

/**
 * _atoi - convert string to integer
 * @s: the string converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
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

        if (sign == -1)
                output = -result;
        else
                output = result;

        return (output);
}
