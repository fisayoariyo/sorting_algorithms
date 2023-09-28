#include "sort.h"

/**
 * exchange_ints - Exchanges two integers in our array.
 * @a: The first integer to be exchanged
 * @b: The second integer to be exchanged
 */
void exchange_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - This will sort an array of integers in ascending
 *              order by using the shell sort algorithm.
 * @array: This is an array of integers.
 * @size: This is the size of the array.
 *
 * Description: This uses the Knuth's interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				exchange_ints(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
