#include "sort.h"
/**
  * partition - implementation of the Lomuto partition scheme
  * @array: array to be sorted
  * @low: lower index
  * @high: higher index
  * @size: length of the array
  * Return: the index + 1
  */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low;
	int j, aux;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;
			if (array[j] != array[i])
				print_array(array, size);
			i++;
		}
	}
	aux = array[i];
	array[i] = array[high];
	array[high] = aux;
	if (array[i] != array[high])
		print_array(array, size);
	return (i);
}
/**
  * sort_it - sorts a partition of an array recursively
  * @array: array to be sorted
  * @low: lower index of partition
  * @high: higher index of partition
  * @size: length of the array
  */
void sort_it(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		sort_it(array, low, pivot - 1, size);
		sort_it(array, pivot + 1, high, size);
	}
}
/**
  * quick_sort - sorts an array using the quick sort algorithm
  * @array: array to be sorted
  * @size: length of the array
  */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sort_it(array, 0, size - 1, size);
}
