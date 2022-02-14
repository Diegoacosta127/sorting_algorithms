#include "sort.h"
/**
  * get_back - swaps nodes backwards
  * @here: node to be swapped
  * @ins: aux node to swap
  * @list: the whole list
  */
void get_back(listint_t *here, listint_t *ins, listint_t **list)
{
	listint_t *sw1 = here->next;
	listint_t *sw2 = ins->prev;

	if (sw1)
		sw1->prev = ins;
	if (sw2)
		sw2->next = here;
	here->prev = sw2;
	ins->next = sw1;
	here->next = ins;
	ins->prev = here;
	if (*list == ins)
		*list = here;
	print_list(*list);
}
/**
  * insertion_sort_list - sorts a doubly linked list of integers
  * @list: pointer to pointer of listint_t
  */
void insertion_sort_list(listint_t **list)
{
	listint_t *here = NULL;
	listint_t *ins = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	here = (*list)->next;
	ins = here->prev;
	while (here)
	{
		ins = here->prev;
		while (ins && ins->n > here->n)
		{
			get_back(here, ins, list);
			ins = here->prev;
		}
		here = here->next;
	}
}
