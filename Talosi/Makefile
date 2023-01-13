all: exec run

exec: main.c threeStack.c threeStack.h
	gcc -o exec main.c threeStack.c

run: exec
	./exec

clear:
	rm -f *.o *~
	rm -f *.gch
rmproper: clear
	rm -f exec