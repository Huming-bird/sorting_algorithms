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
 * bubble_sort - This function sorts an array of size 'size'
 * in ascending order
 *
 * @array: An array to be sorted
 * @size: size of the array
 * Return: void function
 */

void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j, k;

	if (size < 2)
	{
		return;
	}
	else
	{

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
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
	}
}
}
