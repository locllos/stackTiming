#include "header.h"

size_t Increase(const size_t cur_capacity, const double increase_factor, OPERATION operation)
{
	if (operation == ADD)
	{
		return (cur_capacity + increase_factor);
	}

	else if (operation == MULTIPLY)
	{
		return cur_capacity + increase_factor * cur_capacity;
	}

	return 0;
}

Array* constructArray(const size_t start_size, const double increase_factor, OPERATION operation)
{
	Array* arr = (Array*)calloc(start_size, sizeof(Array));

	arr->array = (int*)calloc(start_size, sizeof(int));
	arr->increase_factor = increase_factor;
	arr->operation = operation;
	arr->capacity = start_size;
	arr->size = 0;
	
	return arr;
}

void pushArray(Array* arr, const int value)
{
	if (arr->size + 1 > arr->capacity)
	{
		arr->capacity = Increase(arr->capacity, arr->increase_factor, arr->operation);
		arr->array = (int*)realloc(arr->array, arr->capacity*sizeof(int));
	}

	arr->array[arr->size] = value;
	++arr->size;

}

int topArray(const Array* arr)
{
	assert(arr->size != 0);

	return arr->array[arr->size - 1];
}

void popArray(Array* arr)
{
	if (arr->size == 0)
	{
		return;
	}
	
	--(arr->size);
}

void destroyArray(Array* arr)
{
	free(arr->array);
	free(arr);
}