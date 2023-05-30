CFLAGS:=-Wall -Wextra -Werror -Wno-char-subscripts -pedantic -std=c99 -ggdb

main: main.c
	cc $(CFLAGS) -o $@ $^
