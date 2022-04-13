#include <stdio.h>

#include <stdbool.h>

#include <string.h>

// See if there is another argument
bool has_another_argument(int argc, int i) {
  //printf("argc: %d; i: %d\n", argc, i);
  if ((i + 1) < argc)
    return true;
  return false;
}
struct Contact {
  char * fname;
  char * lname;
  char * number;
}
c1;

int main(int argc, char * argv[]) {

  for (int i = 1; i < argc; i++) {
    const char * arg = argv[i];
    printf("%d: %s\n", i, arg);

    // && strcmp(argv[i], "-fname" != 0) && strcmp(argv[i], "-lname" != 0) && strcmp(argv[i], "-number" != 0)

    if (strcmp(argv[i], "--help") == 0 && argc >= 2) {
      printf("Please enter your first name using -fname, your last name using -lname, and your phone number using -number.\n");
    }

    if (has_another_argument(argc, i) == true) {
        const char * fname = argv[i + 1];
        c1.fname = argv[i + 1];
        i++;
        printf("%d: %s\n", i, argv[i]);
      } else {
        printf("Trying to set first name, but no name provided after -fname\n");
        return 1;
      }
    }

    if (strcmp(argv[i], "-lname") == 0) {
      if (has_another_argument(argc, i) == true) {
        const char * lname = argv[i + 1];
        c1.lname = argv[i + 1];
        i++;
        printf("%d: %s\n", i, argv[i]);

      } else {
        printf("Trying to set last name, but no name provided after -lname\n");
        return 1;
      }
    }

    if (strcmp(argv[i], "-number") == 0) {
      if (has_another_argument(argc, i) == true) {
        c1.number = argv[i + 1];
        i++;
        printf("%d: %s\n", i, argv[i]);
      } else {
        printf("Trying to set number, but no number provided after -number\n");
        return 1;
      }

    }

  }

  printf("\n****Contact List****\nFirst name: %s\nLast name: %s\nPhone number: %s\n", c1.fname, c1.lname, c1.number);
}
