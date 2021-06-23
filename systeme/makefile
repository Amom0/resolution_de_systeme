test_matrice.exe : p_matrice.o p_systeme.o test_matrice.o 
	gcc -o test_matrice.exe p_matrice.o p_systeme.o test_matrice.o
	./test_matrice.exe

p_systeme.o : p_systeme.c p_systeme.h
	gcc -c p_systeme.c
	
p_matrice.o : p_matrice.c p_matrice.h
	gcc -c p_matrice.c

test_matrice.o : test_matrice.c
	gcc -c test_matrice.c
