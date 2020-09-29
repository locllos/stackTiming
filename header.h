#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>


//Dynamic array

typedef enum OPERATION
{
	ADD,
	MULTIPLY
} OPERATION;

typedef struct Array
{
	int* array;
	size_t size;
	size_t capacity;
	double increase_factor;
	OPERATION operation;
} Array;

Array* constructArray(const size_t start_size, const double increase_factor, OPERATION operation);
void pushArray(Array* arr, const int value);
int topArray(const Array* arr);
void popArray(Array* arr);
void destroyArray(Array* arr);


//Linked list
typedef struct Node
{
	int value;
	struct Node* next;
} Node;
typedef struct List
{
	Node* head;
	size_t size;	
} List;

List* constructList();
void pushList(List* list, const int value);
int topList(const List* list);
void popList(List* list);
void destroyList(List* list);
