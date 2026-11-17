struct node;

void list_remove(struct node *p);

void list_insert_next(struct node *node, void *data);

void list_get_data(struct node *node);

void list_get_next(struct node *node);

void list_foreach(struct node *list, void (*doit)(void *));
