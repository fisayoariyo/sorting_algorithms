#include "sort.h"

void exchange_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * exchange_ints - Exchanges two integers in array.
 * @a: The first integer to be exchanged.
 * @b: The second integer to be exchanged.
 */
void exchange_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Make subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: This is the array of integers.
 * @size: This is the  size of the array.
 * @left: This is the  beginning index of the subset to order.
 * @right: This is the finishing  index of the subset to order.
 *
 * Return: The last partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				exchange_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		exchange_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - This will implement our quicksort algorithm thru recursion.
 * @array: This is an array of integers to be sorted.
 * @size: This is the size of the array.
 * @left: This is the beginning index of the array partition to order.
 * @right: The is the finishing index of the array partition to order.
 *
 * Description: This uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - This will sort an array of integers in ascending
 *              order by using the quicksort algorithm.
 * @array: This is an array of integers.
 * @size: This is the size of the array.
 *
 * Description: This uses the Lomuto partition scheme and prints
 *              the array after every exchange of two contents.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
