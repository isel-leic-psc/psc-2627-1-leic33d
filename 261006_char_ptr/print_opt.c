#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int opt;
	opterr = 0;
	char *filename_input = nullptr;
	char *filename_output = nullptr;

	FILE *fin = stdin;
	FILE *fout = stdout;
	
	while ((opt = getopt(argc, argv, "co:i:")) != -1) {
		switch (opt) {
			case 'o':
			   printf("opção o, argumento %s\n", optarg);
			   break;
			case 'i':
				printf("opção i, argumento %s\n", optarg);
				filename_input = optarg;
				break;
			case 'c':
				printf("opção c\n");
				filename_output = optarg;
				break;
			default: /* '?' */
				printf("%c %c\n", opt, optopt);
		}
	}
	if (filename_input != nullptr) {
		fin = fopen(filename_input, "r");
		if (fin == nullptr) {
			fprintf(stderr, "%s - %s\n", filename_input, strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	if (filename_output != nullptr) {
		fout = fopen(filename_output, "w");
		if (fout == nullptr) 	/* erro */
			;
	}	
	char buffer[200];
	fgets(buffer, sizeof buffer, fin);
}


		
