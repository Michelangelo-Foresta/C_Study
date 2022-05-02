DEFAULT_GOAL := all

contact.so: contact.c contact.h
	# https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html
	# https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html
	gcc -c -Wall -Werror -fpic contact.c
	gcc -shared -o libcontact.so contact.o

mike1:  contact.so
	#Make the rest work using the above tutorial
	gcc mike1.c -o m

mike1: mike1.c
	# Make the rest work using the above tutorial
	gcc mike1.c ./libcontact.so -o m

mikeread: contact.so mike1read.c
	gcc mike1read.c ./libcontact.so -o mr

all: mike1 mikeread
	./m -fname Johnnny -lname ir -number 5144857392 -o Hi.contact
	./mr -o Hi.contact

test: mike1
	./m -fname jogdhe -lname kdiehr -number 4364320095 -o /home/michelangelo/Desktop/Hi.txt

testmr: mikeread
	./mr -o /home/michelangelo/Desktop/Hi.txt
