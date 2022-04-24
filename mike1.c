#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <linux/limits.h>
#include "contact.h"
#define Error_too_long 3
#define Error_too_short 2

bool has_another_argument(int argc, int i) {
	if ((i + 1) < argc)
		return true;
	return false;
}


int main(int argc, char* argv[]) {
	char filepath[PATH_MAX];
	struct Contact * c = contact_new();
	clock_t start_clock, stop_clock;
	start_clock = clock();
	for (int i = 1; i < argc; i++) {
		const char* arg = argv[i];
		
		if (strcmp(argv[i], "--help") == 0 && argc >= 2) {
			printf("Please enter your first name using -fname, your last name using -lname, and your phone number using -number. Finally specify the file path you would like it to be copied to using -o\n");
		}
		if (strcmp(argv[i], "-fname") == 0) {
			if (has_another_argument(argc, i) == true) {
				const char* fname = argv[i + 1];
				i++;
				int func = contact_write_fname(c, argv[i]);
				if(func ==Error_too_long){
					printf("First name should not be longer than %d characters.\n", Fname_len);
				}
				if(func == Error_too_short){
					printf("First name should be longer than 1 character.\n");
				}
				
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
				int func = contact_write_lname(c,argv[i]);
				if(func ==Error_too_long){
					printf("Last name should not be longer than %d characters.\n", Lname_len);
				}
				if(func == Error_too_short){
					printf("Last name should be longer than 1 character.\n");
				}
				
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
				int func = contact_write_number(c,argv[i]);
				if(func == Error_too_long){
					printf("Phone number should not be longer than %d characters.\n", Number_len);
				}
				if(func == Error_too_short){
					printf("Phone number should not be less than 1 character.\n");
				}
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
			}
			else {
				printf("Sorry there was no file path provided.\n");
			}

		}
	}

	FILE* file;
	file = fopen(filepath, "wb");
	if (file == NULL) {
		fprintf(stderr,"\nError opened file\n");
		return 1;
	}	
	fwrite(c, sizeof(struct Contact),1,file);

	if (fwrite != 0) {
		printf("Structure has been written!\n");
	}
	else {
		printf("Error writing to file.\n");
	}
	contact_free(c);
	c = NULL;
	fclose(file);
	
	stop_clock = clock();
	double time_elapsed = (double)(stop_clock - start_clock) / CLOCKS_PER_SEC;
	printf("\nTime Elapsed: %lf\n",time_elapsed);
}
