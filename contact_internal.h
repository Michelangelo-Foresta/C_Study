#ifndef INTERNAL_HEADER
#define Fname_len 64
#define Lname_len 64
#define Number_len 12
#include "contact.h"

struct Contact {
        char fname[Fname_len];
        char lname[Lname_len];
        char number[Number_len];
};
#endif
