#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

struct Contact* contact_new() {
       return malloc(sizeof(struct Contact));
}
/*Pass POINTER TO STRUCT THROUGH MALLOC*/

void contact_free(struct Contact *c) {
	free(c);
}
/*FREE POINTER TO STRUCT FROM MALLOC*/


// WRITE INPUT TO POINTER OF STRUCT VARIABLE
void contact_write_fname(struct Contact* c, const char* s) {
 if(strlen(s)<1){
	printf("The first name is required.\n");
	return;
}  
 if(strlen(s)>=63){
	printf("The first name should be less than 63 characters.\n");
	return;
}
  strncpy(c->fname, s , strlen(s));
}
void contact_write_lname(struct Contact* c, const char* s) {
 if(strlen(s)<1){
	printf("The last name is required.\n");
	return; 
}
if(strlen(s)>=63){
	printf("The last name should be less than 63 characters.\n");
	return;
}
strncpy(c->lname, s ,strlen(s));
}
void contact_write_number(struct Contact* c, const char* s) {
 if(strlen(s)<1){
	printf("The phone number is required.\n");
	return;
} 
if(strlen(s)>12){
	printf("The phone number should be less than 12 numbers.\n");
	return;
}  
strncpy(c->number, s ,strlen(s));
}
// END OF WRITE
