#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <linux/limits.h>
#include <stdlib.h>
#include "contact.h"

bool is_another_argument(int argc, int i) {
	if ((i + 1) < argc)
		return true;
	return false;
}

int main(int argc, char* argv[]) {
	char filename[PATH_MAX];

	for (int i = 1; i < argc; i++) {
		const char *arg = argv[i];
		printf("%d : %s\n", i, arg);

		if (strcmp(argv[i], "-o") == 0 && argc > 1) {
			if (is_another_argument(argc, i) == true) {
				const char* file_input = argv[i+1]; //reading the next argument
				i++; //now i'm consuming the argument
				printf("%d : %s\n", i, file_input);
				strncpy(filename, argv[i], 260);
			}
		}
	}

	FILE* file;
	struct Contact input;
	file = fopen(filename, "rb");
	if (file == NULL) {
		fprintf(stderr, "Sorry %s could not be opened.\n", filename);
		return 1;
	}

	while (fread(&input, sizeof(struct Contact), 1, file))
	printf("%64s %64s %13s\n", input.fname, input.lname, input.number);
	
	fclose(file);
}
