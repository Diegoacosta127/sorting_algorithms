#include "sort.h"
/**
  * bubble_sort - sorts an array of integers in ascending order
  * @array: pointer to array to sort
  * @size: size of the array
  */
void bubble_sort(int *array, size_t size)
{
	size_t i, flag;
	int aux;

	if (size < 2)
		return;
	do {
		flag = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				aux = array[i + 1];
				array[i + 1] = array[i];
				array[i] = aux;
				flag = 1;
				print_array(array, size);
			}
		}
	} while (flag == 1);
}
