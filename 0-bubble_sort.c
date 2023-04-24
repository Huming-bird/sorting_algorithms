#include "sort.h"

/**
 * bubble_sort: This function sorts an array of size 'size'
 * in ascending order
 *
 * @array: An array to be sorted
 * @size: size of the array
 * Return: void function
 */

void bubble_sort(int *array, size_t size)
{
	
	int tmp;

	for (size_t i = 0; i < size - 1; i++)
       	{
		for (size_t j = 0; j < size - i - 1; j++)
	       	{
            		if (array[j] > array[j + 1])
		       	{
                		tmp = array[j];
                		array[j] = array[j + 1];
                		array[j + 1] = tmp;
			}
		}
	}
}
