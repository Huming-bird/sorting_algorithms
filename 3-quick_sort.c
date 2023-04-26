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
 * part - this serves as apartition function
 * @array: array to be parted
 * @l: left index
 * @r: right index
 * Return: int value
 */

int part(int *array, int l, int r, size_t size)
{
	int pivot_index, pivot, tm, tmp, swap, j;
	size_t k;
	/*int size = sizeof(array) / sizeof(int);*/

	pivot_index = r;
	pivot = array[r];
	swap = l - 1;

	for (j = l; j < pivot_index; j++)
	{
		if (array[j] < pivot)
		{
			swap++;
			tmp = array[swap];
			array[swap] = array[j];
			array[j] = tmp;
			for (k = 0; k < size; k++)
			{
				print_array_elmt(array[k]);
				if (k != size - 1)
				{
					putchar(',');
					putchar(' ');
				}
			}
		putchar('\n');
		}
	}
	tm = array[swap + 1];
	array[swap + 1] = array[pivot_index];
	array[pivot_index] = tm;
	return (swap + 1);
}

/**
 * quick_sort - This function sorts an array of size 'size',
 * using quick sort algo, in ascending order.
 *
 * @array: An array to be sorted
 * @size: size of the array
 * Return: void function
 */

void quick_sort(int *array, size_t size)
{
	int pivot_index;

	if (size <= 1)
	{
		return;
	}

	pivot_index = part(array, 0, size - 1, size);

	quick_sort(array, pivot_index);
	quick_sort(&array[pivot_index + 1], size - pivot_index - 1);
}
