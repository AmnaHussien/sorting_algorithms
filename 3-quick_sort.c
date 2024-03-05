#include "sort.h"
/**
*swap - the positions of two elements into an array
*@array: array
*@item1: array element
*@item2: array element
*/
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}
/**
 *lomuto_partition - lomuto partition sorting scheme implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: size array
 *Return: the position of the last element sorted
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t curr = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[curr] != array[finder])
			{
				swap(array, curr, finder);
				print_array(array, size);
			}
			curr++;
		}
	}
	if (array[curr] != array[last])
	{
		swap(array, curr, last);
		print_array(array, size);
	}
	return (curr);
}
/**
 *qs - qucksort algorithm implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: array size
 *return: nothing
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;


	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);

		qs(array, first, position - 1, size);
		qs(array, position + 1, last, size);
	}
}
/**
 *quick_sort - prepare the terrain to quicksort algorithm
 *@array: array
 *@size: array size
 *return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
