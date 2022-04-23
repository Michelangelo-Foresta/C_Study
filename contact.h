#ifndef HEADER_FILE
#define HEADER_FILE
#define Fname_len 64
#define Lname_len 64
#define Number_len 12

struct Contact {
        char fname[Fname_len];
        char lname[Lname_len];
        char number[Number_len];
};

struct Contact* contact_new();
void contact_free(struct Contact *c);

int contact_write_fname(struct Contact* c, const char* s);
int contact_write_lname(struct Contact* c, const char* s);
int contact_write_number(struct Contact* c, const char* s);
#endif
