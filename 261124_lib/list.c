#include <stdlib.h>
#include "list.h"

struct node {
	struct node *next, *prev;
	void *data;
};

void *list_get_data(struct node *node)
{
	return node->data;
}

struct node *list_get_next(struct node *node)
{
	return node->next;
}

int counter = 0;

struct node *list_create()
{
	counter++;
	struct node *sentinel = malloc(sizeof *sentinel);
	if (sentinel == nullptr)
		return nullptr;
	return sentinel->next = sentinel->prev = sentinel;
}

struct node *list_insert_next(struct node *node, void *data)
{
	struct node *new = malloc(sizeof *new);
	if (new == nullptr)
		return nullptr;
	new->data = data;

	new->next = node->next;
	new->prev = node;
	node->next->prev = new;
	node->next = new;
	return new;
}

void list_remove(struct node *p)
{
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
}

void list_foreach(struct node *list, void (*doit)(void *, void *), void *context)
{
	for (struct node *p = list->next; p != list; p = p->next)
		doit(p->data, context);
}

struct node *list_search(struct node *list, bool (*cmp)(const void *, const void *), const void *context)
{
	for (struct node *p = list->next; p != list; p = p->next)
		if (cmp(p->data, context) == 0)
			return p;
	return nullptr;
}

bool list_empty(struct node *list)
{
	return list->next == list;
}





