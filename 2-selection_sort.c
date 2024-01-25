#include "sort.h"

/**
 * swap - swaps two integers in an array
 *
 * @x: first integer
 * @y: second integer
 *
 * Return: swapped integer
 */

void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * selection_sort - sorts integers in ascending order using selection
 *
 * @array: array of integers
 * @size: size of array
 *
 * Return: sorted array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, index;

	if (size < 2 || array == NULL)
		return;
	for (i = 0; i < size - 1; i++)
	{
		index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[index])
				index = j;
		}
		if (index != i)
		{
			swap(&array[i], &array[index]);
			print_array(array, size);
		}
	}
}
