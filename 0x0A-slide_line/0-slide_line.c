#include "slide_line.h"

/**
 * slider_man - middle man that does all the hard work
 *
 * @line: Pointer to an array of int
 * @size: Size of the array
 * @direction: Direction of macro - left or right
 *
 * Return: 1 on success
 */

int slider_man(int *line, size_t size, int direction)
{
	int number1 = 0, number2 = 0;
	size_t counter = size - 1, i = size - 1;
	int aswitch = 0;

	if (direction == 2)
		i = counter = 0, aswitch = 1;

	while (i < size)
	{
		if (line[i] != 0 && number1 == 0)
			number1 = line[i];
		else if (line[i] != 0 && number1 != 0)
			number2 = line[i];
		if (number1 != 0 && number2 != 0)
		{
			if (number1 == number2)
			{
				line[aswitch == 1 ? counter++ : counter--] = number1 + number2;
				number1 = number2 = 0;
			}
			else
			{
				line[aswitch == 1 ? counter++ : counter--] = number1;
				number1 = number2, number2 = 0;
				if (i == (aswitch == 1 ? size - 1 : 0))
					line[aswitch == 1 ? counter++ : counter--] = number1;
			}
		}
		else if (number1 != number2 && i == (aswitch == 1 ? size - 1 : 0))
			line[aswitch == 1 ? counter++ : counter--] = number1;
		aswitch == 1 ? i++ : i--;
	}
	if (aswitch == 1)
		for (i = counter; i < size; i++)
			line[i] = 0;
	else
		for (i = 0; i < counter + 1; i++)
			line[i] = 0;
	return (1);
}

/**
 * slide_line - slides & merges an array of int
 *
 * @line: Pointer to an array of int
 * @size: Size of the array
 * @direction: Direction of macro - left or right
 *
 * Return: 1 on success or 0 on failure
 */

int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (direction == SLIDE_RIGHT)
		return (slider_man(line, size, SLIDE_RIGHT));
	return (slider_man(line, size, SLIDE_LEFT));
}
