contact.so: contact.c contact.h
    # https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html
	gcc -c -Wall -Werror -fpic contact.c
	gcc -shared -o libcontact.so contact.o

mike1:  contact.so
	// Make the rest work using the above tutorial
	gcc mike1.c -o m

all: mike1
	./m -fname Johnnny -lname ir -number 5144857392 -o /home/michelangelo/Desktop/Hi.txt
