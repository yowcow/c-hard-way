.PHONY: clean

CFLAGS=-std=c99 -Wall -Werror
TARGET=quick-sort \
	ex1-13 ex1-16 ex1-17 ex1-18 ex1-19 ex1-20 \
	ex2-3 ex2-4 ex2-5 ex2-6 ex2-7 ex2-8 ex2-9 \
	ex3-1 shell-sort ex3-3 ex3-4 ex3-5 \
	ex4-1 ex4-2 ex4-3 \
	ex5-1 ex5-2 ex5-3 ex5-4 ex5-5 ex5-7

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $@.c -lm -o $@

clean:
	-rm -rf $(TARGET)
