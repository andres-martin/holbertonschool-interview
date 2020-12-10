#include "search_algos.h"

/**
 * print_array - Print array or subarray
 * @array: array to be printed
 * @begin: beginning of array
 * @end: end of  array
 */
void print_array(int *array, int begin, int end)
{
	int i;

	printf("Searching in array: ");
	for (i = begin; i <= end; i++)
	{
		if (i != begin)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * recursive_binary_search - Finds value in array recursivelly
 * @array: array to be searched its value
 * @begin: beginning of array (left)
 * @end: end of array (rigth)
 * @value: value to be searched
 * Return: index of value or -1
 */
int recursive_binary_search(int *array, int begin, int end, int value)
{
	if (end >= begin)
	{
		int mid = begin + (end - begin) / 2;

		print_array(array, begin, end);
		if (array[mid] == value)
		{
			if (array[mid - 1] == value)
				return (recursive_binary_search(array, begin, mid, value));

			return (mid);
		}
		if (array[mid] >= value)
			return (recursive_binary_search(array, begin, mid, value));
		return (recursive_binary_search(array, mid + 1, end, value));
	}
	return (-1);
}

/**
 * advanced_binary - Calls recursive binary search function
 * @array: array to be searched its value
 * @size: size of array
 * @value: value to be searched
 * Return: index of value otherwise -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (recursive_binary_search(array, 0, size - 1, value));
}
