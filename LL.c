#include "header.h"

List* constructList()
{
	List* list = (List*)calloc(1, sizeof(List));
	list->size = 0;
	list->head = NULL;

	return list;	
}

void pushList(List* list, const int value)
{
	Node* node = (Node*)calloc(1, sizeof(Node));
	
	node->value = value;
	node->next = list->head;

	list->head = node;
	++list->size;
}

int topList(const List* list)
{
	assert(list->size != 0);

	return list->head->value;
}

void popList(List* list)
{
	if (list->size == 0)
	{
		return;
	}
	
	Node* node = list->head;

	list->head = node->next;
	node->next = NULL;

	free(node);
	--list->size;
}

void destroyList(List* list)
{
	while (list->size)
	{
		popList(list);
	}

	free(list);
}