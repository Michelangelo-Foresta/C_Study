#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <linux/limits.h>

bool has_another_argument(int argc, int i) {
	//printf("argc: %d; i: %d\n", argc, i);
	if ((i + 1) < argc)
		return true;
	return false;
}

struct Contact {
	char fname[64];
	char lname[64];
	char number[13];
}c1;



int main(int argc, char* argv[]) {
	char filepath[PATH_MAX];
	clock_t start_clock, stop_clock;
	start_clock = clock();
	for (int i = 1; i < argc; i++) {
		const char* arg = argv[i];
		//printf("%d: %s\n", i, arg);

		// && strcmp(argv[i], "-o" != 0) && strcmp(argv[i], "-fname" != 0) && strcmp(argv[i], "-lname" != 0) && strcmp(argv[i], "-number" != 0)
		if (strcmp(argv[i], "--help") == 0 && argc >= 2) {
			printf("Please enter your first name using -fname, your last name using -lname, and your phone number using -number. Finally specify the file path you would like it to be copied to using -o\n");
		}

		if (strcmp(argv[i], "-fname") == 0) {
			if (has_another_argument(argc, i) == true) {
				const char* fname = argv[i + 1];
				i++;
				if (strlen(argv[i]) > 63) {
					printf("Your First name should not be longer than 63 characters.\n");
					return 1;
				}
				strncpy(c1.fname, argv[i], 64);
				c1.fname[64 - 1] = '\0';
				//printf("%d: %s\n", i,argv[i]);
			}
			else {
				printf("Trying to set first name, but no name provided after -fname\n");
				return 1;
			}
		}
		if (strcmp(argv[i], "-lname") == 0) {
			if (has_another_argument(argc, i) == true) {
				const char* lname = argv[i + 1];
				i++;
				if (strlen(argv[i]) > 63) {
					printf("Your Last name should not be longer than 63 characters.\n");
					return 1;
				}
				strncpy(c1.lname, argv[i], 64);
				c1.lname[64 - 1] = '\0';
				//printf("%d: %s\n", i ,argv[i]);
			}
			else {
				printf("Trying to set last name, but no name provided after -lname\n");
				return 1;
			}
		}
		if (strcmp(argv[i], "-number") == 0) {
			if (has_another_argument(argc, i) == true) {
				const char* number = argv[i + 1];
				i++;
				if (strlen(argv[i]) > 12) {
					printf("Your number should not be longer than 12 characters.\n");
					return 1;
				}
				strncpy(c1.number, argv[i], 13);
				c1.number[13 - 1] = '\0';
				//printf("%d: %s\n",i,argv[i]);
			}
			else {
				printf("Trying to set number, but no number provided after -number\n");
				return 1;
			}
		}
		if (strcmp(argv[i], "-o") == 0) {
			if (has_another_argument(argc, i) == true) {
				const char* filep = argv[i + 1];
				i++;
				strncpy(filepath, argv[i], 260);
				filepath[260 - 1] = '\0';
				//printf("%d: %s\n", i, argv[i]);
			}
			else {
				printf("Sorry there was not file path provided.\n");
			}
		}
	}

	FILE* file;
	file = fopen(filepath, "ab+");
	if (file == NULL) {
		fprintf(stderr,"\nError opened file\n");
		return 1;
	}	
	//printf("Data has been stored to the following file: %s\n", filepath);
	fwrite(&c1, sizeof(struct Contact),1,file);

	if (fwrite != 0) {
		printf("Structure has been written!\n");
	}
	else {
		printf("Error writing to file.\n");
	}
	fclose(file);

	
	stop_clock = clock();
	double time_elapsed = (double)(stop_clock - start_clock) / CLOCKS_PER_SEC;
	printf("\nTime Elapsed: %lf\n",time_elapsed);
}
