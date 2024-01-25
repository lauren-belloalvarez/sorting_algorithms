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
 * lomutosplit - sorts integers according to lomuto partition
 *
 * @array: array of unsorted integers
 * @size: size of the array
 * @left: starting index of subset
 * @right: ending index of subset
 *
 * Return: final partition index
 */

int lomutosplit(int *array, size_t size, int left, int right)
{
	int *pivot, up, down;

	pivot = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *pivot)
		{
			if (up < down)
			{
				swap(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}
	if (array[up] > *pivot)
	{
		swap(array + up, pivot);
		print_array(array, size);
	}
	return (up);
}

/**
 * lomutosort - algorithm through recursion
 *
 * @array: array of unsorted integers
 * @size: size of the array
 * @left: starting index of the array
 * @right: ending index of the array
 *
 * Return: sorted partition
 */

void lomutosort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomutosplit(array, size, left, right);
		lomutosort(array, size, left, part - 1);
		lomutosort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - sorts integers in ascending order with quicksort
 *
 * @array: array of unsorted integers
 * @size: size of the array
 *
 * Return: sorted array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomutosort(array, size, 0, size - 1);
}
