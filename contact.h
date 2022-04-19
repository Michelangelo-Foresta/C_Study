#ifndef HEADER_FILE
#define HEADER_FILE

struct Contact {
        char fname[64];
        char lname[64];
        char number[13];
};

struct Contact* contact_new();
void contact_free(struct Contact *c);

void contact_write_fname(struct Contact* c, const char* s);
void contact_write_lname(struct Contact* c, const char* s);
void contact_write_number(struct Contact* c, const char* s);
#endif
