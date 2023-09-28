#include "sort.h"

/**
 * exchange_ints - exchange two integers in an array.
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
 * bubble_sort - This will sort an array of integers in ascending pattern.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each exchange.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				exchange_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
