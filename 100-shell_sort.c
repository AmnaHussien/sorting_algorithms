#include "sort.h"

/**
*swap - function that swap the positions of two elements into an array
*@array: array
*@item1: array element
*@item2: array element
*return: nothing
*/
void swap(int *array, int item1, int item2)
{

	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}
/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @size: size of the array
 * @array: list with numbers
 * return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t gapp = 1, i, index = 0;

	if (array == NULL || size < 2)
		return;
	while (gapp < size / 3)
		gapp = 3 * gapp + 1;
	while (gapp >= 1)
	{
		for (i = gapp; i < size; i++)
			for (index = i; index >= gapp &&
			 (array[index] < array[index - gapp]); index -= gapp)
				swap(array, index, index - gapp);
		print_array(array, size);
		gapp /= 3;
	}
}
