struct node {
	struct user *next, *prev;
	void *data;
}

void list_get_data(struct node *node)
{
	return node->data;
}

void list_get_next(struct node *node)
{
	return node->next;
}

struct node *list_create() {
	struct node *sentinel = malloc(sizeof *node);
	return sentinel.next = sentinel.prev = sentinel;
}

void list_insert_next(struct node *node, void *data)
{
	struct node *new = malloc(sizeof *new);
	
	new->next = node->next;
	new->prev = node->next->prev;
	node->next = user;
	node->next->prev = user;
}
	
void list_remove(struct node *p) {
	p->prev->next = p->next;
	p->next->prev = p->prev;
	
void list_foreach(struct node *list, void (*doit)(void *))
{
	for (struct node *p = list->next; p != list; p = p->next)
		doit(p->data);
}

bool list_empty(struct node *list)
{
	return list->next == list;
}



void list_foreach(struct node *list)
{
	
}




