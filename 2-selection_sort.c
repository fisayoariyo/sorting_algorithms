#include "sort.h"

/**
 * exchange_ints - Exchange the two integers in an array.
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
 * selection_sort - This will sort an array of integers in ascending order
 *                  by using the selection sort algorithm.
 * @array: This is an array of integers.
 * @size: This is a size of array.
 *
 * Description: This will print the array after every exchange.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			exchange_ints(array + i, min);
			print_array(array, size);
		}
	}
}
