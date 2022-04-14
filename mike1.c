#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <linux/limits.h>
#include <time.h>

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
				i++;
				FILE* file;
				file = fopen(argv[i], "w");
				if (file == NULL) {
					printf("I tried one bit at a time at the speed of light but this file could not be opened\nI'm NEVER wrong, so check your shit...\n");
					return 1;
				}
				else {
					printf("Data has been stored to the following file: %s\n", argv[i]);
					fprintf(file, "\n****CONTACT DETAILS****\nFirst Name: %s\nLast Name: %s\nPhone Number: %s\n", c1.fname, c1.lname, c1.number);
					fclose(file);
				}
				//printf("%d: %s\n", i, argv[i]);	
			}
			else {
				printf("Sorry that file path is invalid, please make sure your path is valid\n");
				return 1;
			}
		}
	}
	stop_clock = clock();
	double time_elapsed = (double)(stop_clock - start_clock) / CLOCKS_PER_SEC;
	printf("\nTime Elapsed: %lf\n",time_elapsed);
	//printf("\n****Contact List****\nFirst name: %s\nLast name: %s\nPhone number: %s\n");
}

