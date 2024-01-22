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
 * bubble_sort - sorts integers in ascending order with bubble sort
 *
 * @array: array of unsorted integers
 * @size: size of the array
 *
 * Return: sorted array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, len;
	bool test;

	len = size;
	test = false;

	if (size < 2 || array == NULL)
		return;

	while (!test)
	{
		test = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array + i, array + i + 1);
				print_array(array, size);
				test = false;
			}
		}
		len--;
	}
}
