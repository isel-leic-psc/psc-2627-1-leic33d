struct node;

struct node *list_create();

void list_remove(struct node *p);

struct node *list_insert_next(struct node *node, void *data);

void list_foreach(struct node *list, void (*doit)(void *, void *), void *context);

struct node *list_search(struct node *list, bool (*cmp)(const void *, const void *), const void *context);

bool list_empty(struct node *list);

struct node *list_get_next(struct node *node);

void *list_get_data(struct node *node);
