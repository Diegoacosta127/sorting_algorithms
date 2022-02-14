#include "sort.h"
/**
  * selection_sort - sorts an array using Selection sort algorithm
  * @array: array to be sorted
  * @size: length of the array
  */
void selection_sort(int *array, size_t size)
{
	unsigned long int i, j, min;
	int sw;

	if (!array || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		min = i;
		sw = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (i < min)
		{
			array[i] = array[min];
			array[min] = sw;
			print_array(array, size);
		}
	}
}
