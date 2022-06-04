#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "contact_internal.h"
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
 	if(strlen(s)<=1){
		return Error_too_short;
	}
	if(strlen(s)>=Fname_len){
		return Error_too_long;
	}
	strncpy(c->fname, s , strlen(s));
	return 0;
}
	
int contact_write_lname(struct Contact* c, const char* s) {
 	if(strlen(s)<=1){
		return Error_too_short; 
	}
	if(strlen(s)>=Lname_len){
		return Error_too_long;
	}
	strncpy(c->lname, s ,strlen(s));
	return 0;
}

int contact_write_number(struct Contact* c, const char* s) {
	if(strlen(s)<=1){
		return Error_too_short;
	}
 	if(strlen(s)>Number_len){
		return Error_too_long;
	}  
	strncpy(c->number, s ,strlen(s));
	return 0;
}

// Write contents of structure
int contact_write(struct Contact* c,void* fd){
	int res = fwrite(c, sizeof(*c),1,fd);
	if (res != 0) {
		printf("Structure has been written!\n");
		return 1;
	}
	else {
		printf("Error writing to file.\n");
		return 0;
	}
}
// END OF WRITE
