#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

struct user {
	char *name;
	time_t time;
};

#include "list.h"

struct node *queue;

void user_insert(char *name) {
	struct user *user = malloc(sizeof *user); /* sizeof (struct user));*/
	if (user == nullptr) {
		fprintf(stderr, "Out of memory\n");
		exit(EXIT_FAILURE);
	}
	user->name = malloc(strlen(name) + 1);
	if (user->name == NULL) {
		fprintf(stderr, "Out of memory\n");
		exit(EXIT_FAILURE);
	}
	strcpy(user->name, name);
	user->time = time(NULL);
	
	list_insert(queue, user);
}

char *user_answer() {
	if (list_empty(&queue))
		return nullptr;

	struct user *user = list_get_data(list_get_next(queue));
	
	list_remove(list_get_next(queue));
	
	char *name = user->name;
	free(user);
	return name;
}

void user_remove(char *name) {
	for (struct user *p = queue.next; p != &queue; p = p->next)
		if (strcmp(p->name, name) == 0) {
		
			list_remove(p);
			
			free(p->name);
			free(p);
			return;
		}
}

void user_delete_queue() {
	struct user *next;
	for (struct user *p = queue.next; p != &queue; p = next) {
	
		list_remove(p);
		
		next = p->next;
		
		
		free(p->name);
		free(p);
	}
}

void print(void *a)
{
	struct user *user = a;
	printf("[%d] %s\n", i, user->name);
}

void user_print() {
	list_foreach(queue, print)
	


}

void help()
{
	printf("Comandos:\n"
		"        s        - Sair do programa\n"
		"        h        - Mostrar lista de comando\n"
		"        n <name> - Chegada de novo utente\n"
		"        d <name> - Desistencia de utente\n"
		"        l        - Listar fila de espera\n"
		"        a        - Atender utente\n");
}

int main()
{
	queue = list_create();
	
	char line[100];
	while (true) {
		fputs( "> ", stdout);
		if (fgets(line, sizeof line, stdin) == NULL)
			return EXIT_FAILURE;
		char *command = strtok(line, " \n");
		if (command == NULL)
			continue;
		char *name = strtok(NULL, " \n");
		switch (toupper(*command)) {
			case 's':
			case 'S':
				user_delete_queue();
				return EXIT_FAILURE;
			case 'H':
				help();
				break;
			case 'N':
				user_insert(name);
				break;
			case 'D':
				user_remove(name);
				break;
			case 'L':
				user_print();
				break;
			case 'A':
				name = user_answer();
				if (NULL == name) {
					printf("Fila vazia\n");
				}
				else {
					printf("Atender %s\n", name);
					free(name);
				}
				break;
		}
	}
}


