#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "list.h"

struct user {
	char *name;
	time_t time;
};

struct node *queue;

void user_insert(char *name) {
	
	struct user *user = malloc(sizeof *user); /* sizeof (struct user));*/
	if (user == NULL) {
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

	list_insert_prev(queue, user);
}

char *user_answer() {
	if (list_empty(queue))
		return NULL;

	struct node *node = list_next(queue);
	
	struct user *user = list_data(node);
	
	list_remove(node);

	char *name = user->name;
	free(user);
	return name;
}

int cmp_user_name(void *data, void *context) {
	struct user *user = data;
	char *name = context;
	return strcmp(user->name, name);
}

void user_remove(char *name) {
	struct node *node = list_search(queue, cmp_user_name, name);
	if (NULL != node) {
		struct user *user = list_data(node);
		list_remove(node);
		free(user->name);
		free(user);
	}
}

void single_remove(void *data, void *context) {
	struct user *user = data;
	free(user->name);
	free(user);
}


void user_delete_queue() {
	list_foreach(queue, single_remove, NULL);
	list_destroy(queue);
}

int i;

void single_print(void *data, void *context) {
	struct user *user = data;
	printf("[%d] %s\n", i, user->name);
	i++;
}

void user_print() {
	i = 1;
	list_foreach(queue, single_print, NULL);
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
	char line[100];
	queue = list_create();
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


