#include "sort.h"

/**
 * swap_bubble - This function swaps two integers
 * @a: This parameter is a pointer to the first integer
 * @b: This parameter is a pointer to the second integer
 */

void swap_bubble(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sorts array of integers in ascending order using Bubble sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_bubble(&array[j], &array[j + 1]);
				swapped = 1;
				/*Print array after each swap*/
				print_array(array, size);
			}
		}
		/**
		 * If no 2 elements were swapped by inner loop,
		 * the array is sorted
		 */
		if (!swapped)
			break;
	}
}
