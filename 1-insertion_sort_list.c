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
 * insertion_sort_list - sorts a doubly linked list of integers in
 *                       ascending order using the insertion sort algorithm
 * @list: double pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *cur;
	listint_t *tmp;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
	{
		return;
	}

	for (cur = (*list)->next; cur != NULL; cur = cur->next)
	{
		tmp = cur;

		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			if (tmp->next != NULL)
			{
				tmp->next->prev = tmp->prev;
			}

		tmp->prev->next = tmp->next;
		tmp->next = tmp->prev;
		tmp->prev = tmp->prev->prev;

		if (tmp->prev == NULL)
		{
			(*list) = tmp;
		}
		else
		{
			tmp->prev->next = tmp;
		}

		tmp->next->prev = tmp;
		print_list(*list);
		}
	}
}
