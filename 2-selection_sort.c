#include "sort.h"

/**
 * print_array_elmt - This funtion serves as the putchar for this project
 *
 * @elmt: function parameter
 * Returns: void function
 */

void print_array_elmt(int elmt)
{
	int num_digits = 0;
	int divisor = 1;
	int digit;

	if (elmt == 0)
	{
		putchar('0');
		return;
	}

	while (elmt / divisor != 0)
	{
		num_digits++;
		divisor *= 10;
	}

	divisor /= 10;
	while (divisor != 0)
	{
		digit = elmt / divisor;
		putchar(digit + '0');
		elmt -= digit * divisor;
		divisor /= 10;
	}
}


/**
 * selection_sort - sorts an array of integers in ascending order using
 *                  the selection sort algorithm
 * @array: pointer to the first element of the array to sort
 * @size: number of elements in the array
 */

void selection_sort(int *array, size_t size)
{
	size_t a, b, min;

	if (size < 2)
	{
		return;
	}
	for (a = 0; a < size - 1; a++)
	{
		min = a;

		for (b = a + 1; b < size; b++)
		{
			if (array[b] < array[min])
			{
				min = b;
			}
		}
		if (min != a)
		{
			int tmp = array[a];

			array[a] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
