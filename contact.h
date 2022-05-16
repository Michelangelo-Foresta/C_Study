#ifndef HEADER_FILE
#define HEADER_FILE


struct Contact;

struct Contact* contact_new();
void contact_free(struct Contact *c);
int contact_write_fname(struct Contact* c, const char* s);
int contact_write_lname(struct Contact* c, const char* s);
int contact_write_number(struct Contact* c, const char* s);
int contact_write(struct Contact* c,void* fd);
#endif
