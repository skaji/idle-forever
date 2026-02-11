idle-forever: idle-forever.c
	gcc -Wall -Wextra -o idle-forever idle-forever.c

clean:
	rm -f idle-forever
