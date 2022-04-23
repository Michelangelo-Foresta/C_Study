#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#define Error_too_long 3
#define Error_too_short 2


/*Pass POINTER TO STRUCT THROUGH MALLOC*/
struct Contact* contact_new() {
       return malloc(sizeof(struct Contact));
}

/*FREE POINTER TO STRUCT FROM MALLOC*/
void contact_free(struct Contact *c) {
	free(c);
}

// WRITE Fname,Lname and number TO POINTER OF STRUCT VARIABLE
int contact_write_fname(struct Contact* c, const char* s) {
 	if(strlen(s)<1){
		printf("The first name is required.\n");
		return Error_too_short;
	}  
	if(strlen(s)>=Fname_len){
		printf("The first name should be less than 63 characters.\n");
		return Error_too_long;
	}
	strncpy(c->fname, s , strlen(s));
}
	
int contact_write_lname(struct Contact* c, const char* s) {
 	if(strlen(s)<1){
		printf("The last name is required.\n");
		return Error_too_short; 
	}
	if(strlen(s)>=Lname_len){
		printf("The last name should be less than 63 characters.\n");
		return Error_too_long;
	}
	strncpy(c->lname, s ,strlen(s));
}

int contact_write_number(struct Contact* c, const char* s) {
	if(strlen(s)<1){
		printf("The phone number is required.\n");
		return Error_too_short;
	}
 	if(strlen(s)>Number_len){
		printf("The phone number should be less than 12 numbers.\n");
		return Error_too_long;
	}  
	strncpy(c->number, s ,strlen(s));
}

// END OF WRITE
