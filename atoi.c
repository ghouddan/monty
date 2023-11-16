#include "monty.h"

/**
 * _atoi - string to an integer
 * @str: Char type string
 * @n: Pointer to the converted int
 * Return: Integer converted
 */
int _atoi(char *str, int *num)
{
	int sign = 1, resp = 0, firstNum, i;

	for (firstNum = 0; !(str[firstNum] >= 48 && str[firstNum] <= 57); firstNum++)
	{
		if (str[firstNum] == '-')
		{
			sign *= -1;
		}
	}
	for (i = firstNum; str[i] ; i++)
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			resp *= 10;
			resp += (str[i] - 48);
		}
		else
			return (-1);
	}

	*num = resp * sign;
	(void)(num);
	return (0);
}

