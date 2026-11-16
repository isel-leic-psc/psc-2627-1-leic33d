
void user_insert(char *name)
{
}

char *user_answer()
{
}

void user_remove(name)
{
}


static void help()
{
	printf("Comandos:\n"
		"        S        - Sair do programa\n"
		"        H        - Mostrar lista de comando\n"
		"        N <name> - Chegada de novo utente\n"
		"        D <name> - Desistencia de utente\n"
		"        L        - Listar fila de espera\n"
		"        A        - Atender utente\n");
}

int main()
{
	char line[100];
	while (true) {
		if (fgets(line, sizeof line, stdin) == NULL)
			return EXIT_FAILURE;
		char *command = strtok(line, " \n");
		if (command == NULL)
			continue;
		char *name = strtok(NULL, " \n");
		switch (toupper(*command)) {
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


