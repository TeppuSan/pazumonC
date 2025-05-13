CC = gcc

Message: copy doxy ./R_13_3.o 
# ./sub.o
	gcc -o Message ./R_13_3.o
# ./sub.o

cpp: copy
	cppcheck ./R_15_3/* ./checkresult.txt

./R_13_3.o:./R_13_3.c
	gcc -c -o ./R_13_3.o ./R_13_3.c

doxy: ./sub.c
	doxygen ./sub.c ./R_13_3.c

copy:
	cp -R ./R_13_3/* ./R_15_4/
